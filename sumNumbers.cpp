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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        sum(root,0,result);
        return result;
    }
    void sum(TreeNode *root, int num,int &result){
        if(!root)
            return;
        if(!root->left && !root->right)
            result += num * 10 + root->val;
        else{
            sum(root->left,num*10+root->val,result);
            sum(root->right,num*10+root->val,result);        
        }
            
    }
};
