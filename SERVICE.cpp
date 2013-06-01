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

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

const int INF=9999999;

int main()
{
	int T,L,N;
	int cst[202][202],rq[1002];
	int opt[2][202][202];

	Input(T);
	while(T--){
		Input(L),Input(N);

		FOR(rw,0,L)		FOR(cl,0,L)
			Input(cst[rw][cl]);

		FOR(in,0,N){
			Input(rq[in]);
			--rq[in];
		}

		FOR(sc,0,L)		FOR(th,sc+1,L)
			opt[0][sc][th]=opt[0][th][sc]=INF;

		opt[0][0][1]=opt[0][1][0]=cst[2][rq[0]];
		opt[0][1][2]=opt[0][2][1]=cst[0][rq[0]];
		opt[0][0][2]=opt[0][2][0]=cst[1][rq[0]];

		FOR(a,0,N-1){

			FOR(sc,0,L)		FOR(th,sc+1,L)
				opt[(a+1)&1][sc][th]=opt[(a+1)&1][th][sc]=INF;

			FOR(sc,0,L)
				FOR(th,sc+1,L){
					if(opt[a&1][sc][th]>=INF)
						continue;

					if(sc!=rq[a+1] && th!=rq[a+1]){
						opt[(a+1)&1][sc][th]=min(opt[(a+1)&1][sc][th],opt[a&1][sc][th]+cst[rq[a]][rq[a+1]]);
						opt[(a+1)&1][th][sc]=opt[(a+1)&1][sc][th];
					}

					if(rq[a]!=rq[a+1] && th!=rq[a+1]){
						opt[(a+1)&1][rq[a]][th]=min(opt[(a+1)&1][rq[a]][th],opt[a&1][sc][th]+cst[sc][rq[a+1]]);
						opt[(a+1)&1][th][rq[a]]=opt[(a+1)&1][rq[a]][th];
					}

					if(rq[a]!=rq[a+1] && sc!=rq[a+1]){
						opt[(a+1)&1][sc][rq[a]]=min(opt[(a+1)&1][sc][rq[a]],opt[a&1][sc][th]+cst[th][rq[a+1]]);
						opt[(a+1)&1][rq[a]][sc]=opt[(a+1)&1][sc][rq[a]];
					}
				}
		}

		int ans=INF;
		FOR(sc,0,L)		FOR(th,sc+1,L)
			ans=min(ans,opt[(N-1)&1][sc][th]);

		printf("%d\n",ans);
	}

	return 0;
}
