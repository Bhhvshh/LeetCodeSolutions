class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        map<int,int> m;
        for(auto &x:nums) m[(x%value + value) %value]++;

        int curr = 0;

        while(true){
            if(m[curr%value]==0) return curr;
            m[curr++%value]--;
            // curr++;
        }


        return -1;

        
    }
};