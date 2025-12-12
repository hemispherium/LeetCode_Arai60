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
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        while (head != nullptr) {
            st.push(head->val);
            head = head->next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (!st.empty()) {
            int num = st.top(); st.pop();
            curr->next = new ListNode(num);
            curr = curr->next;
        }
        return dummy->next;
    }
};
