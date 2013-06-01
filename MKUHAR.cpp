#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while( (ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int N,M;
	Input(N),Input(M);

	int need[N+1],pres[N+1];
	int small[N+1],smprice[N+1],large[N+1],lrprice[N+1];

	FOR(inp,0,N){
		Input(need[inp]),Input(pres[inp]);
		Input(small[inp]),Input(smprice[inp]),Input(large[inp]),Input(lrprice[inp]);
	}

	int lo=0,hi=M;

	while(lo<hi){
		int mid=lo+(hi-lo+1)/2;

		int tot=0;
		FOR(ing,0,N){
			int req=need[ing]*mid-pres[ing];
			int best=99999999;

			int lim=int( ceil(req/double(small[ing])) );
			EFOR(sml,0,lim){
				int pur=sml*small[ing];
				int rem=(req>=pur)?int(ceil( (req-pur)/double(large[ing]) )):0;

				best=min(best,sml*smprice[ing]+rem*lrprice[ing]);
			}
			if(best>M || tot+best>M){
				tot=M+1;
				break;
			} else
				tot+=best;
		}

		if(tot<=M)
			lo=mid;
		else
			hi=mid-1;
	}
	printf("%d\n",lo);

	return 0;
}
