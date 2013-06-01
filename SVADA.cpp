#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

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

int N,M;
int ak[105],bk[105];
int ck[105],dk[105];

int main()
{
	int tot;
	Input(tot);

	Input(N);
	FOR(inp,0,N)
		Input(ak[inp]),Input(bk[inp]);

	Input(M);
	FOR(inp,0,M)
		Input(ck[inp]),Input(dk[inp]);

	int lo=1,hi=tot;
	while(lo<hi){
		int mid=lo+(hi-lo+1)/2;
		int first=mid,secd=(tot-mid);

		LL fallen=0,open=0;
		FOR(fir,0,N)
			fallen+=(first>=ak[fir])?((first-ak[fir])/bk[fir])+1:0;
		FOR(sec,0,M)
			open+=(secd>=ck[sec])?((secd-ck[sec])/dk[sec])+1:0;

		if(fallen<=open)
			lo=mid;
		else
			hi=mid-1;
	}
	printf("%d\n",lo);

	return 0;
}
