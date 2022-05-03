#include <iostream>

using namespace std;


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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:ListNode* result;
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = nullptr;
        if (list1 != nullptr && list2 == nullptr) return list1;
        if (list2 != nullptr && list1 == nullptr) return list2;
        if (!list1 && !list2) return nullptr;
        ListNode* cache1 = new ListNode();
        if (list1->val <= list2->val) {           
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }
        return result;
    }
    void pushTheList(ListNode* list) {

    }
    void showTheList(ListNode* list) {
        if (list) {
            cout << list->val << " ";
            showTheList(list->next);
        }
    }
};
//int main() {
//    //list 1
//    ListNode* node1 = new ListNode(1);
//    ListNode* node2 = new ListNode(2);
//    ListNode* node3 = new ListNode(4);
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = nullptr;
//    //list 2
//    ListNode* node4 = new ListNode(1);
//    ListNode* node5 = new ListNode(3);
//    ListNode* node6 = new ListNode(4);
//    node4->next = node5;
//    node5->next = node6;
//    node6->next = nullptr;
//    Solution s;
//    ListNode* r = s.mergeTwoLists(node1, node4);
//    s.showTheList(r);
//	return 0;
//}