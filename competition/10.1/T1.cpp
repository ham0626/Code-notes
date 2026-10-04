#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long n;
        cin>>n;
        while(n%2==0) n=n>>1;
        while(n%5==0) n=n/5;
        int len=0;
        while(n>0){
            n=n/10;
            len++;
        }
        cout<<len<<'\n';
    }
    return 0;
}
