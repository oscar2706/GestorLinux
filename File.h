//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_ARCHIVO_H
#define PROYECTO3LINUX_ARCHIVO_H

#include "Permission.h"
#include <string.h>
#include <iostream>
using namespace std;

class File {
private:
    string fileName;
    string data;
    int size;
    Permission ownerPermissions;
    Permission groupPermissions;
    Permission othersPermissions;
public:
    File(const string &fileName, int size);
    File(const string &fileName);
    void printFileName();
    void printData();
    void printPermissions();
    string getFileName();
    int getFileSize();
    void setNewName(const string &newFileName);
    void setOwnerPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute);
    void setGroupPermissions(const string &groupName, bool canRead, bool canWrite, bool canExecute);
    void setOthersPermissions(bool canRead, bool canWrite, bool canExecute);
};


#endif //PROYECTO3LINUX_ARCHIVO_H
