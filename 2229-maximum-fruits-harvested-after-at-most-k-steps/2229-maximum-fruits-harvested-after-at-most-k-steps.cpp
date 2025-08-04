class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int max_element  = INT_MIN;
        for(auto &x:fruits) max_element = max(x[0],max_element);
        max_element= max(max_element,startPos);

        vector<int> preleft(max_element+1);
        vector<int> preright(max_element+1);


       int startval = 0;
        for(auto &x:fruits){
            if(x[0]==startPos) startval = x[1];
            if(x[0]<startPos) preleft[x[0]] = x[1];
            if(x[0]>startPos)preright[x[0]] = x[1];
        }

        for(int i = startPos+1;i<=max_element;i++){
            preright[i] += preright[i-1];
        }

        for(int i = startPos-1;i>=0;i--){
            preleft[i]+=preleft[i+1];
        }

        int ans = 0;
        

        for(int i = startPos;i>=0;i--){
            int curr = startval;
            if(startPos-i<=k) curr+= preleft[i];
            // cout<<preleft[i]<<endl;
            if(i+(k-startPos+i)>startPos) curr+= ( i+(k-startPos+i) <=max_element) ?preright[i+(k-startPos+i)] : preright[max_element];
            // cout << curr<<endl;
            ans= max(ans,curr);

        }

        
        for(int i = startPos;i<=max_element;i++){
            int curr = startval;
            if(i- startPos<=k) curr+= preright[i];
            if(i-(k+startPos-i)<startPos) curr+= ( i-(k+startPos-i)>=0) ? preleft[i-(k+startPos-i)]: preleft[0];
            ans= max(ans,curr);

        }

        return ans;
         







        
    }
};