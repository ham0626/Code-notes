#include<bits/stdc++.h>
using namespace std;
int n;
int dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1};
vector<string> mapp;
//push_back()后面加元素
//pop_back()删除后面元素
//front()访问第一个
//back()访问最后一个
//clear()清空
//sort(v.begin(),v.end())排序
//reverse(v.begin(),v.end())翻转
//max_element(v.begin(),v.end())最大值的位置
//min_element(v.begin(),v.end())最小值的位置
//*max_element(v.begin(),v.end())最大值（注意*）
//accumulate(v.begin(),v.end(),0)求和（需 <numeric>）
//count(v.begin(),v.end(),3)数 3 出现几次
//find(v.begin(),v.end(),3)找 3 的位置
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>n;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    for(int i=1;i<=n;i++) cin>>s,mapp.push_back(s);
    for(int i=0;i<=n-1;i++)
        for(int j=0;j<=n-1;j++){
            if(mapp[i][j]=='y'){
                for(int k=0;k<=7;k++){
                    if(i+dx[k]<0||i+dx[k]>=n||j+dy[k]<0||j+dy[k]>=n||i+6*dx[k]<0||i+6*dx[k]>=n||j+6*dy[k]<0||j+6*dy[k]>=n) continue;
                    else{
                        if(mapp[i+dx[k]][j+dy[k]]=='i'){
                            if(mapp[i+2*dx[k]][j+2*dy[k]]=='z'){
                                if(mapp[i+3*dx[k]][j+3*dy[k]]=='h'){
                                    if(mapp[i+4*dx[k]][j+4*dy[k]]=='o'){
                                        if(mapp[i+5*dx[k]][j+5*dy[k]]=='n'){
                                            if(mapp[i+6*dx[k]][j+6*dy[k]]=='g'){
                                                vis[i][j]=true;
                                                vis[i+dx[k]][j+dy[k]]=true;
                                                vis[i+2*dx[k]][j+2*dy[k]]=true;
                                                vis[i+3*dx[k]][j+3*dy[k]]=true;
                                                vis[i+4*dx[k]][j+4*dy[k]]=true;
                                                vis[i+5*dx[k]][j+5*dy[k]]=true;
                                                vis[i+6*dx[k]][j+6*dy[k]]=true;
                                            }
                                            else continue;
                                        }
                                        else continue;
                                    }
                                    else continue;
                                }
                                continue;
                            }
                            else continue;
                        }
                        else continue;
                    }
                }
            }
            else continue;
        }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            if(vis[i][j]==true) cout<<mapp[i][j];
            else cout<<"*";
        }
        cout<<'\n';
    }   
    return 0;
}
