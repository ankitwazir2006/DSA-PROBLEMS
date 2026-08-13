class Solution {
public:
    vector<string> anagram(string s , vector<string>& strs,vector<bool>& used){
       vector<string> ans;
        for(int i = 0 ; i < strs.size(); i++){
            if(used[i]||s.size()!=strs[i].size()){
                continue;
            }
            int arr[26]={0};
            int arr2[26]={0};
            for(int j = 0 ; j<s.size();j++){
                arr[strs[i][j]-'a']++;
                arr2[s[j]-'a']++;
            }
            bool flag =true;
            for(int j = 0 ; j<s.size();j++){
                if(arr[s[j]-'a']!=arr2[s[j]-'a']){
                    flag=false;
                }
            }
            if(flag){
                ans.push_back(strs[i]);
                 used[i] = true;
            }


        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> used(strs.size(), false);
        for(int i = 0 ; i< strs.size() ; i++){
            if(used[i]){
                continue;
            }
             vector<string> tik= anagram(strs[i],strs,used);
             ans.push_back(tik);
        }
        return ans;
    }
};