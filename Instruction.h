//
// Created by Spat on 27/11/18.
//

#ifndef PROYECTO3LINUX_INSTRUCTION_H
#define PROYECTO3LINUX_INSTRUCTION_H

#include "Folder.h"
#include <string>
#include <stringlist.h>
using namespace std;

class Instruction {
    friend class Folder;
private:
    string validCommands[15];
    string command;
    string value;
    int selectedCommand;
    bool isValid;
public:
    Instruction();
    Instruction(const string &_command, const string &_value);
    void getCommand(string commandToExec);
    bool checkCommand();
    Folder * execCommand(Folder* currentFolder, bool *bandera);

};


#endif //PROYECTO3LINUX_INSTRUCTION_H
