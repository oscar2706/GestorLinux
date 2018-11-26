//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_PERMISSION_H
#define PROYECTO3LINUX_PERMISSION_H

#include <string>

using namespace std;
class Permission {
private:
    string name;
    bool read;
    bool write;
    bool execute;
public:
    Permission();
    Permission(string _name, bool canRead, bool canWrite, bool canExecute);
    void setName(const string &_name);
    void setPermissions(bool canRead, bool canWrite, bool canExecute);
};


#endif //PROYECTO3LINUX_PERMISSION_H
