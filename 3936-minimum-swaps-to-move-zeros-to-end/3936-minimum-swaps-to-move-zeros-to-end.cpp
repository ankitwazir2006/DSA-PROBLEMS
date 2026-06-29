class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        vector<int>dummy(nums.size());
        int countzero=0;
        for(int i = 0 ; i< nums.size();i++){
            
            if(nums[i]==0){
                countzero++;
            }
         
          
        }
        int j = nums.size()-1;
         int lastzero=0;
         int temp=countzero;
         while(temp--){
            if(nums[j]==0)lastzero++;
            j--;
         }
        return countzero-lastzero;
    }
};