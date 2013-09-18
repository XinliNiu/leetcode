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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max,min;
        if(!root)
            return true;
        return isBST(root,max,min);
    }
    bool isBST(TreeNode *root,int &max,int &min) {
        if(!root) 
            return true;
        if(!root->left && !root->right) {
            max = root->val;
            min = root->val;
            return true;
        }
        int l_max,l_min,r_max,r_min;

        if(isBST(root->left,l_max,l_min) && isBST(root->right,r_max,r_min)) {
            if(!root->left) {
                if(root->val < r_min) {
                    min = root->val;
                    max = r_max;
                    return true;
                }
            }
            else if(!root->right) {
                if(root->val > l_max) {
                    min = l_min;
                    max = root->val;
                    return true;
                }
            }
            else if(root->val > l_max && root->val < r_min) {
                min = l_min;
                max = r_max;
                return true;
            }
            return false;
        }
        return false;
    }
};
