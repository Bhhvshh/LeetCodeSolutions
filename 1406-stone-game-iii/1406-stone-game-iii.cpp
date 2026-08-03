class Solution {
    static inline const vector<string> names = {"Tie", "Bob", "Alice"};

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<vector<int>> dp(2,vector<int> (n, INT_MIN));

        auto ans = helper(0, 0, stoneValue, dp);

        


        return names[(ans !=  0) + (ans > 0 ) ];
    }


    int helper(int id ,bool turn, vector<int> &stoneVal, vector<vector<int>> &dp){

        if(id == stoneVal.size()) return 0;
        if(dp[turn][id] != INT_MIN) return dp[turn][id];

        int diff = INT_MIN;

        for(int i = id, curr = 0; i < min(id + 3, (int)stoneVal.size()) ; i++){

            curr+=stoneVal[i];
            diff = max(diff, curr - helper(i + 1, !turn, stoneVal, dp));
            
        }

        return dp[turn][id] = diff;
    }
};