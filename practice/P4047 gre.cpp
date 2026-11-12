#include<bits/stdc++.h>
using namespace std;
int n,k;
int fa[1005];
double x[1005],y[1005];
int find(int u){
    if(u==fa[u]) return u;
    else return fa[u]=find(fa[u]);
}
bool check(double lim){//lim最小距离尽量大->距离必须大于lim
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
        double x1=x[i],y1=y[i];
        double x2=x[j],y2=y[j];
        double dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dis<lim){//距离太近还不在一个块
            if(find(i)!=find(j))
            fa[find(i)]=find(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(find(i)==i) cnt++;
    if(cnt>=k) return true;//尽量远 k小更好
    else return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
        cin>>x[i]>>y[i];
    double l=0,r=15000;
    double ans=0;
    while(r-l>1e-4){
        double mid=(l+r)/2;
        for(int i=1;i<=n;i++) fa[i]=i;
        if(check(mid)==true){
            ans=mid;
            l=mid;
        }
        else r=mid;
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}