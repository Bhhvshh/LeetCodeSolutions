class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int m1 = -1, m2 = -2;
        int c1 = 0, c2 = 0;
        
        for(int i = 0;i<arr.size();i++){
            
            if( m1==arr[i]){
                c1++;
                m1 = arr[i];
            }
            else if( m2==arr[i]){
                c2++;
                m2 = arr[i];
            }
            
            else if(c1==0){
                c1++;
                m1 = arr[i];
                
            }
            else if(c2==0){
                c2++;
                m2 = arr[i];
                
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        int cv1 = 0,cv2=0;
        for(auto x:arr) if(x==m1) cv1++;
        for(auto x:arr) if(x==m2) cv2++;
        if(cv1>arr.size()/3)ans.push_back(m1);
        if(cv2>arr.size()/3)ans.push_back(m2);
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};