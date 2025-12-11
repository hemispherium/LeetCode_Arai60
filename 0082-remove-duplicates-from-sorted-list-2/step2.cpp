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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1000);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            bool duplicated = false;

            while (curr->next != nullptr && curr->val == curr->next->val) {
                curr = curr->next;
                duplicated = true;
            }
            if (duplicated) prev->next = curr->next;
            else prev = prev->next;
            curr = curr->next;
        }
        return dummy.next;
    }
};