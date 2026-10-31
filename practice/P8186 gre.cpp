#include<bits/stdc++.h>
using namespace std;
int n;
int wish[505][505];
int mapp[505][505];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>wish[i][j];
    for(int i=1;i<=n;i++){
        mapp[i][i]=1;
        for(int j=1;j<=n;j++){
            if(wish[i][j]!=i) mapp[i][wish[i][j]]=1;
            else break; 
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            if(mapp[i][k]!=0&&mapp[k][j]!=0)
            mapp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){//序号
            int v=wish[i][j];//礼物编号
            if(mapp[i][v]!=0&&mapp[v][i]!=0){
                cout<<v<<'\n';
                break;
            }
        }
    return 0;
}