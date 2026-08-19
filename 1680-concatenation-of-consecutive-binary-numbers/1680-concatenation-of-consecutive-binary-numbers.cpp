class Solution {
public:
    int concatenatedBinary(int n) {
        int m = 1e9+7;
        long long result = 0 ;
        int digit=  0 ;
        for(int num =   1 ; num<=n ;num++ ){
          if((num&(num-1))==0){
            digit++;
          }
          result=((result<<digit)%m+num)%m;
        }
         return result;
    }
   
};