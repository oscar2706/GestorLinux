//
// Created by Spat on 25/11/18.
//

#include "User.h"

User::User(const string &_userName, const string &_group) {
    userName = _userName;
    password = "password";
    group = _group;
    rootUser = false;
}

void User::save() {
    ofstream guarda;
    guarda.open("Usuarios.txt", ios::app);
    guarda << userName << endl
           << password << endl
           << group << endl
           << userFolder->getFolderName() << endl
           << rootUser << endl;
    guarda.close();
}

void User::setUserFolder(Folder* folder) {
    userFolder = folder;
}

User::User(const string &_userName, const string &_password, const string &_group, const string &_userFolderName,
           const bool &_rootUser) {
    userName = _userName;
    password = _password;
    group = _group;
    userFolder = new Folder();
    userFolder->setNewName(_userFolderName);
    rootUser = _rootUser;

}

void User::printInfo() {
    cout << userName << ", "<< password << ", " << group << ", " << userFolder->getFolderName() << ", " << rootUser << endl;
    userFolder->printPath();
    userFolder->printContent();

}

string User::getUserName() {
    return userName;
}

string User::getUserPassword() {
    return password;
}

Folder* User::getUserFolder() {
    return userFolder;
}
