#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ZorkUL.h"
#include "Room.h"
#include "Parser.h"
#include "CommandWords.h"
#include "Command.h"
#include <iostream>
#include <QPixmap>
#include <QMessageBox>
#include <stdlib.h>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

     zorkgame = new ZorkUL();
     parser = new Parser();
     //commandword = new CommandWords();


}
string MainWindow::paragraph(){

    ui->OutputCons0le->append("\n");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //2.cin

}

//void MainWindow::playbutton()
//{
//    play();
//}

void MainWindow::on_ClearButton_clicked()
{
    ui->OutputCons0le->clear();
}


void MainWindow::on_Description_clicked()
{
 ui->OutputCons0le->append("hehe");
}


void MainWindow::on_west_clicked()
{
    zorkgame->go("west");
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
    ui->OutputCons0le->append("\n")
}


void MainWindow::on_North_clicked()
{
       zorkgame->go("north");
       ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
       ui->OutputCons0le->append("\n");

}


void MainWindow::on_Search_clicked()
{
   ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->longDescription()));
   ui->OutputCons0le->append("\n");
}

//void  MainWindow::updateText( const QString & newText )
//{
// connect(zork, SIGNAL( sendText( const QString & ) ), ui, SLOT( updateText( const QString & ) ) );
//}

void MainWindow::on_South_clicked()
{
    zorkgame->go("south");
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
    ui->OutputCons0le->append("\n");
}


void MainWindow::on_East_clicked()
{
    zorkgame->go("east");
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
    ui->OutputCons0le->append("\n");
}


void MainWindow::on_GoldTooltip_clicked()
{
   // parser->showCommands();
       // ui->OutputCons0le->setText(QString::fromStdString(parser->showCommands()));
}


void MainWindow::on_Use_clicked()
{

}


void MainWindow::on_Item_clicked()
{

}


void MainWindow::on_LOOT_clicked()
{

}


void MainWindow::on_Map_clicked()
{
    ui->OutputCons0le->append("         [a]---[b]    [k]        \n"
                               "          |                |         \n"
                               "[d]---[c]      [l]---[j]---[m]  \n"
                               " |        |!              |         \n"
                               "[e]---[f]---[g]---[h]        \n"
                               "                          |         \n"
                               "                          [i]        \n");
}


void MainWindow::on_OutputCons0le_textChanged()
{

}


void MainWindow::on_Playbutton_clicked()
{
   // zorkgame->play();
          //ui->OutputCons0le->setText(QString::fromStdString(zorkgame->play());
    string help = "click the direction buttons to move through rooms. You will need to search rooms in order to find out what they contain."
                  "if your screen gets cluttered click the clear button however being able to see what past rooms contained can be helpful.";

    ui->OutputCons0le->append("Welcome To Zork. This game takes place in a house where you have just awoken");
             ui->OutputCons0le->append(QString::fromStdString(help));
}

