class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> pref=stones;
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        int b=pref[n-1];
        for(int i=n-2;i>=1;i--){
            b=max(b,pref[i]-b);
        }
        return b;
    }
};
