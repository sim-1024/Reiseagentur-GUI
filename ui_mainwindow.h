/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_Reiseziele;
    QListWidget *listWidget_Reiseziele;
    QLabel *label_Aktivitaeten;
    QListWidget *listWidget_Aktivitaeten;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_DatenLaden;
    QPushButton *pushButton_DatenSpeichern;
    QPushButton *pushButton_ReisezielHinzufuegen;
    QPushButton *pushButton_AktivitaetHinzufuegen;
    QPushButton *pushButton_ReisezielLoeschen;
    QPushButton *pushButton_AktivitaetLoeschen;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(527, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_Reiseziele = new QLabel(centralwidget);
        label_Reiseziele->setObjectName("label_Reiseziele");

        verticalLayout->addWidget(label_Reiseziele);

        listWidget_Reiseziele = new QListWidget(centralwidget);
        listWidget_Reiseziele->setObjectName("listWidget_Reiseziele");

        verticalLayout->addWidget(listWidget_Reiseziele);

        label_Aktivitaeten = new QLabel(centralwidget);
        label_Aktivitaeten->setObjectName("label_Aktivitaeten");

        verticalLayout->addWidget(label_Aktivitaeten);

        listWidget_Aktivitaeten = new QListWidget(centralwidget);
        listWidget_Aktivitaeten->setObjectName("listWidget_Aktivitaeten");

        verticalLayout->addWidget(listWidget_Aktivitaeten);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_DatenLaden = new QPushButton(centralwidget);
        pushButton_DatenLaden->setObjectName("pushButton_DatenLaden");

        horizontalLayout->addWidget(pushButton_DatenLaden);

        pushButton_DatenSpeichern = new QPushButton(centralwidget);
        pushButton_DatenSpeichern->setObjectName("pushButton_DatenSpeichern");

        horizontalLayout->addWidget(pushButton_DatenSpeichern);

        pushButton_ReisezielHinzufuegen = new QPushButton(centralwidget);
        pushButton_ReisezielHinzufuegen->setObjectName("pushButton_ReisezielHinzufuegen");

        horizontalLayout->addWidget(pushButton_ReisezielHinzufuegen);

        pushButton_AktivitaetHinzufuegen = new QPushButton(centralwidget);
        pushButton_AktivitaetHinzufuegen->setObjectName("pushButton_AktivitaetHinzufuegen");

        horizontalLayout->addWidget(pushButton_AktivitaetHinzufuegen);

        pushButton_ReisezielLoeschen = new QPushButton(centralwidget);
        pushButton_ReisezielLoeschen->setObjectName("pushButton_ReisezielLoeschen");

        horizontalLayout->addWidget(pushButton_ReisezielLoeschen);

        pushButton_AktivitaetLoeschen = new QPushButton(centralwidget);
        pushButton_AktivitaetLoeschen->setObjectName("pushButton_AktivitaetLoeschen");

        horizontalLayout->addWidget(pushButton_AktivitaetLoeschen);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 527, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Reiseziele->setText(QCoreApplication::translate("MainWindow", "Reiseziele", nullptr));
        label_Aktivitaeten->setText(QCoreApplication::translate("MainWindow", "Aktivit\303\244ten", nullptr));
        pushButton_DatenLaden->setText(QCoreApplication::translate("MainWindow", "Daten laden", nullptr));
        pushButton_DatenSpeichern->setText(QCoreApplication::translate("MainWindow", "Daten speichern", nullptr));
        pushButton_ReisezielHinzufuegen->setText(QCoreApplication::translate("MainWindow", "Reiseziel hinzuf\303\274gen", nullptr));
        pushButton_AktivitaetHinzufuegen->setText(QCoreApplication::translate("MainWindow", "Aktivit\303\244t hinzuf\303\274gen", nullptr));
        pushButton_ReisezielLoeschen->setText(QCoreApplication::translate("MainWindow", "Resieziel l\303\266schen", nullptr));
        pushButton_AktivitaetLoeschen->setText(QCoreApplication::translate("MainWindow", "Aktivit\303\244t l\303\266schen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
