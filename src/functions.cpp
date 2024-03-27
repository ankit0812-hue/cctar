#include <iostream>
#include <cstring>
#include "../include/functions.h"
#include "../include/utility.h"
Functions::Functions() {
    argumentMap["-tf"] = 1;
    argumentMap["-cf"] = 2;
}
void Functions::parseArguments(int argc, char* argv[]) {
    int opt = argumentMap[argv[2]];
    Utility utility;
    switch(opt) {
        case 1:
            if(argc < 4) {
                std::cerr<<"cctar: option requires an argument -- 'f'"<<std::endl;
            }
            else {
                utility.listArchiveFiles(argv[3]);
            }
            break;
        case 2:
            if(argc < 4) {
                std::cerr<<"cctar: option requires an argument -- 'f'"<<std::endl;
            }
            else {
                int fileEntries = argc - 4 + 1;
                const char* fileNames[fileEntries];
                int fileEntry = 0;
                for(int i=4;i<argc;i++) {
                    fileNames[fileEntry] = argv[i];
                    fileEntry++;
                }
                fileNames[fileEntry] = nullptr;
                utility.createArchive(argv[3],fileNames);
            }
            break;
        default:
            std::cerr<<"Invalid Argument"<<std::endl;
    }
}
Functions::~Functions(){}

