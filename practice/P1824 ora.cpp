#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=0,minn=0x3f3f3f3f;
int hou[100005];
bool check(int lim){
    int cnt=1,las=1;
    for(int i=2;i<=n;i++){
        if(hou[i]-hou[las]>=lim) cnt++,las=i;
        if(cnt==m) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>hou[i];
        maxn=max(maxn,hou[i]);
        minn=min(minn,hou[i]);
    }
    int l=minn,r=maxn;
    sort(hou+1,hou+n+1);
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){//还可以再往大猜
            l=mid+1;
            ans=max(ans,mid);
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
//想让牛之间距离最大 有很多方案
//每个方案有一个最小距离
//找这个最小距离的最大值
//二分答案直接二分出来的答案，就是要输出的答案