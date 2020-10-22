#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <vector>
#include <cctype>
#include <list>
#include <algorithm>
#include <limits>
#include <optional>
#include <set>
#include <cassert>

struct WordAndFrequency {
    std::string word;
    int frequency;
};

void addToFirstTen(std::vector<WordAndFrequency>& words, const std::string& word, int frequency) {
    bool inserted = false;

    for(size_t i = 0; i < words.size(); i++) {
        if(frequency > words[i].frequency)
        {
            auto it = words.begin() + i;
            words.insert(it, {word, frequency});
            inserted = true;
            break;
        }
    }

    if(!inserted)
        words.push_back({word, frequency});

    if(words.size() > 10)
        words.pop_back();
}

void collectMostFrequent(const std::string& fileName, std::vector<WordAndFrequency>& firstTen) {
    std::map<std::string, int> words;

    std::ifstream file;
    file.open (fileName);

    std::string word;
    while (file >> word)
    {
        if(word.length() > 3)
            words[word]++;
    }
    file.close();

    for (std::map<std::string, int>::iterator it = words.begin(); it != words.end(); it++ )
        addToFirstTen(firstTen, it->first, it->second);

    std::cout << "start:\n";
    for(const auto& wordAndFrequency: firstTen)
        std::cout << wordAndFrequency.word << " " << wordAndFrequency.frequency << '\n';
}

std::optional<int> getFrequency(const std::vector<WordAndFrequency>& array, const std::string& word) {
    for(const auto& wordAndFrequency: array) {
        if(wordAndFrequency.word == word)
            return std::optional<int>(wordAndFrequency.frequency);
    }
    return std::optional<int>();
}

void compare(const std::string& word, const std::vector<WordAndFrequency>& firstTen, const std::vector<WordAndFrequency>& firstTenWithoutPunctuation) {
    std::optional<int> frequencyWithPunctuation = getFrequency(firstTen, word);
    std::optional<int> frequencyWithoutPunctuation = getFrequency(firstTenWithoutPunctuation, word);

    if(frequencyWithPunctuation.has_value() && frequencyWithoutPunctuation.has_value())
    {
        if(frequencyWithPunctuation.value() == frequencyWithoutPunctuation.value())
            std::cout << word << " is present in both and with the same frequency: " << frequencyWithPunctuation.value() << '\n';
        else
            std::cout << word << " is present in both but with different frequency: " << frequencyWithPunctuation.value() << " " << frequencyWithoutPunctuation.value() << '\n';
    }
    else if(frequencyWithPunctuation.has_value() && !frequencyWithoutPunctuation.has_value())
        std::cout << word << " is present only with punctuation: " << frequencyWithPunctuation.value() << '\n';
    else if(frequencyWithoutPunctuation.has_value() && !frequencyWithPunctuation.has_value())
        std::cout << word << " is present only without punctuation: " << frequencyWithoutPunctuation.value() << '\n';
    else
        assert(false);
}

void compareIfNotAlreadyCompared(const std::string& word, const std::vector<WordAndFrequency>& firstTen, const std::vector<WordAndFrequency>& firstTenWithoutPunctuation, std::set<std::string>& alreadyComparedWords) {
   if(alreadyComparedWords.find(word) == alreadyComparedWords.end()) {
        alreadyComparedWords.insert(word);
        compare(word, firstTen, firstTenWithoutPunctuation);
   }
}

void creationFileWithoutPunctuation(const std::string& nameOriginalFile, const std::string& nameFileWithoutPunctuation) {
    std::ofstream fileWithoutPunctuation;
    fileWithoutPunctuation.open (nameFileWithoutPunctuation);
    std::ifstream file;
    file.open(nameOriginalFile);
    char character;
    while (file.get(character)) {
        if(ispunct(character))
            fileWithoutPunctuation << " ";
        else
            fileWithoutPunctuation << character;
    }

    fileWithoutPunctuation.close();
    file.close();
}

int main()
{
    std::vector<WordAndFrequency> firstTen;
    std::string nameOriginalFile = "canto1.txt";
    collectMostFrequent(nameOriginalFile, firstTen);

    std::string nameFileWithoutPunctuation = "file without punctuation.txt";
    creationFileWithoutPunctuation(nameOriginalFile, nameFileWithoutPunctuation);

    std::vector<WordAndFrequency> firstTenWithoutPunctuation;
    std::cout << '\n';
    collectMostFrequent(nameFileWithoutPunctuation, firstTenWithoutPunctuation);

    std::set<std::string> alreadyComparedWords;
    std::cout << "\ncompare:\n";
    for(const auto& wordAndFrequency: firstTen)
        compareIfNotAlreadyCompared(wordAndFrequency.word, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);
    for(const auto& wordAndFrequency: firstTenWithoutPunctuation)
        compareIfNotAlreadyCompared(wordAndFrequency.word, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);

    return 0;
}
