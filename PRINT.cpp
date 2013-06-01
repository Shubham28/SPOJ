#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

#define N 10000000
unsigned int prime[N/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sievefull()
{
	memset(prime,-1,sizeof(prime));
	unsigned int i;
	unsigned int sqrtN=(unsigned int)sqrt(double(N))+1;

	for(i=3;i<sqrtN;i+=2)
		if(gP(i)){
			unsigned int i2=i+i;
			for(unsigned int j=i*i;j<N;j+=i2)
				rP(j);
			}

	return;
}

bool chk[1000001];
void SieveRange(int L,int U)
{
	int range=U-L+1;
	FOR(fill,0,range)
		chk[fill]=true;

	for(int i=(L%2==0)?0:1;i<range;i+=2)
		chk[i]=false;

	for(int i=3;i*i<=U;i+=2){

		if(i>L && !chk[i-L])
			continue;

		int j=(L/i)*i;
		if(j<L)
			j+=i;
		if(j==i)
			j+=i;
		j-=L;

		for(;j<range;j+=i)
			chk[j]=false;
	}

	if(L==1)
		chk[1-L]=false;
	if(L<=2)
		chk[2-L]=true;

	FOR(i,0,range)
		if(chk[i])
			printf("%d\n",(L+i));

	return;
}

int main()
{
	sievefull();
	int T;
	Input(T);

	int lo,hi;
	while(T--){
		Input(lo),Input(hi);
		if(lo<=2 && hi>=2)
			printf("2\n");
		if(lo<=3 && hi>=3)
			printf("3\n");

		lo=(lo%2)?lo:(lo+1);
		lo=max(lo,5);
		if(lo%6==3)
			lo+=2;

		hi=(hi%2)?hi:(hi-1);

		if(hi<=N){
			int jmp=(lo%6==1)?(lo-1):(lo+1);

			for(int all=jmp;all<=hi;all+=6){
				if((all-1)>=lo && gP(all-1))
					printf("%d\n",all-1);
				if((all+1)<=hi && gP(all+1))
					printf("%d\n",all+1);
			}
		} else if(lo<N){
			for(int all=lo;all<=N;all+=2){
				if(gP(all))
					printf("%d\n",all);
			}
			SieveRange(N+1,hi);
		} else
			SieveRange(lo,hi);
	}

	return 0;
}
