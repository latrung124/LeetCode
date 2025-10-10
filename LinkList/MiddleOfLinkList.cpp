struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            if (fast->next)
                fast = fast->next->next;
            else {
                fast = nullptr;
                break;
            }
            if (slow)
                slow = slow->next;
        }
        return slow;
    }
};