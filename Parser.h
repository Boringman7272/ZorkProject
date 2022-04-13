#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
    //CommandWords *commands;

public:
    CommandWords *commands;
	Parser();
	Command* getCommand();
    void showCommands(); // should be void
};

#endif /*PARSER_H_*/
