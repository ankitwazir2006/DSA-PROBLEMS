class Solution {
public:
    int maxDepth(string s) {
    int maxi=0;
    int j= 0 ;
     for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='('){
            j++;
            maxi=max(j,maxi);
        }
        if(ch==')'){
            j--;
        }
     }
    
     return maxi;
    }
};