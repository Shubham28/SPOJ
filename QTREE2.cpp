#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

int V;
list<int>cnc[10002],cst[10002];

int levl[10002],P[10002];
int E[30002],L[30002],H[10002];

int dn,dist[10002];

void DFS(int vrt)
{
	E[dn]=vrt,L[dn]=levl[vrt];
	if(H[vrt]==-1)		H[vrt]=dn;
	dn++;

	for(list<int>::iterator nd=cnc[vrt].begin(),vl=cst[vrt].begin();nd!=cnc[vrt].end();nd++,vl++)
		if(levl[*nd]==-1){
			levl[*nd]=levl[vrt]+1,P[*nd]=vrt,dist[*nd]=dist[vrt]+(*vl);
			DFS(*nd);

			E[dn]=vrt,L[dn]=levl[vrt];
			dn++;
		}

	return;
}

int fr,to;
int RM[1<<16];

void init(int ind,int st,int end)
{
	if(st==end)		RM[ind]=st;
	else {
		int nxt=ind<<1,mid=(st+end)>>1;
		init(nxt,st,mid);
		init(nxt+1,mid+1,end);

		RM[ind]=(L[RM[nxt]]<=L[RM[nxt+1]])?RM[nxt]:RM[nxt+1];
	}
	return;
}

int query(int ind,int st,int end)
{
	int p1,p2;

	if(fr>end || to<st)		return -1;
	if(st>=fr && end<=to)		return RM[ind];

	int nxt=ind<<1,mid=(st+end)>>1;
	p1=query(nxt,st,mid);
	p2=query(nxt+1,mid+1,end);

	if(p1==-1)		return p2;
	if(p2==-1)		return p1;
	if(L[p1]<=L[p2])		return p1;

	return p2;
}

int main()
{
	int T;
	char tot[]="DIST",mv[]="KTH",ter[]="DONE";

	scanf("%d",&T);
	while(T--){
		scanf("%d",&V);
		EFOR(fl,0,V)
			cnc[fl].clear(),cst[fl].clear();

		FOR(ed,0,V-1){
			int fr,to,val;
			scanf("%d%d%d",&fr,&to,&val);
			fr--,to--;

			PB(cnc[fr],to);			PB(cnc[to],fr);
			PB(cst[fr],val);		PB(cst[to],val);
		}

		int rt=V>>1;
		MEM(levl,-1);		MEM(H,-1);
		dn=0,levl[rt]=dist[rt]=0,P[rt]=rt;
		DFS(rt);

		init(1,0,dn-1);

		char opt[5];
		scanf("%s",opt);
		while(strcmp(opt,ter)){
			int src,dest;
			scanf("%d%d",&src,&dest);
			src--,dest--;

			fr=H[src],to=H[dest];
			if(fr>to)		swap(fr,to);

			int lca=(fr==to)?src:E[query(1,0,dn-1)];

			if(strcmp(opt,tot)==0){
				int ans=dist[src]+dist[dest]-2*dist[lca];
				printf("%d\n",ans);
			} else if(strcmp(opt,mv)==0){
				int stps;
				scanf("%d",&stps);
				stps--;

				int nd;
				if(stps<=(levl[src]-levl[lca])){
					nd=src;
					for(;nd!=lca && stps!=0;stps--,nd=P[nd]);
				} else{
					stps=levl[dest]+levl[src]-2*levl[lca]-stps;
					nd=dest;
					for(;nd!=lca && stps!=0;stps--,nd=P[nd]);
				}
				printf("%d\n",nd+1);
			}
			scanf("%s",opt);
		}
		printf("\n");
	}

	return 0;
}
