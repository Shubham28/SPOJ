#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define SZ(A) int(A.size())

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
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
	int K,R;
	Input(K),Input(R);

	int M;
	Input(M);

	pair<int,int>loc[M];
	int X,Y;
	FOR(inp,0,M){
		Input(X),Input(Y);
		loc[inp].first=X,loc[inp].second=Y;
	}

	int N;
	Input(N);

	pair<int,int>solit[N];
	int peop[N];
	int S;

	FOR(inp,0,N){
		Input(X),Input(Y),Input(S);
		solit[inp].first=X,solit[inp].second=Y,peop[inp]=S;
	}

	int val[M][N];
	int len[M];
	memset(len,0,sizeof(len));

	FOR(cal,0,M){
		X=loc[cal].first,Y=loc[cal].second;
		int tmpx,tmpy;

		FOR(all,0,N){
			tmpx=solit[all].first,tmpy=solit[all].second;
			int distsqr=(X-tmpx)*(X-tmpx)+(Y-tmpy)*(Y-tmpy);
			if(distsqr<=R*R)
				val[cal][len[cal]++]=all;
		}
	}

	int maxim=0,comp;

	int strt=(1<<K)-1,finsh=0;
	FOR(fill,0,K)
		finsh=(finsh<<1)+1;

	int inc=(finsh>>1)-1;
	finsh=(finsh<<(M-K));

	bool cover[N];

	for(int bits=strt;bits<=finsh;bits++){
		if(inc>=1 && (bits&(bits-1))==0){
			bits+=inc;
			continue;
		}

		if(__builtin_popcount(bits)==K){
			memset(cover,0,sizeof(cover));

			FOR(mask,0,M)
				if(bits&(1<<mask)){
					FOR(chk,0,len[mask])
						cover[val[mask][chk]]=true;
				}

			comp=0;
			FOR(chk,0,N)
				comp+=(cover[chk])?peop[chk]:0;

			maxim=max(maxim,comp);
		}
	}
	printf("%d",maxim);

	return 0;
}
