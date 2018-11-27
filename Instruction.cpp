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
    selectedCommand = -1;
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
    selectedCommand = -1;
}

void Instruction::getCommand(string commandToExec) {
    char espacio = ' ';
    int posIntermedia = 0;
    for (int i = 0; i <commandToExec.size() ; ++i) {
        if(commandToExec.at(i) != espacio){
            command.push_back(commandToExec.at(i));
            posIntermedia = i+2;
        } else
            break;
    }

    for (int j = posIntermedia; j <commandToExec.size(); ++j) {
        value.push_back(commandToExec.at(j));
    }
    //cout << "Command = " << command << ", value = " << value << endl;
}

bool Instruction::checkCommand() {
    for (int i = 0; i <13; ++i) {
        if(command == validCommands[i]){
            isValid = true;
            selectedCommand = i;
            break;
        }
    }
    return isValid;
}

void Instruction::execCommand(Folder* currentFolder) {
    switch (selectedCommand){
        case 0:{
            Folder *newFolder;
            newFolder = new Folder(value, 0, currentFolder, false);
            currentFolder->addSubFolder(newFolder);
            //currentFolder->addSubFolder()
        }break;
        case 1:{
            list <Folder *> foldersToDelete;
            list <Folder *> *foldersDeleted;
            list <Folder *>::iterator itrFoldersDelete;
            Folder *deletedFolder;
            deletedFolder = currentFolder->findFolder(value);

            if(!deletedFolder) {
                cout << "Folder no Encontrado" << endl;
            }
            else {
                foldersDeleted = deletedFolder->getTraverse(&foldersToDelete);

                for(itrFoldersDelete = foldersDeleted->begin(); itrFoldersDelete != foldersDeleted->end(); itrFoldersDelete++) {
                    cout << (*itrFoldersDelete)->getFolderName();
                    delete (*itrFoldersDelete);
                }
            }
        }break;
        case 2:{
        }break;
        case 3:{
        }break;
        case 4:{
        }break;
        case 5:{
        }break;
        case 6:{
        }break;
        case 7:{
        }break;
        case 8:{
        }break;
        case 9:{
        }break;
        case 10:{
        }break;
        case 11:{
        }break;
        case 12:{
        }break;
        case 13:{
        }break;
        default :{

        }
    }
}
