/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        if (!head) return nullptr;
        std::unordered_set<int> setNums(nums.begin(), nums.end());
        auto curr = head;
        ListNode* previous = nullptr;
        while (curr) {
            if (setNums.count(curr->val) > 0) {
                if (previous) {
                    previous->next = curr->next;
                } else {
                    head = head->next;
                    curr = head;
                    continue;
                }
            } else {
                previous = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};