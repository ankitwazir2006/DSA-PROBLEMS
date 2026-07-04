class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        deque<int> dq;
       for(int i = 0 ; i<k; i++){
        while(!dq.empty()&& nums[dq.back()]<=nums[i]){
            dq.pop_back();

        }
        dq.push_back(i);
       }
       ans.push_back(nums[dq.front()]);
       for(int i =k ; i<nums.size(); i++){
        //update window by checking range  out of range element
         if(!dq.empty()&& i-dq.front()>=k){
               dq.pop_front();
        }
        // remove smaller element 
        while(!dq.empty()&& nums[dq.back()]<=nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);

       }
       return ans;
    }
};