class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // PRE PROCESS FOR MINIMUM OF EACH INDEX I TO N-1
         vector<int> ans(nums.size());
         int n = nums.size()-1;
         int mini=INT_MAX;
         for(int i  =  n ; i>=0; i--){
            mini=min(mini, nums[i]);
            ans[i]=mini;
         }

         //now  using loop to calculate the stable index;
          int maxi=INT_MIN;
          for(int i = 0 ; i<nums.size();i++){
            maxi= max(maxi,nums[i]);
            if(maxi-ans[i]<=k){
                return i;
            }
          }
          return -1;
    }
};