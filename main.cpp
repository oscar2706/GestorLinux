#include "Folder.h"
#include "Instruction.h"
#include "User.h"
#include "HardDrive.h"
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
    HardDrive baseMemory(100);

    list<User*> registeredUsers;
    list<User*>::iterator itrUsrs;

    ifstream lee;
    lee.open("Usuarios.txt");

    string userName;
    string password;
    string group;
    string folderName;
    bool rootUser;
    lee >> userName;
    lee >> password;
    lee >> group;
    lee >> folderName;
    lee >> rootUser;
    while (!lee.eof()){
        User *readUsear;
        readUsear = new User(userName,password,group,folderName,rootUser);
        registeredUsers.push_back(readUsear);

        lee >> userName;
        lee >> password;
        lee >> group;
        lee >> folderName;
        lee >> rootUser;
    }

    bool access = false;
    string typedName;
    string userPassword;
    do{
        cout << "Type user name";
        cin >> typedName;
        for (itrUsrs = registeredUsers.begin(); itrUsrs != registeredUsers.end(); ++itrUsrs)
            if((*itrUsrs)->getUserName() == typedName) {
                do{
                    cout << "Type password";
                    cin >> userPassword;

                    if(userPassword == (*itrUsrs)->getUserPassword())
                        access = true;
                }while(!access);
                break;
            }
    }while (!access);

    User *usuarioActual;
    usuarioActual = *(itrUsrs);
    Folder *directorioRoot;
    directorioRoot = new Folder("root", 15, nullptr, true);
    Folder *directorioActual;
    directorioActual = directorioRoot;

    baseMemory.add(directorioRoot->getFolderName(), 1, 1);

    Instruction control(directorioRoot, usuarioActual);
    string typedCommand;
    bool exitFlag = false;
    cin.ignore();
    do{
        directorioActual->printPath();
        cout << "$" << usuarioActual->getUserName() << ": ";
        getline(cin, typedCommand, '\n');
        //cout << typedCommand << endl;
        control.getCommand(typedCommand);
        if(control.checkCommand()){
            directorioActual = control.execCommand(directorioActual, &exitFlag, registeredUsers, &baseMemory);
            usuarioActual = control.getCurrentUser();
            //cout << "Cantidad usuarios = " << registeredUsers.size() << endl;
        }
        else {
            cout << "Command not found" << endl;
        }

    }while(!exitFlag);

    return 0;
}