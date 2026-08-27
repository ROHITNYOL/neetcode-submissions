class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int n = heights.size();
        int st = 0;
        int end = n-1;

        int mx = 0;
        while(st<end){

           int area = min(heights[st],heights[end]) * (end-st); 

            mx = max(mx, area);

            if(heights[st]<heights[end]) st++;
            else end--;

        }

        return mx;    
    }

};
