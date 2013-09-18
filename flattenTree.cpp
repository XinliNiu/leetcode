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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root){
            flatten(root->left);
            flatten(root->right);
            if(root->left) {
                TreeNode *r = root->right;
                TreeNode *l = root->left;
                root->right = l;
                root->left = NULL;
                while(l->right)                    
                    l = l->right;
                l->right = r;
            }
        }
    }
};
