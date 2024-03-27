#include <iostream>

class Utility {
    public:
        Utility();
        void listArchiveFiles(const char* fileName);
        void createArchive(const char* outname,const char** fileNames);
        ~Utility();
};