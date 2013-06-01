#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits.h>
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define ULL unsigned long long
using namespace std;
const int MAXD=1005,DIG=9,BASE=1000000000;
const ULL BOUND=ULLONG_MAX-(ULL)(BASE*BASE);

struct bignum
{
int D,digits[MAXD/DIG+2];
inline void trim()
{
while(D>1 && digits[D-1] == 0)
D--;
}
inline void init(long long x)
{
memset(digits,0,sizeof(digits));
D=0;
do
{
digits[D++]=x%BASE;x/=BASE;
} while(x>0);
}
inline bignum(int x=0)
{
init(x);
}
inline bignum(char *s)
{
memset(digits,0,sizeof(digits));
int len=strlen(s),first=(len+DIG-1)%DIG+1;
D=(len+DIG-1)/DIG;
for(int i=0;i<first;i++)
digits[D-1]=digits[D-1]*10+s[i]-'0';
for(int i=first,d=D-2;i<len;i+=DIG,d--)
for(int j=i;j<i+DIG;j++)
digits[d]=digits[d]*10+s[j]-'0';
trim();
}
inline char *toStr()
{
trim();
char *buf=new char[DIG*D+1];
int pos=0,d=digits[D-1];
do
{
buf[pos++]=d%10+'0';
d/=10;
} while(d>0);
reverse(buf,buf+pos);
for(int i=D-2;i>=0;i--,pos+=DIG)
for(int j=DIG-1,t=digits[i];j>=0;j--){
buf[pos+j]=t%10+'0';
t/=10;
}
buf[pos]='\0';
return buf;
}
inline bignum operator * (const bignum &o) const
{
bignum prod=0;ULL sum=0,carry=0;
for(prod.D=0;prod.D<D+o.D-1 || carry>0;prod.D++){
sum=carry%BASE,carry/=BASE;
for(int j=max(prod.D-o.D+1,0);j <= min(D-1,prod.D);j++){
sum+=(ULL)digits[j]*o.digits[prod.D-j];
if(sum>=BOUND){
carry+=sum/BASE;sum%=BASE;
}
}
carry+=sum/BASE;prod.digits[prod.D]=sum%BASE;
}
prod.trim();
return prod;
}
};
inline void Input(int &N)
{
int ch;N=0;
while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
ch=getchar();
do
N=(N<<3)+(N<<1)+(ch-'0');
while((ch=getchar())>='0' && ch<='9');
return;
}
int main()
{
int T;
Input(T);
bignum fact[101];fact[0]=1,fact[1]=1;
EFOR(cal,2,100){
bignum tmp=cal;
fact[cal]=fact[cal-1]*tmp;
}
while(T--){
int inp;
Input(inp);
printf("%s\n",fact[inp].toStr());
}
return 0;
}
