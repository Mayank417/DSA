class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int minlen=1e9;
        int ct=0;
        int si=-1;
        vector<int> freq(256,0);
        int i=0,j=0;
        for(int k=0;k<m;k++){
            freq[t[k]]++;
        }
        while(j<n){
            if(freq[s[j]]>0)
                ct++;
                freq[s[j]]--;
            while(ct==m){
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    si=i;
                }
               freq[s[i]]++;
                if(freq[s[i]] > 0)
                    ct--;
                i++;
            }
            j++;
        }
        return si==-1? "":s.substr(si,minlen);
    }
};