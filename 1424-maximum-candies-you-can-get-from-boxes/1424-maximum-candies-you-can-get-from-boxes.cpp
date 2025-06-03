class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int result =0;
        int n  = status.size();

        

        vector<bool> box(n);
        vector<bool> keysInHand(n);
        vector<bool> visited(n);

        queue<int> q;

        for(int i = 0;i<initialBoxes.size();i++){
            int currbox = initialBoxes[i];
            box[currbox] =1;
            if(status[currbox]){
                q.push(currbox);
                visited[currbox] = true;

            }
        }


        while(!q.empty()){
            int curr = q.front();
            result+= candies[curr]; q.pop();
             
            for(auto x:containedBoxes[curr]){
                box[x] = true;
            }
            for(auto x:keys[curr]){
                keysInHand[x] =true;
            }

            for(int i =0;i<n;i++){
                if(!visited[i] && box[i] && (status[i] || keysInHand[i])){
                    q.push(i);
                    visited[i] = true;
                }
            }


        }


        return result;


        
    }
};