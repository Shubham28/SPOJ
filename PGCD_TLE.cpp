#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
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

#define L 10000050

unsigned int prime[L/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
	memset(prime,-1,sizeof(prime));

	unsigned int i;
	unsigned int sqrtN=(unsigned int)sqrt((double)L)+1;
	for(i=3;i<sqrtN;i+=2) if(gP(i))
    {
		unsigned int i2=i+i;
		for(unsigned int j=i*i;j<L;j+=i2) rP(j);
	}
}

int prms[664600];

int main()
{
	freopen("Input.txt","r",stdin);
	sieve();

	int T=0;
	prms[T++]=2;
	for(int a=3;a<10000000;a+=2)
		if(gP(a))
			prms[T++]=a;

	FOR(r,1,30){	FOR(c,1,30)
		cout<<__gcd(r,c)<<" ";	cout<<"\n";	}

	fclose(stdin);
	return 0;
}
