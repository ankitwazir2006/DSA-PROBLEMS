class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 3;
        int product= 1;
        int j=nums.size()-1;

         while(i>0){
            product=product*nums[j--];
            i--;
         }
         int oddpro=1;
         for(int i = 0 ; i<2; i++){
            oddpro*=nums[i];
         }
         oddpro=oddpro*nums[nums.size()-1];
         return max(oddpro,product);
      
    }
};