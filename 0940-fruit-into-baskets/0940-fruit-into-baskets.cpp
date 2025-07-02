class Solution {
public:
    int totalFruit(vector<int>& arr) {

        int count =  0;
        unordered_map<int,int> umap;
        int ans = 0;
        for(int  i = 0,l = 0;i<arr.size();i++){
            if(umap[arr[i]]++==0) count++;
            while(l<i && count>2){
                if(umap[arr[l++]]--==1) count--;
               
            }
            
            ans = max(ans,i-l+1);
            
        }
        
        return ans;
        
    }
};