class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int ans = 0;
        vector<int> last;
        vector<int> pre(heights.size()), post(heights.size());

        for(int i = 0;i<heights.size();i++){
            while(st.size() && heights[st.top()]>heights[i]) st.pop();

            pre[i] = (st.size()) ? st.top() : -1;
            st.push(i);
           
               
        }
        stack<int> st2;
        for(int i = heights.size() -1;i>=0;i--){
            while(st2.size() && heights[st2.top()]>=heights[i]) st2.pop();

            post[i] = (st2.size()) ? st2.top() : heights.size();
            st2.push(i);
           
               
        }

        for(int i = 0;i<heights.size();i++){

            ans = max(ans,heights[i]*(post[i]-pre[i]-1));

        }



        return ans;
        
    }
};