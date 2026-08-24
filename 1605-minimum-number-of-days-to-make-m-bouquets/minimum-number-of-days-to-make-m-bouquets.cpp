class Solution {
public:
   bool possible(vector<int>& v, int mid, int m , int k){
    int ct=0,Nb=0;
    for(int i=0;i<v.size();i++){
        if(mid>=v[i])ct++;
        else{
            Nb+=(ct/k);
            ct=0;
        }
    }
    Nb+=(ct/k);
    return Nb>=m;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(bloomDay.size()<val)return -1;
        int st=*min_element(bloomDay.begin(),bloomDay.end());
        int en=*max_element(bloomDay.begin(),bloomDay.end());
         int ans=INT_MAX;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(possible(bloomDay,mid,m,k)){
               ans=mid;
               en=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};