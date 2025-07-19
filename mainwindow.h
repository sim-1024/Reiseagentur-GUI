#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "agentur.h"
#include "reiseziel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reisezieleListeausfuellen();
    void showAktivitaeten(string reiseziel_name);

private slots:
    void on_pushButton_ReisezielHinzufuegen_clicked();

    void on_pushButton_ReisezielLoeschen_clicked();

    void on_pushButton_DatenLaden_clicked();

    void on_pushButton_DatenSpeichern_clicked();

    void on_listWidget_Reiseziele_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_AktivitaetHinzufuegen_clicked();

    void on_pushButton_AktivitaetLoeschen_clicked();

private:
    Ui::MainWindow *ui;
    Agentur agentur;
};
#endif // MAINWINDOW_H
