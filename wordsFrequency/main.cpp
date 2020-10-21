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

std::size_t strlen_utf8(const std::string& str) {
    std::size_t length = 0;
    for (char c : str) {
        if ((c & 0xC0) != 0x80) {
            ++length;
        }
    }
    return length;
}

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

void printTenMostFrequent(const std::string& fileName, std::vector<std::pair<std::string, int>>& firstTen) {
    std::map<std::string, int> words;

    std::ifstream file;
    file.open (fileName);

    std::string word;
    while (file >> word)
    {
        if(strlen_utf8(word) > 3)
            words[word]++;
    }

    for (std::map<std::string, int>::iterator it = words.begin(); it != words.end(); it++ )
        addToFirstTen(firstTen, it->first, it->second);


    std::cout << '\n' << "start:" << '\n';
    for(ulong i = 0; i < firstTen.size(); i++) {
        std::cout << firstTen[i].first << " " << firstTen[i].second << '\n';
    }

    file.close();
}

void compare(const std::string& word, const std::vector<std::pair<std::string, int>>& firstTen, const std::vector<std::pair<std::string, int>>& firstTenWithoutPunctuation, std::set<std::string>& alreadyComparedWords) {
   if(alreadyComparedWords.find(word) == alreadyComparedWords.end()) {
        alreadyComparedWords.insert(word);

        std::optional<int> frequencyWithPunctuation;
        std::optional<int> frequencyWithoutPunctuation;
        for(ulong i = 0; i < firstTen.size(); i++)
        {
            if(firstTen[i].first == word) {
                frequencyWithPunctuation = firstTen[i].second;
                break;
            }
        }

        for(ulong i = 0; i < firstTenWithoutPunctuation.size(); i++)
        {
            if(firstTenWithoutPunctuation[i].first == word) {
                frequencyWithoutPunctuation = firstTenWithoutPunctuation[i].second;
                break;
            }
        }

        if(frequencyWithPunctuation.has_value()
            && frequencyWithoutPunctuation.has_value()
            && frequencyWithPunctuation.value() == frequencyWithoutPunctuation.value())
            std::cout << word << " is present in both and with the same frequency: " << frequencyWithPunctuation.value() << '\n';

        if(frequencyWithPunctuation.has_value()
            && frequencyWithoutPunctuation.has_value()
            && frequencyWithPunctuation.value() != frequencyWithoutPunctuation.value())
            std::cout << word << " is present in both but with different frequency: " << frequencyWithPunctuation.value() << " " << frequencyWithoutPunctuation.value() << '\n';

        if(frequencyWithPunctuation.has_value()
            && !frequencyWithoutPunctuation.has_value())
            std::cout << word << " is present only with punctuation: " << frequencyWithPunctuation.value() << '\n';

        if(frequencyWithoutPunctuation.has_value()
            && !frequencyWithPunctuation.has_value())
            std::cout << word << " is present only without punctuation: " << frequencyWithoutPunctuation.value() << '\n';
   }
}

int main()
{
    std::vector<std::pair<std::string, int>> firstTen;
    std::vector<std::pair<std::string, int>> firstTenWithoutPunctuation;
    std::set<std::string> alreadyComparedWords;


    std::string nameFileWithoutPunctuation = "file without punctuation.txt";
    std::string nameOriginalFile = "canto1.txt";
    printTenMostFrequent(nameOriginalFile, firstTen);

    std::string specialPunctuation = "’";

    std::ofstream fileWithoutPunctuation;
    fileWithoutPunctuation.open (nameFileWithoutPunctuation);
    std::ifstream file;
    file.open (nameOriginalFile);
    char character;
    std::list<char> charactersBuffer;
    int writingJumpCountdown = 0;
    while (file.get(character)) {
        charactersBuffer.push_back(character);
        if(charactersBuffer.size() > 3)
            charactersBuffer.pop_front();
        if(charactersBuffer.size() == 3) {

            auto iterator0 = charactersBuffer.begin();
            auto iterator1 = charactersBuffer.begin();
            std::advance(iterator1, 1);
            auto iterator2 = charactersBuffer.begin();
            std::advance(iterator2, 2);

            if(*iterator0 == specialPunctuation[0] && *iterator1 == specialPunctuation[1] && *iterator2 == specialPunctuation[2])
            {
                writingJumpCountdown = 3;
                fileWithoutPunctuation << " ";
            }

            if(ispunct(*iterator0)) {
                writingJumpCountdown = 1;
                fileWithoutPunctuation << " ";
            }

            if(writingJumpCountdown == 0)
                fileWithoutPunctuation << *charactersBuffer.begin();
            writingJumpCountdown = std::clamp(writingJumpCountdown - 1, 0, std::numeric_limits<int>::max());
        }
    }

    while (charactersBuffer.size() > 1) {
        charactersBuffer.pop_front();
        fileWithoutPunctuation << *charactersBuffer.begin();
    }

    fileWithoutPunctuation.close();
    file.close();


    printTenMostFrequent(nameFileWithoutPunctuation, firstTenWithoutPunctuation);

    std::cout << '\n' << "compare: " << '\n';
    for(ulong i = 0; i < firstTen.size(); i++)
        compare(firstTen[i].first, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);
    for(ulong i = 0; i < firstTenWithoutPunctuation.size(); i++)
        compare(firstTenWithoutPunctuation[i].first, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);

    return 0;
}
