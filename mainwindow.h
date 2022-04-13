#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include "ZorkUL.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ZorkUL* zorkgame;
    Parser* parser;
    CommandWords commandword;
    ZorkUL start_The_game();
    Ui::MainWindow *ui;
    string paragraph();

private slots:
    void on_pushButton_clicked();

    void on_ClearButton_clicked();

    void on_Description_clicked();

    void on_west_clicked();

    void on_North_clicked();

    void on_Search_clicked();

    void on_South_clicked();

    void on_East_clicked();

    void on_GoldTooltip_clicked();

    void on_Use_clicked();

    void on_Item_clicked();

    void on_LOOT_clicked();

    void on_Map_clicked();

    void on_OutputCons0le_textChanged();

  // void  updateText( const QString & newText );

    void on_Playbutton_clicked();

private:
    // Ui::MainWindow *ui;
};








#endif // MAINWINDOW_H
