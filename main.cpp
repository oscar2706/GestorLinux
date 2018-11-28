#include "Folder.h"
#include "Instruction.h"
#include "User.h"
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

int main() {

    list<User> registeredUsers;
    list<User>::iterator itrUsrs;

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

        User readUsear(userName,password,group,folderName,rootUser);
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
            if(itrUsrs->getUserName() == typedName) {
                do{
                    cout << "Type password";
                    cin >> userPassword;

                    if(userPassword == itrUsrs->getUserPassword())
                        access = true;
                }while(!access);
                break;
            }
    }while (!access);

    Folder *directorioRoot;
    directorioRoot = new Folder("root", 15, nullptr, true);
    Folder *directorioActual;
    directorioActual = directorioRoot;

    Instruction control(directorioRoot);
    string typedCommand;
    bool exitFlag = false;
    cin.ignore();
    do{
        directorioActual->printPath();
        cout << "$" << itrUsrs->getUserName() << ": ";
        getline(cin, typedCommand, '\n');
        //cout << typedCommand << endl;
        control.getCommand(typedCommand);
        if(control.checkCommand())
            directorioActual = control.execCommand(directorioActual, &exitFlag, registeredUsers);

    }while(!exitFlag);

    return 0;
}