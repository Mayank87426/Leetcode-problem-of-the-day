class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subTreeSum = left + right + root->val;

        // Try cutting above this subtree
        maxProd = max(maxProd, subTreeSum * (totalSum - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        // First pass: compute total sum
        totalSum = dfsSum(root);

        // Second pass: compute max product
        dfs(root);

        return maxProd % MOD;
    }

private:
    long long dfsSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + dfsSum(root->left) + dfsSum(root->right);
    }
};
