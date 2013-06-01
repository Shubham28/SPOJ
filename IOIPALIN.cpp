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

using namespace std;

int main()
{
	int N;
	char inp[5005];
	int cost[3][5005];

	scanf("%d%s",&N,inp);

	MEM(cost[0],0);
	FOR(ps,0,N-1)
		cost[1][ps]=(inp[ps]!=inp[ps+1]);

	FOR(ln,2,N)
		for(int ps=0;ps+ln<N;ps++){
			int &tmp=cost[ln%3][ps];

			tmp=min(1+cost[(ln-1)%3][ps],1+cost[(ln-1)%3][ps+1]);
			if(inp[ps]==inp[ps+ln])
				tmp=min(tmp,cost[(ln-2)%3][ps+1]);
		}

	printf("%d\n",cost[(N-1)%3][0]);
	return 0;
}
