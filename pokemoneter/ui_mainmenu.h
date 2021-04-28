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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QLineEdit *title_1;
    QPushButton *play_button;
    QLineEdit *title_2;
    QLineEdit *title_3;
    QLabel *background_image;
    QLabel *running_pokemon_image;
    QLabel *running_trainer_image;
    QLabel *subtitle_image;
    QPushButton *quit_button;

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
        MainMenu->setStyleSheet(QString::fromUtf8("QWidget#MainMenu\n"
"{\n"
"    background: url(background.png);\n"
"}"));
        title_1 = new QLineEdit(MainMenu);
        title_1->setObjectName(QString::fromUtf8("title_1"));
        title_1->setGeometry(QRect(20, 35, 441, 81));
        sizePolicy.setHeightForWidth(title_1->sizePolicy().hasHeightForWidth());
        title_1->setSizePolicy(sizePolicy);
        title_1->setMinimumSize(QSize(441, 81));
        title_1->setMaximumSize(QSize(441, 81));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(59, 89, 157, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush2(QColor(255, 203, 4, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        title_1->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Pokemon Hollow"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        title_1->setFont(font);
        title_1->setFocusPolicy(Qt::NoFocus);
        title_1->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background: transparent"));
        title_1->setAlignment(Qt::AlignCenter);
        title_1->setReadOnly(true);
        play_button = new QPushButton(MainMenu);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        play_button->setGeometry(QRect(170, 160, 141, 35));
        sizePolicy.setHeightForWidth(play_button->sizePolicy().hasHeightForWidth());
        play_button->setSizePolicy(sizePolicy);
        play_button->setMinimumSize(QSize(141, 35));
        play_button->setMaximumSize(QSize(141, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        font1.setPointSize(14);
        play_button->setFont(font1);
        play_button->setLayoutDirection(Qt::LeftToRight);
        play_button->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/button_background.png) 0 0 0 0 stretch stretch;"));
        play_button->setFlat(false);
        title_2 = new QLineEdit(MainMenu);
        title_2->setObjectName(QString::fromUtf8("title_2"));
        title_2->setGeometry(QRect(19, 36, 441, 81));
        sizePolicy.setHeightForWidth(title_2->sizePolicy().hasHeightForWidth());
        title_2->setSizePolicy(sizePolicy);
        title_2->setMinimumSize(QSize(441, 81));
        title_2->setMaximumSize(QSize(441, 81));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush5(QColor(35, 55, 95, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        title_2->setPalette(palette1);
        title_2->setFont(font);
        title_2->setFocusPolicy(Qt::NoFocus);
        title_2->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background: transparent"));
        title_2->setAlignment(Qt::AlignCenter);
        title_2->setReadOnly(true);
        title_3 = new QLineEdit(MainMenu);
        title_3->setObjectName(QString::fromUtf8("title_3"));
        title_3->setGeometry(QRect(19, 35, 441, 81));
        sizePolicy.setHeightForWidth(title_3->sizePolicy().hasHeightForWidth());
        title_3->setSizePolicy(sizePolicy);
        title_3->setMinimumSize(QSize(441, 81));
        title_3->setMaximumSize(QSize(441, 81));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush6(QColor(255, 204, 1, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        title_3->setPalette(palette2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Pokemon Solid"));
        font2.setPointSize(36);
        font2.setBold(true);
        font2.setWeight(75);
        title_3->setFont(font2);
        title_3->setFocusPolicy(Qt::NoFocus);
        title_3->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background: transparent"));
        title_3->setAlignment(Qt::AlignCenter);
        title_3->setReadOnly(true);
        background_image = new QLabel(MainMenu);
        background_image->setObjectName(QString::fromUtf8("background_image"));
        background_image->setGeometry(QRect(0, 0, 481, 281));
        background_image->setPixmap(QPixmap(QString::fromUtf8("images/background.png")));
        background_image->setScaledContents(true);
        running_pokemon_image = new QLabel(MainMenu);
        running_pokemon_image->setObjectName(QString::fromUtf8("running_pokemon_image"));
        running_pokemon_image->setGeometry(QRect(20, 170, 101, 71));
        running_pokemon_image->setPixmap(QPixmap(QString::fromUtf8("pikachu_running.gif")));
        running_pokemon_image->setScaledContents(true);
        running_trainer_image = new QLabel(MainMenu);
        running_trainer_image->setObjectName(QString::fromUtf8("running_trainer_image"));
        running_trainer_image->setGeometry(QRect(346, 101, 131, 141));
        running_trainer_image->setScaledContents(true);
        subtitle_image = new QLabel(MainMenu);
        subtitle_image->setObjectName(QString::fromUtf8("subtitle_image"));
        subtitle_image->setGeometry(QRect(110, 121, 251, 31));
        subtitle_image->setPixmap(QPixmap(QString::fromUtf8("images/main_menu_subtext.png")));
        subtitle_image->setScaledContents(true);
        quit_button = new QPushButton(MainMenu);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        quit_button->setGeometry(QRect(170, 200, 141, 35));
        sizePolicy.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy);
        quit_button->setMinimumSize(QSize(141, 35));
        quit_button->setMaximumSize(QSize(141, 35));
        quit_button->setFont(font1);
        quit_button->setLayoutDirection(Qt::LeftToRight);
        quit_button->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/button_background.png) 0 0 0 0 stretch stretch;"));
        quit_button->setFlat(false);
        background_image->raise();
        title_3->raise();
        play_button->raise();
        title_2->raise();
        title_1->raise();
        running_pokemon_image->raise();
        running_trainer_image->raise();
        subtitle_image->raise();
        quit_button->raise();

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Pokemoneter Main Menu", nullptr));
        title_1->setText(QCoreApplication::translate("MainMenu", "PoK\303\251MoNeTeR", nullptr));
        play_button->setText(QCoreApplication::translate("MainMenu", "PLAY", nullptr));
        title_2->setText(QCoreApplication::translate("MainMenu", "PoK\303\251MoNeTeR", nullptr));
        title_3->setText(QCoreApplication::translate("MainMenu", "PoK\303\251MoNeTeR", nullptr));
        background_image->setText(QString());
        running_pokemon_image->setText(QString());
        running_trainer_image->setText(QString());
        subtitle_image->setText(QString());
        quit_button->setText(QCoreApplication::translate("MainMenu", "QUIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
