#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int a,b,ans;//double和int不能直接比！！！
    cin>>a>>b;
    ans=(4*a+3*b+11)/12;//向上取整:(被除数+除数-1)/除数
    cout<<ans;
    return 0;
}