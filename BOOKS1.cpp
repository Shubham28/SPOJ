#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <set>
#include <limits.h>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define ALL(A) A.begin(),A.end()
#define LL long long

using namespace std;

/*	Optimal value can also be calculated using Binary Search (Much faster)
	Almost same problem: http://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650
*/

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

int bks,wrt;
int pgs[501];
LL S[501];

set<int>trk;
LL opt[501][501];

LL calOpt(int pos,int rem)
{
	if(rem==1)		return S[pos];

	LL &tmp=opt[pos][rem];
	if(tmp!=-1)
		return tmp;

	tmp=INT_MAX;	tmp<<=2;

	FOR(brk,rem-1,pos){
		LL chk=max(calOpt(brk,rem-1),S[pos]-S[brk]);
		tmp=min(tmp,chk);
	}
	return tmp;
}

int main()
{
	int N;
	Input(N);

	FOR(in,0,N){
		Input(bks),Input(wrt);

		MEM(S,0);
		FOR(a,0,bks){
			Input(pgs[a]);
			S[a+1]=S[a]+pgs[a];
		}

		MEM(opt,-1);
		LL val=calOpt(bks,wrt);

		trk.clear();
		LL prv=0;
		RFOR(rv,bks-1,0){
			if(prv+pgs[rv]<=val)
				prv+=pgs[rv];
			else {
				prv=pgs[rv];
				trk.insert(rv+1);
			}
		}

		int div=1;
		while(SZ(trk)<wrt-1){
			if(trk.find(div)==trk.end())
				trk.insert(div);
			++div;
		}

		FOR(a,0,bks){
			if(trk.find(a)!=trk.end())
				printf("/ ");
			printf("%d ",pgs[a]);
		}
		printf("\n");
	}

	return 0;
}
