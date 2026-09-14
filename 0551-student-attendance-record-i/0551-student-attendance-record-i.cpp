class Solution {
public:
    bool checkRecord(string s) {
       
        if(s.find("LLL")!=string::npos){
            return false;
        }
        int counts= count(s.begin(),s.end(),'A');
        if(counts>=2){
            return false;
        }
        return true;

    }
};