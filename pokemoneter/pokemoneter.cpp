#include "pokemoneter.h"
#include "ui_pokemoneter.h"
#include "mainmenu.h"
#include "qmovie.h"
#include "qfile.h"
#include "qfilesystemwatcher.h"

int stepCount = 0;
bool stepConv = false;

Pokemoneter::Pokemoneter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pokemoneter)
{
    ui->setupUi(this);



    // Watch file
    QFileSystemWatcher *watcher = new QFileSystemWatcher();
    bool beingWatched = watcher->addPath("input.txt");
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
        ui -> lcdNumber -> display(stepCount);
        stepConv = false;
    }

    // Change Pikachu and Ash image based on step count
    notificationChange(stepCount);
    imageChange(stepCount);
}

void Pokemoneter::notificationChange(int num)
{
    // If 10 steps moved
    if (num % 20 == 0 && num > 0)
    {
        ui ->lineEdit_3->setText("Egg hatched!");
    }
    else if (num % 10 == 0)
    {
        ui ->lineEdit_3->setText("Egg will soon hatch!");
    }
    else
    {
        // Display nothing
        ui ->lineEdit_3->setText("Keep walking!");
    }
}

void Pokemoneter::imageChange(int num)
{
    // If 10 steps moved
    if (num % 20 == 0)
    {
        // Pokemon GIF (For later?)
        //QMovie * movie = new QMovie("pikachu_gif.gif");
        //ui->label_2->setMovie(movie);
        //movie->start();

        QPixmap pix("pikachu.png");
        //ui->label_2->setStyleSheet("border-image:url(:/2.png);");
        ui->label_2->setPixmap(pix);
    }
    else
    {
        QPixmap pix("egg.png");
        //ui->label_2->setStyleSheet("border-image:url(:/2.png);");
        ui->label_2->setPixmap(pix);
    }
}

Pokemoneter::~Pokemoneter()
{
    delete ui;
}
