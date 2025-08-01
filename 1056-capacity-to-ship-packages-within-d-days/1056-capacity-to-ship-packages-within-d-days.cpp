class Solution {
public:
 bool can(int &mid, vector<int> &w, int &d){

    int sum = 0, count = 0;

    for(auto x:w){
        if(x>mid) return false;
        sum+=x;
        if(sum>mid){ count++; sum= x;}

    }
    return count<d;
 }
    int shipWithinDays(vector<int>& weights, int days) {

        int sum = 0;
        for(auto x:weights) sum+=x;



        int l = 1, r = sum;
        int result = -1;

        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(can(mid,weights,days)){
                result = mid;
                r = mid - 1;
            }
            else l = mid + 1;

        }

      return result;

        
    }
};