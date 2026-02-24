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
    int f(string s) {
        int val = 0;
        for (int i = 0; i < s.length(); i++) {
            val = val * 2 + (s[i] - '0');
        }
        return val;
    }

    void dfs(TreeNode* root, string& str, int& ans) {
        if (!root)
            return;

        str.push_back(root->val + '0');

        if (!root->left && !root->right) {
            ans += f(str);
        } else {
            dfs(root->left, str, ans);
            dfs(root->right, str, ans);
        }

        str.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        string s="";
        dfs(root,s,ans);
        return ans;
    }
};
