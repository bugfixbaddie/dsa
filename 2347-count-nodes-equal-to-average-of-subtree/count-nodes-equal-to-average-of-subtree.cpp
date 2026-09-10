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
    pair<int, int> dfs(TreeNode* root, int &ans) {
        if (root == nullptr) {
            return {0, 0};
        }
        
        pair<int, int> left = dfs(root->left, ans);
        pair<int, int> right = dfs(root->right, ans);

        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;
        

        if (sum / count == root->val) {
            ++ans;
        }
        
        return {sum, count};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
