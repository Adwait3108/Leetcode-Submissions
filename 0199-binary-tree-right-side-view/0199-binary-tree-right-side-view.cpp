class Solution {
	public:
		vector<int> rightSideView(TreeNode* root) {
			vector<int>temp;
			if(root==NULL){
				return temp;
			}
			queue<TreeNode*>q;
			q.push(root);
			while(!q.empty()){
				int n=q.size();
				vector<int>temp2;
				for(int i=0; i<n; i++){
					TreeNode* t=q.front();
                    temp2.push_back(t->val);
					if(t->left!=NULL) q.push(t->left);
					if(t->right!=NULL)q.push(t->right);
					q.pop();
				}
				temp.push_back(temp2[temp2.size()-1]);
			}
			return temp;
		}
	};