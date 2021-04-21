#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

public slots:
    void openNewWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
