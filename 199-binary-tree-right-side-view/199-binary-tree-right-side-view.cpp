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
    
    //DFS
    void levelup(TreeNode* root, int level, vector<int>& answer) {
        
        if(!root)
            return;
        
        if(level > answer.size())
            answer.push_back(root->val);
        
        levelup(root->right, level+1, answer);
        levelup(root->left, level+1, answer);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> answer;
        
        if(!root)
            return answer;
        
        levelup(root, 1, answer);
        
        return answer;
    }
};