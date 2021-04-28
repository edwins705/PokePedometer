#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "pokemoneter.h"
#include "qmovie.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    // Pokemon Running GIF
    QMovie * pokemonMovie = new QMovie("images/pikachu_running.gif");
    ui->running_pokemon_image->setMovie(pokemonMovie);
    pokemonMovie->start();

    // Trainer Running GIF
    QMovie * trainerMovie = new QMovie("images/trainer_running.gif");
    ui->running_trainer_image->setMovie(trainerMovie);
    trainerMovie->start();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_play_button_clicked()
{
    Pokemoneter *p = new Pokemoneter;
    this -> close();
    p -> show();
}

void MainMenu::on_quit_button_clicked()
{
    close();
}
