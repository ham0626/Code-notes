#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[100005];
bool check(long long lim){
    long long sum=0;
    int cnt=1;//段数
    for(int i=1;i<=n;i++){
        if(sum+num[i]<=lim) sum+=num[i];//能放下
        else{
            cnt++;
            sum=num[i];
        }
    }
    if(cnt<=m) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    long long sum=0;
    int maxn=0;
    for(int i=1;i<=n;i++){
        cin>>num[i],sum+=num[i];
        maxn=max(maxn,num[i]);
    }
    long long l=maxn,r=sum;
    long long ans;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid)){//可行,还能找更小
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}