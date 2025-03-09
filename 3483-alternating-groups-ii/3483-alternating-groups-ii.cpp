class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int ans=0;
        int l=0;
        int window_size=1;
        for(int i=1; i<n+k-1; i++){
           if(colors[i%n]==colors[(i-1)%n]){
            l=i;
            window_size=1;
           }
           else{
            window_size++;
            if(window_size==k){
               ans++;
               l++;
               window_size--;
            }
           }
        }
        return ans;
    }
};