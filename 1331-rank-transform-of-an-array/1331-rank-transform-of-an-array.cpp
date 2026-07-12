class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ranks=arr;
      
        sort(ranks.begin(),ranks.end());
       map<int , int> mp;
         int r=1;
        for(int x:ranks){
          if(mp.find(x)==mp.end()){
             mp[x]=r++;
          }
        }
        for(int i = 0 ; i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};