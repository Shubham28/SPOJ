#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

#define N 10000100

unsigned int prime[N/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
	MEM(prime,-1);

	unsigned int i;
	unsigned int sqrtN=(unsigned int)sqrt((double)N)+1;
	for(i=3;i<sqrtN;i+=2)
		if(gP(i)){
			unsigned int i2=i+i;
			for(unsigned int j=i*i;j<N;j+=i2) rP(j);
		}
	return;
}

int prms[664605];

int main()
{
	sieve();
	int L=0;
	prms[L++]=2;
	for(int all=3;all<N;all+=2)
		if(gP(all))
			prms[L++]=all;

	int T;
	int fact[100];

	Input(T);
	while(T!=0){
		if(T==2)
			printf("2 = 2\nWith 2 marbles, 1 different rectangles can be constructed.\n");
		else if((T&1) && gP(T))
			printf("%d = %d\nWith %d marbles, 1 different rectangles can be constructed.\n",T,T,T);
		else {
			printf("%d = ",T);

			int dup=T,ind=0,ln=0,prd=1;
			while(dup>1 && prms[ind]*prms[ind]<=dup){
				if(dup%prms[ind]==0){
					int pwr=1;
					fact[ln++]=prms[ind];

					dup/=prms[ind];
					while(dup%prms[ind]==0)
						fact[ln++]=prms[ind],dup/=prms[ind],pwr++;
					prd*=(pwr+1);
				}
				ind++;
			}
			if(dup!=1)
				fact[ln++]=dup,prd*=2;

			FOR(pr,0,ln-1)
				printf("%d * ",fact[pr]);
			printf("%d\n",fact[ln-1]);

			int rt=int(sqrt(T)+1e-9);
			prd=(rt*rt==T)?(prd/2+1):prd/2;

			printf("With %d marbles, %d different rectangles can be constructed.\n",T,prd);
		}
		Input(T);
	}

	return 0;
}
