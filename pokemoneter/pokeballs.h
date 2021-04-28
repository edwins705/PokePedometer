#ifndef POKEBALLS_H
#define POKEBALLS_H

#include <QWidget>

namespace Ui {
class pokeballs;
}

class pokeballs : public QWidget
{
    Q_OBJECT

public:
    explicit pokeballs(QWidget *parent = nullptr);
    ~pokeballs();

private slots:
    void hideSlots();
    void loadSlots(int slotSelect);
    void load0(QString imageName);
    void load1(QString imageName);
    void load2(QString imageName);
    void load3(QString imageName);
    void load4(QString imageName);
    void load5(QString imageName);
    void on_back_button_clicked();
    void on_select_button_clicked();
    void on_release_button_clicked();
    void on_pokemon_button_1_clicked();
    void on_pokemon_button_2_clicked();
    void on_pokemon_button_3_clicked();
    void on_pokemon_button_4_clicked();
    void on_pokemon_button_5_clicked();
    void on_pokemon_button_6_clicked();

private:
    Ui::pokeballs *ui;
};

#endif // POKEBALLS_H
