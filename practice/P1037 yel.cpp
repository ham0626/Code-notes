#include<bits/stdc++.h>
using namespace std;
int k;
int n[40],ans[10],dis[10][10];
int sum[40];
char nn[40];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>nn>>k;
    for(int i=1;i<=k;i++){
        int fro,to;
        cin>>fro>>to;
        dis[fro][to]=1;
    }
    for(int m=0;m<=9;m++)
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++){
                if(dis[i][m]==1&&dis[m][j]==1)
                dis[i][j]=1;
            }
    int len=strlen(nn);
    for(int i=0;i<len;i++) n[i]=nn[i]-'0';
    for(int i=0;i<=9;i++) ans[i]=1;
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
        if(dis[i][j]==1&&i!=j) ans[i]++;
    // for(int i=0;i<=9;i++) cout<<ans[i]<<'\n';
    // for(int i=0;i<=9;i++){
    //     for(int j=0;j<=9;j++)
    //     cout<<dis[i][j]<<" ";
    //     cout<<'\n';
    // }
    sum[0]=1;
    for(int i=0;i<len;i++){
        int re=0;
        for(int j=0;j<=38;j++){
            int temp=sum[j]*ans[n[i]]+re;
            sum[j]=temp%10;
            re=temp/10;
        }
        if(re>0) re++;
    }
    int q=0;
    for(int i=39;i>=0;i--){
        if(sum[i]==0) q++;
        else break;
    }
    for(int i=39-q;i>=0;i--) cout<<sum[i];
    return 0;
}