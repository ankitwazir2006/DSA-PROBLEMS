class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxvalue=0;
        int ans=0;
        for(int i= 0 ; i<nums.size();i++){
            int element=nums[i];
           maxvalue=max(maxvalue,element);
        }
        for(int i = 0 ;i<nums.size();i++){
            int val=abs(maxvalue-nums[i]);
            ans= ans+val;
        }
        return ans;
    }
};