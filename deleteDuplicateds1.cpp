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
        ListNode *current = head;
        for(ListNode *p = current->next; p; p = p->next){
            while(p && p->val == current->val){
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            if(!p)
            {
                current->next = NULL;
                return head;
            }
            current->next = p;
            current = current->next;
        }
        return head;
    }
};
