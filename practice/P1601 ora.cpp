#include<bits/stdc++.h>
using namespace std;
const int maxn=5000;
char ao[maxn];
// char bo[maxn];
int a[maxn],ans[maxn];
// int b[maxn];
long long b;
int main(){//一个套着汉诺塔皮的高精（高精模板）
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    // int flag=0;
    cin>>ao;
    cin>>b;
    // char str[20] = "hello";
    // sizeof(str)：算的是数组总容量，结果是 20
    // strlen(str)：算的是有效字符个数，结果是 5
    int lena=strlen(ao);
    // int lenb=strlen(bo);//strlen遇到数字0会停下，字符0不会
    // int maxn=max(lena,lenb);
    for(int i=0;i<lena;i++) a[i]=ao[i]-'0';//高->低
    // for(int i=0;i<lenb;i++) b[i]=bo[lenb-1-i]-'0';
    // for(int i=0;i<=maxn;i++){//P1601高精加
    //     int sum=a[i]+b[i]+ans[i];
    //     ans[i]=sum%10;
    //     if(sum>=10) ans[i+1]++;
    // }
    // int lenc;
    // if(ans[maxn]==0) lenc=maxn-1;
    // else lenc=maxn;
    // for(int i=lenc;i>=0;i--) cout<<ans[i];
    // if(lena<lenb) flag=3;//P2142高精减 特别别扭，最好还是把a[0]当成个位
    // else if(lena==lenb){
    //     for(int i=0;i<lena;i++){
    //         if(a[i]<b[i]){
    //             flag=2;
    //             break;
    //         }
    //         else if(a[i]>b[i]){
    //             flag=1;//a更大
    //             break;
    //         }
    //     }
    // }
    // else flag=4;
    // if(flag==0){
    //     cout<<"0";//相等
    //     return 0;
    // }
    // if(flag==1){//位数相同，a更大
    //     int q=0;
    //     for(int i=lena-1;i>=0;i--){
    //         int sum=a[i]-b[i]+ans[i];
    //         if(sum>=0) ans[i]=sum;
    //         else ans[i]=sum+10,ans[i-1]--;
    //     }
    //     for(int i=0;i<=lena;i++){//前导0统计，0(a[0]),0(a[1]),0(a[2]),7(a[3]),三个前导0，从ans[3]开始读
    //         if(ans[i]==0) q++;
    //         else break;
    //     }
    //     for(int i=q;i<lena;i++) cout<<ans[i];
    // }
    // if(flag==2){//位数相同，a更小
    //     int q=0;
    //     cout<<"-";
    //     for(int i=lena-1;i>=0;i--){
    //         int sum=b[i]-a[i]+ans[i];
    //         if(sum>=0) ans[i]=sum;
    //         else ans[i]=sum+10,ans[i-1]--;
    //     }
    //     for(int i=0;i<=lena;i++){
    //         if(ans[i]==0) q++;
    //         else break;
    //     }
    //     for(int i=q;i<lena;i++) cout<<ans[i];
    // }
    // if(flag==3){//a位数少
    //     int q=0;
    //     cout<<"-";
    //     int dif=lenb-lena;
    //     for(int i=lena-1;i>=0;i--) a[i+dif]=a[i],a[i]=0;//记得清空原来的数组内容
    //     for(int i=lenb-1;i>=0;i--){
    //         int sum=b[i]-a[i]+ans[i];
    //         if(sum>=0) ans[i]=sum;
    //         else ans[i]=sum+10,ans[i-1]--;
    //     } 
    //     for(int i=0;i<=lenb;i++){
    //         if(ans[i]==0) q++;
    //         else break;
    //     }
    //     for(int i=q;i<lenb;i++) cout<<ans[i];
    // }
    // if(flag==4){//b位数少
    //     int q=0;
    //     int dif=lena-lenb;
    //     for(int i=lenb-1;i>=0;i--) b[i+dif]=b[i],b[i]=0;
    //     for(int i=lena-1;i>=0;i--){
    //         int sum=a[i]-b[i]+ans[i];
    //         if(sum>=0) ans[i]=sum;
    //         else ans[i]=sum+10,ans[i-1]--;
    //     } 
    //     for(int i=0;i<=lena;i++){
    //         if(ans[i]==0) q++;
    //         else break;
    //     }
    //     for(int i=q;i<lena;i++) cout<<ans[i];
    // }
    // if((lena==1&&a[0]==0)||(lenb==1&&b[0]==0)){//P1303高精乘
    //     cout<<"0\n";
    //     return 0;
    // }
    // for(int i=0;i<lena;i++){//把累加和进位拆分开，不然容易累加超过10但是没有处理
    //     for(int j=0;j<lenb;j++){
    //         int sum=0;
    //         sum=a[i]*b[j];
    //         ans[i+j]+=sum;
    //     }
    // }
    // for(int i=0;i<=lena+lenb;i++){
    //     int cur=0,nxt=0;
    //     cur=ans[i]%10;
    //     nxt=ans[i]/10;
    //     ans[i]=cur;
    //     ans[i+1]+=nxt;
    // }
    // int q=0;
    // for(int i=lena+lenb;i>=0;i--){
    //     if(ans[i]==0) q++;
    //     else break;
    // }
    // for(int i=lena+lenb-q;i>=0;i--) cout<<ans[i];
    // if(lena==1&&a[0]==0){//R298687440高精除，一定要开longlong
    //     cout<<"0\n";
    //     return 0;
    // }
    // long long cur=0,rem=0;
    // for(int i=0;i<lena;i++){
    //     cur=(a[i]+rem*10)/b;
    //     if(cur==0) rem=a[i]+rem*10,ans[i]=0;
    //     else ans[i]=cur,rem=(a[i]+rem*10)%b;
    // }
    // int q=0;
    // for(int i=0;i<lena;i++){
    //     if(ans[i]==0) q++;
    //     else break;
    // }
    // for(int i=q;i<lena;i++) cout<<ans[i];
    return 0;
}