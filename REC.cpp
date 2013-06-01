#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <limits.h>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

#define ULL unsigned long long

const int MAXD=105,DIG=9,BASE=1000000000;
const ULL BOUND=ULLONG_MAX-(ULL)(BASE*BASE);

struct bignum
{
	int D,digits[MAXD/DIG+2];

	inline void trim()
	{
		while(D>1 && digits[D-1]== 0)
			D--;
	}

	inline void init(long long x)
	{
		memset(digits,0,sizeof(digits));
		D=0;

		do
		{
			digits[D++]=x%BASE;
			x/=BASE;
		} while(x>0);
	}

	inline bignum(long long x)
	{
		init(x);
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

	inline bool operator < (const bignum &o) const
	{
		if(D!=o.D)
			return D<o.D;

		for(int i=D-1;i>=0;i--)
			if(digits[i]!=o.digits[i])
				return digits[i]<o.digits[i];

		return false;
	}

	inline bool operator == (const bignum &o) const
	{
		if(D!=o.D)
			return false;

		for(int i=0;i<D;i++)
			if(digits[i]!=o.digits[i])
				return false;

		return true;
	}

	inline bignum operator << (int p) const
	{
		bignum temp;
		temp.D=D+p;

		for(int i=0;i<D;i++)
			temp.digits[i+p]=digits[i];

		for(int i=0;i<p;i++)
			temp.digits[i]=0;

		return temp;
	}

	inline bignum operator >> (int p) const
	{
		bignum temp;
		temp.D=D-p;

		for(int i=0;i<D-p;i++)
			temp.digits[i]=digits[i+p];

		for(int i=D-p;i<D;i++)
			temp.digits[i]=0;

		return temp;
	}

	inline bignum range(int a,int b) const
	{
		bignum temp=0;
		temp.D=b-a;

		for(int i=0;i<temp.D;i++)
			temp.digits[i]=digits[i+a];

		return temp;
	}

	inline bignum operator + (const bignum &o) const
	{
		bignum sum=o;
		int carry=0;

		for(sum.D=0;sum.D<D || carry>0;sum.D++){
			sum.digits[sum.D]+=(sum.D<D?digits[sum.D]:0)+carry;

			if(sum.digits[sum.D]>=BASE){
				sum.digits[sum.D]-=BASE;
				carry=1;
			} else
				carry=0;
		}

		sum.D=max(sum.D,o.D);
		sum.trim();
		return sum;
	}

	inline bignum operator - (const bignum &o) const
	{
		bignum diff=*this;

		for(int i=0,carry=0;i<o.D || carry>0;i++){
			diff.digits[i]-=(i<o.D?o.digits[i]:0)+carry;

			if(diff.digits[i]<0){
				diff.digits[i]+=BASE;
				carry=1;
			} else
				carry=0;
		}

		diff.trim();
		return diff;
	}

	inline bignum operator * (const bignum &o) const
	{
		bignum prod=0;
		ULL sum=0,carry=0;

		for(prod.D=0;prod.D<D+o.D-1 || carry>0;prod.D++){
			sum=carry%BASE;
			carry/=BASE;

			for(int j=max(prod.D-o.D+1,0);j<=min(D-1,prod.D);j++){
				sum+=(ULL)digits[j]*o.digits[prod.D-j];

				if(sum>=BOUND){
					carry+=sum/BASE;
					sum%=BASE;
				}
			}

			carry+=sum/BASE;
			prod.digits[prod.D]=sum%BASE;
		}

		prod.trim();
		return prod;
	}

	inline double double_div(const bignum &o) const
	{
		double val=0,oval=0;
		int num=0,onum=0;

		for(int i=D-1;i>=max(D-3,0);i--,num++)
			val=val*BASE+digits[i];

		for(int i=o.D-1;i>=max(o.D-3,0);i--,onum++)
			oval=oval*BASE+o.digits[i];

		return val/oval*(D-num>o.D-onum?BASE:1);
	}

	inline pair<bignum,bignum> divmod(const bignum &mod) const
	{
		bignum quot=0,rem=*this,temp;

		for(int i=D-mod.D;i>=0;i--){
			temp=rem.range(i,rem.D);
			int div=(int)temp.double_div(mod);
			bignum mult=mod*div;

			while(div>0 && temp<mult)
			{
				mult=mult-mod;
				div--;
			}

			while(div+1<BASE && !(temp<mult+mod))
			{
				mult=mult+mod;
				div++;
			}

			rem=rem-(mod*div << i);

			if(div>0){
				quot.digits[i]=div;
				quot.D=max(quot.D,i+1);
			}
		}

		quot.trim();
		rem.trim();
		return make_pair(quot,rem);
	}

	inline bignum operator / (const bignum &divisor) const
	{
		return divmod(divisor).first;
	}

	inline bignum operator % (const bignum &mod) const
	{
		return divmod(mod).second;
	}
};

bignum A,B,N,M;
LL a,b,m;
LL ini[2][2];

inline void prod(LL fr[2][2],LL sc[2][2],LL rt[2][2])
{
	rt[0][0]=fr[0][0]*sc[0][0]+fr[0][1]*sc[1][0];
	rt[0][1]=fr[0][0]*sc[0][1]+fr[0][1]*sc[1][1];
	rt[1][0]=fr[1][0]*sc[0][0]+fr[1][1]*sc[1][0];
	rt[1][1]=fr[1][0]*sc[0][1]+fr[1][1]*sc[1][1];

	rt[0][0]%=m,rt[0][1]%=m,rt[1][0]%=m,rt[1][1]%=m;

	return;
}

void binExp(bignum N,LL rt[2][2])
{
	if(N==1){
		memcpy(rt,ini,sizeof(ini));
		return;
	} else {
		LL mid[2][2];
		binExp(N/2,mid);

		prod(mid,mid,rt);
		if(N%2==1){
			mid[0][0]=rt[0][0],mid[0][1]=rt[0][1],mid[1][0]=rt[1][0],mid[1][1]=rt[1][1];
			prod(ini,mid,rt);
		}
		return;
	}
}

int main()
{
	int T;
	scanf("%d",&T);

	char tmp[105];
	while(T--){
		scanf("%s",tmp);	A=tmp;
		scanf("%s",tmp);	B=tmp;
		scanf("%s",tmp);	N=tmp;
		scanf("%lld",&m);	M=int(m);

		if(m==1){
			printf("0\n");
			continue;
		} else if(N==0){
			printf("1\n");
			continue;
		}

		a=atoi((A%M).toStr());
		b=atoi((B%M).toStr());

		ini[0][0]=a,ini[0][1]=b;
		ini[1][0]=0,ini[1][1]=1;

		LL base[2][2];
		binExp(N,base);

		printf("%lld\n",(base[0][0]+base[0][1])%m);
	}

	return 0;
}
