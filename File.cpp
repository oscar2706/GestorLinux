//

#include "File.h"

//
// Created by Spat on 25/11/18.
File::File(const string &_fileName) {
    fileName = _fileName;
    cout << "Introduce the text you want to save in the file:\n";
    //cin.ignore();
    getline(cin, data);
    if(data.empty())
        size = 2;
    else
        size = 5;
    ownerPermissions = Permission(_fileName);
    groupPermissions = Permission(_fileName);
    othersPermissions = Permission("");
}

File::File(const string &_fileName, int size) : fileName(_fileName), data(data), size(size) {
    fileName = _fileName;
    //cout << "Introduce the text you want to save in the file:\n";
    //cin >> data;
    this->size = size;
    data = "";
    ownerPermissions = Permission(_fileName);
    groupPermissions = Permission(_fileName);
    othersPermissions = Permission("");
}

void File::printFileName() {
    cout << "\t" << fileName << endl;
}

void File::printData() {
    cout << data << endl;
}

void File::setOwnerPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute) {
    ownerPermissions.setName(ownerName);
    ownerPermissions.setPermissions(canRead, canWrite, canExecute);
}

void File::setGroupPermissions(const string &groupName, bool canRead, bool canWrite, bool canExecute) {
    groupPermissions.setName(groupName);
    groupPermissions.setPermissions(canRead, canWrite, canExecute);
}

void File::setOthersPermissions(bool canRead, bool canWrite, bool canExecute) {
    othersPermissions.setPermissions(canRead, canWrite, canExecute);
}

string File::getFileName() {
    return fileName;
}

void File::setNewName(const string &newFileName) {
    fileName = newFileName;
}

void File::printPermissions() {
    ownerPermissions.printPermission();
    groupPermissions.printPermission();
    othersPermissions.printPermission();
    cout << endl;
}

int File::getFileSize() {
    return size;
}
