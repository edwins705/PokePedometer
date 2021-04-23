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

private slots:
  void fileChanged(const QString & path);
  void notificationChange(int num);
  void imageChange(int num);

private:
    Ui::Pokemoneter *ui;
};
#endif // POKEMONETER_H
