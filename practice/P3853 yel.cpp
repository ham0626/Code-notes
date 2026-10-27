#include<bits/stdc++.h>
using namespace std;
int l,n,k;
int sig[100005];
bool check(int lim){
    int cnt=0;//插入的数量
    sig[n+1]=l;
    for(int i=1;i<=n+1;i++){
        int dif=sig[i]-sig[i-1];
        if(dif>lim) cnt+=(dif-1)/lim;
    }
    if(cnt<=k) return true;//要的比限额多
    else return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>l>>n>>k;
    for(int i=1;i<=n;i++) cin>>sig[i];
    int lef=1,rig=l;
    int ans=0;
    while(lef<=rig){
        int mid=(lef+rig)/2;
        if(check(mid)){
            ans=mid;
            rig=mid-1;
        }
        else lef=mid+1;
    }
    cout<<ans;
    return 0;
}