//
// Created by Spat on 25/11/18.
//

#include "PermissionFile.h"

PermissionFile::PermissionFile() {
    owner = Permission();
    group = Permission();
    others = Permission();
}

PermissionFile::PermissionFile(Permission &_owner, Permission &_group, Permission &_others) {
    owner = _owner;
    group = _group;
    others = _others;
}

void PermissionFile::setOwnerPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute) {
    owner.setName(ownerName);
    owner.setPermissions(canRead,canWrite,canExecute);
}

void PermissionFile::setGroupPermissions(const string &ownerName, bool canRead, bool canWrite, bool canExecute) {
    group.setName(ownerName);
    group.setPermissions(canRead,canWrite,canExecute);
}

void PermissionFile::setOthersPermissions(bool canRead, bool canWrite, bool canExecute) {
    others.setPermissions(canRead,canWrite,canExecute);
}
