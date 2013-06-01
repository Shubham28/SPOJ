#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <queue>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

struct triplet{
	int a,b,c;
};

inline void arng(int &a,int &b,int &c) {
	int val[]={a,b,c};
	sort(val,val+3);
	a=val[0],b=val[1],c=val[2];

	return;
}

int mov[60][60][60];
char adj[60][60];

int main()
{
	int N,p1,p2,p3;

	while(1){
		scanf("%d", &N);
		if(N==0)	break;

		scanf("%d%d%d",&p1,&p2,&p3);
		p1--,p2--,p3--;
		arng(p1,p2,p3);

		FOR(i,0,N)		FOR(j,0,N)
			scanf("%1s",&adj[i][j]);

		MEM(mov,-1);
		queue<struct triplet>que;
		bool ans=0;

		struct triplet prs,tmp;

		prs.a=p1,prs.b=p2,prs.c=p3;
		mov[p1][p2][p3]=0;
		que.push(prs);

		while(!que.empty()){
			prs=que.front();
			que.pop();

			p1=prs.a,p2=prs.b,p3=prs.c;
			if(p1==p2 && p2==p3){
				printf("%d\n",mov[p1][p2][p3]);
				ans=1;
				break;
			}

			int val=mov[p1][p2][p3];
			FOR(i,0,N){

				int chk=i,fr=p2,sc=p3;
				arng(chk,fr,sc);
				if(adj[p1][i]==adj[p2][p3] && mov[chk][fr][sc]==-1){
					mov[chk][fr][sc]=val+1;
					tmp.a=chk,tmp.b=fr,tmp.c=sc;
					que.push(tmp);
				}

				chk=i,fr=p1,sc=p3;
				arng(chk,fr,sc);
				if(adj[p2][i]==adj[p1][p3] && mov[chk][fr][sc]==-1){
					mov[chk][fr][sc]=val+1;
					tmp.a=chk,tmp.b=fr,tmp.c=sc;
					que.push(tmp);
				}

				chk=i,fr=p1,sc=p2;
				arng(chk,fr,sc);
				if(adj[p3][i]==adj[p1][p2] && mov[chk][fr][sc]==-1){
					mov[chk][fr][sc]=val+1;
					tmp.a=chk,tmp.b=fr,tmp.c=sc;
					que.push(tmp);
				}
			}
		}

		if(!ans)
			printf("impossible\n");
	}

	return 0;
}
