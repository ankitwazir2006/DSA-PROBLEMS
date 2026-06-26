class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        long long cumsum=0;
        mp[0]=1;
        long long validleftpoints=0;
        long long  result=0;
        for(int i = 0; i<nums.size();i++){
            if(target==nums[i]){
                validleftpoints+=mp[cumsum];
                cumsum+=1;

            }
            else{
                cumsum-=1;
                validleftpoints-=mp[cumsum];
               
            }
            mp[cumsum]+=1;
            result+=validleftpoints;

        }
        return result;
    }
};