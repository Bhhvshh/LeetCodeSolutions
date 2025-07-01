class Solution {
public:
  bool can(vector<int>&n,int m,int p){
    int count = 0;
   for(int i = 0;i<n.size()-1;i++){
    if(n[i+1]-n[i]<=m){
        count++;
        i++;
    }
   }

    return count>=p;

  }
    int minimizeMax(vector<int>& nums, int p) {
        int l = 0, r = *max_element(nums.begin(),nums.end());
        int result = -1;
        sort(nums.begin(),nums.end());

        while(l<=r){
            int mid = l + ((r-l)>>1);
        cout << "mid: "<< mid<<endl;
          if(can(nums,mid,p)){
            result = mid;
            r = mid -1;
          }
          else l = mid + 1;
        }


        return result;
        
    }
};