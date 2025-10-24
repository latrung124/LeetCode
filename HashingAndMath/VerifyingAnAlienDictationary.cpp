#include <vector>
#include <unordered_map>

class Solution {
    std::unordered_map<char, int> map;
    bool compare(const std::string& word1, const std::string& word2) {
        int min = std::min(word1.size(), word2.size());
        for (int i = 0; i < min; ++i) {
            char char1 = word1[i];
            char char2 = word2[i];

            if (char1 == char2) continue;
            if (map[char1] > map[char2]) return false;
            else return true;
        }
        return word1.size() <= word2.size();
    }
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        if (words.empty()) return true;
        for (int i = 0; i < order.size(); ++i) {
            map[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            auto const& word1 = words[i];
            auto const& word2 = words[i + 1];
            if (!compare(word1, word2)) return false;
        }
        return true;
    }
};