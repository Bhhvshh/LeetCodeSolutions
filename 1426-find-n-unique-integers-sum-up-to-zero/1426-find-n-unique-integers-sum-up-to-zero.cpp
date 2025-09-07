class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);

        for(int i = 0;i<n/2;i++){
            arr[i] = i+1;
        }
        for(int i = n/2;i<n;i++){
            arr[i] = -(i - n/2 + 1);
        }
        if(n%2) arr[n-1] = 0;

        return arr;
        
    }
};