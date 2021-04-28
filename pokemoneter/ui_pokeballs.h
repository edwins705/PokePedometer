/********************************************************************************
** Form generated from reading UI file 'pokeballs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKEBALLS_H
#define UI_POKEBALLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pokeballs
{
public:
    QLabel *background_image;
    QPushButton *back_button;
    QPushButton *select_button;
    QPushButton *release_button;
    QRadioButton *pokemon_button_4;
    QLabel *pokemon_unchecked_2;
    QLabel *pokemon_unchecked_4;
    QRadioButton *pokemon_button_1;
    QLabel *pokemon_checked_2;
    QLabel *pokemon_checked_4;
    QRadioButton *pokemon_button_6;
    QLabel *pokemon_checked_3;
    QRadioButton *pokemon_button_2;
    QRadioButton *pokemon_button_3;
    QLabel *pokemon_checked_6;
    QLabel *pokemon_checked_5;
    QRadioButton *pokemon_button_5;
    QLabel *pokemon_unchecked_3;
    QLabel *pokemon_checked_1;
    QLabel *pokemon_unchecked_5;
    QLabel *pokemon_unchecked_6;
    QLabel *pokemon_unchecked_1;
    QLabel *pokemon_icon_c_1;
    QLabel *pokemon_icon_c_2;
    QLabel *pokemon_icon_c_3;
    QLabel *pokemon_icon_c_4;
    QLabel *pokemon_icon_c_5;
    QLabel *pokemon_icon_u_6;
    QLabel *pokemon_icon_c_6;
    QLabel *pokemon_icon_u_1;
    QLabel *pokemon_icon_u_2;
    QLabel *pokemon_icon_u_3;
    QLabel *pokemon_icon_u_4;
    QLabel *pokemon_icon_u_5;
    QLineEdit *pokemon_name_1;
    QProgressBar *progressBar_1;
    QLineEdit *pokemon_name_2;
    QLineEdit *pokemon_name_3;
    QLineEdit *pokemon_name_4;
    QLineEdit *pokemon_name_5;
    QLineEdit *pokemon_name_6;
    QLabel *pokemon_icon_1;
    QLabel *pokemon_icon_2;
    QLabel *pokemon_icon_3;
    QLabel *pokemon_icon_4;
    QLabel *pokemon_icon_5;
    QLabel *pokemon_icon_6;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QProgressBar *progressBar_5;
    QProgressBar *progressBar_6;

    void setupUi(QWidget *pokeballs)
    {
        if (pokeballs->objectName().isEmpty())
            pokeballs->setObjectName(QString::fromUtf8("pokeballs"));
        pokeballs->resize(480, 272);
        background_image = new QLabel(pokeballs);
        background_image->setObjectName(QString::fromUtf8("background_image"));
        background_image->setGeometry(QRect(0, 0, 481, 281));
        background_image->setPixmap(QPixmap(QString::fromUtf8("images/backgrounds/background.png")));
        background_image->setScaledContents(true);
        back_button = new QPushButton(pokeballs);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(10, 240, 80, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        back_button->setFont(font);
        back_button->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        select_button = new QPushButton(pokeballs);
        select_button->setObjectName(QString::fromUtf8("select_button"));
        select_button->setGeometry(QRect(100, 240, 80, 22));
        select_button->setFont(font);
        select_button->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        release_button = new QPushButton(pokeballs);
        release_button->setObjectName(QString::fromUtf8("release_button"));
        release_button->setGeometry(QRect(190, 240, 80, 22));
        release_button->setFont(font);
        release_button->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_button_4 = new QRadioButton(pokeballs);
        pokemon_button_4->setObjectName(QString::fromUtf8("pokemon_button_4"));
        pokemon_button_4->setEnabled(true);
        pokemon_button_4->setGeometry(QRect(241, 85, 231, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pokemon_button_4->sizePolicy().hasHeightForWidth());
        pokemon_button_4->setSizePolicy(sizePolicy);
        pokemon_button_4->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}"));
        pokemon_button_4->setIconSize(QSize(32, 32));
        pokemon_unchecked_2 = new QLabel(pokeballs);
        pokemon_unchecked_2->setObjectName(QString::fromUtf8("pokemon_unchecked_2"));
        pokemon_unchecked_2->setGeometry(QRect(241, 10, 231, 71));
        pokemon_unchecked_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_2->setScaledContents(true);
        pokemon_unchecked_4 = new QLabel(pokeballs);
        pokemon_unchecked_4->setObjectName(QString::fromUtf8("pokemon_unchecked_4"));
        pokemon_unchecked_4->setGeometry(QRect(241, 85, 231, 71));
        pokemon_unchecked_4->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_4->setScaledContents(true);
        pokemon_button_1 = new QRadioButton(pokeballs);
        pokemon_button_1->setObjectName(QString::fromUtf8("pokemon_button_1"));
        pokemon_button_1->setEnabled(true);
        pokemon_button_1->setGeometry(QRect(5, 10, 231, 71));
        sizePolicy.setHeightForWidth(pokemon_button_1->sizePolicy().hasHeightForWidth());
        pokemon_button_1->setSizePolicy(sizePolicy);
        pokemon_button_1->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}"));
        pokemon_button_1->setIconSize(QSize(32, 32));
        pokemon_button_1->setChecked(true);
        pokemon_checked_2 = new QLabel(pokeballs);
        pokemon_checked_2->setObjectName(QString::fromUtf8("pokemon_checked_2"));
        pokemon_checked_2->setGeometry(QRect(241, 10, 231, 71));
        pokemon_checked_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_2->setScaledContents(true);
        pokemon_checked_4 = new QLabel(pokeballs);
        pokemon_checked_4->setObjectName(QString::fromUtf8("pokemon_checked_4"));
        pokemon_checked_4->setGeometry(QRect(241, 85, 231, 71));
        pokemon_checked_4->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_4->setScaledContents(true);
        pokemon_button_6 = new QRadioButton(pokeballs);
        pokemon_button_6->setObjectName(QString::fromUtf8("pokemon_button_6"));
        pokemon_button_6->setEnabled(true);
        pokemon_button_6->setGeometry(QRect(241, 160, 231, 71));
        sizePolicy.setHeightForWidth(pokemon_button_6->sizePolicy().hasHeightForWidth());
        pokemon_button_6->setSizePolicy(sizePolicy);
        pokemon_button_6->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}"));
        pokemon_button_6->setIconSize(QSize(32, 32));
        pokemon_checked_3 = new QLabel(pokeballs);
        pokemon_checked_3->setObjectName(QString::fromUtf8("pokemon_checked_3"));
        pokemon_checked_3->setGeometry(QRect(5, 85, 231, 71));
        pokemon_checked_3->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_3->setScaledContents(true);
        pokemon_button_2 = new QRadioButton(pokeballs);
        pokemon_button_2->setObjectName(QString::fromUtf8("pokemon_button_2"));
        pokemon_button_2->setEnabled(true);
        pokemon_button_2->setGeometry(QRect(241, 10, 231, 71));
        sizePolicy.setHeightForWidth(pokemon_button_2->sizePolicy().hasHeightForWidth());
        pokemon_button_2->setSizePolicy(sizePolicy);
        pokemon_button_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}"));
        pokemon_button_2->setIconSize(QSize(32, 32));
        pokemon_button_3 = new QRadioButton(pokeballs);
        pokemon_button_3->setObjectName(QString::fromUtf8("pokemon_button_3"));
        pokemon_button_3->setEnabled(true);
        pokemon_button_3->setGeometry(QRect(5, 85, 231, 71));
        sizePolicy.setHeightForWidth(pokemon_button_3->sizePolicy().hasHeightForWidth());
        pokemon_button_3->setSizePolicy(sizePolicy);
        pokemon_button_3->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}"));
        pokemon_button_3->setIconSize(QSize(32, 32));
        pokemon_checked_6 = new QLabel(pokeballs);
        pokemon_checked_6->setObjectName(QString::fromUtf8("pokemon_checked_6"));
        pokemon_checked_6->setGeometry(QRect(241, 160, 231, 71));
        pokemon_checked_6->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_6->setScaledContents(true);
        pokemon_checked_5 = new QLabel(pokeballs);
        pokemon_checked_5->setObjectName(QString::fromUtf8("pokemon_checked_5"));
        pokemon_checked_5->setGeometry(QRect(5, 160, 231, 71));
        pokemon_checked_5->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_5->setScaledContents(true);
        pokemon_button_5 = new QRadioButton(pokeballs);
        pokemon_button_5->setObjectName(QString::fromUtf8("pokemon_button_5"));
        pokemon_button_5->setEnabled(true);
        pokemon_button_5->setGeometry(QRect(5, 160, 231, 71));
        sizePolicy.setHeightForWidth(pokemon_button_5->sizePolicy().hasHeightForWidth());
        pokemon_button_5->setSizePolicy(sizePolicy);
        pokemon_button_5->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{ \n"
"width: 0px;\n"
"height: 0px;\n"
"border-radius: 0px;\n"
"}"));
        pokemon_button_5->setIconSize(QSize(32, 32));
        pokemon_unchecked_3 = new QLabel(pokeballs);
        pokemon_unchecked_3->setObjectName(QString::fromUtf8("pokemon_unchecked_3"));
        pokemon_unchecked_3->setGeometry(QRect(5, 85, 231, 71));
        pokemon_unchecked_3->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_3->setScaledContents(true);
        pokemon_checked_1 = new QLabel(pokeballs);
        pokemon_checked_1->setObjectName(QString::fromUtf8("pokemon_checked_1"));
        pokemon_checked_1->setGeometry(QRect(5, 10, 231, 71));
        pokemon_checked_1->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_1->setScaledContents(true);
        pokemon_unchecked_5 = new QLabel(pokeballs);
        pokemon_unchecked_5->setObjectName(QString::fromUtf8("pokemon_unchecked_5"));
        pokemon_unchecked_5->setGeometry(QRect(5, 160, 231, 71));
        pokemon_unchecked_5->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_5->setScaledContents(true);
        pokemon_unchecked_6 = new QLabel(pokeballs);
        pokemon_unchecked_6->setObjectName(QString::fromUtf8("pokemon_unchecked_6"));
        pokemon_unchecked_6->setGeometry(QRect(241, 160, 231, 71));
        pokemon_unchecked_6->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_6->setScaledContents(true);
        pokemon_unchecked_1 = new QLabel(pokeballs);
        pokemon_unchecked_1->setObjectName(QString::fromUtf8("pokemon_unchecked_1"));
        pokemon_unchecked_1->setGeometry(QRect(5, 10, 231, 71));
        pokemon_unchecked_1->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_1->setScaledContents(true);
        pokemon_icon_c_1 = new QLabel(pokeballs);
        pokemon_icon_c_1->setObjectName(QString::fromUtf8("pokemon_icon_c_1"));
        pokemon_icon_c_1->setGeometry(QRect(8, 13, 65, 65));
        pokemon_icon_c_1->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(182, 182, 216);"));
        pokemon_icon_c_1->setScaledContents(true);
        pokemon_icon_c_2 = new QLabel(pokeballs);
        pokemon_icon_c_2->setObjectName(QString::fromUtf8("pokemon_icon_c_2"));
        pokemon_icon_c_2->setGeometry(QRect(244, 13, 65, 65));
        pokemon_icon_c_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(182, 182, 216);"));
        pokemon_icon_c_2->setScaledContents(true);
        pokemon_icon_c_3 = new QLabel(pokeballs);
        pokemon_icon_c_3->setObjectName(QString::fromUtf8("pokemon_icon_c_3"));
        pokemon_icon_c_3->setGeometry(QRect(8, 88, 65, 65));
        pokemon_icon_c_3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(182, 182, 216);"));
        pokemon_icon_c_3->setScaledContents(true);
        pokemon_icon_c_4 = new QLabel(pokeballs);
        pokemon_icon_c_4->setObjectName(QString::fromUtf8("pokemon_icon_c_4"));
        pokemon_icon_c_4->setGeometry(QRect(244, 88, 65, 65));
        pokemon_icon_c_4->setStyleSheet(QString::fromUtf8("border: 5px;\n"
"border-radius: 10px;\n"
"background-color: rgb(182, 182, 216);"));
        pokemon_icon_c_4->setScaledContents(true);
        pokemon_icon_c_5 = new QLabel(pokeballs);
        pokemon_icon_c_5->setObjectName(QString::fromUtf8("pokemon_icon_c_5"));
        pokemon_icon_c_5->setGeometry(QRect(8, 163, 65, 65));
        pokemon_icon_c_5->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(182, 182, 216);"));
        pokemon_icon_c_5->setScaledContents(true);
        pokemon_icon_u_6 = new QLabel(pokeballs);
        pokemon_icon_u_6->setObjectName(QString::fromUtf8("pokemon_icon_u_6"));
        pokemon_icon_u_6->setGeometry(QRect(244, 163, 65, 65));
        pokemon_icon_u_6->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(146, 146, 173);"));
        pokemon_icon_u_6->setScaledContents(true);
        pokemon_icon_c_6 = new QLabel(pokeballs);
        pokemon_icon_c_6->setObjectName(QString::fromUtf8("pokemon_icon_c_6"));
        pokemon_icon_c_6->setGeometry(QRect(244, 163, 65, 65));
        pokemon_icon_c_6->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(182, 182, 216);"));
        pokemon_icon_c_6->setScaledContents(true);
        pokemon_icon_u_1 = new QLabel(pokeballs);
        pokemon_icon_u_1->setObjectName(QString::fromUtf8("pokemon_icon_u_1"));
        pokemon_icon_u_1->setGeometry(QRect(8, 13, 65, 65));
        pokemon_icon_u_1->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(146, 146, 173);"));
        pokemon_icon_u_1->setScaledContents(true);
        pokemon_icon_u_2 = new QLabel(pokeballs);
        pokemon_icon_u_2->setObjectName(QString::fromUtf8("pokemon_icon_u_2"));
        pokemon_icon_u_2->setGeometry(QRect(244, 13, 65, 65));
        pokemon_icon_u_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(146, 146, 173);"));
        pokemon_icon_u_2->setScaledContents(true);
        pokemon_icon_u_3 = new QLabel(pokeballs);
        pokemon_icon_u_3->setObjectName(QString::fromUtf8("pokemon_icon_u_3"));
        pokemon_icon_u_3->setGeometry(QRect(8, 88, 65, 65));
        pokemon_icon_u_3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(146, 146, 173);"));
        pokemon_icon_u_3->setScaledContents(true);
        pokemon_icon_u_4 = new QLabel(pokeballs);
        pokemon_icon_u_4->setObjectName(QString::fromUtf8("pokemon_icon_u_4"));
        pokemon_icon_u_4->setGeometry(QRect(244, 88, 65, 65));
        pokemon_icon_u_4->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(146, 146, 173);"));
        pokemon_icon_u_4->setScaledContents(true);
        pokemon_icon_u_5 = new QLabel(pokeballs);
        pokemon_icon_u_5->setObjectName(QString::fromUtf8("pokemon_icon_u_5"));
        pokemon_icon_u_5->setGeometry(QRect(8, 163, 65, 65));
        pokemon_icon_u_5->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: rgb(146, 146, 173);"));
        pokemon_icon_u_5->setScaledContents(true);
        pokemon_name_1 = new QLineEdit(pokeballs);
        pokemon_name_1->setObjectName(QString::fromUtf8("pokemon_name_1"));
        pokemon_name_1->setGeometry(QRect(78, 20, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        pokemon_name_1->setFont(font1);
        pokemon_name_1->setFocusPolicy(Qt::NoFocus);
        pokemon_name_1->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;\n"
"color: rgb(75, 75, 75);"));
        pokemon_name_1->setReadOnly(true);
        progressBar_1 = new QProgressBar(pokeballs);
        progressBar_1->setObjectName(QString::fromUtf8("progressBar_1"));
        progressBar_1->setGeometry(QRect(78, 61, 151, 16));
        progressBar_1->setValue(24);
        progressBar_1->setInvertedAppearance(false);
        pokemon_name_2 = new QLineEdit(pokeballs);
        pokemon_name_2->setObjectName(QString::fromUtf8("pokemon_name_2"));
        pokemon_name_2->setGeometry(QRect(314, 20, 151, 31));
        pokemon_name_2->setFont(font1);
        pokemon_name_2->setFocusPolicy(Qt::NoFocus);
        pokemon_name_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;\n"
"color: rgb(75, 75, 75);"));
        pokemon_name_2->setReadOnly(true);
        pokemon_name_3 = new QLineEdit(pokeballs);
        pokemon_name_3->setObjectName(QString::fromUtf8("pokemon_name_3"));
        pokemon_name_3->setGeometry(QRect(78, 95, 151, 31));
        pokemon_name_3->setFont(font1);
        pokemon_name_3->setFocusPolicy(Qt::NoFocus);
        pokemon_name_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;\n"
"color: rgb(75, 75, 75);"));
        pokemon_name_3->setReadOnly(true);
        pokemon_name_4 = new QLineEdit(pokeballs);
        pokemon_name_4->setObjectName(QString::fromUtf8("pokemon_name_4"));
        pokemon_name_4->setGeometry(QRect(314, 95, 151, 31));
        pokemon_name_4->setFont(font1);
        pokemon_name_4->setFocusPolicy(Qt::NoFocus);
        pokemon_name_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;\n"
"color: rgb(75, 75, 75);"));
        pokemon_name_4->setReadOnly(true);
        pokemon_name_5 = new QLineEdit(pokeballs);
        pokemon_name_5->setObjectName(QString::fromUtf8("pokemon_name_5"));
        pokemon_name_5->setGeometry(QRect(78, 170, 151, 31));
        pokemon_name_5->setFont(font1);
        pokemon_name_5->setFocusPolicy(Qt::NoFocus);
        pokemon_name_5->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;\n"
"color: rgb(75, 75, 75);"));
        pokemon_name_5->setReadOnly(true);
        pokemon_name_6 = new QLineEdit(pokeballs);
        pokemon_name_6->setObjectName(QString::fromUtf8("pokemon_name_6"));
        pokemon_name_6->setGeometry(QRect(314, 170, 151, 31));
        pokemon_name_6->setFont(font1);
        pokemon_name_6->setFocusPolicy(Qt::NoFocus);
        pokemon_name_6->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;\n"
"color: rgb(75, 75, 75);"));
        pokemon_name_6->setReadOnly(true);
        pokemon_icon_1 = new QLabel(pokeballs);
        pokemon_icon_1->setObjectName(QString::fromUtf8("pokemon_icon_1"));
        pokemon_icon_1->setGeometry(QRect(8, 13, 65, 65));
        pokemon_icon_1->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;"));
        pokemon_icon_1->setScaledContents(true);
        pokemon_icon_2 = new QLabel(pokeballs);
        pokemon_icon_2->setObjectName(QString::fromUtf8("pokemon_icon_2"));
        pokemon_icon_2->setGeometry(QRect(244, 13, 65, 65));
        pokemon_icon_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;"));
        pokemon_icon_2->setScaledContents(true);
        pokemon_icon_3 = new QLabel(pokeballs);
        pokemon_icon_3->setObjectName(QString::fromUtf8("pokemon_icon_3"));
        pokemon_icon_3->setGeometry(QRect(8, 88, 65, 65));
        pokemon_icon_3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;"));
        pokemon_icon_3->setScaledContents(true);
        pokemon_icon_4 = new QLabel(pokeballs);
        pokemon_icon_4->setObjectName(QString::fromUtf8("pokemon_icon_4"));
        pokemon_icon_4->setGeometry(QRect(244, 88, 65, 65));
        pokemon_icon_4->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;"));
        pokemon_icon_4->setScaledContents(true);
        pokemon_icon_5 = new QLabel(pokeballs);
        pokemon_icon_5->setObjectName(QString::fromUtf8("pokemon_icon_5"));
        pokemon_icon_5->setGeometry(QRect(8, 163, 65, 65));
        pokemon_icon_5->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;"));
        pokemon_icon_5->setScaledContents(true);
        pokemon_icon_6 = new QLabel(pokeballs);
        pokemon_icon_6->setObjectName(QString::fromUtf8("pokemon_icon_6"));
        pokemon_icon_6->setGeometry(QRect(244, 163, 65, 65));
        pokemon_icon_6->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;"));
        pokemon_icon_6->setScaledContents(true);
        progressBar_2 = new QProgressBar(pokeballs);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(314, 61, 151, 16));
        progressBar_2->setValue(24);
        progressBar_2->setInvertedAppearance(false);
        progressBar_3 = new QProgressBar(pokeballs);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(78, 136, 151, 16));
        progressBar_3->setValue(24);
        progressBar_3->setInvertedAppearance(false);
        progressBar_4 = new QProgressBar(pokeballs);
        progressBar_4->setObjectName(QString::fromUtf8("progressBar_4"));
        progressBar_4->setGeometry(QRect(314, 136, 151, 16));
        progressBar_4->setValue(24);
        progressBar_4->setInvertedAppearance(false);
        progressBar_5 = new QProgressBar(pokeballs);
        progressBar_5->setObjectName(QString::fromUtf8("progressBar_5"));
        progressBar_5->setGeometry(QRect(78, 211, 151, 16));
        progressBar_5->setValue(24);
        progressBar_5->setInvertedAppearance(false);
        progressBar_6 = new QProgressBar(pokeballs);
        progressBar_6->setObjectName(QString::fromUtf8("progressBar_6"));
        progressBar_6->setGeometry(QRect(314, 211, 151, 16));
        progressBar_6->setValue(24);
        progressBar_6->setInvertedAppearance(false);
        background_image->raise();
        pokemon_checked_6->raise();
        pokemon_unchecked_6->raise();
        pokemon_unchecked_5->raise();
        pokemon_checked_1->raise();
        pokemon_unchecked_1->raise();
        pokemon_unchecked_3->raise();
        pokemon_unchecked_4->raise();
        pokemon_checked_4->raise();
        back_button->raise();
        select_button->raise();
        release_button->raise();
        pokemon_unchecked_2->raise();
        pokemon_checked_2->raise();
        pokemon_checked_3->raise();
        pokemon_checked_5->raise();
        pokemon_icon_c_1->raise();
        pokemon_icon_c_2->raise();
        pokemon_icon_c_3->raise();
        pokemon_icon_c_4->raise();
        pokemon_icon_c_5->raise();
        pokemon_icon_u_6->raise();
        pokemon_icon_c_6->raise();
        pokemon_icon_u_1->raise();
        pokemon_icon_u_2->raise();
        pokemon_icon_u_3->raise();
        pokemon_icon_u_4->raise();
        pokemon_icon_u_5->raise();
        pokemon_name_1->raise();
        progressBar_1->raise();
        pokemon_name_2->raise();
        pokemon_name_3->raise();
        pokemon_name_4->raise();
        pokemon_name_5->raise();
        pokemon_name_6->raise();
        pokemon_icon_1->raise();
        pokemon_icon_2->raise();
        pokemon_icon_3->raise();
        pokemon_icon_4->raise();
        pokemon_icon_5->raise();
        pokemon_icon_6->raise();
        progressBar_2->raise();
        progressBar_3->raise();
        progressBar_4->raise();
        progressBar_5->raise();
        progressBar_6->raise();
        pokemon_button_1->raise();
        pokemon_button_2->raise();
        pokemon_button_3->raise();
        pokemon_button_4->raise();
        pokemon_button_5->raise();
        pokemon_button_6->raise();

        retranslateUi(pokeballs);

        QMetaObject::connectSlotsByName(pokeballs);
    } // setupUi

    void retranslateUi(QWidget *pokeballs)
    {
        pokeballs->setWindowTitle(QCoreApplication::translate("pokeballs", "Pokeballs", nullptr));
        background_image->setText(QString());
        back_button->setText(QCoreApplication::translate("pokeballs", "BACK", nullptr));
        select_button->setText(QCoreApplication::translate("pokeballs", "SELECT", nullptr));
        release_button->setText(QCoreApplication::translate("pokeballs", "RELEASE", nullptr));
        pokemon_button_4->setText(QString());
        pokemon_unchecked_2->setText(QString());
        pokemon_unchecked_4->setText(QString());
        pokemon_button_1->setText(QString());
        pokemon_checked_2->setText(QString());
        pokemon_checked_4->setText(QString());
        pokemon_button_6->setText(QString());
        pokemon_checked_3->setText(QString());
        pokemon_button_2->setText(QString());
        pokemon_button_3->setText(QString());
        pokemon_checked_6->setText(QString());
        pokemon_checked_5->setText(QString());
        pokemon_button_5->setText(QString());
        pokemon_unchecked_3->setText(QString());
        pokemon_checked_1->setText(QString());
        pokemon_unchecked_5->setText(QString());
        pokemon_unchecked_6->setText(QString());
        pokemon_unchecked_1->setText(QString());
        pokemon_icon_c_1->setText(QString());
        pokemon_icon_c_2->setText(QString());
        pokemon_icon_c_3->setText(QString());
        pokemon_icon_c_4->setText(QString());
        pokemon_icon_c_5->setText(QString());
        pokemon_icon_u_6->setText(QString());
        pokemon_icon_c_6->setText(QString());
        pokemon_icon_u_1->setText(QString());
        pokemon_icon_u_2->setText(QString());
        pokemon_icon_u_3->setText(QString());
        pokemon_icon_u_4->setText(QString());
        pokemon_icon_u_5->setText(QString());
        pokemon_name_1->setText(QString());
        pokemon_name_2->setText(QString());
        pokemon_name_3->setText(QString());
        pokemon_name_4->setText(QString());
        pokemon_name_5->setText(QString());
        pokemon_name_6->setText(QString());
        pokemon_icon_1->setText(QString());
        pokemon_icon_2->setText(QString());
        pokemon_icon_3->setText(QString());
        pokemon_icon_4->setText(QString());
        pokemon_icon_5->setText(QString());
        pokemon_icon_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pokeballs: public Ui_pokeballs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POKEBALLS_H
