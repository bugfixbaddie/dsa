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
      int findPos(int in[], int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == target)
                return i;
        }
        return -1;
    }
     TreeNode* build(int in[], int pre[], int instart, int inend, int &preIndex) {

        // No elements left in this subtree
        if (instart > inend)
            return NULL;

        // Preorder tells us the ROOT
        TreeNode* root = new TreeNode(pre[preIndex]);

        // Move to the next preorder element
        preIndex++;

        // Find root's position in inorder
        int pos = findPos(in, root->val, instart, inend);

        // Everything LEFT of root in inorder belongs to left subtree
        root->left = build(in, pre, instart, pos - 1, preIndex);

        // Everything RIGHT of root in inorder belongs to right subtree
        root->right = build(in, pre, pos + 1, inend, preIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
           int n = inorder.size();
           int  preIndex=0;
             
               return build(inorder.data(), preorder.data(), 0, n - 1, preIndex);
    }
};