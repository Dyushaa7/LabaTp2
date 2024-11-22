#include "FileHandler.h"
#include "SentenceFilter.h"

int main() {
    try {
        char filename[100];
        std::cout << "Vvedite imya fayla: ";
        std::cin >> filename;

        FileHandler fileHandler(filename);
        char* content = fileHandler.readFile();

        char keyword[50];
        std::cout << "Vvedite slovo dlya poiska: ";
        std::cin >> keyword;

        SentenceFilter filter(content);
        filter.filterSentences(keyword);

        delete[] content;
    } catch (const std::exception& e) {
        std::cerr << "Oshibka: " << e.what() << std::endl;
    }

    return 0;
}
