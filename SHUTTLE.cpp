#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

#define L 10050
int prime[L/64];

#define gP(n) (n==2 || ( (n&1) && (prime[n>>6]&(1<<((n>>1)&31))) ))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
	MEM(prime,-1);

	int sqrtN=(int)sqrt((double)L)+1;
	for(int i=3;i<sqrtN;i+=2)
		if(gP(i)){
			int i2=i+i;
			for(int j=i*i;j<L;j+=i2)		rP(j);
		}
}

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0'&&ch<='9');

	return;
}

int P=0;
int prm[1250];

int main()
{
	sieve();

	prm[P++]=2;
	for(int chk=3;chk<=L;chk++)
		if(gP(chk))
			prm[P++]=chk;

	int T,N;
	Input(T);

	while(T--){
		Input(N);

		int ans=1,pwr,copy;
		for(int i=0;prm[i]<=N;i++)
			if(N%prm[i]==0){
				copy=N,pwr=0;

				while(copy%prm[i]==0)
					copy/=prm[i],pwr++;

				ans*=( int(pow(prm[i],pwr-1.)*(prm[i]-1)) );
			}

		printf("%d\n",ans);
	}

	return 0;
}
