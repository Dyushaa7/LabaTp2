#include "FileHandler.h"
#include <cstring> // Необходим для strcpy и strlen
#include <stdexcept> // Для std::runtime_error
#include <iostream>
#include <fstream>
#include <string> // Необходим для работы с std:string

FileHandler::FileHandler() : filename(nullptr) {
    std::cout << "Konstruktor po umolchaniyu FileHandler vyzvan." << std::endl;
}

FileHandler::FileHandler(const char* name) {
    std::cout << "Konstruktor s parametrami FileHandler vyzvan." << std::endl;
    setFilename(name);
}

FileHandler::FileHandler(const FileHandler& other) {
    std::cout << "Konstruktor kopirovaniya FileHandler vyzvan." << std::endl;
    if (other.filename) {
        filename = new char[strlen(other.filename) + 1];
        strcpy(filename, other.filename);
    } else {
        filename = nullptr;
    }
}

FileHandler::~FileHandler() {
    std::cout << "Destuktor FileHandler vyzvan." << std::endl;
    delete[] filename;
}

void FileHandler::setFilename(const char* name) {
    if (filename) delete[] filename;
    filename = new char[strlen(name) + 1];
    strcpy(filename, name);
}

char* FileHandler::getFilename() const {
    return filename;
}

char* FileHandler::readFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ne udalos' otkryt' fayl.");
    }

    std::string content;
    std::string line;
    while (std::getline(file, line)) { // Используйте std:getline
        content += line + "\n";
    }
    file.close();

    char* result = new char[content.length() + 1];
    strcpy(result, content.c_str());
    return result;
}
