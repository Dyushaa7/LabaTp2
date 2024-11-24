#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>

class FileHandler {
private:
    char* filename;
public:
    FileHandler();
    FileHandler(const char* name);
    FileHandler(const FileHandler& other);
    ~FileHandler();

    void setFilename(const char* name);
    char* getFilename() const;
    char* readFile();
};

#endif // FIiLEHANDLER_H
