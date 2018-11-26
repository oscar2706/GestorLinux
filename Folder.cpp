//
// Created by Spat on 25/11/18.
//

#include "Folder.h"

Folder::Folder() {
    folderName = "New Folder";
    size = 1;
}

Folder::Folder(const string &_folderName, int _size, Folder* _parentFolder) {
    folderName = _folderName;
    size = _size;
    parentFolder = _parentFolder;
}

const string &Folder::getFolderName() const {
    return folderName;
}

void Folder::addSubFolder(Folder *subFolder) {
    subFolders.push_back(subFolder);
    //cout << "Cantidad de subfolders = " << subFolders.size() << endl;
}

void Folder::setNewName(const string &newFolderName) {
    folderName = newFolderName;
}

void Folder::printSubFolders() {
    cout << "Sub folders de " << folderName << ":\n";

    if(subFolders.empty())
        cout << "Sin sub-directorios" << endl;
    else{
        for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
            cout << (*itrFolder)->folderName << endl;
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
    for (itrFile = files.begin();  itrFile != files.end(); ++itrFile) {
        (*itrFile)->printFileName();
        (*itrFile)->printData();
    }
}

