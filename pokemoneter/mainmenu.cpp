#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "pokemoneter.h"
#include "qmovie.h"
#include "qfile.h"
#include "qfileinfo.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    // Pokemon Running GIF
    QMovie * pokemonMovie = new QMovie("images/running/pikachu_running.gif");
    ui->running_pokemon_image->setMovie(pokemonMovie);
    pokemonMovie->start();

    // Trainer Running GIF
    QMovie * trainerMovie = new QMovie("images/running/trainer_running.gif");
    ui->running_trainer_image->setMovie(trainerMovie);
    trainerMovie->start();

    /* FILE CREATION */
    // Step File: Create if doesn't exist
    QString stepsFileName = "steps.txt";
    QFileInfo check_steps_file(stepsFileName);
    if (!check_steps_file.exists())
    {
        QFile file(stepsFileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            //qInfo( "Unable to create steps file." );
        }
        QTextStream out(&file);
        out << 0;
    }
    // Pokemon File: Create if doesn't exist
    QString pokemonFileName = "pokemon.txt";
    QFileInfo check_pokemon_file(pokemonFileName);
    if (!check_pokemon_file.exists())
    {
        QFile file(pokemonFileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            //qInfo( "Unable to create pokemon file." );
        }
        QTextStream out(&file);
        // By default: 1 green egg, 0 coins
        out << "1\ngreen\negg\n0\n0\n0\n";
    }
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_play_button_clicked()
{
    // Open pokemoneter page
    Pokemoneter *p = new Pokemoneter;
    this -> close();
    p -> show();
}

void MainMenu::on_quit_button_clicked()
{
    close();
}

void MainMenu::on_reset_button_clicked()
{
    // Step File: Reset
    QString stepsFileName = "steps.txt";
    QFileInfo check_steps_file(stepsFileName);
    if (check_steps_file.exists())
    {
        QFile file(stepsFileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            //qInfo( "Unable to create step file." );
            return;
        }
        QTextStream out(&file);
        out << "0";
    }

    // Pokemon File: Reset
    QString pokemonFileName = "pokemon.txt";
    QFileInfo check_pokemon_file(pokemonFileName);
    if (check_pokemon_file.exists())
    {
        QFile file(pokemonFileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            //qInfo( "Unable to create pokemon file." );
            return;
        }
        QTextStream out(&file);
        out << "1\ngreen\negg\n0\n0\n0\n";
    }
}
