//
// Created by Spat on 27/11/18.
//

#ifndef PROYECTO3LINUX_INSTRUCTION_H
#define PROYECTO3LINUX_INSTRUCTION_H

#include "Folder.h"
#include "User.h"
#include <string>
#include <stringlist.h>
using namespace std;

class Instruction {
    friend class Folder;
private:
    string validCommands[16];
    string command;
    string value;
    int selectedCommand;
    bool isValid;
    Folder *rootFolder;
    User *currentUser;
public:
    Instruction();
    Instruction(Folder *rootFolder, User *_currentUser);
    Instruction(const string &_command, const string &_value);
    void getCommand(string commandToExec);
    User * getCurrentUser();
    bool checkCommand();
    Folder * execCommand(Folder* currentFolder, bool *bandera, list <User*> &registeredUser);

};


#endif //PROYECTO3LINUX_INSTRUCTION_H
