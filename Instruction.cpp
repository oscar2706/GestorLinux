//
// Created by Spat on 27/11/18.
//

#include "Instruction.h"

Instruction::Instruction() {
    isValid = false;
    command = "";
    value = "";
    validCommands[0] = "mkdir";
    validCommands[1] = "rmdir";
    validCommands[2] = "touch";
    validCommands[3] = "nano";
    validCommands[4] = "rm";
    validCommands[5] = "cat";
    validCommands[6] = "chmod";
    validCommands[7] = "mv";
    validCommands[8] = "cd";
    validCommands[9] = "su";
    validCommands[10] = "prisk"; // :v
    validCommands[11] = "ls";
    validCommands[12] = "pitree";
    validCommands[13] = "exit";
    validCommands[14] = "adduser";
    validCommands[15] = "userdel";
    selectedCommand = -1;
    rootFolder = new Folder();
}

Instruction::Instruction(Folder *_rootFolder, User * _currentUser) {
    isValid = false;
    command = "";
    value = "";
    validCommands[0] = "mkdir";
    validCommands[1] = "rmdir";
    validCommands[2] = "touch";
    validCommands[3] = "nano";
    validCommands[4] = "rm";
    validCommands[5] = "cat";
    validCommands[6] = "chmod";
    validCommands[7] = "mv";
    validCommands[8] = "cd";
    validCommands[9] = "su";
    validCommands[10] = "prisk"; // :v
    validCommands[11] = "ls";
    validCommands[12] = "pitree";
    validCommands[13] = "exit";
    validCommands[14] = "adduser";
    validCommands[15] = "userdel";
    selectedCommand = -1;
    rootFolder = _rootFolder;
    currentUser = _currentUser;
}

Instruction::Instruction(const string &_command, const string &_value) {
    validCommands[0] = "mkdir";
    validCommands[1] = "rmdir";
    validCommands[2] = "touch";
    validCommands[3] = "nano";
    validCommands[4] = "rm";
    validCommands[5] = "cat";
    validCommands[6] = "chmod";
    validCommands[7] = "mv";
    validCommands[8] = "cd";
    validCommands[9] = "su";
    validCommands[10] = "prisk"; // :v
    validCommands[11] = "ls";
    validCommands[12] = "pitree";
    validCommands[13] = "exit";
    validCommands[14] = "adduser";
    validCommands[15] = "userdel";
    selectedCommand = -1;
    rootFolder = new Folder();
}

void Instruction::getCommand(string commandToExec) {
    command.clear();
    value.clear();
    selectedCommand = -1;
    isValid = false;
    char espacio = ' ';
    int posIntermedia = 0;
    for (int i = 0; i <commandToExec.size() ; ++i) {
        if(commandToExec.at(i) != espacio){
            command.push_back(commandToExec.at(i));
            posIntermedia = i+2;
        } else
            break;
    }

    //cout << "posIntermedia: " << posIntermedia << ", commandToExec: " << commandToExec.size() << endl;

    for (int j = posIntermedia; j < commandToExec.size(); ++j) {
        value.push_back(commandToExec.at(j));
    }
    //cout << "Command = " << command << ", value = " << value << ", bandera = " << selectedCommand << endl;
}

bool Instruction::checkCommand() {
    for (int i = 0; i <16; ++i) {
        if(command == validCommands[i]){
            isValid = true;
            selectedCommand = i;
            break;
        }
    }
    //cout << "Command = " << command << ", value = " << value << ", bandera = " << selectedCommand << endl;
    return isValid;
}

Folder * Instruction::execCommand(Folder* currentFolder, bool *bandera, list <User*> &registeredUser) {
    //cout << "Command = " << command << ", value = " << value << ", bandera = " << selectedCommand << endl;
    switch (selectedCommand){
        case 0:{//mkdir :D
            if(value.empty())
                cout << "Unspecified name" << endl;
            else if(currentFolder->alreadyExistFolder(value)){
                cout << "Folder name already exists" << endl;
            } else{
                Folder *newFolder;
                newFolder = new Folder(value, 0, currentFolder, false);
                currentFolder->addSubFolder(newFolder);
            }
            //currentFolder->printContent();
        }break;
        case 1:{//rmdir :'C
            Folder *deletedFolder;
            deletedFolder = currentFolder->findFolder(value);

            if(!deletedFolder) {
                cout << "Folder does not exist" << endl;
            }
            else {
                deletedFolder->getTraverse();
                currentFolder->removeFolder(value);
            }
        }break;
        case 2:{//touch
            if(value.empty())
                cout << "Unspecified name" << endl;
            else if(currentFolder->alreadyExistFile(value)){
                cout << "File name already exists" << endl;
            } else{
                File *newFile;
                newFile = new File(value, 2);
                currentFolder->addFile(newFile);
            }
            //currentFolder->printContent();
        }break;
        case 3:{//nano
            if(value.empty())
                cout << "Unspecified name" << endl;
            else if(currentFolder->alreadyExistFile(value)){
                cout << "File name already exists" << endl;
            } else{
                File *newFile;
                newFile = new File(value);
                currentFolder->addFile(newFile);
            }
            //currentFolder->printContent();
        }break;
        case 4:{//rm
            if(value.empty())
                cout << "file name needed" << endl;
            else if(currentFolder->alreadyExistFile(value)){
                currentFolder->removeFile(value);
            } else{
                cout << "file does not exist" << endl;
            }
            //currentFolder->printContent();
        }break;
        case 5:{//cat
            if(value.empty())
                cout << "Debug File name needed" << endl;
            else if(currentFolder->alreadyExistFile(value)){
                currentFolder->openFile(value);
            } else{
                cout << "file does not exist" << endl;
            }
            //currentFolder->printContent();
        }break;
        case 6:{
        }break;
        case 7:{//mv
            if(value.empty())
                cout << "incomplete command" << endl;
            else{

                char espacio = ' ';
                string oldName;
                string newName;

                int posIntermedia = 0;
                for (int i = 0; i <value.size() ; ++i) {
                    if(value.at(i) != espacio){
                        oldName.push_back(value.at(i));
                        posIntermedia = i+2;
                    } else
                        break;
                }
                for (int j = posIntermedia; j < value.size(); ++j) {
                    newName.push_back(value.at(j));
                }
                if(newName.empty() || oldName.empty())
                    cout << "Incomplete command" << endl;
                else{
                    if(currentFolder->alreadyExistFile(oldName)){
                        if(currentFolder->alreadyExistFile(newName)){
                            cout << "File already exists" << endl;
                        } else{
                            currentFolder->changeFileName(oldName, newName);
                        }
                    } else{
                        cout << "File does not exists" << endl;
                    }
                }
            }
            //currentFolder->printContent();
        }break;
        case 8:{//cd
            string pattern = "..";
            Folder *foundFolder;
            if(value.empty())
                cout << "Folder name needed" << endl;
            else {
                if (value == pattern && (currentFolder->retutnParentFolder() != nullptr)) {
                    foundFolder = currentFolder->retutnParentFolder();
                    currentFolder = foundFolder;
                }
                else if(currentFolder->alreadyExistFolder(value)) {
                    foundFolder = currentFolder->returnSubFolder(value);
                    currentFolder = foundFolder;
                } else {
                    cout << "Folder does not exist" << endl;
                }
            }
            //currentFolder->printContent();
        }break;
        case 9:{//su
            bool userExists = false;
            list <User*>::iterator itrUser;
            string password;

            if(value.empty()){
                cout << "Incomplete command" << endl;
            } else {
                for(itrUser = registeredUser.begin(); itrUser != registeredUser.end(); ++itrUser) {
                    if((*itrUser)->getUserName() == value) {
                        userExists = true;
                        break;
                    }
                }

                if(userExists) {
                    do {
                        cout << "Type User Password: ";
                        cin >> password;
                    }while(password.empty());
                    cin.ignore();

                    if((*itrUser)->getUserPassword() == password) {
                        User *selecteduser;
                        selecteduser = (*itrUser);
                        currentUser = selecteduser;
                        cout << "Usuario en Instruction: " << currentUser->getUserName()<< endl;
                    } else {
                        cout << "Invalid password" << endl;
                    }
                }
                else {
                    cout << "User does not exist" << endl;
                }
            }
        }break;
        case 10:{
        }break;
        case 11:{//ls
            if(value.empty()){
                currentFolder->printContent();
            } else if(value == "-l") {
                currentFolder->printContentDetailed();
            } else {
                cout << "Command not found" << endl;
            }
        }break;
        case 12:{//pitree
            if(value.empty()) {
                rootFolder->traverse();
            } else {
                cout << "Command not found" << endl;
            }
        }break;
        case 13:{//exit
            //cout << value.length() << endl;
            if(value.length() == 0)
                *bandera = true;
            //cout << bandera;
        }break;
        case 14:{//adduser
            string password;
            bool userExists = false;
            list <User*>::iterator itrUser;

            if(value.empty()) {
                cout << "Username needed" << endl;
            } else {
                for(itrUser = registeredUser.begin(); itrUser != registeredUser.end(); ++itrUser) {
                    if((*itrUser)->getUserName() == value) {
                        userExists = true;
                        break;
                    }
                }

                if(userExists) {
                    cout << "User already exists" << endl;
                }
                else {
                    Folder *userFolder;
                    userFolder = new Folder(value, 15, rootFolder, false);
                    rootFolder->addSubFolder(userFolder);

                    do {
                        cout << "Type User Password: ";
                        cin >> password;
                    }while(password.empty());
                    cin.ignore();

                    User *newUser;
                    newUser = new User(value, password, value, userFolder, false);
                    registeredUser.push_back(newUser);
                }
            }

            //rootFolder->traverse();
        }break;
        case 15: {//userdel
            list <User*>::iterator itrUser;
            bool userExists = false;

            if(value.empty()) {
                cout << "Incomplete command" << endl;
            } else {
                for(itrUser = registeredUser.begin(); itrUser != registeredUser.end(); ++itrUser) {
                    if((*itrUser)->getUserName() == value) {
                        userExists = true;
                        break;
                    }
                }

                if(userExists) {
                    currentFolder = rootFolder;
                    (*itrUser)->getUserFolder()->getTraverse();
                    currentFolder->removeFolder(value);
                }
                else {
                    cout << "User does not exist" << endl;
                }
            }
        } break;
        default :{
            cout << "Command not found" << endl;
        }
    }

    return currentFolder;
}

User *Instruction::getCurrentUser() {
    return currentUser;
}
