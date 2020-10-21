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

void addToFirstTen(std::vector<std::pair<std::string, int>>& words, const std::string& word, int frequency) {
    bool inserted = false;

    for(ulong i = 0; i < words.size(); i++) {
        if(frequency > words[i].second)
        {
            auto it = words.begin() + i;
            words.insert(it, std::pair(word, frequency));
            inserted = true;
            break;
        }
    }

    if(!inserted)
        words.push_back(std::pair(word, frequency));

    if(words.size() > 10)
        words.pop_back();
}

void collectMostFrequent(const std::string& fileName, std::vector<std::pair<std::string, int>>& firstTen) {
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
    for(ulong i = 0; i < firstTen.size(); i++) {
        std::cout << firstTen[i].first << " " << firstTen[i].second << '\n';
    }
}

std::optional<int> getFrequency(const std::vector<std::pair<std::string, int>>& array, const std::string& word) {
    for(ulong i = 0; i < array.size(); i++) {
        if(array[i].first == word)
            return std::optional<int>(array[i].second);
    }
    return std::optional<int>();
}

void compare(const std::string& word, const std::vector<std::pair<std::string, int>>& firstTen, const std::vector<std::pair<std::string, int>>& firstTenWithoutPunctuation) {
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

void compareIfNotAlreadyCompared(const std::string& word, const std::vector<std::pair<std::string, int>>& firstTen, const std::vector<std::pair<std::string, int>>& firstTenWithoutPunctuation, std::set<std::string>& alreadyComparedWords) {
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
    std::vector<std::pair<std::string, int>> firstTen;
    std::string nameOriginalFile = "canto1.txt";
    collectMostFrequent(nameOriginalFile, firstTen);

    std::string nameFileWithoutPunctuation = "file without punctuation.txt";
    creationFileWithoutPunctuation(nameOriginalFile, nameFileWithoutPunctuation);

    std::vector<std::pair<std::string, int>> firstTenWithoutPunctuation;
    std::cout << '\n';
    collectMostFrequent(nameFileWithoutPunctuation, firstTenWithoutPunctuation);

    std::set<std::string> alreadyComparedWords;
    std::cout << "\ncompare:\n";
    for(ulong i = 0; i < firstTen.size(); i++)
        compareIfNotAlreadyCompared(firstTen[i].first, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);
    for(ulong i = 0; i < firstTenWithoutPunctuation.size(); i++)
        compareIfNotAlreadyCompared(firstTenWithoutPunctuation[i].first, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);

    return 0;
}
