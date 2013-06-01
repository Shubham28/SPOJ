#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PII pair<int,int>
#define MP(A,B) make_pair(A,B)
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'|| ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int R,C;
char grid[30][30];
int dist[30][30];
bool span[30][30];

int mr[]={-1,0,0,1};
int mc[]={0,-1,1,0};

void dijkstra(PII src)
{
	FOR(fr,0,R)	FOR(fc,0,C)	dist[fr][fc]=9999;
	MEM(span,0);

	dist[src.first][src.second]=0;
	PII ver=src;

	while(span[ver.first][ver.second]==0){
		span[ver.first][ver.second]=1;

		FOR(mv,0,4){
			int tr=ver.first+mr[mv],tc=ver.second+mc[mv];

			if(0<=tr && tr<R && 0<=tc && tc<C && '0'<=grid[tr][tc] && grid[tr][tc]<='9'){
				int wt=grid[tr][tc]-'0';
				if(dist[ver.first][ver.second]+wt<dist[tr][tc])
					dist[tr][tc]=dist[ver.first][ver.second]+wt;
			}
		}

		int minim=999999;
		PII chs;
		FOR(rw,0,R)	FOR(cl,0,C)
			if(!span[rw][cl] && minim>dist[rw][cl])
				minim=dist[rw][cl],chs=MP(rw,cl);

		if(minim==999999)
			return;

		ver=chs;
	}
	return;
}

int main()
{
	Input(C),Input(R);
	while(R!=0 && C!=0){
		FOR(rw,0,R)	scanf("%s",grid[rw]);

		PII src,dst;
		FOR(rw,0,R)	FOR(cl,0,C)	if(grid[rw][cl]=='S'){
			src=MP(rw,cl);
			break;
		}
		FOR(rw,0,R)	FOR(cl,0,C)	if(grid[rw][cl]=='D'){
			dst=MP(rw,cl);
			grid[rw][cl]='0';
			break;
		}

		dijkstra(src);
		printf("%d\n",dist[dst.first][dst.second]);

		Input(C),Input(R);
	}

	return 0;
}
