class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;

        int last = 0, n = colors.size();

        for(int i = 1;i<n;i++){
            if(colors[last]==colors[i]){
                if(neededTime[last]>neededTime[i]){
                    cost+=neededTime[i];

                }
                else{
                    cost+=neededTime[last];
                    last = i;

                }
            }
             else last = i;

        }
       
        return cost;
    }

    
};