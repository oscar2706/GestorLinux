//
// Created by Spat on 25/11/18.
//

#include "HardDrive.h"

HardDrive::HardDrive() {
    ROM = 100;
    freeSpace = ROM;
    RAM = new string[ROM];
    for(int i = 0; i < ROM; i++)
        RAM[i] = "";
}

HardDrive::HardDrive(int _ROM) {
    ROM = _ROM;
    freeSpace = ROM;
    RAM = new string[ROM];
    for(int i = 0; i < ROM; i++)
        RAM[i] = "";
}

void HardDrive::graphicView() {
    for(int i=0; i<ROM; i++)
        cout << RAM[i] << "|";
    cout << endl;
}

int HardDrive::getFreeSpace() {
    return freeSpace;
}

void HardDrive::add(const string &_dataName, const int &_dataType, const int &_dataSize) {
    //1 carpeta, 2 archivo
    int remainingFile = _dataSize;
    bool finished = false;

    for(int i = 0; i < ROM; i++) {
        if(RAM[i] == "") {
            RAM[i] = _dataName;
            remainingFile--;

            if(remainingFile<=0)
                finished = true;

            if(finished)
                break;
        }
    }

    if(_dataType==1) {
        savedFolders.push_back(_dataName);
    }
    else {
        savedFiles.push_back(_dataName);
    }
}

void HardDrive::remove(const string &_dataName, const int &_dataType) {
    //1 carpeta, 2 archivo
    for(int i = 0; i < ROM; i++) {
        if(RAM[i] == _dataName) {
            RAM[i] = "";
            freeSpace++;
        }
    }

    if(_dataType==1) {
        for(itrFolders = savedFolders.begin(); itrFolders != savedFolders.end(); ++itrFolders) {
            if(*itrFolders == _dataName) {
                savedFolders.remove(_dataName);
                break;
            }
        }
    }
    else {
        for(itrFiles = savedFiles.begin(); itrFolders != savedFiles.end(); ++itrFiles) {
            if(*itrFiles == _dataName) {
                savedFiles.remove(_dataName);
                break;
            }
        }
    }
}
