#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

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

int N;
LL comb[(1<<20)+1];
bool pref[21][21];

LL calWays(int calc,int stud)
{
	if(stud==N)
		return 1;

	LL &res=comb[calc];
	if(res!=-1)
		return res;

	res=0;
	FOR(all,0,N){
		if(pref[stud][all] && (calc&(1<<all))==0)
			res+=calWays(calc|(1<<all),stud+1);
	}
	return res;
}

int main()
{
	int T;
	Input(T);

	while(T--){
		Input(N);
		FOR(row,0,N)
			FOR(col,0,N){
				int tmp;
				Input(tmp);
				pref[row][col]=tmp;
			}

		memset(comb,-1,sizeof(comb));
		LL ans=calWays(0,0);
		printf("%lld\n",ans);
	}

	return 0;
}
