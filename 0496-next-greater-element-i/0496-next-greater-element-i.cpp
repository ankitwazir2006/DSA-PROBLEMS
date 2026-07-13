class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    s.push(-1);
    vector<int>ans(nums2.size());
    unordered_map<int,int>mp;
    for(int i = nums2.size()-1;i>=0; i--){
        int curr=nums2[i];
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
                }
        if(s.empty()){
            ans[i]=-1;

        }
        else{
            ans[i]=s.top();
        }

          s.push(nums2[i]);

        }
        for(int i = 0 ;i< nums2.size();i++){
            mp[nums2[i]]=ans[i];
        }
        int r = 0;
        for(int x: nums1){
            nums1[r++]=mp[x];
        }
    

          return nums1;
    }
    

    
}; 