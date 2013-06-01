#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(short A=B;A<C;A++)
#define EFOR(A,B,C) for(short A=B;A<=C;A++)
#define RFOR(A,B,C) for(short A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<short>
#define SZ(A) short(A.size())

using namespace std;

int LIM=6105;

int main()
{
	char inp[LIM];
	short cost[LIM][3];

	int T,N;
	scanf("%d",&T);
	while(T--){
		scanf("%s",inp);
		N=strlen(inp);

		FOR(zer,0,N)
			cost[zer][0]=0;

		FOR(len,1,N)
			FOR(pos,0,N-len){
				if(inp[pos]==inp[pos+len])
					cost[pos][len%3]=(len==1)?0:cost[pos+1][(len-2+30)%3];
				else
					cost[pos][len%3]=1+min(cost[pos][(len-1+30)%3],cost[pos+1][(len-1+30)%3]);
			}

		printf("%hd\n",cost[0][(N-1+30)%3]);
	}

	return 0;
}

