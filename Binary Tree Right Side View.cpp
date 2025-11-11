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
    vector<int> res;
    int level;
public:
    void dfs(TreeNode* node){
        if(node == nullptr){
            return;
        }
        if(res.size() < level){
            res.push_back(node->val);
        }
        level++;
        if(node->right != nullptr){
            dfs(node->right);
        }
        if(node->left != nullptr){
            dfs(node->left);
        }
        level--;
    }
    vector<int> rightSideView(TreeNode* root) {
        level = 1;
        dfs(root);
        return res;
    }
};
