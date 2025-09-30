#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> setNums(nums.begin(), nums.end());
        return setNums.size() != nums.size();
    }
};