#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

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

int N,C;
int P[1005],rnk[1005];
int wts[1005],comp[1005];
set<int>roots;

void createSet(int nm)
{
	P[nm]=nm,rnk[nm]=0,comp[nm]=1;
	roots.insert(nm);
}

int findSet(int nm)
{
	if(nm!=P[nm])
		P[nm]=findSet(P[nm]);

	return P[nm];
}

void mergeSet(int x,int y)
{
	int px=findSet(x);
	int py=findSet(y);

	if(px==py)		return;

	if(rnk[px]>=rnk[py])		P[py]=px;
	else		P[px]=py;

	if(rnk[px]==rnk[py])	rnk[px]++;

	int chs,nt;
	if(rnk[px]>=rnk[py])	chs=px,nt=py;
	else			chs=py,nt=px;

	roots.erase(nt);
	wts[chs]+=wts[nt];
	comp[chs]+=comp[nt];

	return;
}

int main()
{
	int cost[1005],val[1005],opt[1005];

	Input(N),Input(C);
	while(N!=0 && C!=0){

		roots.clear();
		FOR(in,0,N)		createSet(in);

		FOR(in,0,N)		Input(wts[in]);

		FOR(fr,0,N){
			int tmp;
			Input(tmp);

			FOR(lk,0,tmp){
				int to;
				Input(to);
				mergeSet(fr,to-1);
			}
		}

		int T=0;
		for(set<int>::iterator it=roots.begin();it!=roots.end();it++)
			cost[T]=wts[*it],val[T++]=comp[*it];

		MEM(opt,0);
		FOR(tr,0,T)
			RFOR(v,C,cost[tr]){
				if(opt[v-cost[tr]]+val[tr]>=opt[v])
					opt[v]=opt[v-cost[tr]]+val[tr];
			}

		printf("%d\n",opt[C]);

		Input(N),Input(C);
	}

	return 0;
}
