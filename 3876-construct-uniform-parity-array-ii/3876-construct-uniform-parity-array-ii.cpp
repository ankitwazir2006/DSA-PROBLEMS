class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minelement=*min_element(nums1.begin(),nums1.end());
        if(minelement%2 ==1 ){
            return true;
        }
       //for making all even there should be no odd 

       for(int i = 0 ; i<nums1.size();i++){
           if(nums1[i]%2==1){
            return false;
           }
       }
       return true;
    }
};