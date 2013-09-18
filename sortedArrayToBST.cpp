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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(num,0,num.size()-1);
        
    }
    TreeNode *build(vector<int> &num, int i,int j) {
        if(i > j)
            return NULL;
        TreeNode * root = new TreeNode(num[(i+j)/2]);
        root->left = build(num,i,(i+j)/2-1);
        root->right = build(num,(i+j)/2+1,j);
        return root;
    }
};
