class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 ;
        int j = height.size()-1;
        int maxarea=0;
        while(i<j){
         int width=j-i;
          int heights= min(height[i],height[j]);
          int area= heights*width;
          maxarea=max(maxarea,area);
          if(height[i]>height[j]){
            j--;
          }
          else{
            i++;
          }
        }
        return maxarea;
    }
};