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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode * head=NULL,*tmp = NULL;
        if(!l1 && !l2)
            return NULL;
        int carry = 0;
        for( ; l1 && l2; l1=l1->next,l2=l2->next)
        {
            if(!tmp)
            {
                tmp = new ListNode((l1->val+l2->val)%10);
                carry = (l1->val+l2->val)/10;
                head = tmp;
            }
            else
            {
                tmp->next = new ListNode((l1->val+l2->val+carry)%10);
                carry = (l1->val + l2->val + carry) / 10;
                tmp = tmp->next;
            }
            

        }
        while(l1)
        {
            tmp->next = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            tmp = tmp->next;
        }
        while(l2)
        {
            tmp->next = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            tmp = tmp->next;
        }
        if(carry)
            tmp->next = new ListNode(carry);
            
        return head;
    }
};
