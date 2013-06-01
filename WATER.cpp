#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define PII pair<int,int>
#define MP make_pair
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}


int main()
{
	int T,R,C;
	int cb[105][105];
	bool vst[105][105];

	int mr[]={-1,0,0,1};
	int mc[]={0,-1,1,0};

	Input(T);
	while(T--){
		Input(R),Input(C);

		FOR(rw,0,R)		FOR(cl,0,C)		Input(cb[rw][cl]);

		priority_queue< PII, vector< PII >, greater< PII > >cubs;
		MEM(vst,0);

		FOR(rw,0,R){
			vst[rw][0]=vst[rw][C-1]=1;
			cubs.push( MP(cb[rw][0],rw*C) );
			cubs.push( MP(cb[rw][C-1],rw*C+C-1) );
		}

		FOR(cl,1,C-1){
			vst[0][cl]=vst[R-1][cl]=1;
			cubs.push( MP(cb[0][cl],cl) );
			cubs.push( MP(cb[R-1][cl],(R-1)*C+cl) );
		}

		int ans=0;
		while(!cubs.empty()){
			PII now=cubs.top();
			cubs.pop();

			int bld=now.first,rw=now.second/C,cl=now.second%C;
			PII adjc[4];
			int tot=0;

			FOR(mv,0,4){
				int tr=rw+mr[mv],tc=cl+mc[mv];
				if(0<=tr && tr<R && 0<=tc && tc<C && !vst[tr][tc]){
					vst[tr][tc]=1;

					if(cb[tr][tc]<=bld){
						ans+=(bld-cb[tr][tc]);
						adjc[tot++]=MP(bld,tr*C+tc);
					} else
						adjc[tot++]=MP(cb[tr][tc],tr*C+tc);
				}
			}

			FOR(ins,0,tot)	cubs.push(adjc[ins]);
		}

		printf("%d\n",ans);
	}

	return 0;
}
