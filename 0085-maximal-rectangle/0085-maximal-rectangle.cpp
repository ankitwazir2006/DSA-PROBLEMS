class Solution {
private:
    int largestRectangleArea(vector<int>& heights ) {
       int n= heights.size();
        vector<int> prev(n);
        prev=prevsmallerelement(heights,n);
        vector<int> next(n);
        next=nextsmallerelement(heights,n);
        int area= INT_MIN;
        for(int i = 0 ; i<n ; i++){
            int lenght= heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int breadth= next[i]-prev[i]-1;
            int newarea=lenght*breadth;
            area=max(newarea,area);
        }
        return area;

    }
     vector<int>nextsmallerelement(vector<int>& heights, int n ){
        vector<int> ans(n);
        stack<int>s;
        s.push(-1);
        for(int i = n-1; i>=0; i--){
            int curr=heights[i];
             while(s.top()!=-1&&heights[s.top()]>=curr){
                s.pop();
             }
             ans[i]=s.top();
             s.push(i);
        }
        return ans;
    }
    vector<int> prevsmallerelement(vector<int>&heights, int n ){
         vector<int> ans(n);
        stack<int>s;
        s.push(-1);
        for(int i = 0; i<n; i++){
            int curr=heights[i];
            while(s.top()!=-1&&heights[s.top()]>=curr){
                s.pop();
            }
             ans[i]=s.top();
             s.push(i);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0 ;
        }
        vector<int> heights(matrix[0].size(), 0);
        int area= 0 ;
        for(int i = 0 ; i<matrix.size();i++){
            for(int j = 0 ;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    heights[j]+=1;
                    
                }
                else{
                   heights[j]=0;
                }
            }
            area=max(area,largestRectangleArea(heights));
        }
        return area;
    }
};