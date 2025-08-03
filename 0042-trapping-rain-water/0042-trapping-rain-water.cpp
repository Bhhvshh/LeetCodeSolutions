class Solution {
public:
    int trap(vector<int>& height) {
        int max_ = 0, n = height.size();

        vector<int> mleft(n);

        for(int i = 0;i<n;i++){
            mleft[i] = max_;
            max_ = max(max_,height[i]);
        }
        vector<int> mright(n);
        max_ = 0;
        for(int i = n-1;i>=0;i--){
            mright[i] = max_;
            max_ = max(max_,height[i]);
        }

        long long result = 0;

        for(int i = 0;i<n;i++){
            int curr = min(mleft[i],mright[i]);
            if(curr>height[i]) result+=curr-height[i];
        }

        return result;
        
    }
};