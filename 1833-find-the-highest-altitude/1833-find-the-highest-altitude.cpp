class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        ans=max(ans,gain[0]);
        for(int i=1; i<gain.size(); i++){
            gain[i]+=gain[i-1];
            ans=max(ans,gain[i]);
        }
        return ans;
    }
};