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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *p1 = NULL,*p2=NULL,*p3=NULL;
        inorder(root,p1,p2,p3);
        swap(p2->val,p3->val);
    }
    void inorder(TreeNode* root, TreeNode *&p1,TreeNode *&p2, TreeNode *&p3) {
        if(!root) return;
        inorder(root->left,p1,p2,p3);
        if(p1) {
            if(p1->val > root->val) {
                if(p2) {
                    p3 = root;
                    return;
                }
                    
                else {
                    p2 = p1;
                    p3 = root;
                }
                    
            }
        }
        p1 = root;
        inorder(root->right,p1,p2,p3);
    }
};
