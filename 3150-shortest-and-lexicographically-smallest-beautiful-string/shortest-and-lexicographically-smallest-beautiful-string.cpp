class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int ct=0,l=0;
        string ans="";
        for(int r=0;r<n;r++){
            if(s[r]=='1')ct++;
            while(ct>k){
                if(s[l]=='1')ct--;
                l++;
            }
            if(ct==k){
                while(s[l]=='0')
                    l++;
                string curr=s.substr(l,r-l+1);

                if(ans==""||curr.size()<ans.size()||(curr.size()==ans.size()&& curr<ans)){
                    ans=curr;
                }
            }
        }
        return ans;
    }
};