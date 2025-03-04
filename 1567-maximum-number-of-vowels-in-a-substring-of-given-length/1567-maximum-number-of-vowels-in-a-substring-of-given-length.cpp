class Solution {
public:
    int maxVowels(string s, int k) {
        map<char,int>mp;
        mp['a']++;
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;
        int ans=0;
        int curr=0;
        int ss=0;
        for(int i=0; i<k; i++){
            if(mp[s[i]]){
                ans++;
                curr++;
            }
        }
        for(int i=k; i<s.size(); i++){
           if(mp[s[i]]){
            curr++;
           }
           if(mp[s[ss]]){
            curr--;
           }
           ss++;
           ans=max(ans,curr);
        }
        return ans;
    }
};