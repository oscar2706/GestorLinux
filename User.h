//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_USUARIO_H
#define PROYECTO3LINUX_USUARIO_H

#include <string.h>
#include <iostream>
#include <fstream>

#include "Folder.h"
using namespace std;

class User {
private:
    string userName;
    string group;
    string password;
    Folder *userFolder;
    bool rootUser;
public:
    User();
    User(const string &_userName, const string &_group);
    User(const string &_userName, const string &_password, const string &_group, Folder *_userFolder, const bool &_rootUser);
    User(const string &_userName, const string &_password, const string &_group, const string &_userFolderName, const bool &_rootUser);
    bool isRoot();
    bool hasUserFolder();
    void setUserFolder(Folder* folder);
    Folder* getUserFolder();
    string getUserName();
    string getUserPassword();
    void printInfo();
    void save();
};


#endif //PROYECTO3LINUX_USUARIO_H
