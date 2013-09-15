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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
            return 0;
        int current = 0x7FFFFFFF;
        int depth = 1;
        minD(current,depth,root);
        return current;
    }
    void minD(int &current,int &depth,TreeNode *root){
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            if(current > depth)
                current = depth;
        }
        else
        {
            minD(current,++depth,root->left);
            --depth;
            minD(current,++depth,root->right);
            --depth;
        }
    }
};
