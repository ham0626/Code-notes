#include<bits/stdc++.h>
using namespace std;
char so[10100];
int s[10100],pri[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int lens;
    long long ans=0;
    cin>>so;
    lens=strlen(so);
    for(int i=0;i<=lens;i++) s[i]=so[i]-'0';
    for(int i=0;i<=lens-2;i++){
        int res=0;
        res=s[i]*10+s[i+1];
        for(int j=0;j<=26;j++){
            if(res==pri[j]) ans+=res;
        }
    }
    cout<<ans;
    return 0;
}