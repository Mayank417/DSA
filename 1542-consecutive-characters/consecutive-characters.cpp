class Solution {
public:
    int maxPower(string s) {
        int n=s.size();
        int ct=1,ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])ct++;
            else {
            ans=max(ct,ans);
            ct=1;
            }
        }
        ans=max(ct,ans);
        return ans;
    }
};