class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i=0,j=0;
        int n=cards.size();
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        while(j<n){
            mp[cards[j]]++;
            while(mp[cards[j]]>1){
                ans=min(ans,j-i+1);
                mp[cards[i]]--;
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};