class Solution {
public:
    vector<vector<int>>ans;
    void recurse(int index,vector<int>temp,int size,vector<int>&a){
        if(index==size){
        ans.push_back(temp);
        return;
        }
        recurse(index+1,temp,size,a);
        temp.push_back(a[index]);
        recurse(index+1,temp,size,a);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        recurse(0,temp,n,nums);
        return ans;
    }
};