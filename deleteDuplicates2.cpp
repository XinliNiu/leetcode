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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || !head->next) return head;
        if(head->val == head->next->val)
        {
            ListNode *tmp1 = head;
            while(head && head->val == tmp1->val)
                head = head->next;
            while(tmp1 != head)
            {
                ListNode *tmp2 = tmp1;
                tmp1 = tmp1->next;
                delete tmp2;
            }
            return deleteDuplicates(head);
        }
        else
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
