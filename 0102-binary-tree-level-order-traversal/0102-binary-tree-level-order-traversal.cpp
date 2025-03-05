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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        while(!qu.empty()){
            int s=qu.size();
            vector<int>temp;
            for(int i=0; i<s; i++){
                TreeNode* t=qu.front();
                temp.push_back(t->val);
                if(t->left!=NULL){
                    qu.push(t->left);
                }
                if(t->right!=NULL)qu.push(t->right);
                qu.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};