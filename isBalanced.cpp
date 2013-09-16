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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int depth = 0;
        return balanced(root,depth);
    }
    bool balanced(TreeNode *root,int &depth){
        if(!root){
            depth = 0;
            return true;
        }
        if(!root->left && !root->right){
            depth = 1;
            return true;
        }
        int d1,d2;
        if(balanced(root->left,d1) && balanced(root->right,d2))
        {
            if(abs(d1-d2) <= 1){
                depth = 1+max(d1,d2);
                return true;
            }
            return false;
        }
        return false;
    }
};
