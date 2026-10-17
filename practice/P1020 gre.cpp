#include<bits/stdc++.h>//最长不上升子列
using namespace std;
int cnt,len;
int maxn=0,maxm=0;
int dp[100010],bomb[100010];//以第i个元素结尾的最长不下降子序列
int d[100010];
//对于单调不增序列的套数=最长严格上升子序列长度
//e.g.导弹 6 7 3 9 1 2 1 
//第一问（单调不增）是4 第二问（严格单增）是3（
//(6，3，2，1）+（7，1）+（9） ，
//第二问就最长严格单增6 7 9 
//把头逮到(如果是严格下降就和导弹打击序列很重合了,没有区分度)
int find_pos(int x){//二分找单调不减
    int l=0,r=maxn-1,mid=(l+r)/2;
    while(l<=r){//最后l>r错开后停止
        int mid=(l+r)/2;
        if(d[mid]<x){
            r=mid-1;//下标指针
        }
        else if(d[mid]>x){
            l=mid+1;//下标指针
        }
        else l=mid+1;//等号情况，相当于插入元素
    }
    return l;
}
int find_pos1(int x){//二分找严格单增
    int l=0,r=maxm-1,mid=(l+r)/2;
    while(l<=r){//最后l>r错开后停止
        int mid=(l+r)/2;
        if(d[mid]>=x){
            r=mid-1;//下标指针
        }
        else l=mid+1;//下标指针
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int hei;
    while(cin>>hei){
        bomb[cnt]=hei;
        cnt++;
    }
    for(int i=0;i<cnt;i++){//降序数组
        int temp=find_pos(bomb[i]);
        d[temp]=bomb[i];
        if(temp==maxn) maxn++; 
        //能找到插入位置：temp=l替换
        //找不到 返回pos 插在最后
    }
    memset(d,0,sizeof(d));
    for(int i=0;i<cnt;i++){//升序数组
        int temp=find_pos1(bomb[i]);
        d[temp]=bomb[i];
        if(temp==maxm) maxm++; 
    }
    //O(n平方)
    // for(int i=0;i<cnt+1;i++){
    //     dp[i]=1;
    //     for(int j=0;j<i;j++){
    //         if(bomb[j]>=bomb[i]) dp[i]=max(dp[i],dp[j]+1);
    //         else continue;
    //     }
    // }
    // for(int i=0;i<cnt;i++) maxn=max(maxn,dp[i]);
    // cout<<maxn<<'\n';
    // for(int i=0;i<cnt+1;i++){
    //     dp[i]=1;
    //     for(int j=0;j<i;j++){
    //         if(bomb[j]<bomb[i]) dp[i]=max(dp[i],dp[j]+1);
    //     }
    // }
    // for(int i=0;i<cnt;i++) maxm=max(maxm,dp[i]);
    // cout<<maxm;
    //O(nlogn)
    cout<<maxn<<'\n';//最长不增子序列
    cout<<maxm;
    return 0;
}