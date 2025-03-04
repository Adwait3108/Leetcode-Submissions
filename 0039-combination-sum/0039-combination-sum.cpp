class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(int index, int current_sum, vector<int>& temp, int target, vector<int>& candidates) {
        if (current_sum == target) {
            ans.push_back(temp);
            return;
        }
        if (current_sum > target) return;

        for (int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            backtrack(i, current_sum + candidates[i], temp, target, candidates); 
            temp.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(0, 0, temp, target, candidates);
        return ans;
    }
};
