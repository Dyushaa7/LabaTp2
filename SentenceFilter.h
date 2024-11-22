#ifndef SENTENCEFILTER_H
#define SENTENCEFILTER_H

#include <iostream>
#include <cstring>

class SentenceFilter {
private:
    char* text;
public:
    SentenceFilter(const char* inputText);
    SentenceFilter(const SentenceFilter& other);
    ~SentenceFilter();

    void filterSentences(const char* keyword);
};

#endif // SENTENCEFILTER_H
