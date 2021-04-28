/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shop
{
public:
    QLabel *background_image;
    QPushButton *buy_egg_button;
    QPushButton *back_button;
    QRadioButton *pokemon_button_1;
    QRadioButton *pokemon_button_3;
    QRadioButton *pokemon_button_2;
    QLabel *pokemon_unchecked_1;
    QLabel *pokemon_unchecked_2;
    QLabel *pokemon_unchecked_3;
    QLabel *pokemon_checked_1;
    QLabel *pokemon_checked_2;
    QLabel *pokemon_checked_3;
    QLCDNumber *pokecoin_counter;
    QLabel *pokecoin_background;
    QLabel *pokecoin_icon;
    QLCDNumber *pokemon_cost_1;
    QLabel *pokemon_cost_icon_1;
    QLCDNumber *pokemon_cost_2;
    QLabel *pokemon_cost_icon_2;
    QLCDNumber *pokemon_cost_3;
    QLabel *pokemon_cost_icon_3;
    QLabel *egg_icon_1;
    QLabel *egg_icon_2;
    QLabel *egg_icon_3;

    void setupUi(QWidget *shop)
    {
        if (shop->objectName().isEmpty())
            shop->setObjectName(QString::fromUtf8("shop"));
        shop->resize(480, 272);
        background_image = new QLabel(shop);
        background_image->setObjectName(QString::fromUtf8("background_image"));
        background_image->setGeometry(QRect(0, 0, 481, 281));
        background_image->setPixmap(QPixmap(QString::fromUtf8("images/backgrounds/background.png")));
        background_image->setScaledContents(true);
        buy_egg_button = new QPushButton(shop);
        buy_egg_button->setObjectName(QString::fromUtf8("buy_egg_button"));
        buy_egg_button->setGeometry(QRect(100, 240, 80, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        buy_egg_button->setFont(font);
        buy_egg_button->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        back_button = new QPushButton(shop);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(10, 240, 80, 22));
        back_button->setFont(font);
        back_button->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_button_1 = new QRadioButton(shop);
        pokemon_button_1->setObjectName(QString::fromUtf8("pokemon_button_1"));
        pokemon_button_1->setEnabled(true);
        pokemon_button_1->setGeometry(QRect(5, 5, 153, 221));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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
        pokemon_button_3 = new QRadioButton(shop);
        pokemon_button_3->setObjectName(QString::fromUtf8("pokemon_button_3"));
        pokemon_button_3->setEnabled(true);
        pokemon_button_3->setGeometry(QRect(321, 5, 153, 221));
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
        pokemon_button_2 = new QRadioButton(shop);
        pokemon_button_2->setObjectName(QString::fromUtf8("pokemon_button_2"));
        pokemon_button_2->setEnabled(true);
        pokemon_button_2->setGeometry(QRect(163, 5, 153, 221));
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
        pokemon_unchecked_1 = new QLabel(shop);
        pokemon_unchecked_1->setObjectName(QString::fromUtf8("pokemon_unchecked_1"));
        pokemon_unchecked_1->setGeometry(QRect(5, 5, 153, 221));
        pokemon_unchecked_1->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_1->setScaledContents(true);
        pokemon_unchecked_2 = new QLabel(shop);
        pokemon_unchecked_2->setObjectName(QString::fromUtf8("pokemon_unchecked_2"));
        pokemon_unchecked_2->setGeometry(QRect(163, 5, 153, 221));
        pokemon_unchecked_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_2->setScaledContents(true);
        pokemon_unchecked_3 = new QLabel(shop);
        pokemon_unchecked_3->setObjectName(QString::fromUtf8("pokemon_unchecked_3"));
        pokemon_unchecked_3->setGeometry(QRect(321, 5, 153, 221));
        pokemon_unchecked_3->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background_dark.png) 0 0 0 0 stretch stretch;"));
        pokemon_unchecked_3->setScaledContents(true);
        pokemon_checked_1 = new QLabel(shop);
        pokemon_checked_1->setObjectName(QString::fromUtf8("pokemon_checked_1"));
        pokemon_checked_1->setGeometry(QRect(5, 5, 153, 221));
        pokemon_checked_1->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_1->setScaledContents(true);
        pokemon_checked_2 = new QLabel(shop);
        pokemon_checked_2->setObjectName(QString::fromUtf8("pokemon_checked_2"));
        pokemon_checked_2->setGeometry(QRect(163, 5, 153, 221));
        pokemon_checked_2->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_2->setScaledContents(true);
        pokemon_checked_3 = new QLabel(shop);
        pokemon_checked_3->setObjectName(QString::fromUtf8("pokemon_checked_3"));
        pokemon_checked_3->setGeometry(QRect(321, 5, 153, 221));
        pokemon_checked_3->setStyleSheet(QString::fromUtf8("border-radius: 15px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/notification_background.png) 0 0 0 0 stretch stretch;"));
        pokemon_checked_3->setScaledContents(true);
        pokecoin_counter = new QLCDNumber(shop);
        pokecoin_counter->setObjectName(QString::fromUtf8("pokecoin_counter"));
        pokecoin_counter->setGeometry(QRect(420, 242, 51, 21));
        pokecoin_counter->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
""));
        pokecoin_counter->setSegmentStyle(QLCDNumber::Flat);
        pokecoin_counter->setProperty("intValue", QVariant(88888));
        pokecoin_background = new QLabel(shop);
        pokecoin_background->setObjectName(QString::fromUtf8("pokecoin_background"));
        pokecoin_background->setGeometry(QRect(411, 242, 60, 21));
        pokecoin_background->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/backgrounds/button_background.png) 0 0 0 0 stretch stretch;"));
        pokecoin_background->setScaledContents(true);
        pokecoin_icon = new QLabel(shop);
        pokecoin_icon->setObjectName(QString::fromUtf8("pokecoin_icon"));
        pokecoin_icon->setGeometry(QRect(390, 237, 30, 30));
        pokecoin_icon->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: transparent;\n"
""));
        pokecoin_icon->setPixmap(QPixmap(QString::fromUtf8("images/icons/pokecoin_icon.png")));
        pokecoin_icon->setScaledContents(true);
        pokemon_cost_1 = new QLCDNumber(shop);
        pokemon_cost_1->setObjectName(QString::fromUtf8("pokemon_cost_1"));
        pokemon_cost_1->setGeometry(QRect(69, 174, 51, 31));
        pokemon_cost_1->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
""));
        pokemon_cost_1->setDigitCount(2);
        pokemon_cost_1->setSegmentStyle(QLCDNumber::Flat);
        pokemon_cost_1->setProperty("intValue", QVariant(20));
        pokemon_cost_icon_1 = new QLabel(shop);
        pokemon_cost_icon_1->setObjectName(QString::fromUtf8("pokemon_cost_icon_1"));
        pokemon_cost_icon_1->setGeometry(QRect(40, 171, 35, 35));
        pokemon_cost_icon_1->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: transparent;\n"
""));
        pokemon_cost_icon_1->setScaledContents(true);
        pokemon_cost_2 = new QLCDNumber(shop);
        pokemon_cost_2->setObjectName(QString::fromUtf8("pokemon_cost_2"));
        pokemon_cost_2->setGeometry(QRect(230, 173, 51, 31));
        pokemon_cost_2->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
""));
        pokemon_cost_2->setDigitCount(2);
        pokemon_cost_2->setSegmentStyle(QLCDNumber::Flat);
        pokemon_cost_2->setProperty("intValue", QVariant(40));
        pokemon_cost_icon_2 = new QLabel(shop);
        pokemon_cost_icon_2->setObjectName(QString::fromUtf8("pokemon_cost_icon_2"));
        pokemon_cost_icon_2->setGeometry(QRect(201, 170, 35, 35));
        pokemon_cost_icon_2->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: transparent;\n"
""));
        pokemon_cost_icon_2->setScaledContents(true);
        pokemon_cost_3 = new QLCDNumber(shop);
        pokemon_cost_3->setObjectName(QString::fromUtf8("pokemon_cost_3"));
        pokemon_cost_3->setGeometry(QRect(389, 173, 51, 31));
        pokemon_cost_3->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
""));
        pokemon_cost_3->setDigitCount(2);
        pokemon_cost_3->setSegmentStyle(QLCDNumber::Flat);
        pokemon_cost_3->setProperty("intValue", QVariant(60));
        pokemon_cost_icon_3 = new QLabel(shop);
        pokemon_cost_icon_3->setObjectName(QString::fromUtf8("pokemon_cost_icon_3"));
        pokemon_cost_icon_3->setGeometry(QRect(360, 170, 35, 35));
        pokemon_cost_icon_3->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: transparent;\n"
""));
        pokemon_cost_icon_3->setScaledContents(true);
        egg_icon_1 = new QLabel(shop);
        egg_icon_1->setObjectName(QString::fromUtf8("egg_icon_1"));
        egg_icon_1->setGeometry(QRect(25, 20, 113, 113));
        egg_icon_1->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: transparent;\n"
""));
        egg_icon_1->setScaledContents(true);
        egg_icon_2 = new QLabel(shop);
        egg_icon_2->setObjectName(QString::fromUtf8("egg_icon_2"));
        egg_icon_2->setGeometry(QRect(183, 20, 113, 113));
        egg_icon_2->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: transparent;\n"
""));
        egg_icon_2->setScaledContents(true);
        egg_icon_3 = new QLabel(shop);
        egg_icon_3->setObjectName(QString::fromUtf8("egg_icon_3"));
        egg_icon_3->setGeometry(QRect(341, 20, 113, 113));
        egg_icon_3->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"background-color: transparent;\n"
""));
        egg_icon_3->setScaledContents(true);
        background_image->raise();
        pokecoin_background->raise();
        pokemon_checked_2->raise();
        pokemon_checked_1->raise();
        pokemon_checked_3->raise();
        pokemon_unchecked_3->raise();
        pokemon_unchecked_2->raise();
        pokemon_unchecked_1->raise();
        buy_egg_button->raise();
        back_button->raise();
        pokecoin_counter->raise();
        pokecoin_icon->raise();
        pokemon_cost_1->raise();
        pokemon_cost_icon_1->raise();
        pokemon_cost_2->raise();
        pokemon_cost_icon_2->raise();
        pokemon_cost_3->raise();
        pokemon_cost_icon_3->raise();
        egg_icon_1->raise();
        egg_icon_2->raise();
        egg_icon_3->raise();
        pokemon_button_1->raise();
        pokemon_button_3->raise();
        pokemon_button_2->raise();

        retranslateUi(shop);

        QMetaObject::connectSlotsByName(shop);
    } // setupUi

    void retranslateUi(QWidget *shop)
    {
        shop->setWindowTitle(QCoreApplication::translate("shop", "Shop", nullptr));
        background_image->setText(QString());
        buy_egg_button->setText(QCoreApplication::translate("shop", "BUY", nullptr));
        back_button->setText(QCoreApplication::translate("shop", "BACK", nullptr));
        pokemon_button_1->setText(QString());
        pokemon_button_3->setText(QString());
        pokemon_button_2->setText(QString());
        pokemon_unchecked_1->setText(QString());
        pokemon_unchecked_2->setText(QString());
        pokemon_unchecked_3->setText(QString());
        pokemon_checked_1->setText(QString());
        pokemon_checked_2->setText(QString());
        pokemon_checked_3->setText(QString());
        pokecoin_background->setText(QString());
        pokecoin_icon->setText(QString());
        pokemon_cost_icon_1->setText(QString());
        pokemon_cost_icon_2->setText(QString());
        pokemon_cost_icon_3->setText(QString());
        egg_icon_1->setText(QString());
        egg_icon_2->setText(QString());
        egg_icon_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class shop: public Ui_shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
