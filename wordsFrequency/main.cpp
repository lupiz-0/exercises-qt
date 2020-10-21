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

using std::ifstream;
using std::string;
using std::cout;
using std::map;
using std::endl;
using std::pair;
using std::vector;
using std::ofstream;
using std::list;
using std::set;

std::size_t strlen_utf8(const std::string& str) {
    std::size_t length = 0;
    for (char c : str) {
        if ((c & 0xC0) != 0x80) {
            ++length;
        }
    }
    return length;
}

void addToFirstTen(vector<pair<string, int>>& words, const string& word, int frequency) {
    bool inserted = false;

    for(ulong i = 0; i < words.size(); i++) {
        if(frequency > words[i].second)
        {
            auto it = words.begin() + i;
            words.insert(it, pair(word, frequency));
            inserted = true;
            break;
        }
    }

    if(!inserted)
        words.push_back(pair(word, frequency));

    if(words.size() > 10)
        words.pop_back();
}

void printTenMostFrequent(const string& fileName, vector<pair<string, int>>& firstTen) {
    map<string, int> words;

    ifstream file;
    file.open (fileName);

    string word;
    while (file >> word)
    {
        if(strlen_utf8(word) > 3)
            words[word]++;
    }

    for (map<string, int>::iterator it = words.begin(); it != words.end(); it++ )
        addToFirstTen(firstTen, it->first, it->second);


    cout << endl << "start:" << endl;
    for(ulong i = 0; i < firstTen.size(); i++) {
        cout << firstTen[i].first << " " << firstTen[i].second << endl;
    }

    file.close();
}

void compare(const string& word, const vector<pair<string, int>>& firstTen, const vector<pair<string, int>>& firstTenWithoutPunctuation, set<string>& alreadyComparedWords) {
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
            cout << word << " is present in both and with the same frequency: " << frequencyWithPunctuation.value() << endl;

        if(frequencyWithPunctuation.has_value()
            && frequencyWithoutPunctuation.has_value()
            && frequencyWithPunctuation.value() != frequencyWithoutPunctuation.value())
            cout << word << " is present in both but with different frequency: " << frequencyWithPunctuation.value() << " " << frequencyWithoutPunctuation.value() << endl;

        if(frequencyWithPunctuation.has_value()
            && !frequencyWithoutPunctuation.has_value())
            cout << word << " is present only with punctuation: " << frequencyWithPunctuation.value() << endl;

        if(frequencyWithoutPunctuation.has_value()
            && !frequencyWithPunctuation.has_value())
            cout << word << " is present only without punctuation: " << frequencyWithoutPunctuation.value() << endl;
   }
}

int main()
{
    vector<pair<string, int>> firstTen;
    vector<pair<string, int>> firstTenWithoutPunctuation;
    set<string> alreadyComparedWords;


    string nameFileWithoutPunctuation = "file without punctuation.txt";
    string nameOriginalFile = "canto1.txt";
    printTenMostFrequent(nameOriginalFile, firstTen);

    string specialPunctuation = "’";

    ofstream fileWithoutPunctuation;
    fileWithoutPunctuation.open (nameFileWithoutPunctuation);
    ifstream file;
    file.open (nameOriginalFile);
    char character;
    list<char> charactersBuffer;
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

    cout << endl << "compare: " << endl;
    for(ulong i = 0; i < firstTen.size(); i++)
        compare(firstTen[i].first, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);
    for(ulong i = 0; i < firstTenWithoutPunctuation.size(); i++)
        compare(firstTenWithoutPunctuation[i].first, firstTen, firstTenWithoutPunctuation, alreadyComparedWords);

    return 0;
}
