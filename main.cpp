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

    Instruction control;
    string typedCommand;
    bool exitFlag = false;
    cin.ignore();
    do{
        directorioActual->printPath();
        cout << itrUsrs->getUserName() << ": ";
        getline(cin, typedCommand, '\n');
        //cout << typedCommand << endl;
        control.getCommand(typedCommand);
        if(control.checkCommand())
            control.execCommand(directorioActual, &exitFlag);

    }while(!exitFlag);


    /*//Pruebas
    Folder *root;
    root = new Folder("root",1, nullptr, true);
    Folder *folderOscar;
    folderOscar = new Folder("LeoBebe", 1, root, false);
    Folder *folderAna;
    folderAna = new Folder("Ana", 1, root, false);
    Folder *subFolder3;
    subFolder3 = new Folder("Luis", 1, root, false);

    root->addSubFolder(folderOscar);
    root->addSubFolder(folderAna);
    root->addSubFolder(subFolder3);
    root->printContent();
    cout << endl;

    Folder *directorioActual;
    directorioActual = root->returnSubFolder("LeoBebe");
    directorioActual->printContent();
    cout << endl;

    directorioActual = folderOscar->retutnParentFolder();
    directorioActual->printContent();
    cout << endl;

    //Subfolders Oscar
    Folder *subFolderOscar1;
    subFolderOscar1 = new Folder("Musica", 1, folderOscar, false);
    Folder *subFolderOscar2;
    subFolderOscar2 = new Folder("Documentos", 1, folderOscar, false);
    folderOscar->addSubFolder(subFolderOscar1);
    folderOscar->addSubFolder(subFolderOscar2);

    //Subfolders Documentos
    Folder *subFolderDocumentos1;
    subFolderOscar1 = new Folder("Musica1", 1, subFolderOscar2, false);
    Folder *subFolderDocumentos2;
    subFolderOscar2 = new Folder("Documentos1", 1, subFolderOscar2, false);
    folderOscar->addSubFolder(subFolderDocumentos1);
    folderOscar->addSubFolder(subFolderDocumentos2);

    //Subfolders Ana
    Folder *subFolderAna1;
    subFolderAna1 = new Folder("Musica Ana", 1, folderAna, false);
    Folder *subFolderAna2;
    subFolderAna2 = new Folder("Documentos Ana", 1, folderAna, false);
    folderAna->addSubFolder(subFolderAna1);
    folderAna->addSubFolder(subFolderAna2);

    root->traverse();

    Instruction comandoPrueba;

    comandoPrueba.getCommand("rmdir LeoBebe");
    comandoPrueba.checkCommand();
    comandoPrueba.execCommand(root);

    cout << "-----------------------------------------------------------------------" << endl;

    root->traverse();*/

    /*File *archivoPrueba;
    archivoPrueba = new File("Prueba", 1);
    directorioActual->addFile(archivoPrueba);
    directorioActual->printContent();

    for (int i = 0; i < 10; ++i) {
        cout << endl;
    }
    directorioActual = root;
    directorioActual->setOwnerPermissions("Dueño", true, true, true);
    directorioActual->traverse();

    list<Folder*>::iterator iterator1;
    iterator1 = directorioActual->subFolders.begin();

    directorioActual->setOwnerPermissions(iterator1,"Oscar", true, true, true);

    directorioActual = root;
    directorioActual->printPath();
    directorioActual->printPermissions();
    directorioActual = folderOscar;
    directorioActual->printPath();
    directorioActual->printPermissions();
    directorioActual = subFolderOscar1;
    directorioActual->printPath();
    directorioActual->printPermissions();
    directorioActual = subFolderOscar2;
    directorioActual->printPath();
    directorioActual->printPermissions();

    delete root;
    delete folderOscar;
    delete folderAna;
    delete subFolder3;
    delete subFolderAna1;
    delete subFolderAna2;
    delete subFolderOscar1;
    delete subFolderOscar2;
    */

    return 0;
}