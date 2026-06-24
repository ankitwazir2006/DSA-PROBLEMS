class Solution {
private:
  
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream=1;
        int i = 0 ;
        vector<string> ans;
        while(stream<=n&&i<target.size()){
            ans.push_back("Push");
            if(stream==target[i]){
                i++;
            }
            else{
                ans.push_back("Pop");
            }
            stream++;
        }

     return ans;
    }
};