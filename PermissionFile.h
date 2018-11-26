//
// Created by Spat on 25/11/18.
//

#ifndef PROYECTO3LINUX_PERMISSIONFILE_H
#define PROYECTO3LINUX_PERMISSIONFILE_H

#include "Permission.h"
#include <string.h>

using namespace std;
class PermissionFile {
private:
    Permission owner;
    Permission group;
    Permission others;
public:
    PermissionFile();
    PermissionFile(Permission &_owner, Permission &_group, Permission &_others);
    void setOwnerPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute);
    void setGroupPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute);
    void setOthersPermissions(bool canRead, bool canWrite, bool canExecute);
};


#endif //PROYECTO3LINUX_PERMISSIONFILE_H
