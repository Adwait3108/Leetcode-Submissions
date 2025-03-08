class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<int>s;
        map<int,int>mp;
        for(int i=0; i<k; i++){
            mp[nums[i]]++;
            s.insert(nums[i]);
        }
        vector<int>ans;
        ans.push_back(*s.rbegin());
        int ss=0;
        for(int i=k; i<nums.size(); i++){
           if(mp[nums[ss]]==1){
            s.erase(nums[ss]);
           }
           mp[nums[ss]]--;
           mp[nums[i]]++;
           ss++;
           s.insert(nums[i]);
           ans.push_back(*s.rbegin());
        }
        return ans;
    }
};