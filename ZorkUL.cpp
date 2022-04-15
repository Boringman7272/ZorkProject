
#include "ZorkUL.h"
#include "mainwindow.h"
#include "CommandWords.h"
#include <QApplication>
#include <QTextStream>
#include <string>
#include <iostream>
#include <vector>
#include "ui_mainwindow.h"
#include "Room.h"
#include "Parser.h"
#include <iostream>
#include <QPixmap>
#include <QMessageBox>
#include <stdlib.h>
#include <QDebug>
using namespace std;
#define PI 3.14159
//ima go

string s;
vector<Item> inventory;

int main(int argc, char *argv[]) {


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


    ZorkUL temp;
    temp.play();


    return 0;
}




ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k;


    a = new Room("This is a musty hallway with a ambient buzz no windows only a doors in all directions front, back, left and right");
        a->addItem(new Item("Gold1", 1, 500));
    b = new Room("This is a empty living room on a sofa and a old burnt out fire are in front of you");
        b->addItem(new Item("Gold2", 1, 500));
    c = new Room("Theres a crackling fire in this room it looks like a small campfire however the light it emits is eaten by the shadows");
        c->addItem(new Item("Gold4", 1, 500));
    d = new Room("A typical kitchen with a press however the windows are drawn onto the wall");
        d->addItem(new Item("Gold3", 1, 500));
    e = new Room("Stairs only way forward is up");
        e->addItem(new Item("Gold5", 1, 500));
    f = new Room("Top of the stairs only way foward is ahead");
        f->addItem(new Item("Gold6", 1, 500));
    g = new Room("another hallway this one looks more clean and modern then the last");
    h = new Room("A old house libary reeks of mold");
    i = new Room("A crack in the wall turns into a door and you enter a small room that is a dead end");
    j = new Room("A mad scienctists lab");
        j->addItem(new Item("Gold7", 1, 500));
    k = new Room("attic");


    rooms.push_back(*a);
    rooms.push_back(*b);
    rooms.push_back(*c);
    rooms.push_back(*d);
    rooms.push_back(*e);
    rooms.push_back(*f);
    rooms.push_back(*g);
    rooms.push_back(*h);
    rooms.push_back(*i);
    rooms.push_back(*j);



//             (N, E, S, W)
	a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, e, a);
    c->setExits(h, a, NULL, NULL);
    d->setExits(a, e, j, i);
    e->setExits(b, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, c, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(d, NULL, k, NULL);
    k->setExits(j, NULL, NULL, NULL);

        currentRoom = a;

}


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {

	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
  //  ui->OutputCons0le->append("start");
   // ui->OutputCons0le->append("click info for your surroundings");
  // ui->OutputCons0le->append("currentRoom->longDescription()");
   //emit sendText( "Here is new text" );
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
        {
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
string ZorkUL::printHelp() {
    string r;
    cout << "valid inputs are";
    parser.showCommands();

    return r;
}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}


string ZorkUL::randTeleport(){

    currentRoom = &rooms.at((int) rand() % rooms.size());
        return currentRoom->longDescription();

}
   /* random = rooms.at((int) rand() % rooms.size());
    Room* nextRoom =currentRoom -> &rooms.at((int) rand() % rooms.size());;

    if (nextRoom == NULL)
        cout<<"direction NUll"<< endl;

    else
{

    currentRoom = nextRoom;
    return currentRoom->longDescription();

}

}
*/

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

string ZorkUL::take(string item) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    //Room* gold = currentItem->Item(item);
    //if (gold == NULL)
    //	return("gold null");
    //else
    //{
    //	currentRoom = gold;
    //	return currentRoom->longDescription();
    //}
    return item;
}
string ZorkUL::addItemToInv(int location)
{
    string r;
    if ((!currentRoom->numberOfItems()) == 0)
    {

        string sitem = currentRoom->getItem(location).getShortDescription();

        Item item = currentRoom->getItem(location);

        inventory.push_back(item);

        currentRoom->removeItemFromRoom();
        return sitem;
    }
        else{
        return r;
    }

}
void parseInput(const string &input)
{
 input;
}
