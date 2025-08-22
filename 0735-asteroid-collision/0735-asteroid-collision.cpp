class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        vector<bool> mark(asteroids.size());

        for(int i = asteroids.size() - 1;i>=0;i--){
            if(asteroids[i]<0){
                st.push(i);
            }
            else{
                if(st.empty()) continue;
                if(asteroids[i]> abs(asteroids[st.top()])){
                    mark[st.top()] = 1;
                    st.pop();
                    i++;

                }
                else if(asteroids[i] == abs(asteroids[st.top()])){
                    mark[st.top()] = 1;
                    mark[i] = true;
                    st.pop();
                    // i++;

                }
                else{
                    mark[i] = true;
                }
            }
        }


        vector<int> ans;
        for(int i = 0;i<asteroids.size();i++)
         if(!mark[i]) ans.push_back(asteroids[i]);

        return ans;
        
    }
};