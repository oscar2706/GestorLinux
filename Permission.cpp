//
// Created by Spat on 25/11/18.
//

#include "Permission.h"

Permission::Permission() {
    name = "";
    read = false;
    write = false;
    execute = false;
}

Permission::Permission(string _name,bool canRead, bool canWrite, bool canExecute) {
    name = name;
    read = canRead;
    write = canWrite;
    execute = canExecute;
}

void Permission::setName(const string &_name) {
    name = _name;
}

void Permission::setPermissions(bool canRead, bool canWrite, bool canExecute) {
    read = canRead;
    write = canWrite;
    execute = canExecute;
}

void Permission::printPermission() {
    cout << name << ": ";
    cout << "read = " << read << ", ";
    cout << "write = " << write << ", ";
    cout << "execute = " << execute << endl;

}
