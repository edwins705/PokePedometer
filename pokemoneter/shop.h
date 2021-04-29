#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include "pokemoneter.h"

namespace Ui {
class shop;
}

class shop : public QWidget
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr);
    ~shop();

private slots:
    void on_back_button_clicked();
    void on_pokemon_button_1_clicked();
    void on_pokemon_button_2_clicked();
    void on_pokemon_button_3_clicked();
    void on_buy_egg_button_clicked();

private:
    Ui::shop *ui;
};

#endif // SHOP_H
