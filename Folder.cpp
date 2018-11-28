//
// Created by Spat on 25/11/18.
//

#include "Folder.h"

Folder::Folder() {
    folderName = "New Folder";
    size = 1;
    isRootFolder = false;
    ownerPermissions = Permission("New Folder");
    groupPermissions = Permission("New Folder");
    othersPermissions = Permission("");
}

Folder::Folder(const string &_folderName, int _size, Folder* _parentFolder, bool isRoot) {
    folderName = _folderName;
    size = _size;
    //size = 0;
    parentFolder = _parentFolder;
    isRootFolder = isRoot;
    if(isRootFolder) {
        path = "root";
    }
    else{
        string currentPath = parentFolder->path;
        currentPath.append("/");
        currentPath.append(folderName);
        path = currentPath;
    }
    ownerPermissions = Permission(_folderName);
    groupPermissions = Permission(_folderName);
    othersPermissions = Permission("");
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
        cout << path;
}

void Folder::printContent() {
    //printPath();
    //cout << endl;
    printSubFolders();
    printFiles();
}

void Folder::setOwnerPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute) {
    ownerPermissions.setName(ownerName);
    ownerPermissions.setPermissions(canRead, canWrite, canExecute);
    //ownerPermissions.printPermission();
    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->subFolders.empty() == false){
            (*itrFolder)->setOwnerPermissions(ownerName, canRead, canWrite, canExecute);
        } else{
            (*itrFolder)->ownerPermissions.setName(ownerName);
            (*itrFolder)->ownerPermissions.setPermissions(canRead, canWrite, canExecute);
        }
    }
}

void Folder::setGroupPermissions(const string &groupName, bool canRead, bool canWrite, bool canExecute) {
    groupPermissions.setName(groupName);
    groupPermissions.setPermissions(canRead, canWrite, canExecute);
    //groupPermissions.printPermission();
    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->subFolders.empty() == false){
            (*itrFolder)->setGroupPermissions(groupName, canRead, canWrite, canExecute);
        } else{
            (*itrFolder)->groupPermissions.setName(groupName);
            (*itrFolder)->groupPermissions.setPermissions(canRead, canWrite, canExecute);
        }
    }
    /*groupPermissions.setName(groupName);
    groupPermissions.setPermissions(canRead, canWrite, canExecute);
    /*
     TODO Hacer los cambios para todos los archivos y subcarpetas(con sus resperctivos archivos)
     */
}

void Folder::setOthersPermissions(bool canRead, bool canWrite, bool canExecute) {
    othersPermissions.setPermissions(canRead, canWrite, canExecute);
    //othersPermissions.printPermission();
    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->subFolders.empty() == false){
            (*itrFolder)->setOthersPermissions(canRead, canWrite, canExecute);
        } else{
            (*itrFolder)->othersPermissions.setPermissions(canRead, canWrite, canExecute);
        }
    }
    //othersPermissions.setPermissions(canRead, canWrite, canExecute);
    /*
     TODO Hacer los cambios para todos los archivos y subcarpetas(con sus resperctivos archivos)
     */
}

void Folder::printPermissions() {
    ownerPermissions.printPermission();
    groupPermissions.printPermission();
    othersPermissions.printPermission();
    cout << endl;
    /*
    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        cout << "Folder - " << (*itrFolder)->folderName << ": ";
        (*itrFolder)->ownerPermissions.printPermission();
        (*itrFolder)->groupPermissions.printPermission();
        (*itrFolder)->othersPermissions.printPermission();
    }
    cout << endl;
     */
}

void Folder::traverse() {
    printPath();
    cout << endl;
    //printPermissions();
    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->subFolders.empty() == false){
            (*itrFolder)->traverse();
            //(*itrFolder)->printPath();
        } else{
            (*itrFolder)->printPath();
            cout << endl;
            //(*itrFolder)->printPermissions();
        }
    }
}

void Folder::getTraverse(HardDrive *memory) {
    for(itrFolder = subFolders.begin(); itrFolder != subFolders.end(); itrFolder++) {
        memory->remove((*itrFolder)->getFolderName(), 1);
    }

    for(itrFile = files.begin(); itrFile != files.end(); ++itrFile) {
        memory->remove((*itrFile)->getFileName(), 2);
    }


    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->subFolders.empty() == false){
            (*itrFolder)->getTraverse(memory);
            //(*itrFolder)->printPath();
        } else{
            //(*itrFolder)->printPath();
            //out << endl;
            //(*itrFolder)->printPermissions();
        }
    }

    subFolders.clear();
    files.clear();
}

Folder *Folder::findFolder(const string &_folderName) {

    Folder *foundFolder;
    foundFolder = nullptr;

    for (itrFolder = subFolders.begin();  itrFolder != subFolders.end(); ++itrFolder) {
        if((*itrFolder)->getFolderName() == _folderName) {
            foundFolder = *(itrFolder);
            break;
        }
    }

    return foundFolder;
}

bool Folder::alreadyExistFolder(const string &folderName) {
    bool isCopied = false;
    for(itrFolder = subFolders.begin(); itrFolder != subFolders.end(); ++itrFolder){
        if(folderName == (*itrFolder)->getFolderName())
            isCopied = true;
    }
    return isCopied;
}

bool Folder::alreadyExistFile(const string &fileName) {
    bool isCopied = false;
    for(itrFile= files.begin(); itrFile!= files.end(); ++itrFile){
        if(fileName == (*itrFile)->getFileName())
            isCopied = true;
    }
    return isCopied;
}

void Folder::removeFile(const string &fileName) {
    for(itrFile = files.begin(); itrFile != files.end(); ++itrFile)
        if(fileName == (*itrFile)->getFileName()){
            files.remove((*itrFile));
            break;
        }
}

void Folder::openFile(const string &fileName) {
    for(itrFile = files.begin(); itrFile != files.end(); ++itrFile)
        if(fileName == (*itrFile)->getFileName()){
            (*itrFile)->printData();
            break;
        }
}

void Folder::changeFileName(const string &oldFileName, const string &newFileName) {
    for(itrFile = files.begin(); itrFile != files.end(); ++itrFile)
        if(oldFileName== (*itrFile)->getFileName()){
            (*itrFile)->setNewName(newFileName);
            break;
        }
}

void Folder::removeFolder(const string &folderName) {
    for(itrFolder = subFolders.begin(); itrFolder != subFolders.end(); ++itrFolder)
        if(folderName == (*itrFolder)->getFolderName()){
            subFolders.remove((*itrFolder));
            break;
        }
}

void Folder::printContentDetailed() {
    for(itrFile = files.begin(); itrFile != files.end(); ++itrFile) {
            cout << (*itrFile)->getFileName() << endl;
            (*itrFile)->printPermissions();
        }

    for(itrFolder = subFolders.begin(); itrFolder != subFolders.end(); ++itrFolder) {
            cout << (*itrFolder)->getFolderName() << endl;
            (*itrFolder)->printPermissions();
        }
}

File *Folder::returnFile(const string &searchedFile) {
    File *fileLocated;
    for (itrFile = files.begin();  itrFile != files.end(); ++itrFile) {
        if((*itrFile)->getFileName() == searchedFile)
            fileLocated = *itrFile;
    }
    return fileLocated;
}


