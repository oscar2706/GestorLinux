//

#include "File.h"

//
// Created by Spat on 25/11/18.
File::File(const string &fileName) {
    this->fileName = fileName;
    cout << "Introduce the text you want to save in the file:\n";
    //cin.ignore();
    getline(cin, data);
    if(data.empty())
        size = 2;
    else
        size = 5;
    ownerPermissions.setPermissions(true, true, true);
    groupPermissions.setPermissions(true, false, true);
    othersPermissions.setPermissions(true, false, false);
}

File::File(const string &fileName, int size) : fileName(fileName), data(data), size(size) {
    this->fileName = fileName;
    //cout << "Introduce the text you want to save in the file:\n";
    //cin >> data;
    this->size = size;
    data = "";
    ownerPermissions.setPermissions(true, true, true);
    groupPermissions.setPermissions(true, false, true);
    othersPermissions.setPermissions(true, false, false);
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
