#include<bits/stdc++.h>
using namespace std;
int n,m,dis;
int stone[50005];
bool check(int lim){//距离近的就搬走 大于lim的留下
    int cnt=0;
    int las=0;
    for(int i=1;i<=n+1;i++){
        if(stone[i]-las<lim) cnt++;
        else las=stone[i];
    }
    if(cnt>m) return false;//跨太远了 不能再大了
    else return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>dis>>n>>m;
    int minn=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>stone[i];
        minn=min(minn,stone[i]-stone[i-1]);
    }
    stone[n+1]=dis;
    int l=minn,r=dis;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=max(ans,mid);
        }
        else r=mid-1;
    }
    if(m==0) cout<<dis;
    else cout<<ans;
    return 0;
}