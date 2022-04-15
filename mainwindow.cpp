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

string z = "\n";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

     zorkgame = new ZorkUL();
     parser = new Parser();
     //commandword = new CommandWords();


}
inline void MainWindow::paragraph(){

   ui->OutputCons0le->append(QString::fromStdString(z));

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
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->longDescription()));
   // ui->OutputCons0le->append(QString::fromStdString(z));
    paragraph();
}


void MainWindow::on_west_clicked()
{
    zorkgame->go("west");
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
    paragraph();
}


void MainWindow::on_North_clicked()
{
       zorkgame->go("north");
       ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
       paragraph();

}


void MainWindow::on_Search_clicked()
{
   ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->longDescription()));
   paragraph();
}

//void  MainWindow::updateText( const QString & newText )
//{
// connect(zork, SIGNAL( sendText( const QString & ) ), ui, SLOT( updateText( const QString & ) ) );
//}

void MainWindow::on_South_clicked()
{
    zorkgame->go("south");
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
    paragraph();
}


void MainWindow::on_East_clicked()
{
    zorkgame->go("east");
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
    paragraph();
}


void MainWindow::on_GoldTooltip_clicked()
{
   // parser->showCommands();
       // ui->OutputCons0le->setText(QString::fromStdString(parser->showCommands()));
}


void MainWindow::on_Use_clicked()
{

 if(zorkgame->inventory.size() < 7){

     qApp->quit();

 }

}


void MainWindow::on_Item_clicked()
{

}


void MainWindow::on_LOOT_clicked()
{
 //zorkgame->take("gold");
    ui->Inventory->append(QString::fromStdString(zorkgame->addItemToInv(zorkgame->currentRoom->numberOfItems()-1)));
    paragraph();
}


void MainWindow::on_Map_clicked()
{
    ui->OutputCons0le->append( "  [H]<--->[F]<--->[G]      \n"
                               "    |             |           \n"
                               "  [C]<--->[A]<--->[B]      \n"
                               "                |              |   \n"
                               "  [I]<--->[D]<--->[E]      \n"
                               "                |           \n"
                               "              [J]              \n"
                               "                |           \n"
                               "              [K]              \n");
}


void MainWindow::on_OutputCons0le_textChanged()
{

}


void MainWindow::on_Playbutton_clicked()
{
   // zorkgame->play();
          //ui->OutputCons0le->setText(QString::fromStdString(zorkgame->play());
    string help = "click the direction buttons to move through rooms. You will need to search rooms in order to find out what they contain."
                  "if your screen gets cluttered click the clear button however being able to see what past rooms contained can be helpful."
                  "Just rememeber to carefully search the rooms and click loot howver many times is nessarsy to pick up the items you need."
                  "If you reference the map via the button you will your starting point is A and it is oriented accordingly.               "
                  "Collect the 7 piece a mthyical gold treasure and click USE in order to escape and attempt a final puzzle.                              ";

   ui->OutputCons0le->append("Welcome To Zork. This game takes place in a house where you have just awoken \n");
            ui->OutputCons0le->append(QString::fromStdString(help + z));
                ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
                paragraph();
              //  ui->OutputCons0le->append(QString::fromStdString(zorkgame->printHelp()));
}


void MainWindow::on_Teleport_released()
{
    zorkgame->randTeleport();
    ui->OutputCons0le->append(QString::fromStdString(zorkgame->currentRoom->shortDescription()));
    paragraph();

}


void MainWindow::on_Inventory_copyAvailable(bool b)
{

}

