class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long curr_sum=0;
        int ss=0;
        map<int,int>mp;
        for(int i=0; i<k; i++){
            curr_sum+=nums[i];
            mp[nums[i]]++;
        }
        int unique=0;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            unique++;
        }
        if(unique==k){
            ans=max(ans,curr_sum);
        }
        for(int i=k; i<nums.size(); i++){
            if(mp[nums[ss]]==1){
                unique--;
            }
            mp[nums[ss]]--;
            mp[nums[i]]++;
            if(mp[nums[i]]==1){
                unique++;
            }
            curr_sum+=nums[i];
            curr_sum-=nums[ss];
            ss++;
            if(unique==k){
                ans=max(ans,curr_sum);
            }
        }
        return ans;
    }
};