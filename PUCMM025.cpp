#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <limits.h>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

#define ULL unsigned long long

// NealWu's BigInteger Library

// MAXD: Maximum number of Digits in Number
const int MAXD=245,DIG=9,BASE=1000000000;
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

int main()
{
	char inp[250];
	int L;
	int dig[10];

	while(scanf("%s",inp)!=EOF){
		MEM(dig,0);
		L=strlen(inp);

		int sum=0;
		FOR(a,0,L){
			sum+=(inp[a]-'0');
			++dig[inp[a]-'0'];
		}

		int ans=dig[1];

		if((inp[L-1]-'0')%2==0)			ans+=dig[2];
		if(sum%3==0)					ans+=dig[3];

		if(L<2 && (inp[L-1]=='4' || inp[L-1]=='8'))
			ans+=dig[4];
		if(L>=2){
			char tmp[3];
			tmp[0]=inp[L-2],tmp[1]=inp[L-1],tmp[2]=0;
			if(atoi(tmp)%4==0)
				ans+=dig[4];
		}

		if(inp[L-1]=='0' || inp[L-1]=='5')		ans+=dig[5];
		if((inp[L-1]-'0')%2==0 && sum%3==0)		ans+=dig[6];

		bignum chk=inp;
		bignum svn=7;
		if(chk%svn==0)
			ans+=dig[7];


		if(L==1 && inp[L-1]=='8')			ans+=dig[8];
		if(L>=2){
			char tmp[5];
			if(L==2)
				tmp[0]='0',tmp[1]=inp[L-2],tmp[2]=inp[L-1],tmp[3]=0;
			else
				tmp[0]=inp[L-3],tmp[1]=inp[L-2],tmp[2]=inp[L-1],tmp[3]=0;

			if(atoi(tmp)%8==0)
				ans+=dig[8];
		}

		if(sum%9==0)		ans+=dig[9];

		printf("%d\n",ans);
	}

	return 0;
}
