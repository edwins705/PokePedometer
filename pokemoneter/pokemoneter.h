#ifndef POKEMONETER_H
#define POKEMONETER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Pokemoneter; }
QT_END_NAMESPACE

class Pokemoneter : public QMainWindow
{
    Q_OBJECT

public:
    Pokemoneter(QWidget *parent = nullptr);
    ~Pokemoneter();

private:
    Ui::Pokemoneter *ui;
};
#endif // POKEMONETER_H
