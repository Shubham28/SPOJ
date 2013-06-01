#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define LL long long
#define LD long double

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

LL nCr[34][34];

inline void calComb()
{
	nCr[0][0]=1;
	EFOR(row,1,34){
		nCr[row][0]=1;
		EFOR(col,1,34)
			nCr[row][col]=nCr[row-1][col-1]+nCr[row-1][col];
	}
	return;
}

int N,lim;
int req[34];
LD prob[34][34];

LD ways(int pos,int G)
{
	if(pos==N)
		return (G==0)?1.:0.;

	LD &tmp=prob[pos][G];
	if(tmp!=-1.0)
		return tmp;

	tmp=0;
	EFOR(use,req[pos],min(G,req[pos]+lim))
		tmp+=ways(pos+1,G-use)*nCr[G][use]/pow(N+0.L,use);

	return tmp;
}

int main()
{
	int T;
	Input(T);

	int G;
	calComb();
	EFOR(cs,1,T){
		Input(G),Input(N);

		FOR(a,0,N)
			Input(req[a]);

		FOR(rw,0,34)	FOR(cl,0,34)
			prob[rw][cl]=-1.0;

		lim=G-accumulate(req,req+N,0);

		LD ans=ways(0,G);
		printf("Case #%d: %.6Lf\n",cs,100*ans);
	}

	return 0;
}
