/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void in(TreeNode *root){
       if (!root) 
        return;
        in(root->left);
        ans.push_back(root->val);
        in(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        in(root);
        int n=ans.size();
        int l=0,r=n-1;
        while(l<r){
            int s=ans[l]+ans[r];
            if(s==k){
                return true;
            }else if(s>k){
                r--;
            }
            else{
                l++;
            }
          
        }
    return false;
    }
};