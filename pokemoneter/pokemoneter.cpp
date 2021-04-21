#include "pokemoneter.h"
#include "ui_pokemoneter.h"
#include "mainmenu.h"
#include "qmovie.h"

Pokemoneter::Pokemoneter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pokemoneter)
{
    ui->setupUi(this);
    QMovie * movie = new QMovie("pikachu_gif.gif");
    ui->label_2->setMovie(movie);
    movie->start();
}

Pokemoneter::~Pokemoneter()
{
    delete ui;
}
