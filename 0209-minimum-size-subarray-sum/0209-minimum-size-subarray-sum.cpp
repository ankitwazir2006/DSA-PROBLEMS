class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
       int left= 0 ;
       int right = 0;
       int mini=INT_MAX;
       int sum = 0;
       while(right<n){
        
         sum+=nums[right];
         
        
        //if the sum excced the target
        while(sum>=target){
            mini= min(mini,right-left+1);
            sum-=nums[left];
            left++;
        }
          
            right++;
    
        

        
     


       }
       return mini == INT_MAX ? 0 : mini;
    }
};