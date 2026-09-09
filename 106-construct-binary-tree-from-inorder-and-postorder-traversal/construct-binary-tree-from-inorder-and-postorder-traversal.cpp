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
     TreeNode* build(int in[], int post[], int instart, int inend, int &postIndex) {

        // No elements left in this subtree
        if (instart > inend)
            return NULL;

        // Preorder tells us the ROOT
        TreeNode* root = new TreeNode(post[postIndex]);

        // Move to the next preorder element
        postIndex--;

        // Find root's position in inorder
        int pos = findPos(in, root->val, instart, inend);
         // Everything RIGHT of root in inorder belongs to right subtree
        root->right = build(in, post, pos + 1, inend, postIndex);

        // Everything LEFT of root in inorder belongs to left subtree
        root->left = build(in, post, instart, pos - 1, postIndex);

       

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          int postIndex = postorder.size() - 1;
           return build(inorder.data(), postorder.data(), 0, inorder.size() - 1, postIndex);
    }

    
};