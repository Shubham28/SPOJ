#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &inp)
{
	int ch;
	inp=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar_unlocked();

	do
		inp=(inp<<3)+(inp<<1)+(ch-'0');
	while((ch=getchar_unlocked())>='0' && ch<='9');

	return;
}

#define N 10000000
int prlen;
unsigned int prime[N/64],prnum[664580];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
    memset(prime,-1,sizeof(prime));

    unsigned int i;
    unsigned int sqrtN=(unsigned int)sqrt((double)N)+1;
    for(i=3;i<sqrtN;i+=2)
		if(gP(i)){
	        unsigned int i2=i+i;
		    for(unsigned int j=i*i;j<N;j+=i2) rP(j);
		}

	return;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	prlen=0;
	prnum[prlen++]=2;
	sieve();

	EFOR(all,3,N)
		if( (all&1) && gP(all) )
			prnum[prlen++]=all;

	int T,ran;
	Input(T);
	while(T--){
		Input(ran);
		if(ran==2)
			printf("1\n");
		else if(ran==3)
			printf("2\n");
		else {
			int cnt=0,lower=ran/2;
			lower+=1;

			int lo=0,hi=prlen-1;
			while(lo<hi){
				int mid=lo+(hi-lo)/2;
				if(prnum[mid]>=lower)
					hi=mid;
				else
					lo=mid+1;
			}
			if(prnum[lo]<lower)
				continue;

			int strt=0,end=prlen-1;
			while(strt<end){
				int mid=strt+(end-strt)/2;
				if(prnum[mid]>ran)
					end=mid;
				else
					strt=mid+1;
			}
			if(prnum[strt]<=ran)
				cnt+=(strt-lo+1);
			else
				cnt+=(strt-lo);

			printf("%d\n",cnt);
		}
	}

//	fclose(stdin);
	return 0;
}
