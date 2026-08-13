class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
    for(int i = 0 ; i<  nums.size() ; i++ ){
         
        int sum = target-nums[i];

        if(mp.count(sum)){
            return {mp[sum],i};
        }
        else{
           mp[nums[i]]=i;
        }
    }
    return { };
    }
};