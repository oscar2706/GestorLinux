//
// Created by Spat on 25/11/18.
//

#include "File.h"

File::File(const string &fileName, int size) : fileName(fileName), data(data), size(size) {
    this->fileName = fileName;
    cout << "Introduce the text you want to save in the file:\n";
    cin >> data;
    this->size = size;
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
