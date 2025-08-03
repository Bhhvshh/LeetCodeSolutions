class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {

        int max_ = w[0];
        int count = 0;
        for(int i = 0;i<w.size()-1;i++){
            if(w[i]<max_){
                count++;
                max_ = w[i+1];
            }
            else max_ = max(max_,w[i]);

            
        }

        if(max_<=w[w.size()-1]) return count;

        return count+1;

        
    }
};