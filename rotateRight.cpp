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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || !head->next)
            return head;
        if(k == 0)
            return head;
        ListNode *p1 = head,*p2 = head;
        int i;
        int len = 0;
        for(;p2;p2 = p2->next){
            len++;
        }
        k = k % len;
        p2 = head;
        for(i = 1; p2->next && i <= k; i++){
            p2 = p2->next;
        }
        if(i <= k)
            return head;
        while(p2->next){
            p2 = p2->next;
            p1 = p1->next;
        }
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
        return head;
    }
};
