/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *play_button;
    QLabel *background_image;
    QLabel *running_pokemon_image;
    QLabel *running_trainer_image;
    QLabel *subtitle_image;
    QPushButton *quit_button;
    QLabel *title;
    QPushButton *reset_button;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(480, 272);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        MainMenu->setMinimumSize(QSize(480, 0));
        MainMenu->setAutoFillBackground(true);
        MainMenu->setStyleSheet(QString::fromUtf8(""));
        play_button = new QPushButton(MainMenu);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        play_button->setGeometry(QRect(170, 140, 141, 35));
        sizePolicy.setHeightForWidth(play_button->sizePolicy().hasHeightForWidth());
        play_button->setSizePolicy(sizePolicy);
        play_button->setMinimumSize(QSize(141, 35));
        play_button->setMaximumSize(QSize(141, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        font.setPointSize(14);
        play_button->setFont(font);
        play_button->setLayoutDirection(Qt::LeftToRight);
        play_button->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        play_button->setFlat(false);
        background_image = new QLabel(MainMenu);
        background_image->setObjectName(QString::fromUtf8("background_image"));
        background_image->setGeometry(QRect(0, 0, 481, 281));
        background_image->setPixmap(QPixmap(QString::fromUtf8("images/backgrounds/background.png")));
        background_image->setScaledContents(true);
        running_pokemon_image = new QLabel(MainMenu);
        running_pokemon_image->setObjectName(QString::fromUtf8("running_pokemon_image"));
        running_pokemon_image->setGeometry(QRect(20, 170, 101, 71));
        running_pokemon_image->setPixmap(QPixmap(QString::fromUtf8("pikachu_running.gif")));
        running_pokemon_image->setScaledContents(true);
        running_trainer_image = new QLabel(MainMenu);
        running_trainer_image->setObjectName(QString::fromUtf8("running_trainer_image"));
        running_trainer_image->setGeometry(QRect(326, 101, 151, 141));
        running_trainer_image->setScaledContents(true);
        subtitle_image = new QLabel(MainMenu);
        subtitle_image->setObjectName(QString::fromUtf8("subtitle_image"));
        subtitle_image->setGeometry(QRect(110, 101, 251, 31));
        subtitle_image->setPixmap(QPixmap(QString::fromUtf8("images/text/main_menu_subtext.png")));
        subtitle_image->setScaledContents(true);
        quit_button = new QPushButton(MainMenu);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        quit_button->setGeometry(QRect(170, 220, 141, 35));
        sizePolicy.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy);
        quit_button->setMinimumSize(QSize(141, 35));
        quit_button->setMaximumSize(QSize(141, 35));
        quit_button->setFont(font);
        quit_button->setLayoutDirection(Qt::LeftToRight);
        quit_button->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        quit_button->setFlat(false);
        title = new QLabel(MainMenu);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(80, 40, 311, 61));
        title->setPixmap(QPixmap(QString::fromUtf8("images/text/title.png")));
        title->setScaledContents(true);
        reset_button = new QPushButton(MainMenu);
        reset_button->setObjectName(QString::fromUtf8("reset_button"));
        reset_button->setGeometry(QRect(170, 180, 141, 35));
        sizePolicy.setHeightForWidth(reset_button->sizePolicy().hasHeightForWidth());
        reset_button->setSizePolicy(sizePolicy);
        reset_button->setMinimumSize(QSize(141, 35));
        reset_button->setMaximumSize(QSize(141, 41));
        reset_button->setFont(font);
        reset_button->setLayoutDirection(Qt::LeftToRight);
        reset_button->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        reset_button->setFlat(false);
        background_image->raise();
        play_button->raise();
        running_pokemon_image->raise();
        running_trainer_image->raise();
        subtitle_image->raise();
        quit_button->raise();
        title->raise();
        reset_button->raise();

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Pokemoneter Main Menu", nullptr));
        play_button->setText(QCoreApplication::translate("MainMenu", "PLAY", nullptr));
        background_image->setText(QString());
        running_pokemon_image->setText(QString());
        running_trainer_image->setText(QString());
        subtitle_image->setText(QString());
        quit_button->setText(QCoreApplication::translate("MainMenu", "QUIT", nullptr));
        title->setText(QString());
        reset_button->setText(QCoreApplication::translate("MainMenu", "RESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
