//
// Created by Spat on 25/11/18.
//

#include "File.h"

File::File(const string &fileName, const string &data, int size) : fileName(fileName), data(data), size(size) {
    this->fileName = fileName;
    this->data = data;
    this->size = size;
}

void File::printFileName() {
    cout << "Nombre del archivo: " << fileName << endl;
}

void File::printData() {
    cout << data << endl;
}
