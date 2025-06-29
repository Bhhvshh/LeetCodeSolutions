class Solution {
public:
long long  mod = 1e9 + 7;
  int lowerbound(vector<int> &arr,int l,int tar){
    int r = arr.size() - 1;
    int result = -1;
    while(l<=r){
        int mid = l + ((r-l)>>1);

        if(arr[mid]>tar){
            
            r = mid - 1;
        }
        else{result = mid;
        l = mid + 1;} 
    }

    return result;
  }

  long long pow(int n,int r){

    long long res = 1;
    long long base = n%mod;

    while(r){
        if(r&1)res = (res*base)%mod;
        base = (base*base)%mod;
        r>>=1;
    }

    return res;


  }

  
    int numSubseq(vector<int>& nums, int target) {
        long long ans = 0;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size();i++){
            int lb = lowerbound(nums,i,target-nums[i]);
            if(lb==-1) break;
            cout <<lb<< endl;
            ans= (ans+pow(2,lb-i)) %mod;

            


        }


        return ans;


        
    }
};