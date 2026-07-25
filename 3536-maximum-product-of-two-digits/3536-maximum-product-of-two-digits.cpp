class Solution {
public:
    int maxProduct(int n) {
        vector<int> numbers;
        while(n>0){
            int digit= n%10;
            n=n/10;
            numbers.push_back(digit);

        }
        int a = 0 ; 
        int b= 0;
        for(int i = 0 ; i<numbers.size(); i++){
               if(numbers[i]>a){
                b=a;
                a=numbers[i];
               }
               else if( b<numbers[i]){
                b=numbers[i];
               }
             
        }
        return a*b;

    }
};