class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        int starteven = 0, startodd = 0;
        int flag1 = 0 ,flag2 = 1;
        for(auto x:nums){
            odd += (x%2);
            even += (x%2==0);
            if(x%2==flag1) {starteven++; flag1 = !flag1;}
            if(x%2==flag2){startodd++; flag2 = !flag2;}

        }

        int ans = max(odd,even);

        return max(ans,max(starteven,startodd));
    }
};