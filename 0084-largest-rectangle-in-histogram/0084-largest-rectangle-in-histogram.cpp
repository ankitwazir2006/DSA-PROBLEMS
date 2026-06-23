class Solution {
private:
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
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
       
          
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
};