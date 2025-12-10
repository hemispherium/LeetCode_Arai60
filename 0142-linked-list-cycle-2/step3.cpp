/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> used;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (used.count(curr)) return curr;
            used.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};