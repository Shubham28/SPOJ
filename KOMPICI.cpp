#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	LL sum=0;
	int type[1<<10];
	MEM(type,0);

	bool dig[10];
	char buf[20];

	FOR(a,0,N){
		scanf("%s",buf);

		MEM(dig,0);
		int ln=strlen(buf);
		FOR(ps,0,ln)
			dig[buf[ps]-'0']=1;

		int mask=0;
		EFOR(d,0,9){
			mask|=dig[d];
			mask<<=1;
		}
		mask>>=1;
		++type[mask];
	}

    FOR(fr,0,1<<10)
		FOR(sc,fr+1,1<<10)
			if(fr&sc)
				sum+=(LL)type[fr]*type[sc];

	FOR(all,0,1<<10)
		sum+=(LL)type[all]*(type[all]-1)/2;

	printf("%lld\n",sum);

	return 0;
}
