//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_USUARIO_H
#define PROYECTO3LINUX_USUARIO_H

#include <string.h>
#include <iostream>
#include "Folder.h"
using namespace std;

class User {
private:
    int userID;
    string userName;
    string group;
    string password;
    Folder userFolder;
    bool root;
public:
    User(const string &_userName, const string &_group);
    bool isRoot();
    bool hasUserFolder();
    Folder getUserFolder();
    string getUserName();
};


#endif //PROYECTO3LINUX_USUARIO_H
