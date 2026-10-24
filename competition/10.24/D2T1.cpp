#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+6;
int n;
int a[MAXN],b[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    if(n<=4){
        cout<<"-1";
        return 0;
    }
    if(n%2!=0){//奇数:先奇后偶
        for(int i=1;i<=n/2+1;i++){
            a[i]=2*(i-1)+1;
            cout<<2*(i-1)+1<<" ";
        }
        for(int i=1;i<=n/2;i++){
            cout<<2*i<<" ";
            a[i+n/2+1]=2*i;
        }
        cout<<'\n';
        for(int i=1;i<=n/2;i++)
            b[i]=a[i+1];
        b[n/2+1]=1;
        for(int i=1;i<=n/2;i++)
            b[i+n/2+1]=a[i+n/2+2];
        b[n]=2;
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
    }
    else{
        for(int i=1;i<=(n/2)-1;i++)
            cout<<(i+1)*2<<" ";
        for(int i=1;i<=n/2;i++)
            cout<<2*(i-1)+1<<" ";
        cout<<"2";
        cout<<'\n';
        for(int i=1;i<=n/2;i++)
            cout<<2*i<<" ";
        for(int i=1;i<=n/2;i++)
            cout<<2*(i-1)+1<<" ";
    }
    return 0;
}