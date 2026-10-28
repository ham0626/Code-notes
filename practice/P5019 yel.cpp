#include<bits/stdc++.h>
using namespace std;
int n;
int road[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>road[i];
    int sum=0;
    for(int i=0;i<=n;i++){
        if(road[i]<road[i+1]) sum+=road[i+1]-road[i];
    }
    cout<<sum;
    return 0;
}