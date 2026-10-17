#include<bits/stdc++.h>
using namespace std;
int t,n,m;
vector<long long> cola;
vector<long long> colb;
vector<long long> ansa;
vector<long long> ansb;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    for(int k=1;k<=t;k++){
        long long suma=0,sumb=0;
        cin>>n>>m;
        cola.clear();
        colb.clear();
        ansa.clear();
        ansb.clear();
        for(int j=0;j<n;j++){
            long long g;
            cin>>g;
            suma=suma+g;
            cola.push_back(g);
        }
        for(int j=0;j<m;j++){
            long long g;
            cin>>g;
            sumb=sumb+g;
            colb.push_back(g);
        }
        long long temp=0;
        for(int i=0;i<n-1;i++){
            temp=temp+cola[i];
            ansa.push_back(temp);
        }
        temp=0;
        for(int i=0;i<m-1;i++){
            temp=temp+colb[i];
            ansb.push_back(temp);
        }
        if(suma!=sumb){
            cout<<"-1"<<'\n';
            continue;
        }
        long long cnt=0;
        long long sa=0,sb=0;
        int i=0,j=0;
        while(i<n-1 && j<m-1){
            if(sa==sb){
                sa+=cola[i++];
                sb+=colb[j++];
            }
            else if(sa<sb){
                sa+=cola[i++];
            }
            else{
                sb+=colb[j++];
            }
            if(sa==sb)
                cnt++;
        }
        cout<<n+m-2-2*cnt<<'\n';
    }
    return 0;
}