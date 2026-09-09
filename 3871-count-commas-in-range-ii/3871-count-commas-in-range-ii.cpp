class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long i = 1000;
        if (n<1000){return 0;}
        while(i<=n){
             ans= ans+( n-i +1);
             i*=1000;

        }
        return ans;
    }
};