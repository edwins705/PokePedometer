#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "pokemoneter.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    //connect(ui -> pushButton, SIGNAL(click()), this, SLOT(openNewWindow()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::openNewWindow()
{
    Pokemoneter *p = new Pokemoneter;
    this -> close();
    p -> show();
}


void MainMenu::on_pushButton_clicked()
{
    openNewWindow();
}
