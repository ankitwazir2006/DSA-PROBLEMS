class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        unordered_set<int> result;
        int n = nums.size();
        for(int i = 0 ; i< n ; i++){
            for(int j= 0; j<n ; j++){
                for(int k = 0 ; k<n ; k++){
                    if(i==k||k==j||j==i){
                        continue;
                    }
                    int num=(100*nums[i]+10*nums[j]+nums[k]);
                    if(num>=100&&num%2==0){
                        result.insert(num);
                    }
                }
            }
        }
       return result.size();
    }
};