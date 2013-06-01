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
int dist[(1<<16)+1];
int prsnt[17],valid[17];

int calDist(int comb,int chn)
{
	if(chn==N)
		return 0;

	int &res=dist[comb];
	if(res!=-1)
		return res;

	res=999999;
	FOR(all,0,N){
		if((comb&(1<<all))==0){
			int tmpdis=abs(all-chn)+abs(valid[all]-prsnt[chn]);
			tmpdis+=(calDist(comb|(1<<all),chn+1));
			res=min(res,tmpdis);
		}
	}
	return res;
}

int main()
{
	Input(N);
	while(N!=0){

		FOR(inp,0,N){
			int tmp;
			Input(tmp),prsnt[inp]=tmp;
		}
		FOR(inp,0,N){
			int tmp;
			Input(tmp),valid[inp]=tmp;
		}

		memset(dist,-1,sizeof(dist));
		int ans=calDist(0,0);
		printf("%d\n",ans);

		Input(N);
	}

	return 0;
}
