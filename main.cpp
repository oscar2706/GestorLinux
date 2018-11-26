#include <iostream>
#include "Folder.h"

using namespace std;

int main() {
    Folder *root;
    root = new Folder();
    root->setNewName("root");
    Folder *folderOscar;
    folderOscar = new Folder("Oscar", 1, root);
    Folder *subFolder2;
    subFolder2 = new Folder("Ana", 1, root);
    Folder *subFolder3;
    subFolder3 = new Folder("Luis", 1, root);

    root->addSubFolder(folderOscar);
    root->addSubFolder(subFolder2);
    root->addSubFolder(subFolder3);

    root->printSubFolders();
    cout << endl;

    Folder *directorioActual;
    directorioActual = new Folder();

    directorioActual = root->returnSubFolder("Oscar");
    directorioActual->printSubFolders();
    cout << endl;

    directorioActual = folderOscar->retutnParentFolder();
    directorioActual->printSubFolders();
    cout << endl;

    Folder *subFolderOscar1;
    subFolderOscar1 = new Folder("Musica", 1, folderOscar);
    Folder *subFolderOscar2;
    subFolderOscar2 = new Folder("Documentos", 1, folderOscar);

    folderOscar->addSubFolder(subFolderOscar1);
    folderOscar->addSubFolder(subFolderOscar2);

    directorioActual = folderOscar;
    directorioActual->printSubFolders();
    cout << endl;

    directorioActual = folderOscar->returnSubFolder("Musica");
    directorioActual->printSubFolders();
    cout << endl;

    directorioActual = directorioActual->retutnParentFolder();
    directorioActual->printSubFolders();
    cout << endl;

    directorioActual = directorioActual->retutnParentFolder();
    directorioActual->printSubFolders();
    cout << endl;

    File *archivoPrueba;
    archivoPrueba = new File("Prueba","Hola Oscar! :D", 1);

    directorioActual->addFile(archivoPrueba);
    directorioActual->printSubFolders();
    directorioActual->printFiles();

    delete root;
    delete folderOscar;
    delete subFolder2;
    delete subFolder3;
    delete subFolderOscar1;
    delete subFolderOscar2;
    return 0;
}