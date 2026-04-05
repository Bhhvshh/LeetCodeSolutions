class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        vector<pair<int, int>> vp;

        for(int i = 0; i < positions.size(); i++ ){
            vp.push_back({positions[i], i});
        }
        

        sort(vp.begin(), vp.end());
        stack<pair<int,int>> st;
        for(auto &x: vp){
            if(st.empty()){
                st.push(x);
            }
            else if(directions[x.second] == 'R'){
                st.push(x);
            }
            else{

                while(st.size() && directions[st.top().second] == 'R' && healths[st.top().second] < healths[x.second]){
                    st.pop();
                    healths[x.second]--;
                }

                if(st.empty() && healths[x.second]) st.push(x);
                else if(st.size() && directions[st.top().second] == 'L' && healths[x.second]) st.push(x);
                else if(st.size() && directions[st.top().second] == 'R' && healths[st.top().second] == healths[x.second]) st.pop();
                else if(st.size() && directions[st.top().second] == 'R' && healths[st.top().second] > healths[x.second]){
                    if(healths[st.top().second]-- == 1) st.pop();
                    
                }

            }
        }

        vector<int> mark(positions.size(), 0);

        while(st.size()){
            mark[st.top().second] = true;
            st.pop();
        }

        vector<int> ans;

        for(int i = 0; i < positions.size(); i++ ){
            if(mark[i]){
                ans.push_back(healths[i]);
            }
        }

        return ans;

    }
};