//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_HARDDRIVE_H
#define PROYECTO3LINUX_HARDDRIVE_H

#include <string.h>
#include <list>
#include <iostream>

using namespace std;

class HardDrive {
private:
    int ROM;
    int freeSpace;
    string *RAM;
    list<string> savedFiles;
    list<string>::iterator itrFiles;
    list<string> savedFolders;
    list<string>::iterator itrFolders;
public:
    HardDrive();
    HardDrive(int _ROM);
    void graphicView();
    int getFreeSpace();
    void add(const string &_dataName, const int &_dataType, const int &_dataSize);
    void remove(const string &_dataName, const int &_dataType);
};


#endif //PROYECTO3LINUX_HARDDRIVE_H
