#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        std::unordered_map<char, int> map;
        std::string firstRow = "qwertyuiop";
        std::string secondRow = "asdfghjkl";
        std::string thirdRow = "zxcvbnm";
        for (auto c : firstRow) {
            map[c] = 1;
        }
        for (auto c : secondRow) {
            map[c] = 2;
        }

        for (auto c : thirdRow) {
            map[c] = 3;
        }

        std::vector<std::string> result;
        for (const auto& word : words) {
            bool canType = true;
            int row = map[std::tolower(word[0])];
            for (auto c : word) {
                if (row != map[std::tolower(c)]) {
                    canType = false;
                    break;
                }
            }
            if (canType) result.push_back(word);
        }

        return result;
    }
};