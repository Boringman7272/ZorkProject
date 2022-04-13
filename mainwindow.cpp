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
     ZorkUL* zork = new ZorkUL();
     ZorkUL play();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //2.cin

}

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

}


void MainWindow::on_North_clicked()
{
   // zork->processCommand("go north");
       ui->OutputCons0le->setText(QString::fromStdString(zork->currentRoom->longDescription()));
}


void MainWindow::on_Search_clicked()
{
zork->printWelcome();
}

void  MainWindow::updateText( const QString & newText )
{
 connect(zork, SIGNAL( sendText( const QString & ) ), ui, SLOT( updateText( const QString & ) ) );
}

void MainWindow::on_South_clicked()
{
    ui->OutputCons0le->append( "south" );
}


void MainWindow::on_East_clicked()
{

}


void MainWindow::on_GoldTooltip_clicked()
{

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

