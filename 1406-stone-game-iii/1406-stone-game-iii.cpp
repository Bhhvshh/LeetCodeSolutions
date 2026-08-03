class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<vector<pair<int,int>>> dp(2,vector<pair<int,int>> (n, {INT_MAX,INT_MIN}));

        auto ans = helper(0, 0, stoneValue, dp);

        if(ans.first == ans.second) return "Tie";
        vector<string> names = {"Bob", "Alice"};


        return names[(ans.first > ans.second)];
    }


    pair<int,int> helper(int id ,bool turn, vector<int> &stoneVal, vector<vector<pair<int,int>>> &dp){

        if(id == stoneVal.size()) return {0,0};
        if(dp[turn][id] != std::make_pair(INT_MAX, INT_MIN)) return dp[turn][id];

        pair<int,int> ans;
        int diff = INT_MIN;



        for(int i = id, curr = 0; i < min(id + 3, (int)stoneVal.size()) ; i++){

            pair<int,int> tmp = helper(i + 1, !turn, stoneVal, dp);
            curr+=stoneVal[i];
            if(turn && (curr + tmp.second - tmp.first) > diff ){
                tmp.second += curr;
                ans = tmp;
                diff = tmp.second - tmp.first;
                
            }
            else if(!turn && (curr + tmp.first - tmp.second) > diff){
                tmp.first += curr;
                ans = tmp;
                diff = tmp.first - tmp.second;
                // cout << "Alice" << " "<< diff << endl;

            }







            
        }

         


        return dp[turn][id] = ans;
    }
};