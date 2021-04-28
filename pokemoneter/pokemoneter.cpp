#include "pokemoneter.h"
#include "ui_pokemoneter.h"
#include "mainmenu.h"
#include "pokeballs.h"
#include "shop.h"
#include "qmovie.h"
#include "qfile.h"
#include "qfilesystemwatcher.h"
#include "qfileinfo.h"
#include "qtextstream.h"

int stepCount = 0;
bool stepConv = false;
QString stepFileName = "steps.txt";

int maxPokemon = 6;
QString pokemonFileName = "pokemon.txt";
int pStored;
QStringList typeList;
QStringList pNames;
int pSteps[6] = {0, 0, 0, 0, 0, 0};
int currentPIndex;
int pokecoins;
int threshold = 10 * 3;   // Find new egg after 10 steps
int newEggCounter;
int walkThreshold = 10;


Pokemoneter::Pokemoneter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pokemoneter)
{
    ui->setupUi(this);

    /* POKEMON FILE READ */
    // Open file
    QFile pokemonFile(pokemonFileName);
    if (!pokemonFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qInfo( "Unable to open file." );
        return;
    }
    // Read file: Stored Pokemon
    pokemonFile.flush();
    QTextStream inPokemon(&pokemonFile);
    pStored = inPokemon.readLine().toInt();
    for (int i = 0; i < pStored; i++)
    {
        typeList << inPokemon.readLine();
        inPokemon.flush();
        pNames << inPokemon.readLine();
        inPokemon.flush();
        pSteps[i] = inPokemon.readLine().toInt();
        inPokemon.flush();
    }
    currentPIndex = inPokemon.readLine().toInt();
    pokecoins = inPokemon.readLine().toInt();

    /* STEP FILE READ */
    // Read from file and display step count in file
    QFile stepFile(stepFileName);
    if (!stepFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    // Read file and set images
    QTextStream in(&stepFile);
    QString line = in.readLine();
    // Step count conversion
    stepCount = line.toInt(&stepConv);
      
    qInfo( "integer: %d\n", stepCount );

    if (stepConv == true)
    {
        ui -> step_counter -> display(stepCount);
        stepConv = false;
        set(currentPIndex);
    }

    /* FILE WATCHER */
    QFileSystemWatcher *watcher = new QFileSystemWatcher();
    watcher->addPath(stepFileName);
    QObject::connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(fileChanged(QString)));
}

int Pokemoneter::checkStage(QString type, QString name, int steps)
{
    // Based on egg color and step count, determine stage:
    // FOR GREEN EGG
    // (stage 0) 0th step (0 steps) egg
    // (stage 1) completely unhatched (1 - 9 steps) egg
    // (stage 2) about to hatch (10 - 19 steps) egg
    // (stage 3) hatched (20 steps) egg
    // (stage 4) pokemon (21 - 29 steps) pokemon
    // (stage 5) found new egg (30 steps) pokemon
    //
    // FOR BLUE EGG
    // (stage 0) 0th step (0 steps) egg
    // (stage 1) completely unhatched (1 - 19 steps) egg
    // (stage 2) about to hatch (20 - 39 steps) egg
    // (stage 3) hatched (40 steps) egg
    // (stage 4) pokemon (41 - 49 steps) pokemon
    // (stage 5) found new egg (50 steps) pokemon
    //
    // FOR BLUE EGG
    // (stage 0) 0th step (0 steps) egg
    // (stage 1) completely unhatched (1 - 29 steps) egg
    // (stage 2) about to hatch (30 - 59 steps) egg
    // (stage 3) hatched (60 steps) egg
    // (stage 4) pokemon (61 - 69 steps) pokemon
    // (stage 5) found new egg (70 steps) pokemon

    if (type == "green")
    {
        threshold = 10 * 3;
        if (stepCount == 0)
        {
            return 0;
        }
        else if (steps == 0)
        {
            return 1;
        }
        else if ((steps == threshold) || ((steps > (threshold / 3 * 2)) && (steps % walkThreshold == 0)))
        {
            return 5;
        }
        else if (steps == (threshold / 3 * 2))
        {
            return 3;
        }
        else if ((steps >= 1) && (steps <= (threshold / 3 - 1)))
        {
            return 1;
        }
        else if ((steps >= (threshold / 3)) && (steps <= (threshold / 3 * 2 - 1)))
        {
            return 2;
        }
        else
        {
            return 4;
        }
    }
    else if (type == "blue")
    {
        threshold = 20 * 3;
        if (stepCount == 0)
        {
            return 0;
        }
        else if (steps == 0)
        {
            return 1;
        }
        else if ((steps == threshold) || ((steps > (threshold / 3 * 2)) && (steps % walkThreshold == 0)))
        {
            return 5;
        }
        else if (steps == (threshold / 3 * 2))
        {
            return 3;
        }
        else if ((steps >= 1) && (steps <= (threshold / 3 - 1)))
        {
            return 1;
        }
        else if ((steps >= (threshold / 3)) && (steps <= (threshold / 3 * 2 - 1)))
        {
            return 2;
        }
        else
        {
            return 4;
        }
    }
    if (type == "purple")
    {
        threshold = 30 * 3;
        if (stepCount == 0)
        {
            return 0;
        }
        else if (steps == 0)
        {
            return 1;
        }
        else if ((steps == threshold) || ((steps > (threshold / 3 * 2)) && (steps % walkThreshold == 0)))
        {
            return 5;
        }
        else if (steps == (threshold / 3 * 2))
        {
            return 3;
        }
        else if ((steps >= 1) && (steps <= (threshold / 3 - 1)))
        {
            return 1;
        }
        else if ((steps >= (threshold / 3)) && (steps <= (threshold / 3 * 2 - 1)))
        {
            return 2;
        }
        else
        {
            return 4;
        }
    }
    return 0;
}

void Pokemoneter::set(int currentPIndex)
{
    // Checks stage of pokemon selected for walking
    int stage = checkStage(typeList[currentPIndex], pNames[currentPIndex], pSteps[currentPIndex]);

    // Sets notification based on stage
    setNotification(stage);

    // Sets capture button background based on stage
    setButton(stage);

    // If max capacity or not in "found new egg" stage, shade capture button background
    if (pStored == 6 || stage != 5)
    {
        ui -> capture_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> capture_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }

    // Based on egg color and whether hatched or not,
    // set image for the trainer and pokemon
    if (typeList[currentPIndex] == "green")
    {
        // Set the images
        if (pNames[currentPIndex] == "egg")
        {
            if (stage == 0 || stage == 1)
            {
                setImage("trainer 1");
                setImage("green egg before");
            }
            else if (stage == 2)
            {
                setImage("trainer 1");
                setImage("green egg hatching");
            }
            else if (stage == 3)
            {
                setImage("trainer 2");
                setImage("pikachu");
                typeList[currentPIndex] = "green";
                pNames[currentPIndex] = "pikachu";
            }
        }
        else if (pNames[currentPIndex] == "pikachu")
        {
            if (stage == 4)
            {
                setImage("trainer 2");
                setImage("pikachu");
            }
            else if (stage == 5)
            {
                setImage("trainer 2");
                setImage("found egg");
            }
        }
    }
    else if (typeList[currentPIndex] == "blue")
    {
        // Set the images
        if (pNames[currentPIndex] == "egg")
        {
            if (stage == 0 || stage == 1)
            {
                setImage("trainer 1");
                setImage("blue egg before");
            }
            else if (stage == 2)
            {
                setImage("trainer 1");
                setImage("blue egg hatching");
            }
            else if (stage == 3)
            {
                setImage("trainer 2");
                setImage("squirtle");
                typeList[currentPIndex] = "blue";
                pNames[currentPIndex] = "squirtle";
            }
        }
        else if (pNames[currentPIndex] == "squirtle")
        {
            if (stage == 4)
            {
                setImage("trainer 2");
                setImage("squirtle");
            }
            else if (stage == 5)
            {
                setImage("trainer 2");
                setImage("found egg");
            }
        }
    }
    else
    {
        // Set the images
        if (pNames[currentPIndex] == "egg")
        {
            if (stage == 0 || stage == 1)
            {
                setImage("trainer 1");
                setImage("purple egg before");
            }
            else if (stage == 2)
            {
                setImage("trainer 1");
                setImage("purple egg hatching");
            }
            else if (stage == 3)
            {
                setImage("trainer 2");
                setImage("bulbasaur");
                typeList[currentPIndex] = "purple";
                pNames[currentPIndex] = "bulbasaur";
            }
        }
        else if (pNames[currentPIndex] == "bulbasaur")
        {
            if (stage == 4)
            {
                setImage("trainer 2");
                setImage("squirtle");
            }
            else if (stage == 5)
            {
                setImage("trainer 2");
                setImage("found egg");
            }
        }
    }
}

void Pokemoneter::setImage(QString imageName)
{
    // Based on imageName input, set image/gif for trainer or pokemon
    if (imageName == "trainer 1")
    {
        QPixmap trainerPixmap("images/trainer/ash_1.png");
        ui->trainer_image->setPixmap(trainerPixmap);
    }
    if (imageName == "trainer 2")
    {
        QPixmap trainerPixmap("images/trainer/ash_2.png");
        ui->trainer_image->setPixmap(trainerPixmap);
    }
    if (imageName == "green egg before")
    {
        QPixmap pokemonPixmap("images/eggs/green_egg_before.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
    if (imageName == "green egg hatching")
    {
        QMovie * pokemonMovie = new QMovie("images/eggs/green_egg_hatching.gif");
        ui->pokemon_image->setMovie(pokemonMovie);
        pokemonMovie->start();
    }
    if (imageName == "blue egg before")
    {
        QPixmap pokemonPixmap("images/eggs/blue_egg_before.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
    if (imageName == "blue egg hatching")
    {
        QMovie * pokemonMovie = new QMovie("images/eggs/blue_egg_hatching.gif");
        ui->pokemon_image->setMovie(pokemonMovie);
        pokemonMovie->start();
    }
    if (imageName == "purple egg before")
    {
        QPixmap pokemonPixmap("images/eggs/purple_egg_before.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
    if (imageName == "purple egg hatching")
    {
        QMovie * pokemonMovie = new QMovie("images/eggs/purple_egg_hatching.gif");
        ui->pokemon_image->setMovie(pokemonMovie);
        pokemonMovie->start();
    }
    if (imageName == "found egg")
    {
        QMovie * pokemonMovie = new QMovie("images/eggs/found_egg.gif");
        ui->pokemon_image->setMovie(pokemonMovie);
        pokemonMovie->start();
    }
    // GENERATION I
    if(imageName == "pikachu")
    {
        QPixmap pokemonPixmap("images/pokemon/pikachu.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
    if (imageName == "squirtle")
    {
        QPixmap pokemonPixmap("images/pokemon/squirtle.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
    if (imageName == "charmander")
    {
        QPixmap pokemonPixmap("images/pokemon/charmander.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
    if (imageName == "bulbasaur")
    {
        QPixmap pokemonPixmap("images/pokemon/bulbasaur.png");
        ui->pokemon_image->setPixmap(pokemonPixmap);
    }
}

void Pokemoneter::setNotification(int stage)
{
    // Based on current stage, change notification
    if (stage == 0)
    {
        ui ->notification_content->setText("Welcome to Pokemoneter!");
    }
    else if (stage == 1 || stage == 4)
    {
        ui ->notification_content->setText("Keep walking!");
    }
    else if (stage == 2)
    {
        ui ->notification_content->setText("Egg will soon hatch!");
    }
    else if (stage == 3)
    {
        ui ->notification_content->setText("Egg hatched!");
    }
    else
    {
        ui ->notification_content->setText("New egg!\nCapture or release?");
    }
}

void Pokemoneter::setButton(int stage)
{
    // Set background of capture button based on stage
    if (stage == 5)
    {
        ui -> capture_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background.png) "
                                              "0 0 0 0 stretch stretch;");
    }
    else
    {
        ui -> capture_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
    }
}

void Pokemoneter::fileChanged(const QString & path)
{
    // When file change is triggered in steps.txt
    // File IO
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    // Read file
    QTextStream in(&file);
    QString line = in.readLine();

    // Step count conversion
    stepCount = line.toInt(&stepConv);
    //qInfo( "%d\n", stepCount );
    if (stepConv == true)
    {
        ui -> step_counter -> display(stepCount);
        stepConv = false;
    }

    // Every 5 steps, earn a pokecoin
    if (stepCount % 5 == 0)
    {
        pokecoins++;
    }

    // Add steps to the specific pokemon selected
    pSteps[currentPIndex]++;
    set(currentPIndex);
}

Pokemoneter::~Pokemoneter()
{
    delete ui;
}

void Pokemoneter::on_back_button_clicked()
{
    // Save information changed to pokemon.txt
    QFileInfo check_pokemon_file(pokemonFileName);
    QFile file(pokemonFileName);
    if (check_pokemon_file.exists())
    {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream out(&file);
        out << pStored << "\n";
        for (int i = 0; i < pStored; i++)
        {
            out << typeList[i] << "\n";
            out << pNames[i] << "\n";
            out << pSteps[i] << "\n";
        }
        out << currentPIndex << "\n";
        out << pokecoins << "\n";
    }
    file.flush();
    file.close();

    MainMenu *menu = new MainMenu;
    this -> close();
    menu -> show();
}

void Pokemoneter::on_capture_button_clicked()
{
    // Check stage of current pokemon walking with
    int stage = checkStage(typeList[currentPIndex], pNames[currentPIndex], pSteps[currentPIndex]);

    // If pokemon is in "found new egg" stage
    if (stage == 5)
    {
        // AND if pokemon is not at max storage capacity, capture the egg
        if (pStored < 6)
        {
            typeList << typeList[currentPIndex];
            pNames << "egg";
            pSteps[pStored] = 0;
            pStored++;
        }
    }

    // Set button background to shaded when capture is clicked
    ui -> capture_button -> setStyleSheet("border-radius: 10px;\n"
                                              "border-width: 0px;\n"
                                              "background-color: transparent;\n"
                                              "border-image: url(images/backgrounds/button_background_dark.png) "
                                              "0 0 0 0 stretch stretch;");
}

void Pokemoneter::on_pokeball_button_clicked()
{
    // Save information changed to pokemon.txt
    QFileInfo check_pokemon_file(pokemonFileName);
    QFile file(pokemonFileName);
    if (check_pokemon_file.exists())
    {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream out(&file);
        out << pStored << "\n";
        for (int i = 0; i < pStored; i++)
        {
            out << typeList[i] << "\n";
            out << pNames[i] << "\n";
            out << pSteps[i] << "\n";
        }
        out << currentPIndex << "\n";
        out << pokecoins << "\n";
    }
    file.flush();
    file.close();

    pokeballs *p = new pokeballs;
    this -> close();
    p -> show();
}

void Pokemoneter::on_shop_button_clicked()
{
    // Save information changed to pokemon.txt
    QFileInfo check_pokemon_file(pokemonFileName);
    QFile file(pokemonFileName);
    if (check_pokemon_file.exists())
    {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream out(&file);
        out << pStored << "\n";
        for (int i = 0; i < pStored; i++)
        {
            out << typeList[i] << "\n";
            out << pNames[i] << "\n";
            out << pSteps[i] << "\n";
        }
        out << currentPIndex << "\n";
        out << pokecoins << "\n";
    }
    file.flush();
    file.close();

    shop *s = new shop;
    this -> close();
    s -> show();
}
