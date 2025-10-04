class Solution {
public:
    int maxArea(vector<int>& height) {

        int ans = 0;

        for(int l = 0, r= height.size()-1;l<r;){
            if(height[l]>height[r]) ans = max(ans, (r-l)*height[r--]);
            else ans = max(ans, (r-l)*height[l++]);
           
             
              
            
        }

        return ans;
        
    }
};