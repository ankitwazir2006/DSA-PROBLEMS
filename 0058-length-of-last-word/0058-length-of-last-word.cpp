class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
      
        int i=s.size()-1;
        if(s.length()==1&&s[0]!=' '){
            return 1;
            
        }
        while(i>=0 && s[i]==' '){
          i--;
          }
        while(i>=0){
            if(s[i]==' '){
                break;
            }
            else{
              ans++;
              i--;
            }
        }
        return ans;
    }
};