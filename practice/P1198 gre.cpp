#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=1e6+5;
long long n,m,s;
long long op[MAXN][2];
long long owei[MAXN],oval[MAXN];
long long numw[MAXM],sumv[MAXM];//重量>=w的矿石数量和价值和
long long check(long long lim){
    numw[0]=0,sumv[0]=0;
    for(int i=1;i<=n;i++){
        if(owei[i]>=lim){//限制在变化,每次都新处理一次
            numw[i]=numw[i-1]+1;
            sumv[i]=sumv[i-1]+oval[i];
        }
        else{
            numw[i]=numw[i-1];
            sumv[i]=sumv[i-1];
        }
    }
    long long sum=0;
    for(int i=1;i<=m;i++){
        int l=op[i][0],r=op[i][1];
        sum+=(numw[r]-numw[l-1])*(sumv[r]-sumv[l-1]);
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    long long ans=1e18;
    for(int i=1;i<=n;i++)
        cin>>owei[i]>>oval[i];
    for(int i=1;i<=m;i++) cin>>op[i][0]>>op[i][1];
    long long l=0,r=1e6+5;
    while(l<=r){
        long long mid=(l+r)/2;
        long long y=check(mid);//差多少
        ans=min(ans,abs(y-s));
        if(y>s) l=mid+1;//重量可以更大，卡的范围更少
        else if(y<s) r=mid-1;
        else break;
    }
    cout<<ans;
    return 0;
}