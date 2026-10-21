#include<bits/stdc++.h>
using namespace std;
int n,m;
int hei[1000005];
long long cut(int h){
    long long sum=0;
    for(int i=1;i<=n;i++){
        if(hei[i]<=h) continue;
        else sum+=hei[i]-h;
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int maxn=0;
    for(int i=1;i<=n;i++) cin>>hei[i],maxn=max(maxn,hei[i]);
    int l=0,r=maxn,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(cut(mid)<m) r=mid-1;//不够，下调
        else if(cut(mid)>m) l=mid+1,ans=mid;//够了 还可以更高
        else{
            ans=mid;
            break;
        }
    }
    cout<<ans;
    return 0;
}