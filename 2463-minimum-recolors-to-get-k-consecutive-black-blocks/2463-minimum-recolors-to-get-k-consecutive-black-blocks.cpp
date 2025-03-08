class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        int curr=0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W'){
                curr++;
            }
        }
        ans=min(ans,curr);
        int s=0;
        for(int i=k; i<blocks.size(); i++){
            if(blocks[i]=='W'){
                curr++;
            }
            if(blocks[s]=='W'){
                curr--;
            }
            ans=min(ans,curr);
            s++;
        }
        return ans;
    }
};