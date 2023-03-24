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

private:
    int sum = 0;
    
    int dfs(TreeNode* root) {
        
        if(root == nullptr)
            return 0;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        sum += abs(l) + abs(r); // 음수가 올라와도 양수로 취급
        //왼쪽이 양수면 그만큼 오른쪽이 음수이다. 
        //절댓값으로 더해주면 1이 재자리로 찾아가는 이동 횟수를 구할 수 있다.
        
        return root->val + l + r - 1; // 현재 노드에 1만 남기고 나머지는 모두 올린다.
    }
    
public:
    
    //discuss 참고..
    int distributeCoins(TreeNode* root) {
        
        dfs(root);
        return sum;
    }
};