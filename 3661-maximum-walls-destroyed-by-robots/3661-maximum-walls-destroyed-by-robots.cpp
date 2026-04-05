class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {

        vector<pair<int,int>> vp;

        for(int i = 0 ; i < robots.size() ; i++ ){
            vp.push_back({robots[i], i});
        }

        sort(vp.begin(), vp.end());
        sort(walls.begin(), walls.end());
        vp.push_back({INT_MAX,-1});
        vector<vector<int>> dp(robots.size(), vector<int> ( 2, 0));

        dp[0][0] = upper_bound(walls.begin(), walls.end(), vp[0].first) - lower_bound(walls.begin(), walls.end(), vp[0].first - distance[vp[0].second] );
        dp[0][1] = upper_bound(walls.begin(), walls.end(), min(vp[0].first + distance[vp[0].second], vp[1].first - 1)) - lower_bound(walls.begin(), walls.end(), vp[0].first );
        // cout << dp[0][0] << " " << dp[0][1] << endl;

        for(int i = 1; i < dp.size(); i++){
            dp[i][0] = max((upper_bound(walls.begin(), walls.end(), vp[i].first) - lower_bound(walls.begin(), walls.end(), 
            max(vp[i].first - distance[vp[i].second],min(vp[i].first,vp[i-1].first + distance[vp[i-1].second] + 1) ))) + dp[i-1][1],
            (upper_bound(walls.begin(), walls.end(), vp[i].first) - lower_bound(walls.begin(), walls.end(), max(vp[i].first- distance[vp[i].second], vp[i - 1].first + 1)) + dp[i - 1][0] ));

            dp[i][1] = upper_bound(walls.begin(), walls.end(), min(vp[i].first + distance[vp[i].second], vp[i+1].first - 1)) - lower_bound(walls.begin(), walls.end(), vp[i].first ) + max(dp[i-1][1], dp[i - 1][0]);
    
        }

        // cout << dp[robots.size() - 1][0]<< " " <<  dp[robots.size() - 1][1];

        return max(dp[robots.size() - 1][0], dp[robots.size() - 1][1]);
        
    }
};