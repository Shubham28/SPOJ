#include <list>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int V,E;
int P[10005],rnk[10005];

struct edge{
	int wt,fr,to;
};

edge data[1000005];

int findPrnt(int node)
{
	if(P[node]!=node)
		P[node]=findPrnt(P[node]);

	return P[node];
}

bool isSame(int fr,int to)
{	return (findPrnt(fr)==findPrnt(to));	}

void unionCmp(int fr,int to)
{
	int pr1=findPrnt(fr),pr2=findPrnt(to);

	if(rnk[pr1]>=rnk[pr2])		P[pr2]=pr1;
	else		P[pr1]=pr2;

	if(rnk[pr1]==rnk[pr2])		++rnk[pr1];

	return;
}

inline bool cmpr(edge fir, edge sec)
{		return (fir.wt<sec.wt);		}

LL Kruskal()
{
	sort(data,data+E,cmpr);

	LL cost=0;
	FOR(grdy,0,E){
		int st=data[grdy].fr,en=data[grdy].to;
		if(!isSame(st,en)){
			cost+=data[grdy].wt;
			unionCmp(st,en);
		}
	}

	return cost;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&V);

		char buf[15];
		memset(rnk,0,sizeof(int)*(V+1));
		E=0;

		FOR(c,0,V){
			P[c]=c;

			int deg,vrt,val;
			scanf("%s%d",buf,&deg);
			FOR(i,0,deg){
				scanf("%d%d",&vrt,&val);
				--vrt;
				data[E].fr=c,data[E].to=vrt;
				data[E].wt=val;
				++E;
			}
		}
		printf("%lld\n",Kruskal());
	}

	return 0;
}
