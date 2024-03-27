#include <iostream>
#include <map>
class Functions {
    public:
        Functions();
        void parseArguments(int argc, char* argv[]);
        ~Functions();
    private:
        std::map<std::string, uint8_t> argumentMap;
};