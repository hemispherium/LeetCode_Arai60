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

// ↓ 最初このコードを書いていて、L30-L32あたりで、ListNode temp(0)を作ってそれをcurr->nextにつなげていけばうまく動くかなと思ったけどエラーが出てうまく動かず、修正する方法を思いつかなくてChatGPTに聞いた。

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sum(0);
        ListNode* curr = &sum;
        ListNode* num1 = l1;
        ListNode* num2 = l2;

        int carryOver = 0;
        while (num1 != nullptr || num2 != nullptr) {
            int sumOfTheDigits = 0;
            if (num1 != nullptr) sumOfTheDigits += num1->val;
            if (num2 != nullptr) sumOfTheDigits += num2->val;
            sumOfTheDigits += carryOver;
            curr->val = sumOfTheDigits % 10;
            carryOver = sumOfTheDigits / 10;
            ListNode temp(0);
            curr->next = &temp;
            curr = curr->next;
            if (num1 != nullptr) num1 = num1->next;
            if (num2 != nullptr) num2 = num2->next;
        }
        return &sum;
    }
};

// ChatGPTに直してもらってスッキリしたのが以下のコード

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
        }

        return dummy->next;
    }
};
