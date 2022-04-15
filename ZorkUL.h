#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <QApplication>
#include <QTextStream>
#include <iostream>
#include <QPixmap>
#include <QMessageBox>
#include <stdlib.h>
using namespace std;

class ZorkUL {
private:

    //Parser parser;
    /*Room *currentRoom;*/
    //void createRooms();
    //void printWelcome();
    /*bool processCommand(Command command);*/
    //void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
    vector<Room> rooms;

protected:
    Parser parser;
    void createRooms();

public:
	ZorkUL();    
    string printHelp();
    Room *currentRoom;
	void play();
	string go(string direction);
    string randTeleport();
    bool processCommand(Command command);
    void printWelcome();
    string take(string item);
    Room *currentItem;
    vector<Item> inventory;
    string addItemToInv(int location);

signals:
  void  sendText( const QString & newText );

};

#endif /*ZORKUL_H_*/
