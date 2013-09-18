/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return false;
        bool flag = 0;
        judge(root,sum,0,flag);
        return flag;
    }
    void judge(TreeNode *root,int sum,int current,bool &flag) {
        if(flag) return;
        if(!root ) return;
        if(!root->left && !root->right) {
            if (current + root->val == sum)
            {
                flag = true;
                return;
            }
        }
        judge(root->left,sum,current+root->val,flag);
        judge(root->right,sum,current+root->val,flag);
        
    }
};
