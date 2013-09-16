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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        if(!head->next){
            free(head);
            return NULL;
        }
        ListNode *p1 = head;
        ListNode *p2 = head;
        int i;
        for(i = 0; p2 && i <=n; i++){
            p2 = p2->next;
        }
        if(!p2 && i <= n ){
            head = head->next;
            free(p1);
            return head;
        }
        while(p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *tmp = p1->next->next;
        free(p1->next);
        p1->next = tmp;
        return head;
    }
};
