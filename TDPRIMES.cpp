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
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

#define MAXX 5000000
char *opos, OutFile[MAXX], DIP[15];

inline void Outp(int x)
{
	int y;
	int dig=0;
	while(x || !dig){
		y=x/10;
		DIP[dig++]=x-((y<<3)+(y<<1))+'0';
		x=y;
	}
	while(dig--)	*opos++=DIP[dig];
}

inline void InitFASTIO()
{
	opos=OutFile;
}

inline void FlushFASTIO()
{
	fwrite(OutFile,opos-OutFile,1,stdout);
}


#define L 100000100
#define UI unsigned int
UI prime[L/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
	memset(prime,-1,sizeof(prime));

	UI i;
	UI sqrtN=(UI)sqrt((double)L)+1;

	for(i=3;i<sqrtN;i+=2)
		if(gP(i)){
			UI i2=i+i;
			for(UI j=i*i;j<L;j+=i2)		rP(j);
		}
}

int main()
{
	InitFASTIO();

	sieve();
	int cnt=2;
	Outp(2);
	*opos++='\n';

	for(int mul=1;mul*6-1<=100000000;mul++){

		if(gP(mul*6-1)){
			cnt++;
			if(cnt%100==1){
				Outp(mul*6-1);
				*opos++='\n';
			}
		}
		if(gP(mul*6+1)){
			cnt++;
			if(cnt%100==1){
				Outp(mul*6+1);
				*opos++='\n';
			}
		}
	}
	FlushFASTIO();

	return 0;
}
