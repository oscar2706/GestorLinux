//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_CARPETA_H
#define PROYECTO3LINUX_CARPETA_H

#include "File.h"
#include <string.h>
#include <list>
#include <iostream>
using namespace std;

class Folder {
public:

private:
    string folderName;
    int size;
    Folder *parentFolder;
    list<Folder*> subFolders;
    list<Folder*>::iterator itrFolder;
    list<File*> files;
    list<File*>::iterator itrFile;

public:
    Folder();
    Folder(const string &_folderName, int _size, Folder *_parentFolder);
    const string &getFolderName() const;
    void addSubFolder(Folder *subFolder);
    void addFile(File *newFile);
    void setNewName(const string &newFolderName);
    void printSubFolders();
    void printFiles();
    bool hasSubFolder(const string &searchedFolder);
    Folder* returnSubFolder(const string &searchedFolder);
    Folder* retutnParentFolder();
};


#endif //PROYECTO3LINUX_CARPETA_H
