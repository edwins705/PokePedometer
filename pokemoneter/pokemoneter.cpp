#include "pokemoneter.h"
#include "ui_pokemoneter.h"
#include "mainmenu.h"
#include "qmovie.h"
#include "qfile.h"
#include "qfilesystemwatcher.h"
#include "qpainter.h"

int stepCount = 0;
bool stepConv = false;
QString fileName = "input.txt";

Pokemoneter::Pokemoneter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pokemoneter)
{
    ui->setupUi(this);

    // Set Images
    // Ash Image: Variation 1
    QPixmap ashPixmap("images/ash_1.png");
    ui->trainer_image->setPixmap(ashPixmap);
    // Pokemon Image: Unhatched Egg
    QPixmap pokemonPixmap("images/egg_before_hatching.png");
    ui->pokemon_image->setPixmap(pokemonPixmap);

    // Create file if doesn't exist
    //
    //
    //



    // Watch file
    QFileSystemWatcher *watcher = new QFileSystemWatcher();
    bool beingWatched = watcher->addPath(fileName);
    if (beingWatched)
    {
        qInfo("Watched");
    }
    QObject::connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(fileChanged(QString)));
}

void Pokemoneter::fileChanged(const QString & path)
{
    qInfo( "Triggered file change." );

    // File IO
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qInfo( "Unable to open file." );
        return;
    }

    // Read file
    QTextStream in(&file);
    QString line = in.readLine();

    // Step count conversion
    stepCount = line.toInt(&stepConv);
    qInfo( "%d\n", stepCount );
    if (stepConv == true)
    {
        ui -> step_counter -> display(stepCount);
        stepConv = false;
    }

    // Change Pikachu and Ash image based on step count
    int stage = checkStage(stepCount);
    notificationChange(stage);
    imageChange(stage);
}

// Checks which stage the egg is in:
// (stage 0) completely unhatched (0th step and 1 - 9 steps)
// (stage 1) about to hatch (10 - 19 steps)
// (stage 2) hatched (20 - 29 steps)
// (stage 3) found new egg (30 steps)
int Pokemoneter::checkStage(int steps)
{
    if ((steps == 0) || ((steps % 30 >= 1) && (steps % 30 <= 9)))
    {
        return 0;
    }
    else if ((steps % 30 >= 10) && (steps % 30 <= 19))
    {
        return 1;
    }
    else if ((steps % 30 >= 20) && (steps % 30 <= 29))
    {
        return 2;
    }
    else
    {
        return 3;
    }

}

// Based on current stage, change notification
void Pokemoneter::notificationChange(int stage)
{
    if (stage == 0)
    {
        ui ->notification_content->setText("Keep walking!");
    }
    else if (stage == 1)
    {
        ui ->notification_content->setText("Egg will soon hatch!");
    }
    else if (stage == 2)
    {
        ui ->notification_content->setText("Egg hatched!");
    }
    else
    {
        ui ->notification_content->setText("Found new egg!");
    }
}

// Based on current stage, change image
void Pokemoneter::imageChange(int stage)
{
    // If 10 steps moved
    if (stage == 0)
    {
        // Ash Image: Variation 1
        QPixmap ashPixmap("images/ash_1.png");
        ui->trainer_image->setPixmap(ashPixmap);

        // Pokemon Image: Unhatched Egg
        QPixmap pokemonPixmap("images/egg_before_hatching.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
    else if (stage == 1)
    {
        // Ash Image: Variation 1
        QPixmap ashPixmap("images/ash_1.png");
        ui->trainer_image->setPixmap(ashPixmap);

        // Pokemon Image: Hatching Egg Gif
        QMovie * pokemonMovie = new QMovie("images/egg_hatching.gif");
        ui->pokemon_image->setMovie(pokemonMovie);
        pokemonMovie->start();
    }
    else if (stage == 2)
    {
        // Ash Image: Variation 2
        QPixmap ashPixmap("images/ash_2.png");
        ui->trainer_image->setPixmap(ashPixmap);

        // Pokemon Image: Pikachu Gif
        QMovie * pokemonMovie = new QMovie("images/pikachu.gif");
        ui->pokemon_image->setMovie(pokemonMovie);
        pokemonMovie->start();
    }
    else
    {
        // Ash Image Change
        QPixmap ashPixmap("images/ash_2.png");
        ui->trainer_image->setPixmap(ashPixmap);

        // Pokemon Image: Found New Egg Gif
        QMovie * pokemonMovie = new QMovie("images/found_egg.gif");
        ui->pokemon_image->setMovie(pokemonMovie);
        pokemonMovie->start();
    }
}

Pokemoneter::~Pokemoneter()
{
    delete ui;
}

void Pokemoneter::on_back_button_clicked()
{
    MainMenu *menu = new MainMenu;
    this -> close();
    menu -> show();
}

void Pokemoneter::on_quit_button_clicked()
{
    close();
}
