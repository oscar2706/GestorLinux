//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_ARCHIVO_H
#define PROYECTO3LINUX_ARCHIVO_H

#include <string.h>
#include <iostream>
using namespace std;

class File {
private:
    string fileName;
    string data;
    int size;

public:
    File(const string &fileName, const string &data, int size);
    void printFileName();
    void printData();
};


#endif //PROYECTO3LINUX_ARCHIVO_H
