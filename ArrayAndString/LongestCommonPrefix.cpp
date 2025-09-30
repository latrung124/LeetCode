#include <string>
#include <vector>

class Solution {
public:
    std::string checkString(const std::string& first, const std::string& second) {
        size_t size = first.size() > second.size() ? second.size() : first.size();
        std::string prefix = "";
        for (int i = 0; i < size; ++i) {
            if (first[i] != second[i]) break;
            prefix += first[i];
        }
        return prefix;
    }

    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        std::string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            prefix = checkString(prefix, strs[i]);
            if (prefix.empty()) return "";
        }

        return prefix;
    }
};