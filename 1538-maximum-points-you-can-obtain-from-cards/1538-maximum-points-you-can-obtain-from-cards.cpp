class Solution {
public:
    int maxScore(vector<int>& card, int k) {

        int sum = accumulate(card.begin(),card.end(),0);
        int curr = 0;
        int ans = 0;

        for(int i = 0;i<card.size()-k;i++){
            curr+=card[i];
        }

        for(int i = card.size()  - k;i<card.size();i++){
            ans = max(ans,sum-curr);
            curr+=card[i];
            curr-=card[i-card.size() + k];

        }


        return ans = max(ans,sum-curr);
        
    }
};