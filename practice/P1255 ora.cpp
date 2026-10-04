#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int a[maxn][3000];
int main(){//一个套着汉诺塔皮的高精（高精模板）
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    a[1][0]=1;
    a[2][0]=2;
    int sum=0;
    for(int i=3;i<=n;i++){//P1601高精加
        for(int j=0;j<=2999;j++){
            sum=a[i][j]+a[i-1][j]+a[i-2][j];
            if(sum>=10) a[i][j]=sum%10,a[i][j+1]+=sum/10;
            else a[i][j]=sum;
        }
    }
    int q=0;
    for(int i=2999;i>=0;i--){
        if(a[n][i]==0) q++;
        else break;
    }
    for(int i=2999-q;i>=0;i--) cout<<a[n][i];
    return 0;
}