#include "mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reisezieleListeausfuellen()
{
    ui->listWidget_Reiseziele->clear();
    ui->listWidget_Aktivitaeten->clear();

    for(auto ziel : agentur.getReiseziele()) {
        std::stringstream ss;
        ss << ziel.getName() << " (" << ziel.getLand() << ")\n";
        ui->listWidget_Reiseziele->addItem(QString::fromStdString(ss.str()));
    }
}

void MainWindow::showAktivitaeten(string reiseziel_name)
{
    ui->listWidget_Aktivitaeten->clear();
    for (auto reiseziel : agentur.getReiseziele()) {
        if(reiseziel.getName() == reiseziel_name) {
            for (string aktivitaet : reiseziel.getAktivitaeten()) {
                ui->listWidget_Aktivitaeten->addItem(QString::fromStdString(aktivitaet));
            }
        }
    }
}

void MainWindow::on_pushButton_ReisezielHinzufuegen_clicked()
{
    QString name = QInputDialog::getText(this, "Reiseziel hinzufügen", "Stadt: ");
    if(name.isEmpty()) {return;}
    QString land = QInputDialog::getText(this, "Reiseziel hinzufügen", "Land: ");
    if(land.isEmpty()) {return;}

    int counter = QInputDialog::getInt(this, "Reiseziel hinzufügen", "Wie viele Aktivitäten?");
    if(!counter) {return;}

    vector<string>aktivitaeten;

    for (int i = 0; i < counter; i++) {
        QString aktivitaet = QInputDialog::getText(this, "Reiseziel hinzufügen", "Aktivität:");
        aktivitaeten.push_back(aktivitaet.toStdString());
    }

    Reiseziel neuerZiel(name.toStdString(), land.toStdString(), aktivitaeten);
    agentur.getReiseziele().push_back(neuerZiel);

    QMessageBox::information(this, "Reiseziel hinzufügen", "Reiseziel erfolgreich hinzugefügt!");

    reisezieleListeausfuellen();
}


void MainWindow::on_pushButton_ReisezielLoeschen_clicked()
{
    if(!ui->listWidget_Reiseziele->currentItem()) {
        QMessageBox::critical(this, "Kein Reisziel ausgewählt", "Bitte Reiseziel auswählen");
        return;
    }

    if (QMessageBox::question(this, "Reiseziel löschen", "Reiseziel wirklich löschen?") != QMessageBox::Yes)
        return;

    QString currentItem = ui->listWidget_Reiseziele->currentItem()->text();
    string name = currentItem.section('(', 0, 0).trimmed().toStdString();

    if(agentur.reisezielLoeschen(name)){
        QMessageBox::information(this, "Reiseziel löschen", "Reiseziel erfolgreich gelöscht!");
        reisezieleListeausfuellen();;
    } else {
        QMessageBox::critical(this, "Reiseziel löschen", "Reiseziel konnte nicht gelöscht werden!");
    }
}


void MainWindow::on_pushButton_DatenLaden_clicked()
{
    if (QMessageBox::question(this, "Daten laden", "Möchten Sie die Daten aus der Datei \"reiseziele.json\" laden?") != QMessageBox::Yes) {return;}

    agentur.laden("reiseziele.json");
    reisezieleListeausfuellen();
    QMessageBox::information(this, "Daten laden", "Daten erfolgreich geladen!");
}


void MainWindow::on_pushButton_DatenSpeichern_clicked()
{
    if (QMessageBox::question(this, "Daten speichern", "Möchten Sie die Daten in der Datei \"reiseziele.json\" speichern?") != QMessageBox::Yes) {return;}

    agentur.speichern("reiseziele.json");
    QMessageBox::information(this, "Bestätigung", "Daten erfolgreich gespeichert!");
}


void MainWindow::on_listWidget_Reiseziele_itemDoubleClicked(QListWidgetItem *item)
{
    string reiseziel_name = item->text().section('(', 0, 0).trimmed().toStdString();
    showAktivitaeten(reiseziel_name);
}


void MainWindow::on_pushButton_AktivitaetHinzufuegen_clicked()
{
    QListWidgetItem* reiseziel_Item = ui->listWidget_Reiseziele->currentItem();

    if(!reiseziel_Item) {
        QMessageBox::critical(this, "Kein Reiszielausgewählt", "Bitte Reiseziel auswählen");
        return;
    }

    QString zeile = ui->listWidget_Reiseziele->currentItem()->text();
    string reiseziel_name = zeile.section('(', 0, 0).trimmed().toStdString();

    string aktivitaet_name = QInputDialog::getText(this, "Aktivität hinzufügen", "Aktivität:").toStdString();
    if(aktivitaet_name.empty()) {return;}

    if(agentur.aktivitaetHinzufuegen(reiseziel_name, aktivitaet_name)) {
        showAktivitaeten(reiseziel_name);
        QMessageBox::information(this, "Aktivität hinzufügen", "Aktivität erfolgreich hinzugefügt");
    } else {
        QMessageBox::critical(this, "Aktivität hinzufügen", "Aktivität konnte nicht hinzugefügt werden!");
    }
}


void MainWindow::on_pushButton_AktivitaetLoeschen_clicked()
{
    QListWidgetItem* reiseziel_item = ui->listWidget_Reiseziele->currentItem();
    QListWidgetItem* aktivitaet_item = ui->listWidget_Aktivitaeten->currentItem();

    if(!reiseziel_item || !aktivitaet_item) {
        QMessageBox::critical(this, "Kein Reisziel/Aktivität ausgewählt", "Bitte Reiseziel/Aktivität auswählen");
        return;
    }

    string reiseziel_name = reiseziel_item->text().section('(', 0, 0).trimmed().toStdString();
    string aktivitaet_name = aktivitaet_item->text().section('(', 0, 0).trimmed().toStdString();

    if(QMessageBox::question(this, "Aktivität löschen", "Aktivität wirklich löschen?") != QMessageBox::Yes) {return;}

    if(agentur.aktivitaetLoeschen(reiseziel_name, aktivitaet_name)) {
        showAktivitaeten(reiseziel_name);
        QMessageBox::information(this, "Aktivität löschen", "Aktivität erfolgreich gelöscht");
    } else {
        QMessageBox::critical(this, "Aktivität löschen", "Aktivität konnte nicht gelöscht werden!");
    }
}

