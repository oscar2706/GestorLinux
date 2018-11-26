//
// Created by Spat on 25/11/18.
//

#include "Folder.h"

Folder::Folder() {
    folderName = "New Folder";
    size = 1;
    isRootFolder = false;
    ownerPermissions = Permission();
    groupPermissions = Permission();
    othersPermissions = Permission();
}

Folder::Folder(const string &_folderName, int _size, Folder* _parentFolder, bool isRoot) {
    folderName = _folderName;
    size = _size;
    parentFolder = _parentFolder;
    isRootFolder = isRoot;
    if(isRootFolder) {
        path = "";
    }
    else{
        string currentPath = parentFolder->path;
        currentPath.append("/");
        currentPath.append(folderName);
        path = currentPath;
    }
    ownerPermissions = Permission();
    groupPermissions = Permission();
    othersPermissions = Permission();
}

const string &Folder::getFolderName() const {
    return folderName;
}

void Folder::addSubFolder(Folder *subFolder) {
    subFolders.push_back(subFolder);
}

void Folder::setNewName(const string &newFolderName) {
    folderName = newFolderName;
}

void Folder::printSubFolders() {
    cout << "Folders:\n";
    if(subFolders.empty())
        cout << "\tEmpty" << endl;
    else{
        for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
            cout << "\t" << (*itrFolder)->folderName << endl;
        }
    }
}

bool Folder::hasSubFolder(const string &searchedFolder) {
    bool folderExists = false;
    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->folderName == searchedFolder)
            folderExists = true;
    }
    return folderExists;
}

Folder *Folder::returnSubFolder(const string &searchedFolder) {
    Folder *directory;
    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->folderName == searchedFolder)
            directory = *itrFolder;
    }
    return directory;
}

Folder *Folder::retutnParentFolder() {
    return parentFolder;
}

void Folder::addFile(File *newFile) {
    files.push_back(newFile);
}

void Folder::printFiles() {
    cout << "Files:\n";
    for (itrFile = files.begin();  itrFile != files.end(); ++itrFile) {
        (*itrFile)->printFileName();
    }
}

void Folder::printPath() {
    if(isRootFolder)
        cout << "/" << endl;
    else
        cout << path << endl;
}

void Folder::printContent() {
    printPath();
    printSubFolders();
    printFiles();
}

void Folder::setOwnerPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute) {
    if(this->subFolders.empty()){
        ownerPermissions.setName(ownerName);
        ownerPermissions.setPermissions(canRead, canWrite, canExecute);
        for (itrFile = files.begin();  itrFile != files.end(); ++itrFile) {
            (*itrFile)->setOwnerPermissions(ownerName, canRead, canWrite, canExecute);
        }
    }
    else{

        for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
            (*itrFolder)->ownerPermissions.setName(ownerName);
            (*itrFolder)->ownerPermissions.setPermissions(canRead, canWrite, canExecute);
            for (itrFile = files.begin();  itrFile != files.end(); ++itrFile) {
                (*itrFile)->setOwnerPermissions(ownerName, canRead, canWrite, canExecute);
            }
        }
    }
    /*
     TODO Hacer los cambios para todos los archivos y subcarpetas(con sus resperctivos archivos)
     */
}

void Folder::setGroupPermissions(const string &groupName, bool canRead, bool canWrite, bool canExecute) {
    groupPermissions.setName(groupName);
    groupPermissions.setPermissions(canRead, canWrite, canExecute);
    /*
     TODO Hacer los cambios para todos los archivos y subcarpetas(con sus resperctivos archivos)
     */
}

void Folder::setOthersPermissions(bool canRead, bool canWrite, bool canExecute) {
    othersPermissions.setPermissions(canRead, canWrite, canExecute);
    /*
     TODO Hacer los cambios para todos los archivos y subcarpetas(con sus resperctivos archivos)
     */
}


