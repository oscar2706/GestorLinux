#include <iostream>
#include "Folder.h"

using namespace std;

int main() {
    Folder *root;
    root = new Folder("root",1, nullptr, true);
    Folder *folderOscar;
    folderOscar = new Folder("Oscar", 1, root, false);
    Folder *subFolder2;
    subFolder2 = new Folder("Ana", 1, root, false);
    Folder *subFolder3;
    subFolder3 = new Folder("Luis", 1, root, false);

    root->addSubFolder(folderOscar);
    root->addSubFolder(subFolder2);
    root->addSubFolder(subFolder3);
    root->printContent();
    cout << endl;

    Folder *directorioActual;
    directorioActual = new Folder();

    directorioActual = root->returnSubFolder("Oscar");
    directorioActual->printContent();
    cout << endl;

    directorioActual = folderOscar->retutnParentFolder();
    directorioActual->printContent();
    cout << endl;

    Folder *subFolderOscar1;
    subFolderOscar1 = new Folder("Musica", 1, folderOscar, false);
    Folder *subFolderOscar2;
    subFolderOscar2 = new Folder("Documentos", 1, folderOscar, false);

    folderOscar->addSubFolder(subFolderOscar1);
    folderOscar->addSubFolder(subFolderOscar2);

    directorioActual = folderOscar;
    directorioActual->printContent();
    cout << endl;

    directorioActual = folderOscar->returnSubFolder("Musica");
    directorioActual->printContent();
    cout << endl;

    directorioActual = directorioActual->retutnParentFolder();
    directorioActual->printContent();
    cout << endl;

    directorioActual = directorioActual->retutnParentFolder();
    directorioActual->printContent();
    cout << endl;

    File *archivoPrueba;
    archivoPrueba = new File("Prueba", 1);

    directorioActual->addFile(archivoPrueba);
    directorioActual->printContent();

    directorioActual->setOwnerPermissions("Oscar", true, true, true);
    directorioActual->printPermissions();

    delete root;
    delete folderOscar;
    delete subFolder2;
    delete subFolder3;
    delete subFolderOscar1;
    delete subFolderOscar2;
    return 0;
}