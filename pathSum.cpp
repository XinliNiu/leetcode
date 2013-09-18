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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if(!root)
            return result;
        vector<int> current_path;
        judge(root,sum,0,current_path,result);
        return result;
    }
    void judge(TreeNode *root,int sum,int current,vector<int> &current_path, vector<vector<int> > &result) {
  
        if(!root ) return;
        if(!root->left && !root->right) {
            if (current + root->val == sum)
            {
                vector<int> new_path(current_path.begin(),current_path.end());
                new_path.push_back(root->val);
                result.push_back(new_path);
                return;
            }
        }
        current_path.push_back(root->val);
        judge(root->left,sum,current+root->val,current_path,result);
        judge(root->right,sum,current+root->val,current_path,result);
        current_path.pop_back();
        
    }
};
