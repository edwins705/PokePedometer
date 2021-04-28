#include "pokeballs.h"
#include "ui_pokeballs.h"
#include "pokemoneter.h"
#include "qmovie.h"
#include "qfile.h"
#include "qfilesystemwatcher.h"
#include "qfileinfo.h"


QString pFile = "pokemon.txt";
int pTotal;
QStringList types = { };
QStringList names = { };
int steps[] = {0, 0, 0, 0, 0, 0};
int pIndex;
int coins;
int slotSelect = 0;

pokeballs::pokeballs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pokeballs)
{
    ui->setupUi(this);

    // Hiding buttons, icons, and progress bars
    ui -> pokemon_unchecked_1 -> hide();
    ui -> pokemon_checked_1 -> show();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_3 -> show();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_4 -> show();
    ui -> pokemon_checked_4 -> hide();
    ui -> pokemon_unchecked_5 -> show();
    ui -> pokemon_checked_5 -> hide();
    ui -> pokemon_unchecked_6 -> show();
    ui -> pokemon_checked_6 -> hide();
    ui -> pokemon_icon_u_1 -> hide();
    ui -> pokemon_icon_c_1 -> show();
    ui -> pokemon_icon_u_2 -> show();
    ui -> pokemon_icon_c_2 -> hide();
    ui -> pokemon_icon_u_3 -> show();
    ui -> pokemon_icon_c_3 -> hide();
    ui -> pokemon_icon_u_4 -> show();
    ui -> pokemon_icon_c_4 -> hide();
    ui -> pokemon_icon_u_5 -> show();
    ui -> pokemon_icon_c_5 -> hide();
    ui -> pokemon_icon_u_6 -> show();
    ui -> pokemon_icon_c_6 -> hide();
    ui -> progressBar_1 -> hide();
    ui -> progressBar_2 -> hide();
    ui -> progressBar_3 -> hide();
    ui -> progressBar_4 -> hide();
    ui -> progressBar_5 -> hide();
    ui -> progressBar_6 -> hide();


    /* POKEMON FILE READ */
    // Open file
    QFile pokemonFile(pFile);
    if (!pokemonFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    // Read file: Stored Pokemon
    QTextStream inPokemon(&pokemonFile);
    pTotal = inPokemon.readLine().toInt();
    for (int i = 0; i < pTotal; i++)
    {
        types << inPokemon.readLine();
        names << inPokemon.readLine();
        steps[i] = inPokemon.readLine().toInt();

    }
    pIndex = inPokemon.readLine().toInt();
    coins = inPokemon.readLine().toInt();

    // Load Pokemon into slots
    if (pIndex == 0)
    {
        on_pokemon_button_1_clicked();
    }
    else if (pIndex == 1)
    {
        on_pokemon_button_2_clicked();
    }
    else if (pIndex == 2)
    {
        on_pokemon_button_3_clicked();
    }
    else if (pIndex == 3)
    {
        on_pokemon_button_4_clicked();
    }
    else if (pIndex == 4)
    {
        on_pokemon_button_5_clicked();
    }
    else
    {
        on_pokemon_button_6_clicked();
    }
    slotSelect = 0;
    on_pokemon_button_1_clicked();
    loadSlots(slotSelect);
    hideSlots();
}

pokeballs::~pokeballs()
{
    delete ui;
}

void pokeballs::hideSlots()
{
    // Hide the slots and background images based on total pokemon stored currently
    if (pTotal == 1)
    {
        ui ->pokemon_button_2->hide();
        ui ->pokemon_button_3->hide();
        ui ->pokemon_button_4->hide();
        ui ->pokemon_button_5->hide();
        ui ->pokemon_button_6->hide();
        ui ->pokemon_checked_2->hide();
        ui ->pokemon_checked_3->hide();
        ui ->pokemon_checked_4->hide();
        ui ->pokemon_checked_5->hide();
        ui ->pokemon_checked_6->hide();
        ui->pokemon_icon_2->hide();
        ui->pokemon_icon_3->hide();
        ui->pokemon_icon_4->hide();
        ui->pokemon_icon_5->hide();
        ui->pokemon_icon_6->hide();
        ui->pokemon_icon_c_2->hide();
        ui->pokemon_icon_c_3->hide();
        ui->pokemon_icon_c_4->hide();
        ui->pokemon_icon_c_5->hide();
        ui->pokemon_icon_c_6->hide();
        ui->pokemon_icon_u_2->hide();
        ui->pokemon_icon_u_3->hide();
        ui->pokemon_icon_u_4->hide();
        ui->pokemon_icon_u_5->hide();
        ui->pokemon_icon_u_6->hide();
        ui->pokemon_name_2->hide();
        ui->pokemon_name_3->hide();
        ui->pokemon_name_4->hide();
        ui->pokemon_name_5->hide();
        ui->pokemon_name_6->hide();
    }
    if (pTotal == 2)
    {
        ui ->pokemon_button_3->hide();
        ui ->pokemon_button_4->hide();
        ui ->pokemon_button_5->hide();
        ui ->pokemon_button_6->hide();
        ui ->pokemon_checked_3->hide();
        ui ->pokemon_checked_4->hide();
        ui ->pokemon_checked_5->hide();
        ui ->pokemon_checked_6->hide();
        ui->pokemon_icon_3->hide();
        ui->pokemon_icon_4->hide();
        ui->pokemon_icon_5->hide();
        ui->pokemon_icon_6->hide();
        ui->pokemon_icon_c_3->hide();
        ui->pokemon_icon_c_4->hide();
        ui->pokemon_icon_c_5->hide();
        ui->pokemon_icon_c_6->hide();
        ui->pokemon_icon_u_3->hide();
        ui->pokemon_icon_u_4->hide();
        ui->pokemon_icon_u_5->hide();
        ui->pokemon_icon_u_6->hide();
        ui->pokemon_name_3->hide();
        ui->pokemon_name_4->hide();
        ui->pokemon_name_5->hide();
        ui->pokemon_name_6->hide();
    }
    if (pTotal == 3)
    {
        ui ->pokemon_button_4->hide();
        ui ->pokemon_button_5->hide();
        ui ->pokemon_button_6->hide();
        ui ->pokemon_checked_4->hide();
        ui ->pokemon_checked_5->hide();
        ui ->pokemon_checked_6->hide();
        ui->pokemon_icon_4->hide();
        ui->pokemon_icon_5->hide();
        ui->pokemon_icon_6->hide();
        ui->pokemon_icon_c_4->hide();
        ui->pokemon_icon_c_5->hide();
        ui->pokemon_icon_c_6->hide();
        ui->pokemon_icon_u_4->hide();
        ui->pokemon_icon_u_5->hide();
        ui->pokemon_icon_u_6->hide();
        ui->pokemon_name_4->hide();
        ui->pokemon_name_5->hide();
        ui->pokemon_name_6->hide();
    }
    if (pTotal == 4)
    {
        ui ->pokemon_button_5->hide();
        ui ->pokemon_button_6->hide();
        ui ->pokemon_checked_5->hide();
        ui ->pokemon_checked_6->hide();
        ui->pokemon_icon_5->hide();
        ui->pokemon_icon_6->hide();
        ui->pokemon_icon_c_5->hide();
        ui->pokemon_icon_c_6->hide();
        ui->pokemon_icon_u_5->hide();
        ui->pokemon_icon_u_6->hide();
        ui->pokemon_name_5->hide();
        ui->pokemon_name_6->hide();
    }
    if (pTotal == 5)
    {
        ui ->pokemon_button_6->hide();
        ui ->pokemon_checked_6->hide();
        ui->pokemon_icon_6->hide();
        ui->pokemon_icon_c_6->hide();
        ui->pokemon_icon_u_6->hide();
        ui->pokemon_name_6->hide();
    }
}

void pokeballs::loadSlots(int slotSelect)
{
    // Load the slots and background images based on total pokemon stored currently

    // If there's only one pokemon stored, shade the release button
    if (pTotal == 1)
    {
        ui -> release_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background_dark.png) "
                                             "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> release_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background.png) "
                                             "0 0 0 0 stretch stretch;");
    }
    // SLOT 0: Choose the correct pokemon image and name
    if (pTotal > 0)
    {
        if (slotSelect == 0)
        {
            if (names[0] == "egg")
            {
                if (types[0] == "green")
                {
                    load0("green egg");
                }
                if (types[0] == "blue")
                {
                    load0("blue egg");
                }
                if (types[0] == "purple")
                {
                    load0("purple egg");
                }
            }
            if (names[0] == "pikachu")
            {
                load0("pikachu");
            }
            if (names[0] == "bulbasaur")
            {
                load0("bulbasaur");
            }
            if (names[0] == "squirtle")
            {
                load0("squirtle");
            }
            if (names[0] == "charmander")
            {
                load0("charmander");
            }
        }
        else
        {
            if (names[0] == "egg")
            {
                if (types[0] == "green")
                {
                    load0("green egg dark");
                }
                if (types[0] == "blue")
                {
                    load0("blue egg dark");
                }
                if (types[0] == "purple")
                {
                    load0("purple egg dark");
                }
            }
            if (names[0] == "pikachu")
            {
                load0("pikachu dark");
            }
            if (names[0] == "bulbasaur")
            {
                load0("bulbasaur dark");
            }
            if (names[0] == "squirtle")
            {
                load0("squirtle dark");
            }
            if (names[0] == "charmander")
            {
                load0("charmander dark");
            }
        }
    }
    // SLOT 1: Choose the correct pokemon image and name
    if (pTotal > 1)
    {
        if (slotSelect == 1)
        {
            if (names[1] == "egg")
            {
                if (types[1] == "green")
                {
                    load1("green egg");
                }
                if (types[1] == "blue")
                {
                    load1("blue egg");
                }
                if (types[1] == "purple")
                {
                    load1("purple egg");
                }
            }
            if (names[1] == "pikachu")
            {
                load1("pikachu");
            }
            if (names[1] == "bulbasaur")
            {
                load1("bulbasaur");
            }
            if (names[1] == "squirtle")
            {
                load1("squirtle");
            }
            if (names[1] == "charmander")
            {
                load1("charmander");
            }
        }
        else
        {
            if (names[1] == "egg")
            {
                if (types[1] == "green")
                {
                    load1("green egg dark");
                }
                if (types[1] == "blue")
                {
                    load1("blue egg dark");
                }
                if (types[1] == "purple")
                {
                    load1("purple egg dark");
                }
            }
            if (names[1] == "pikachu")
            {
                load1("pikachu dark");
            }
            if (names[1] == "bulbasaur")
            {
                load1("bulbasaur dark");
            }
            if (names[1] == "squirtle")
            {
                load1("squirtle dark");
            }
            if (names[1] == "charmander")
            {
                load1("charmander dark");
            }
        }
    }
    // SLOT 2: Choose the correct pokemon image and name
    if (pTotal > 2)
    {
        if (slotSelect == 2)
        {
            if (names[2] == "egg")
            {
                if (types[2] == "green")
                {
                    load2("green egg");
                }
                if (types[2] == "blue")
                {
                    load2("blue egg");
                }
                if (types[2] == "purple")
                {
                    load2("purple egg");
                }
            }
            if (names[2] == "pikachu")
            {
                load2("pikachu");
            }
            if (names[2] == "bulbasaur")
            {
                load2("bulbasaur");
            }
            if (names[2] == "squirtle")
            {
                load2("squirtle");
            }
            if (names[2] == "charmander")
            {
                load2("charmander");
            }
        }
        else
        {
            if (names[2] == "egg")
            {
                if (types[2] == "green")
                {
                    load2("green egg dark");
                }
                if (types[2] == "blue")
                {
                    load2("blue egg dark");
                }
                if (types[2] == "purple")
                {
                    load2("purple egg dark");
                }
            }
            if (names[2] == "pikachu")
            {
                load2("pikachu dark");
            }
            if (names[2] == "bulbasaur")
            {
                load2("bulbasaur dark");
            }
            if (names[2] == "squirtle")
            {
                load2("squirtle dark");
            }
            if (names[2] == "charmander")
            {
                load2("charmander dark");
            }
        }
    }
    // SLOT 3: Choose the correct pokemon image and name
    if (pTotal > 3)
    {
        if (slotSelect == 3)
        {
            if (names[3] == "egg")
            {
                if (types[3] == "green")
                {
                    load3("green egg");
                }
                if (types[3] == "blue")
                {
                    load3("blue egg");
                }
                if (types[3] == "purple")
                {
                    load3("purple egg");
                }
            }
            if (names[3] == "pikachu")
            {
                load3("pikachu");
            }
            if (names[3] == "bulbasaur")
            {
                load3("bulbasaur");
            }
            if (names[3] == "squirtle")
            {
                load3("squirtle");
            }
            if (names[3] == "charmander")
            {
                load3("charmander");
            }
        }
        else
        {
            if (names[3] == "egg")
            {
                if (types[3] == "green")
                {
                    load3("green egg dark");
                }
                if (types[3] == "blue")
                {
                    load3("blue egg dark");
                }
                if (types[3] == "purple")
                {
                    load3("purple egg dark");
                }
            }
            if (names[3] == "pikachu")
            {
                load3("pikachu dark");
            }
            if (names[3] == "bulbasaur")
            {
                load3("bulbasaur dark");
            }
            if (names[3] == "squirtle")
            {
                load3("squirtle dark");
            }
            if (names[3] == "charmander")
            {
                load3("charmander dark");
            }
        }
    }
    // SLOT 4: Choose the correct pokemon image and name
    if (pTotal > 4)
    {
        if (slotSelect == 4)
        {
            if (names[4] == "egg")
            {
                if (types[4] == "green")
                {
                    load4("green egg");
                }
                if (types[4] == "blue")
                {
                    load4("blue egg");
                }
                if (types[4] == "purple")
                {
                    load4("purple egg");
                }
            }
            if (names[4] == "pikachu")
            {
                load4("pikachu");
            }
            if (names[4] == "bulbasaur")
            {
                load4("bulbasaur");
            }
            if (names[4] == "squirtle")
            {
                load4("squirtle");
            }
            if (names[4] == "charmander")
            {
                load4("charmander");
            }
        }
        else
        {
            if (names[4] == "egg")
            {
                if (types[4] == "green")
                {
                    load4("green egg dark");
                }
                if (types[4] == "blue")
                {
                    load4("blue egg dark");
                }
                if (types[4] == "purple")
                {
                    load4("purple egg dark");
                }
            }
            if (names[4] == "pikachu")
            {
                load4("pikachu dark");
            }
            if (names[4] == "bulbasaur")
            {
                load4("bulbasaur dark");
            }
            if (names[4] == "squirtle")
            {
                load4("squirtle dark");
            }
            if (names[4] == "charmander")
            {
                load4("charmander dark");
            }
        }
    }
    // SLOT 5: Choose the correct pokemon image and name
    if (pTotal > 5)
    {
        if (slotSelect == 5)
        {
            if (names[5] == "egg")
            {
                if (types[5] == "green")
                {
                    load5("green egg");
                }
                if (types[5] == "blue")
                {
                    load5("blue egg");
                }
                if (types[5] == "purple")
                {
                    load5("purple egg");
                }
            }
            if (names[5] == "pikachu")
            {
                load5("pikachu");
            }
            if (names[5] == "bulbasaur")
            {
                load5("bulbasaur");
            }
            if (names[5] == "squirtle")
            {
                load5("squirtle");
            }
            if (names[5] == "charmander")
            {
                load5("charmander");
            }
        }
        else
        {
            if (names[5] == "egg")
            {
                if (types[5] == "green")
                {
                    load5("green egg dark");
                }
                if (types[5] == "blue")
                {
                    load5("blue egg dark");
                }
                if (types[5] == "purple")
                {
                    load5("purple egg dark");
                }
            }
            if (names[5] == "pikachu")
            {
                load5("pikachu dark");
            }
            if (names[5] == "bulbasaur")
            {
                load5("bulbasaur dark");
            }
            if (names[5] == "squirtle")
            {
                load5("squirtle dark");
            }
            if (names[5] == "charmander")
            {
                load5("charmander dark");
            }
        }
    }
}

/* THE load# FUNCTIONS ARE FOR SETTING IMAGES IN SPECIFIC ICONS AND NAME LABELS */
void pokeballs::load0(QString imageName)
{
    if (imageName == "green egg")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Green Egg");
    }
    if (imageName == "green egg dark")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon_dark.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Green Egg");
    }
    if (imageName == "blue egg")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Blue Egg");
    }
    if (imageName == "blue egg dark")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon_dark.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Blue Egg");
    }
    if (imageName == "purple egg")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Purple Egg");
    }
    if (imageName == "purple egg dark")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon_dark.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Purple Egg");
    }
    // GENERATION I
    if(imageName == "pikachu")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Pikachu");

    }
    if(imageName == "pikachu dark")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu_dark.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Pikachu");

    }
    if (imageName == "squirtle")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Squirtle");
    }
    if (imageName == "squirtle dark")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle_dark.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Squirtle");
    }
    if (imageName == "charmander")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Charmander");
    }
    if (imageName == "charmander dark")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander_dark.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Charmander");
    }
    if (imageName == "bulbasaur")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Bulbasaur");
    }
    if (imageName == "bulbasaur dark")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur_dark.png");
        ui->pokemon_icon_1->setPixmap(pokemonPixmap);
        ui -> pokemon_name_1->setText("Bulbasaur");
    }
}

void pokeballs::load1(QString imageName)
{
    if (imageName == "green egg")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Green Egg");
    }
    if (imageName == "green egg dark")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon_dark.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Green Egg");
    }
    if (imageName == "blue egg")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Blue Egg");
    }
    if (imageName == "blue egg dark")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon_dark.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Blue Egg");
    }
    if (imageName == "purple egg")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Purple Egg");
    }
    if (imageName == "purple egg dark")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon_dark.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Purple Egg");
    }
    // GENERATION I
    if(imageName == "pikachu")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Pikachu");

    }
    if(imageName == "pikachu dark")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu_dark.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Pikachu");

    }
    if (imageName == "squirtle")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Squirtle");
    }
    if (imageName == "squirtle dark")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle_dark.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Squirtle");
    }
    if (imageName == "charmander")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Charmander");
    }
    if (imageName == "charmander dark")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander_dark.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Charmander");
    }
    if (imageName == "bulbasaur")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Bulbasaur");
    }
    if (imageName == "bulbasaur dark")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur_dark.png");
        ui->pokemon_icon_2->setPixmap(pokemonPixmap);
        ui -> pokemon_name_2->setText("Bulbasaur");
    }
}

void pokeballs::load2(QString imageName)
{
    if (imageName == "green egg")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Green Egg");
    }
    if (imageName == "green egg dark")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon_dark.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Green Egg");
    }
    if (imageName == "blue egg")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Blue Egg");
    }
    if (imageName == "blue egg dark")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon_dark.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Blue Egg");
    }
    if (imageName == "purple egg")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Purple Egg");
    }
    if (imageName == "purple egg dark")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon_dark.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Purple Egg");
    }
    // GENERATION I
    if(imageName == "pikachu")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Pikachu");

    }
    if(imageName == "pikachu dark")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu_dark.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Pikachu");

    }
    if (imageName == "squirtle")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Squirtle");
    }
    if (imageName == "squirtle dark")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle_dark.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Squirtle");
    }
    if (imageName == "charmander")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Charmander");
    }
    if (imageName == "charmander dark")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander_dark.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Charmander");
    }
    if (imageName == "bulbasaur")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Bulbasaur");
    }
    if (imageName == "bulbasaur dark")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur_dark.png");
        ui->pokemon_icon_3->setPixmap(pokemonPixmap);
        ui -> pokemon_name_3->setText("Bulbasaur");
    }
}

void pokeballs::load3(QString imageName)
{
    if (imageName == "green egg")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Green Egg");
    }
    if (imageName == "green egg dark")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon_dark.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Green Egg");
    }
    if (imageName == "blue egg")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Blue Egg");
    }
    if (imageName == "blue egg dark")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon_dark.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Blue Egg");
    }
    if (imageName == "purple egg")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Purple Egg");
    }
    if (imageName == "purple egg dark")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon_dark.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Purple Egg");
    }
    // GENERATION I
    if(imageName == "pikachu")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Pikachu");

    }
    if(imageName == "pikachu dark")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu_dark.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Pikachu");

    }
    if (imageName == "squirtle")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Squirtle");
    }
    if (imageName == "squirtle dark")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle_dark.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Squirtle");
    }
    if (imageName == "charmander")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Charmander");
    }
    if (imageName == "charmander dark")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander_dark.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Charmander");
    }
    if (imageName == "bulbasaur")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Bulbasaur");
    }
    if (imageName == "bulbasaur dark")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur_dark.png");
        ui->pokemon_icon_4->setPixmap(pokemonPixmap);
        ui -> pokemon_name_4->setText("Bulbasaur");
    }
}

void pokeballs::load4(QString imageName)
{
    if (imageName == "green egg")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Green Egg");
    }
    if (imageName == "green egg dark")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon_dark.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Green Egg");
    }
    if (imageName == "blue egg")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Blue Egg");
    }
    if (imageName == "blue egg dark")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon_dark.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Blue Egg");
    }
    if (imageName == "purple egg")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Purple Egg");
    }
    if (imageName == "purple egg dark")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon_dark.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Purple Egg");
    }
    // GENERATION I
    if(imageName == "pikachu")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Pikachu");

    }
    if(imageName == "pikachu dark")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu_dark.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Pikachu");

    }
    if (imageName == "squirtle")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Squirtle");
    }
    if (imageName == "squirtle dark")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle_dark.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Squirtle");
    }
    if (imageName == "charmander")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Charmander");
    }
    if (imageName == "charmander dark")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander_dark.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Charmander");
    }
    if (imageName == "bulbasaur")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Bulbasaur");
    }
    if (imageName == "bulbasaur dark")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur_dark.png");
        ui->pokemon_icon_5->setPixmap(pokemonPixmap);
        ui -> pokemon_name_5->setText("Bulbasaur");
    }
}

void pokeballs::load5(QString imageName)
{
    if (imageName == "green egg")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Green Egg");
    }
    if (imageName == "green egg dark")
    {
        QPixmap pokemonPixmap("images/icons/green_egg_icon_dark.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Green Egg");
    }
    if (imageName == "blue egg")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Blue Egg");
    }
    if (imageName == "blue egg dark")
    {
        QPixmap pokemonPixmap("images/icons/blue_egg_icon_dark.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Blue Egg");
    }
    if (imageName == "purple egg")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Purple Egg");
    }
    if (imageName == "purple egg dark")
    {
        QPixmap pokemonPixmap("images/icons/purple_egg_icon_dark.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Purple Egg");
    }
    // GENERATION I
    if(imageName == "pikachu")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Pikachu");

    }
    if(imageName == "pikachu dark")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu_dark.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Pikachu");

    }
    if (imageName == "squirtle")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Squirtle");
    }
    if (imageName == "squirtle dark")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle_dark.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Squirtle");
    }
    if (imageName == "charmander")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Charmander");
    }
    if (imageName == "charmander dark")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander_dark.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Charmander");
    }
    if (imageName == "bulbasaur")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Bulbasaur");
    }
    if (imageName == "bulbasaur dark")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur_dark.png");
        ui->pokemon_icon_6->setPixmap(pokemonPixmap);
        ui -> pokemon_name_6->setText("Bulbasaur");
    }
}

void pokeballs::on_back_button_clicked()
{
    // Save information changed to pokemon.txt
    QFileInfo check_pokemon_file(pFile);
    QFile file(pFile);
    if (check_pokemon_file.exists())
    {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream out(&file);
        out << pTotal << "\n";
        for (int i = 0; i < pTotal; i++)
        {
            out << types[i] << "\n";
            out << names[i] << "\n";
            out << steps[i] << "\n";
        }
        out << pIndex << "\n";
        out << coins << "\n";
    }
    file.flush();
    file.close();

    Pokemoneter *p = new Pokemoneter;
    this -> close();
    p -> show();
}

void pokeballs::on_select_button_clicked()
{
    // Select the pokemon that is highlighted (if it is not already selected)
    if (pIndex != slotSelect)
    {
        pIndex = slotSelect;
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                             "border-width: 0px;\n"
                                             "background-color: transparent;\n"
                                             "border-image: url(images/backgrounds/button_background_dark.png) "
                                             "0 0 0 0 stretch stretch;");
    }
}

void pokeballs::on_release_button_clicked()
{
    // Allow pokemon to be released if more than 1 left in storage
    if (pTotal > 1)
    {
        // If only 2 pokemon in storage, shade the button background after clicked
        if (pTotal == 2)
        {
            ui -> release_button -> setStyleSheet("border-radius: 10px;\n"
                                                 "border-width: 0px;\n"
                                                 "background-color: transparent;\n"
                                                 "border-image: url(images/backgrounds/button_background_dark.png) "
                                                 "0 0 0 0 stretch stretch;");
        }

        // Remove pokemon from total count and relevant arrays
        pTotal--;
        types.removeAt(slotSelect);
        names.removeAt(slotSelect);
        for (int i = slotSelect; i < (pTotal - slotSelect - 1); i++)
        {
            steps[i] = steps [i + 1];
        }

        // Default the selected pokemon to the first pokemon and highlight it
        // if the selected pokemon was removed.
        if (pIndex == pTotal - 1 || slotSelect == pIndex)
        {
            slotSelect = 0;
            pIndex = slotSelect;
        }
        slotSelect = 0;
        on_pokemon_button_1_clicked();
        loadSlots(slotSelect);
        hideSlots();
    }
}

/* THE on_pokemon_button_#_clicked FUNCTIONS ARE FOR HIGHLIGHTING */
/* AND SHADING THE POKEMON PRESSED AND SELECT BUTTON BACKGROUND   */
void pokeballs::on_pokemon_button_1_clicked()
{
    ui -> pokemon_button_1 -> setChecked(true);
    ui -> pokemon_checked_1 -> show();
    ui -> pokemon_unchecked_1 -> hide();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_3 -> show();
    ui -> pokemon_checked_4 -> hide();
    ui -> pokemon_unchecked_4 -> show();
    ui -> pokemon_checked_5 -> hide();
    ui -> pokemon_unchecked_5 -> show();
    ui -> pokemon_checked_6 -> hide();
    ui -> pokemon_unchecked_6 -> show();
    ui -> pokemon_icon_u_1 -> hide();
    ui -> pokemon_icon_c_1 -> show();
    ui -> pokemon_icon_u_2 -> show();
    ui -> pokemon_icon_c_2 -> hide();
    ui -> pokemon_icon_u_3 -> show();
    ui -> pokemon_icon_c_3 -> hide();
    ui -> pokemon_icon_u_4 -> show();
    ui -> pokemon_icon_c_4 -> hide();
    ui -> pokemon_icon_u_5 -> show();
    ui -> pokemon_icon_c_5 -> hide();
    ui -> pokemon_icon_u_6 -> show();
    ui -> pokemon_icon_c_6 -> hide();
    slotSelect = 0;
    loadSlots(slotSelect);
    hideSlots();
    if (pIndex == 0)
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }
}

void pokeballs::on_pokemon_button_2_clicked()
{
    ui -> pokemon_button_2 -> setChecked(true);
    ui -> pokemon_checked_1 -> hide();
    ui -> pokemon_unchecked_1 -> show();
    ui -> pokemon_checked_2 -> show();
    ui -> pokemon_unchecked_2 -> hide();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_3 -> show();
    ui -> pokemon_checked_4 -> hide();
    ui -> pokemon_unchecked_4 -> show();
    ui -> pokemon_checked_5 -> hide();
    ui -> pokemon_unchecked_5 -> show();
    ui -> pokemon_checked_6 -> hide();
    ui -> pokemon_unchecked_6 -> show();
    ui -> pokemon_icon_u_1 -> show();
    ui -> pokemon_icon_c_1 -> hide();
    ui -> pokemon_icon_u_2 -> hide();
    ui -> pokemon_icon_c_2 -> show();
    ui -> pokemon_icon_u_3 -> show();
    ui -> pokemon_icon_c_3 -> hide();
    ui -> pokemon_icon_u_4 -> show();
    ui -> pokemon_icon_c_4 -> hide();
    ui -> pokemon_icon_u_5 -> show();
    ui -> pokemon_icon_c_5 -> hide();
    ui -> pokemon_icon_u_6 -> show();
    ui -> pokemon_icon_c_6 -> hide();
    slotSelect = 1;
    loadSlots(slotSelect);
    hideSlots();
    if (pIndex == 1)
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }
}

void pokeballs::on_pokemon_button_3_clicked()
{
    ui -> pokemon_button_3 -> setChecked(true);
    ui -> pokemon_checked_1 -> hide();
    ui -> pokemon_unchecked_1 -> show();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_3 -> show();
    ui -> pokemon_unchecked_3 -> hide();
    ui -> pokemon_checked_4 -> hide();
    ui -> pokemon_unchecked_4 -> show();
    ui -> pokemon_checked_5 -> hide();
    ui -> pokemon_unchecked_5 -> show();
    ui -> pokemon_checked_6 -> hide();
    ui -> pokemon_unchecked_6 -> show();
    ui -> pokemon_icon_u_1 -> show();
    ui -> pokemon_icon_c_1 -> hide();
    ui -> pokemon_icon_u_2 -> show();
    ui -> pokemon_icon_c_2 -> hide();
    ui -> pokemon_icon_u_3 -> hide();
    ui -> pokemon_icon_c_3 -> show();
    ui -> pokemon_icon_u_4 -> show();
    ui -> pokemon_icon_c_4 -> hide();
    ui -> pokemon_icon_u_5 -> show();
    ui -> pokemon_icon_c_5 -> hide();
    ui -> pokemon_icon_u_6 -> show();
    ui -> pokemon_icon_c_6 -> hide();
    slotSelect = 2;
    loadSlots(slotSelect);
    hideSlots();
    if (pIndex == 2)
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }

}

void pokeballs::on_pokemon_button_4_clicked()
{
    ui -> pokemon_button_4 -> setChecked(true);
    ui -> pokemon_checked_1 -> hide();
    ui -> pokemon_unchecked_1 -> show();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_3 -> show();
    ui -> pokemon_checked_4 -> show();
    ui -> pokemon_unchecked_4 -> hide();
    ui -> pokemon_checked_5 -> hide();
    ui -> pokemon_unchecked_5 -> show();
    ui -> pokemon_checked_6 -> hide();
    ui -> pokemon_unchecked_6 -> show();
    ui -> pokemon_icon_u_1 -> show();
    ui -> pokemon_icon_c_1 -> hide();
    ui -> pokemon_icon_u_2 -> show();
    ui -> pokemon_icon_c_2 -> hide();
    ui -> pokemon_icon_u_3 -> show();
    ui -> pokemon_icon_c_3 -> hide();
    ui -> pokemon_icon_u_4 -> hide();
    ui -> pokemon_icon_c_4 -> show();
    ui -> pokemon_icon_u_5 -> show();
    ui -> pokemon_icon_c_5 -> hide();
    ui -> pokemon_icon_u_6 -> show();
    ui -> pokemon_icon_c_6 -> hide();
    slotSelect = 3;
    loadSlots(slotSelect);
    hideSlots();
    if (pIndex == 3)
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }
}

void pokeballs::on_pokemon_button_5_clicked()
{
    ui -> pokemon_button_5 -> setChecked(true);
    ui -> pokemon_checked_1 -> hide();
    ui -> pokemon_unchecked_1 -> show();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_3 -> show();
    ui -> pokemon_checked_4 -> hide();
    ui -> pokemon_unchecked_4 -> show();
    ui -> pokemon_checked_5 -> show();
    ui -> pokemon_unchecked_5 -> hide();
    ui -> pokemon_checked_6 -> hide();
    ui -> pokemon_unchecked_6 -> show();
    ui -> pokemon_icon_u_1 -> show();
    ui -> pokemon_icon_c_1 -> hide();
    ui -> pokemon_icon_u_2 -> show();
    ui -> pokemon_icon_c_2 -> hide();
    ui -> pokemon_icon_u_3 -> show();
    ui -> pokemon_icon_c_3 -> hide();
    ui -> pokemon_icon_u_4 -> show();
    ui -> pokemon_icon_c_4 -> hide();
    ui -> pokemon_icon_u_5 -> hide();
    ui -> pokemon_icon_c_5 -> show();
    ui -> pokemon_icon_u_6 -> show();
    ui -> pokemon_icon_c_6 -> hide();
    slotSelect = 4;
    loadSlots(slotSelect);
    hideSlots();
    if (pIndex == 4)
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }
}

void pokeballs::on_pokemon_button_6_clicked()
{
    ui -> pokemon_button_6 -> setChecked(true);
    ui -> pokemon_checked_1 -> hide();
    ui -> pokemon_unchecked_1 -> show();
    ui -> pokemon_checked_2 -> hide();
    ui -> pokemon_unchecked_2 -> show();
    ui -> pokemon_checked_3 -> hide();
    ui -> pokemon_unchecked_3 -> show();
    ui -> pokemon_checked_4 -> hide();
    ui -> pokemon_unchecked_4 -> show();
    ui -> pokemon_checked_5 -> hide();
    ui -> pokemon_unchecked_5 -> show();
    ui -> pokemon_checked_6 -> show();
    ui -> pokemon_unchecked_6 -> hide();
    ui -> pokemon_icon_u_1 -> show();
    ui -> pokemon_icon_c_1 -> hide();
    ui -> pokemon_icon_u_2 -> show();
    ui -> pokemon_icon_c_2 -> hide();
    ui -> pokemon_icon_u_3 -> show();
    ui -> pokemon_icon_c_3 -> hide();
    ui -> pokemon_icon_u_4 -> show();
    ui -> pokemon_icon_c_4 -> hide();
    ui -> pokemon_icon_u_5 -> show();
    ui -> pokemon_icon_c_5 -> hide();
    ui -> pokemon_icon_u_6 -> hide();
    ui -> pokemon_icon_c_6 -> show();
    slotSelect = 5;
    loadSlots(slotSelect);
    hideSlots();
    if (pIndex == 5)
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> select_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }
}
