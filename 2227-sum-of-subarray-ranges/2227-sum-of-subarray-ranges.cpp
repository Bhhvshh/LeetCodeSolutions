class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> nextg(nums.size());

        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            nextg[i] = (st.empty()) ? -1: st.top();

            st.push(i);
        }
        long long maxsum = 0;
        stack<int> st2;

        for(int i = n -1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()] <= nums[i]) st2.pop();
            maxsum+= (long long)nums[i]*(i -nextg[i] )* ((st2.empty())? n-i: st2.top()-i);
            st2.push(i);
            




        }

        stack<int> st3;
        vector<int> nexts(nums.size());

        for(int i = 0;i<n;i++){
            while(!st3.empty() && nums[st3.top()] > nums[i]) st3.pop();
            nexts[i] = (st3.empty()) ? -1: st3.top();

            st3.push(i);
        }
        long long minsum = 0;
        stack<int> st4;

        for(int i = n -1;i>=0;i--){
            while(!st4.empty() && nums[st4.top()] >= nums[i]) st4.pop();
            minsum+= (long long)nums[i]*(i -nexts[i] )* ((st4.empty())? n-i: st4.top()-i);
            st4.push(i);
            




        }
        cout << maxsum <<endl;

        return maxsum - minsum;
        
    }
};