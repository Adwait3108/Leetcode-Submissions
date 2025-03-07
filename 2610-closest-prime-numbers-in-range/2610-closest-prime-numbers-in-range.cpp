class Solution {
public:
   vector<bool> is_prime = vector<bool>(100101, true);

    void sieveOfEratosthenes(int n) {
    is_prime.assign(n + 1, true); 
    is_prime[0] = is_prime[1] = false; 
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false; 
            }
        }
    }
}
    vector<int> closestPrimes(int left, int right) {
        sieveOfEratosthenes(1001001);
        vector<int>primes;
        for(int i=0; i<1001001; i++){
            if(is_prime[i]){
                primes.push_back(i);
            }
        }
        int ans=INT_MAX;
        int l=-1;
        int r=-1;
        for(int i=1; i<primes.size(); i++){
             if((primes[i-1]>= left && primes[i]<=right)){
                int diff=primes[i]-primes[i-1];
                if(ans>diff){
                    ans=diff;
                    l=primes[i-1];
                    r=primes[i];
                }
             }
        }
        vector<int>anss;
        anss.push_back(l);
        anss.push_back(r);
        return anss;
    }
};