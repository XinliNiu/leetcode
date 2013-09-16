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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || !head->next) return head;
        if(m == n) return head;
        ListNode *before_start = NULL;
        ListNode *start,*end;
        if(m == 1)
        {
            before_start = NULL;
            start = head;
        }
        else
        {
            before_start = head;
            start = head->next;
            for(int i = 3; i <= m; i++)
            {
                before_start = before_start->next;
                start = start->next;
            }
        }
        if(start == NULL)
            return head;
        ListNode *p1 = start;
        ListNode *p2 = start->next;
        if(p2 == NULL)
            return head;
        for(int i = m; i < n; i++)
        {
            end = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = end;
        }
        start->next = end;
        if(before_start == NULL)
            return p1;
        else
        {
            before_start->next = p1;
            return head;
        }
            
        
    }
};
