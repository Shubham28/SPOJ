#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while( (ch=getchar())>='0' && ch<='9');

	return;
}

#define N 100035

int prime[N/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void SieveFast()
{
	memset(prime,-1,sizeof(prime));

	int sqrtN=(int)sqrt((long double)N+1e-7)+1;
	for(int i=3;i<sqrtN+1;i+=2)
		if(gP(i)){
			int i2=i+i;
			for(int j=i*i;j<N;j+=i2)
				rP(j);
		}

	return;
}

int cnt[N];
int ran,K;

int main()
{
	SieveFast();

	cnt[0]=0,cnt[1]=0,cnt[2]=1;
	EFOR(fill,3,100003){
		if(fill&1 && gP(fill))
			cnt[fill]=cnt[fill-1]+1;
		else
			cnt[fill]=cnt[fill-1];
	}

	int T;
	Input(T);
	while(T--){
		Input(ran),Input(K);
		LL ans=0;

		EFOR(chk,2,ran){
			int targ=cnt[chk-1]+K;
			int lo=lower_bound(cnt+chk,cnt+ran+1,targ)-cnt;
			if(lo<=ran)
				ans+=(LL)(ran-lo+1);
		}
		printf("%lld\n",ans);
	}

	return 0;
}
