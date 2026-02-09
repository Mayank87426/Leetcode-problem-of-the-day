/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBSTFromInorder(const vector<int>& inorder, int l, int r) {
        if (l > r)
            return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = buildBSTFromInorder(inorder, l, mid - 1);
        root->right = buildBSTFromInorder(inorder, mid + 1, r);

        return root;
    }

    TreeNode* constructBSTFromInorder(const vector<int>& inorder) {
        return buildBSTFromInorder(inorder, 0, inorder.size() - 1);
    }

    void inorderHelper(TreeNode* root, vector<int>& res) {
        if (!root)
            return;
        inorderHelper(root->left, res);
        res.push_back(root->val);
        inorderHelper(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderHelper(root, res);
        return res;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root);
       return  constructBSTFromInorder(inorder);
        
    }
};
