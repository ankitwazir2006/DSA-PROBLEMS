class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int num=0;
        for(int i = 0 ; i<nums.size();i++){
              int count=0;
            
             for(int j = i ; j<nums.size();j++){
                
                if(target == nums[j]){
                    count++;
                }
                int n = j-i+1;
                if(2*count>n){
                    num++;
                }
             }
             
        }
       
        return num;
    }
};