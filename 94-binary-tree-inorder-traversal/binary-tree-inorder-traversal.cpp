class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        while (root != nullptr) {

            if (root->left == nullptr) {
                ans.push_back(root->val);
                root = root->right;
            }
            else {
                TreeNode* curr = root->left;

                // Find inorder predecessor
                while (curr->right != nullptr &&
                       curr->right != root) {
                    curr = curr->right;
                }

                if (curr->right == nullptr) {
                    curr->right = root;
                    root = root->left;
                }
                else {
                    curr->right = nullptr;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }

        return ans;
    }
};