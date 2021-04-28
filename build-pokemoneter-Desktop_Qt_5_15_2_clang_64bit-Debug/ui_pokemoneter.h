/********************************************************************************
** Form generated from reading UI file 'pokemoneter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKEMONETER_H
#define UI_POKEMONETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pokemoneter
{
public:
    QWidget *centralwidget;
    QLineEdit *step_counter_label;
    QLCDNumber *step_counter;
    QLabel *pokemon_image;
    QLabel *background_image;
    QLabel *trainer_image;
    QPushButton *quit_button;
    QLineEdit *notification_label;
    QLineEdit *notification_content;
    QPushButton *back_button;

    void setupUi(QMainWindow *Pokemoneter)
    {
        if (Pokemoneter->objectName().isEmpty())
            Pokemoneter->setObjectName(QString::fromUtf8("Pokemoneter"));
        Pokemoneter->resize(480, 272);
        centralwidget = new QWidget(Pokemoneter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        step_counter_label = new QLineEdit(centralwidget);
        step_counter_label->setObjectName(QString::fromUtf8("step_counter_label"));
        step_counter_label->setGeometry(QRect(10, 10, 211, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        font.setPointSize(18);
        step_counter_label->setFont(font);
        step_counter_label->setFocusPolicy(Qt::NoFocus);
        step_counter_label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;"));
        step_counter_label->setReadOnly(true);
        step_counter = new QLCDNumber(centralwidget);
        step_counter->setObjectName(QString::fromUtf8("step_counter"));
        step_counter->setGeometry(QRect(10, 50, 211, 51));
        step_counter->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/notification_background.png) 0 0 0 0 stretch stretch;\n"
""));
        step_counter->setSegmentStyle(QLCDNumber::Flat);
        pokemon_image = new QLabel(centralwidget);
        pokemon_image->setObjectName(QString::fromUtf8("pokemon_image"));
        pokemon_image->setGeometry(QRect(370, 160, 101, 101));
        pokemon_image->setStyleSheet(QString::fromUtf8("background: transparent;"));
        pokemon_image->setPixmap(QPixmap(QString::fromUtf8("images/egg_before_hatching.png")));
        pokemon_image->setScaledContents(true);
        background_image = new QLabel(centralwidget);
        background_image->setObjectName(QString::fromUtf8("background_image"));
        background_image->setGeometry(QRect(0, 0, 481, 281));
        background_image->setPixmap(QPixmap(QString::fromUtf8("images/background.png")));
        background_image->setScaledContents(true);
        trainer_image = new QLabel(centralwidget);
        trainer_image->setObjectName(QString::fromUtf8("trainer_image"));
        trainer_image->setGeometry(QRect(240, 10, 181, 241));
        trainer_image->setStyleSheet(QString::fromUtf8("background: transparent;"));
        trainer_image->setPixmap(QPixmap(QString::fromUtf8("images/ash_1.png")));
        trainer_image->setScaledContents(true);
        quit_button = new QPushButton(centralwidget);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        quit_button->setGeometry(QRect(100, 240, 80, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        quit_button->setFont(font1);
        quit_button->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/button_background.png) 0 0 0 0 stretch stretch;"));
        notification_label = new QLineEdit(centralwidget);
        notification_label->setObjectName(QString::fromUtf8("notification_label"));
        notification_label->setGeometry(QRect(10, 120, 211, 41));
        notification_label->setFont(font);
        notification_label->setFocusPolicy(Qt::NoFocus);
        notification_label->setAutoFillBackground(false);
        notification_label->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: 0px;"));
        notification_label->setReadOnly(true);
        notification_content = new QLineEdit(centralwidget);
        notification_content->setObjectName(QString::fromUtf8("notification_content"));
        notification_content->setGeometry(QRect(10, 160, 211, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("PKMN RBYGSC"));
        font2.setPointSize(7);
        notification_content->setFont(font2);
        notification_content->setStyleSheet(QString::fromUtf8("border: 0px;\n"
"border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/notification_background.png) 0 0 0 0 stretch stretch;\n"
""));
        notification_content->setReadOnly(true);
        back_button = new QPushButton(centralwidget);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(10, 240, 80, 22));
        back_button->setFont(font1);
        back_button->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border-width: 0px;\n"
"background-color: transparent;\n"
"border-image: url(images/button_background.png) 0 0 0 0 stretch stretch;"));
        Pokemoneter->setCentralWidget(centralwidget);
        background_image->raise();
        step_counter_label->raise();
        step_counter->raise();
        trainer_image->raise();
        pokemon_image->raise();
        quit_button->raise();
        notification_label->raise();
        notification_content->raise();
        back_button->raise();

        retranslateUi(Pokemoneter);

        QMetaObject::connectSlotsByName(Pokemoneter);
    } // setupUi

    void retranslateUi(QMainWindow *Pokemoneter)
    {
        Pokemoneter->setWindowTitle(QCoreApplication::translate("Pokemoneter", "Pokemoneter", nullptr));
        step_counter_label->setText(QCoreApplication::translate("Pokemoneter", "Step Count", nullptr));
        pokemon_image->setText(QString());
        background_image->setText(QString());
        trainer_image->setText(QString());
        quit_button->setText(QCoreApplication::translate("Pokemoneter", "QUIT", nullptr));
        notification_label->setText(QCoreApplication::translate("Pokemoneter", "Notification", nullptr));
        notification_content->setText(QCoreApplication::translate("Pokemoneter", "Welcome to Pokemoneter!", nullptr));
        back_button->setText(QCoreApplication::translate("Pokemoneter", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pokemoneter: public Ui_Pokemoneter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POKEMONETER_H
