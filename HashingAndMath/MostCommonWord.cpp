#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        std::unordered_map<std::string, int> freq;
        std::unordered_set<std::string> bannedSet(banned.begin(), banned.end());

        std::string word;
        paragraph += ".";
        for (char c : paragraph) {
            if (std::isalpha(c)) {
                word += std::tolower(c);
            } else {
                if (!word.empty() && bannedSet.find(word) == bannedSet.end()) {
                    ++freq[word];
                }
                word = "";
            }
        }

        std::string result = "";
        int maxFreq = 0;
        for (const auto& pair : freq) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
                result = pair.first;
            }
        }
        return result;
    }
};