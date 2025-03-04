class Solution {
public:
    vector<vector<int>>ans;
    map<vector<int>,int>mp;
    void recurse(int index,vector<int>temp,int size,vector<int>&a){
        if(index==size){
             sort(temp.begin(),temp.end());
            if(mp[temp]){
                return;
            }
            ans.push_back(temp);
            mp[temp]++;
            return;
        }
        recurse(index+1,temp,size,a);
        temp.push_back(a[index]);
        recurse(index+1,temp,size,a);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        recurse(0,temp,nums.size(),nums);
        return ans;
    }
};