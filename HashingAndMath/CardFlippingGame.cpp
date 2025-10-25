#include <vector>
#include <unordered_set>
#include <climits>

class Solution {
public:
    int flipgame(std::vector<int>& fronts, std::vector<int>& backs) {
        std::unordered_set<int> bannedCards;
        size_t size = fronts.size();
        for (int i = 0; i < size; ++i) {
            if (fronts[i] == backs[i]) bannedCards.insert(fronts[i]);
        }

        int result = INT_MAX;
        for (int i = 0; i < size; ++i) {
            int front = fronts[i];
            if (!bannedCards.count(front)) {
                result = std::min(result, front);
            }

            int back = backs[i];
            if (!bannedCards.count(back)) {
                result = std::min(result, back);
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};