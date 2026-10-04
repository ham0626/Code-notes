#include<bits/stdc++.h>
using namespace std;
char ro[200];
int r[200],ans[200],fez[200],temp[200],tempc[200];//ans分母，fez分子
int pri[60]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281};
int length(){
    int q=0;
    for(int i=199;i>=0;i--){
        if(temp[i]==0) q++;
        else break;
    }
    return 200-q;
}
int comp(int lenr){
    int len=length();
    if(len<lenr) return 1;//当前值更小，可以继续乘
    else if(len>lenr) return 2;//当前值更大，不可继续乘
    else{
        for(int i=lenr-1;i>=0;i--){
            if(temp[i]>r[i]) return 2;//当前值更大，不可继续乘
            else if(temp[i]<r[i]) return 1;//当前值更小，可以继续乘
        }
        return 3;//相等
    }
}
void multi(int a[],int k){
    int nxt=0;
    for(int i=0;i<200;i++){
        int cur=k*a[i]+nxt;
        a[i]=cur%10;//依然不需要一次处理完所有位数
        nxt=cur/10;
    }
}
int divi(int a[],int k){
    int cur=0,rem=0;
    for(int i=199;i>=0;i--){
        cur=rem*10+a[i];
        a[i]=cur/k;
        rem=cur%k;
    }
    return rem;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        int flag=-1;
        memset(r,0,sizeof(r));
        memset(ans,0,sizeof(ans));
        memset(temp,0,sizeof(temp));
        memset(ro,0,sizeof(ro));
        memset(fez,0,sizeof(fez));
        ans[0]=1,temp[0]=1,fez[0]=1;
        cin>>ro;
        int lenr=strlen(ro);
        for(int i=0;i<lenr;i++) r[i]=ro[lenr-1-i]-'0';//把累加和进位拆分开，不然容易累加超过10但是没有处理
        for(int j=0;j<59;j++){
            if(comp(lenr)==1){
                multi(temp,pri[j]);
                if(comp(lenr)==1||comp(lenr)==3){//相等也可以乘
                    multi(ans,pri[j]);
                    flag=j;
                    continue;
                }
                else break;
            }
        }//分母在ans中，temp可能被污染。低到高
        for(int i=0;i<=flag;i++){
            multi(fez,pri[i]+1);
        }
        for(int i=0;i<=flag;i++){
            for(int j=0;j<=199;j++) tempc[j]=fez[j];
            if(divi(tempc,pri[i])==0){
                divi(ans,pri[i]);
                divi(fez,pri[i]);
            }
        }
        int ansc=0,fezc=0;
        for(int i=199;i>=0;i--){
            if(ans[i]==0) ansc++;
            else break;
        }
        for(int i=199;i>=0;i--){
            if(fez[i]==0) fezc++;
            else break;
        }
        for(int i=199-ansc;i>=0;i--) cout<<ans[i];
        cout<<"/";
        for(int i=199-fezc;i>=0;i--) cout<<fez[i];
        cout<<'\n';//注意最后输出的是并联电阻
    }
    return 0;
}