class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rep=-1;
        map<int,int>mp;
        int n=grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mp[grid[i][j]]){
                    rep=grid[i][j];
                }
                mp[grid[i][j]]++;
            }
        }
        int miss=-1;
        for(int i=1; i<=n*n; i++){
            if(mp[i]==0){
                miss=i;
                break;
            }
        }
        vector<int>temp;
        temp.push_back(rep);
        temp.push_back(miss);
        return temp;
    }
};