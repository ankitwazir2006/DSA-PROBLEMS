class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>output(nums.size(),1);
        int right=1;
        for(int i = 0 ; i< nums.size();i++){
            output[i]=output[i]*right;
            right=right*nums[i];
        }
        int left=1;
        for(int i =nums.size()-1; i>=0;i--){
            output[i]=output[i]*left;
            left=left*nums[i];
        }
        return output;
    }
};