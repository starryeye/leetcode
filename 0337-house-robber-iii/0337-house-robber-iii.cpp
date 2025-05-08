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

    // 인접한 노드를 선택하면 안됨.
    // 최대 수익을 얻기 위해 노트를 선택하고 그 최대 수익을 반환.
    int rob(TreeNode* root) {
        
        pair<int, int> result = dfs(root);

        return max(result.first, result.second);
    }

    // pair<int, int>
    //      first=현재노드 선택했을때의 최대 값
    //      second=현재노드 선택하지 않았을때의 최대값
    pair<int, int> dfs(TreeNode* node) {

        if (!node) return {0, 0};

        // 자식 노드 접근
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);

        int curNodeSelect = node->val + left.second + right.second;

        int curNodeNotSelect = max(left.first, left.second) + max(right.first, right.second);

        return {curNodeSelect, curNodeNotSelect};
    }
};