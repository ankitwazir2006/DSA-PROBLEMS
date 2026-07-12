class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ranks=arr;
      
        sort(ranks.begin(),ranks.end());
       unordered_map<int , int> mp;
         int r=1;
        for(int i = 0 ; i<arr.size(); i++){
          if(mp.find(ranks[i])==mp.end()){
             mp[ranks[i]]=r++;
          }
        }
        for(int i = 0 ; i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};