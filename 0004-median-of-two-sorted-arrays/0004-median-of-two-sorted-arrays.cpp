class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0 ;i<nums1.size();i++){
             ans.push_back(nums1[i]);
        }
        for(int i = 0 ; i< nums2.size();i++){
            ans.push_back(nums2[i]);

        }
        sort(ans.begin(),ans.end());
         int median= ans.size()/2;
          double ans1=0;
         if((ans.size())%2==0){
           
          ans1= (ans[median]+ans[median-1])/2.0;

         }
         else{
        
            ans1=(ans[median]);
         }
         return ans1;
    }
 

};