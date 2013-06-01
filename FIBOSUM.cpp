#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

LL MOD=1000000007;

inline LL fib(LL n)
{
	if(n==0)	return 0;

	LL i=n-1,a=1,b=0,c=0,d=1,t;

	while(i>0){
		if(i&1){
			t=d*(b+a)+c*b;		t%=MOD;
 			a=d*b+c*a;			a%=MOD;
			b=t;
		}
		t=d*(2*c+d);		t%=MOD;
		c=c*c+d*d;			c%=MOD;
		d=t;
		i/=2;
	}

	return (a+b)%MOD;
}

int main()
{
	int T,N,M;
	LL ans;

	Input(T);
	while(T--){
		Input(N),Input(M);

		if(N==0)
			ans=fib(M+2)-1;
		else
			ans=fib(M+2)-fib(N+1);

		if(ans<0)	ans+=MOD;
		printf("%lld\n",ans);
	}

	return 0;
}
