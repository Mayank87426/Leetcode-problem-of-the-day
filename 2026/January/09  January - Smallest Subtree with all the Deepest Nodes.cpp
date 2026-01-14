class Solution {
public:
    void calcDepthOfEachNode(TreeNode* root,
                             unordered_map<TreeNode*, int>& mp,
                             int depth,
                             int& maxDepth) {
        if (!root) return;

        mp[root] = depth;
        maxDepth = max(maxDepth, depth);

        calcDepthOfEachNode(root->left, mp, depth + 1, maxDepth);
        calcDepthOfEachNode(root->right, mp, depth + 1, maxDepth);
    }

    TreeNode* lcaOfDeepestNodes(TreeNode* root,
                                unordered_map<TreeNode*, int>& mp,
                                int maxDepth) {
        if (!root) return nullptr;

        if (mp[root] == maxDepth)
            return root;

        TreeNode* left = lcaOfDeepestNodes(root->left, mp, maxDepth);
        TreeNode* right = lcaOfDeepestNodes(root->right, mp, maxDepth);

        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        int maxDepth = 0;

        calcDepthOfEachNode(root, mp, 0, maxDepth);
        return lcaOfDeepestNodes(root, mp, maxDepth);
    }
};
