//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_CARPETA_H
#define PROYECTO3LINUX_CARPETA_H

#include "File.h"
#include "Permission.h"
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
    Permission ownerPermissions;
    Permission groupPermissions;
    Permission othersPermissions;
    string path;
    bool isRootFolder;
public:
    Folder();
    Folder(const string &_folderName, int _size, Folder *_parentFolder,bool isRoot);
    const string &getFolderName() const;
    void addSubFolder(Folder *subFolder);
    void addFile(File *newFile);
    void removeFile(const string &fileName);
    void removeFolder(const string &folderName);
    void setNewName(const string &newFolderName);
    void openFile(const string &fileName);
    void changeFileName(const string &oldFileName, const string &newFileName);
    void printSubFolders();
    void printFiles();
    void printContent();
    void printContentDetailed();
    void printPath();
    void printPermissions();
    bool alreadyExistFolder(const string &folderName);
    bool alreadyExistFile(const string &fileName);
    bool hasSubFolder(const string &searchedFolder);
    Folder* returnSubFolder(const string &searchedFolder);
    Folder* retutnParentFolder();
    void traverse();
    void getTraverse();
    Folder* findFolder(const string &_folderName);
    void setOwnerPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute);
    void setGroupPermissions(const string &groupName, bool canRead, bool canWrite, bool canExecute);
    void setOthersPermissions(bool canRead, bool canWrite, bool canExecute);
};

#endif //PROYECTO3LINUX_CARPETA_H
