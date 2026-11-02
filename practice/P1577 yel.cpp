#include<bits/stdc++.h>
using namespace std;
int n,k;
float rope[10005];
double check(double lim){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(int)(rope[i]/lim);
    }
    if(cnt<k) return false;
    else return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    double maxn=0;
    for(int i=1;i<=n;i++){
        cin>>rope[i];
        if(rope[i]>maxn) maxn=rope[i];
    }
    double l=0,r=maxn;
    double ans=0;
    while(r-l>1e-4){//浮点
        double mid=(l+r)/2;
        if(check(mid)){
            if(mid>ans) ans=mid;
            l=mid;//浮点不能+1
        }
        else r=mid;
    }
    //fixed<<setprecision(2)会四舍五入 不能四舍五入
    printf("%.2f\n",floor(l*100)/100.0);
    return 0;
}