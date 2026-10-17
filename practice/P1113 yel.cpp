#include<bits/stdc++.h>
using namespace std;
int n;
int tim[10010],num[10010];//前置有多少个
int dp[10010];
vector<int> work[10010];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int lab,pre;//存后续，一个做完做下一个
        cin>>lab>>tim[lab];
        while(cin>>pre&&pre!=0){
            num[lab]++;
            work[pre].push_back(lab);
        }
    }
    //不能直接每个遍历走完这个任务要多久，maxm=max（maxm+ans）最后输出maxm结束
    //有可能两个前置任务并行 时间更少
    for(int i=1;i<=n;i++){
        if(num[i]==0) q.push(i),dp[i]=tim[i];
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<work[cur].size();i++){//后续一个个出来
            num[work[cur][i]]--;
            dp[work[cur][i]]=max(dp[cur]+tim[work[cur][i]],dp[work[cur][i]]);
            if(num[work[cur][i]]==0) q.push(work[cur][i]);
        }
    }
    int maxm=0;
    for(int i=1;i<=n;i++)
        maxm=max(maxm,dp[i]);
    cout<<maxm;
    return 0;
}