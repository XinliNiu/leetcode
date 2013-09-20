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
    struct Index {
        int val;
        int index;
        Index( int a= 0, int b= 0 ):
        val(a), index(b) {}
    };
    struct cmp
    {
        bool operator()(Index a,Index b){
            return a.val > b.val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        ListNode *tmp_head = NULL;
        if(lists.size() == 0)
            return NULL;

        priority_queue<Index,vector<Index>,cmp> pq;
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i]) {
                Index a(lists[i]->val,i);
                pq.push(a);
            }    
        }
        while(!pq.empty()) {
            Index tmp = pq.top();
            pq.pop();
            ListNode *p = lists[tmp.index];
            lists[tmp.index] = p->next;
            if(lists[tmp.index]) {
                tmp.val = lists[tmp.index]->val;
                pq.push(tmp);
            }
            if(!head) {
                head = p;
                tmp_head = p;
            }
            else {
                tmp_head->next = p;
                tmp_head = tmp_head->next;
                tmp_head->next = NULL;
            }
        }
        return head;
        
    }

};
