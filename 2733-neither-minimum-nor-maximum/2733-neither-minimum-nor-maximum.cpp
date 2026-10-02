#include <algorithm>
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int minelement=*min_element(nums.begin(),nums.end());
        int maxelement=*max_element(nums.begin(),nums.end());
        for(int i =0 ; i<nums.size();i++){
            if(nums[i]!=minelement&&nums[i]!=maxelement){
                return nums[i];
            }
        }
        return -1;

    }
};