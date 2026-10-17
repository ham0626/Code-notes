#include<bits/stdc++.h>
using namespace std;
int t;
long long a,b;//lcm=a*b/gcd
long long gcd(long long a,long long b){
    while(b!=0){
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b;
        cout<<a+b+(a*b/gcd(a,b))<<'\n';
    }
    return 0;
}