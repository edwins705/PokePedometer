#include "shop.h"
#include "ui_shop.h"
#include "pokemoneter.h"
#include "qfile.h"
#include "qfilesystemwatcher.h"
#include "qfileinfo.h"
#include "qtextstream.h"
#include "qdebug.h"


QString pF = "pokemon.txt";
int pT;
QStringList tList = { };
QStringList nList = { };
int sList[] = {0, 0, 0, 0, 0, 0};
int pInd;
int pC;
int slot = 0;
int greenEgg = 20;
int blueEgg = 40;
int purpleEgg = 60;

shop::shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);
    // Button Background Image
    ui -> pokemon_unchecked_1 -> hide();
    ui -> pokemon_checked_1 -> show();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_3 -> show();
    ui -> pokemon_checked_3 -> hide();

    // Coin Image
    QPixmap coinPixmap("images/icons/pokecoin_icon.png");
    QPixmap darkCoinPixmap("images/icons/pokecoin_icon_dark.png");
    ui -> pokemon_cost_icon_1 -> setPixmap(coinPixmap);
    ui -> pokemon_cost_icon_2 -> setPixmap(darkCoinPixmap);
    ui -> pokemon_cost_icon_3 -> setPixmap(darkCoinPixmap);

    // Egg Image
    QPixmap greenEggPixmap("images/icons/green_egg_icon.png");
    QPixmap darkBlueEggPixmap("images/icons/blue_egg_icon_dark.png");
    QPixmap darkPurpleEggPixmap("images/icons/purple_egg_icon_dark.png");
    ui -> egg_icon_1 -> setPixmap(greenEggPixmap);
    ui -> egg_icon_2 -> setPixmap(darkBlueEggPixmap);
    ui -> egg_icon_3 -> setPixmap(darkPurpleEggPixmap);

    /* POKEMON FILE READ */
    // Open file
    QFile pokemonFile(pF);
    if (!pokemonFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    // Read file: Stored Pokemon
    QTextStream in(&pokemonFile);
    pT = in.readLine().toInt();
    for (int i = 0; i < pT; i++)
    {
        tList << in.readLine();
        nList << in.readLine();
        sList[i] = in.readLine().toInt();
    }
    pInd = in.readLine().toInt();
    pC = in.readLine().toInt();
    // Set coin counter
    ui ->pokecoin_counter->display(pC);
    on_pokemon_button_1_clicked();
    slot = 0;

}

shop::~shop()
{
    delete ui;
}

void shop::on_back_button_clicked()
{
    // Save information changed to pokemon.txt
    QFileInfo check_pokemon_file(pF);
    QFile file(pF);
    if (check_pokemon_file.exists())
    {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream out(&file);
        out << pT << "\n";
        for (int i = 0; i < pT; i++)
        {
            out << tList[i] << "\n";
            out << nList[i] << "\n";
            out << sList[i] << "\n";
        }
        out << pInd << "\n";
        out << pC << "\n";
    }
    file.flush();
    file.close();

    Pokemoneter *p = new Pokemoneter;
    this -> close();
    p -> show();
}

void shop::on_pokemon_button_1_clicked()
{
    // If green egg is pressed, highlight the correct images
    ui -> pokemon_button_1 -> setChecked(true);
    ui -> pokemon_checked_1 -> show();
    ui -> pokemon_unchecked_1 -> hide();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_3 -> show();

    QPixmap coinPixmap("images/icons/pokecoin_icon.png");
    QPixmap darkCoinPixmap("images/icons/pokecoin_icon_dark.png");
    ui -> pokemon_cost_icon_1 -> setPixmap(coinPixmap);
    ui -> pokemon_cost_icon_2 -> setPixmap(darkCoinPixmap);
    ui -> pokemon_cost_icon_3 -> setPixmap(darkCoinPixmap);

    QPixmap greenEggPixmap("images/icons/green_egg_icon.png");
    QPixmap darkBlueEggPixmap("images/icons/blue_egg_icon_dark.png");
    QPixmap darkPurpleEggPixmap("images/icons/purple_egg_icon_dark.png");
    ui -> egg_icon_1 -> setPixmap(greenEggPixmap);
    ui -> egg_icon_2 -> setPixmap(darkBlueEggPixmap);
    ui -> egg_icon_3 -> setPixmap(darkPurpleEggPixmap);

    slot = 0;

    // If not enough coins or max capacity in storage, shade buy button
    if (pC - greenEgg < 0 || pT == 6)
    {
        ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background_dark.png) "
                                             "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background.png) "
                                             "0 0 0 0 stretch stretch;");
    }
}

void shop::on_pokemon_button_2_clicked()
{
    // If blue egg is pressed, highlight the correct images
    ui -> pokemon_button_2 -> setChecked(true);
    ui -> pokemon_checked_1 -> hide();
    ui -> pokemon_unchecked_1 -> show();
    ui -> pokemon_checked_2 -> show();
    ui -> pokemon_unchecked_2 -> hide();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_3 -> show();

    QPixmap coinPixmap("images/icons/pokecoin_icon.png");
    QPixmap darkCoinPixmap("images/icons/pokecoin_icon_dark.png");
    ui -> pokemon_cost_icon_1 -> setPixmap(darkCoinPixmap);
    ui -> pokemon_cost_icon_2 -> setPixmap(coinPixmap);
    ui -> pokemon_cost_icon_3 -> setPixmap(darkCoinPixmap);

    QPixmap darkGreenEggPixmap("images/icons/green_egg_icon_dark.png");
    QPixmap blueEggPixmap("images/icons/blue_egg_icon.png");
    QPixmap darkPurpleEggPixmap("images/icons/purple_egg_icon_dark.png");
    ui -> egg_icon_1 -> setPixmap(darkGreenEggPixmap);
    ui -> egg_icon_2 -> setPixmap(blueEggPixmap);
    ui -> egg_icon_3 -> setPixmap(darkPurpleEggPixmap);

    slot = 1;

    // If not enough coins or max capacity in storage, shade buy button
    if (pC - blueEgg < 0 || pT == 6)
    {
        ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background_dark.png) "
                                             "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background.png) "
                                             "0 0 0 0 stretch stretch;");
    }
}

void shop::on_pokemon_button_3_clicked()
{
    // If purple egg is pressed, highlight the correct images
    ui -> pokemon_button_3 -> setChecked(true);
    ui -> pokemon_checked_1 -> hide();
    ui -> pokemon_unchecked_1 -> show();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_3 -> show();
    ui -> pokemon_unchecked_3 -> hide();

    QPixmap coinPixmap("images/icons/pokecoin_icon.png");
    QPixmap darkCoinPixmap("images/icons/pokecoin_icon_dark.png");
    ui -> pokemon_cost_icon_1 -> setPixmap(darkCoinPixmap);
    ui -> pokemon_cost_icon_2 -> setPixmap(darkCoinPixmap);
    ui -> pokemon_cost_icon_3 -> setPixmap(coinPixmap);

    QPixmap darkGreenEggPixmap("images/icons/green_egg_icon_dark.png");
    QPixmap darkBlueEggPixmap("images/icons/blue_egg_icon_dark.png");
    QPixmap purpleEggPixmap("images/icons/purple_egg_icon.png");
    ui -> egg_icon_1 -> setPixmap(darkGreenEggPixmap);
    ui -> egg_icon_2 -> setPixmap(darkBlueEggPixmap);
    ui -> egg_icon_3 -> setPixmap(purpleEggPixmap);

    slot = 2;

    // If not enough coins or max capacity in storage, shade buy button
    if (pC - purpleEgg < 0 || pT == 6)
    {
        ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background_dark.png) "
                                             "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background.png) "
                                             "0 0 0 0 stretch stretch;");
    }
}

void shop::on_buy_egg_button_clicked()
{
    // Set buy button background on click
    if (slot == 0)
    {
        if (pC - greenEgg >= 0 && pT < 6)
        {
            pC -= greenEgg;
            tList << "green";
            nList << "egg";
            sList[pT] = 0;
            pT++;
            if (pT == 6)
            {
                ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                     "border-width: 0px;\n"
                                                     "background-color: transparent;\n"
                                                     "border-image: url(images/backgrounds/button_background_dark.png) "
                                                     "0 0 0 0 stretch stretch;");
            }
        }
        else
        {
            ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                 "border-width: 0px;\n"
                                                 "background-color: transparent;\n"
                                                 "border-image: url(images/backgrounds/button_background_dark.png) "
                                                 "0 0 0 0 stretch stretch;");
        }
        if (pC < greenEgg)
        {
            ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                 "border-width: 0px;\n"
                                                 "background-color: transparent;\n"
                                                 "border-image: url(images/backgrounds/button_background_dark.png) "
                                                 "0 0 0 0 stretch stretch;");
        }
    }
    else if (slot == 1)
    {
        if (pC - blueEgg >= 0 && pT < 6)
        {
            pC -= blueEgg;
            tList << "blue";
            nList << "egg";
            sList[pT] = 0;
            pT++;
            if (pT == 6)
            {
                ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                     "border-width: 0px;\n"
                                                     "background-color: transparent;\n"
                                                     "border-image: url(images/backgrounds/button_background_dark.png) "
                                                     "0 0 0 0 stretch stretch;");
            }
        }
        else
        {
            ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                 "border-width: 0px;\n"
                                                 "background-color: transparent;\n"
                                                 "border-image: url(images/backgrounds/button_background_dark.png) "
                                                 "0 0 0 0 stretch stretch;");
        }
        if (pC < blueEgg)
        {
            ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                 "border-width: 0px;\n"
                                                 "background-color: transparent;\n"
                                                 "border-image: url(images/backgrounds/button_background_dark.png) "
                                                 "0 0 0 0 stretch stretch;");
        }
    }
    else
    {
        if (pC - purpleEgg >= 0 && pT < 6)
        {
            pC -= purpleEgg;
            tList << "purple";
            nList << "egg";
            sList[pT] = 0;
            pT++;
            if (pT == 6)
            {
                ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                     "border-width: 0px;\n"
                                                     "background-color: transparent;\n"
                                                     "border-image: url(images/backgrounds/button_background_dark.png) "
                                                     "0 0 0 0 stretch stretch;");
            }
        }
        else
        {
            ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                 "border-width: 0px;\n"
                                                 "background-color: transparent;\n"
                                                 "border-image: url(images/backgrounds/button_background_dark.png) "
                                                 "0 0 0 0 stretch stretch;");
        }
        if (pC < purpleEgg)
        {
            ui -> buy_egg_button -> setStyleSheet("border-radius: 10px;\n"
                                                 "border-width: 0px;\n"
                                                 "background-color: transparent;\n"
                                                 "border-image: url(images/backgrounds/button_background_dark.png) "
                                                 "0 0 0 0 stretch stretch;");
        }
    }
    ui ->pokecoin_counter->display(pC);
}
