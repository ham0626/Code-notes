//混合背包
#include<bits/stdc++.h>
using namespace std;
char t1[6],t2[6];
int n,h11,h12,h21,h22,m11,m12,m21,m22,diff;
int tim[100005],aes[100005],num[100005];
int dp[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t1>>t2;
    cin>>n;
    for(int i=0;i<6;i++){
        if(t1[i]==':'&&i==2){//hh:mm
            h11=t1[i-2]-'0';
            h12=t1[i-1]-'0';
            m11=t1[i+1]-'0';
            m12=t1[i+2]-'0';
            break;
        }
        else if(t1[i]==':'&&i==1){//0h:mm
            h11=0;
            h12=t1[i-1]-'0';
            m11=t1[i+1]-'0';
            m12=t1[i+2]-'0';
            break;
        }
        else continue;
    }
    for(int i=0;i<6;i++){
        if(t2[i]==':'&&i==2){//hh:mm
            h21=t2[i-2]-'0';
            h22=t2[i-1]-'0';
            m21=t2[i+1]-'0';
            m22=t2[i+2]-'0';
            break;
        }
        else if(t2[i]==':'&&i==1){//0h:mm
            h21=0;
            h22=t2[i-1]-'0';
            m21=t2[i+1]-'0';
            m22=t2[i+2]-'0';
            break;
        }
        else continue;
    }
    int t11=(h11*10+h12)*60+m11*10+m12;
    int t22=(h21*10+h22)*60+m21*10+m22;
    diff=t22-t11;
    for(int i=1;i<=n;i++){
        cin>>tim[i]>>aes[i]>>num[i];
        if(num[i]==0){//完全背包
            for(int j=tim[i];j<=diff;j++)
            dp[j]=max(dp[j],dp[j-tim[i]]+aes[i]);
        }
        else if(num[i]==1){//01背包
            for(int j=diff;j>=tim[i];j--)
            dp[j]=max(dp[j],dp[j-tim[i]]+aes[i]);
        }
        else{//多重背包
            int k=1;//块大小
            while(num[i]>0){
                int blo=min(k,num[i]);//有可能不够分
                int blov=blo*aes[i];
                int blow=blo*tim[i];
                for(int j=diff;j>=blow;j--)
                    dp[j]=max(dp[j],dp[j-blow]+blov);
                k=k*2;
                num[i]=num[i]-blo;
            }
        }
    }
    cout<<dp[diff];
    return 0;
}