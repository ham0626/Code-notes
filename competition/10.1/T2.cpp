#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
int n,k;
int main(){//按余数分成三组，刚好a整除，b余1，b+b余2
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    cout<<"Yes"<<'\n';
    int m=3*n;
    for(int i=0;i<n;i++) cout<<(3*i)%m<<" ";
    cout<<'\n';
    for(int i=0;i<n;i++) cout<<(3*i+1)%m<<" ";
    return 0;
}
