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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
    TreeNode* curr = root;

    while (curr != NULL || !s.empty()) {

        // Go as left as possible
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        // Process node
        curr = s.top();
        s.pop();
        ans.push_back(curr->val);

        // Move right
        curr = curr->right;
    }

    return ans;
    }
};