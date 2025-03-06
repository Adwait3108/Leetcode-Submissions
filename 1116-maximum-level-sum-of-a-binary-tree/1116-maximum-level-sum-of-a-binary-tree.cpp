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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN; 
        int maxLevel = 0;     
        int level = 1;         

        while (!q.empty()) {
            int n = q.size();
            int levelSum = 0; 
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                
                levelSum += t->val;

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = level;
            }

            level++; 
        }

        return maxLevel;
    }
};
