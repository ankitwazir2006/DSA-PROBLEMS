class Solution {
public:
    int hammingWeight(int n) {
        int count = 0 ;
        //as we know when we &2raised to any power with its -1 value it gives zero so until we make every zero in it we will loop 
        while(n){
            n&=(n-1);
            count++;
        }
            return count++;
    }
};