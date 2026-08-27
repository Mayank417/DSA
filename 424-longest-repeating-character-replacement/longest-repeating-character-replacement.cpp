class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int maxlen=0;
        int maxf=0;
        int n=s.size();
        vector<int> freq(26,0);
        while(r<n){
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);
            while(r-l+1-maxf>k){
                freq[s[l]-'A']--;
                maxf=0;
                for(int i=0;i<26;i++){
                    maxf=max(maxf,freq[i]);
                }
                l++;
            }
            if(r-l+1-maxf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};