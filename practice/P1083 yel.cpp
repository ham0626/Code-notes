#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n,m;
long long room[MAXN],day[MAXN],sta[MAXN],to[MAXN];//肯定在某一天后开始装不下
long long diff[MAXN];
bool check(int lim){
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=lim;i++){
        int s=sta[i],t=to[i],d=day[i];
        diff[s]+=d,diff[t+1]-=d;
    }
    for(int i=1;i<=n;i++){//遍历天数
        diff[i]+=diff[i-1];
        if(diff[i]>room[i]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>room[i];
    for(int i=1;i<=m;i++)
        cin>>day[i]>>sta[i]>>to[i];
    int l=0,r=m;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))
            l=mid+1;
        else{
            ans=mid;
            r=mid-1;
        }
    }
    if(ans==0) cout<<"0";
    else cout<<"-1"<<'\n'<<ans;
    return 0;
}