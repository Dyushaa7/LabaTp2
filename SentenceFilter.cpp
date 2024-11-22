#include "SentenceFilter.h"

SentenceFilter::SentenceFilter(const char* inputText) {
    std::cout << "Konstruktor SentenceFilter vyzvan." << std::endl;
    text = new char[strlen(inputText) + 1];
    strcpy(text, inputText);
}

SentenceFilter::SentenceFilter(const SentenceFilter& other) {
    std::cout << "Konstruktor kopirovaniya SentenceFilter vyzvan." << std::endl;
    text = new char[strlen(other.text) + 1];
    strcpy(text, other.text);
}

SentenceFilter::~SentenceFilter() {
    std::cout << "Destuktor SentenceFilter vyzvan." << std::endl;
    delete[] text;
}

void SentenceFilter::filterSentences(const char* keyword) {
    char* sentence = strtok(text, ".");
    while (sentence) {
        if (strstr(sentence, keyword)) {
            std::cout << sentence << "." << std::endl;
        }
        sentence = strtok(nullptr, ".");
    }
}
