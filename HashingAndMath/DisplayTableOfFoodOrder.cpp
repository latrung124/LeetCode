#include <vector>
#include <string>
#include <map>
#include <set>

class Solution {
public:
    std::vector<std::vector<std::string>> displayTable(std::vector<std::vector<std::string>>& orders) {
        std::map<int, std::map<std::string, int>> tables;
        std::set<std::string> foods;

        for (const auto& order : orders) {
            ++tables[std::stoi(order[1])][order[2]];
            foods.insert(order[2]);
        }
        std::vector<std::vector<std::string>> result;
        result.reserve(tables.size() + 1);
        
        std::vector<std::string> header;
        header.emplace_back("Table");
        header.insert(std::next(header.begin()), foods.begin(), foods.end());
        result.emplace_back(header);
        for (const auto& [t, m] : tables) {
            std::vector<std::string> temp;
            temp.emplace_back(std::to_string(t));
            for (const auto& food : foods) {
                if (m.count(food)) {
                    temp.emplace_back(std::to_string(m.at(food)));
                } else {
                    temp.emplace_back("0");
                }
            }
            result.emplace_back(temp);
        }
        return result;
    }
};