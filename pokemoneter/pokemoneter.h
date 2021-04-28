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
  int checkStage(QString type, QString name, int steps);
  void set(int currentPIndex);
  void setImage(QString imageName);
  void setNotification(int stage);
  void setButton(int stage);
  void fileChanged(const QString & path);
  void on_back_button_clicked();
  void on_capture_button_clicked();
  void on_pokeball_button_clicked();
  void on_shop_button_clicked();

private:
    Ui::Pokemoneter *ui;
};
#endif // POKEMONETER_H
