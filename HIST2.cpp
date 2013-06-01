#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
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

int N,best,FILL;
int hts[16],perm[16];
int posib[(1<<15)+1][16];
int ways[(1<<15)+1][16];

int maxPerim(int arng,int last)
{

	int &res=posib[arng][last];
	int &cnt=ways[arng][last];

	if(res!=-1)
		return res;

	if(arng==0){
		res=(hts[last]+2*N),cnt=1;
		return res;
	}

	res=-1,cnt=0;
	FOR(all,0,N)
		if(arng&(1<<all)){
			int tmp=abs(hts[all]-hts[last])+maxPerim(arng-(1<<all),all);
			if(tmp==res)
				cnt+=ways[arng-(1<<all)][all];
			else if(tmp>res)
				res=tmp,cnt=ways[arng-(1<<all)][all];
		}

	return res;
}

int main()
{
	Input(N);
	while(N!=0){
		FOR(inp,0,N){
			int tmp;
			Input(tmp);
			hts[inp]=tmp;
		}

		sort(hts,hts+N);
		reverse(hts,hts+N);

		int mid=int(ceil(N/2.0)),pos=0;
		FOR(grt,0,mid)
			perm[pos]=hts[grt],pos+=2;
		pos=1;
		RFOR(less,N-1,mid)
			perm[pos]=hts[less],pos+=2;

		best=N*2;
		best+=(perm[0]+perm[N-1]);
		FOR(dif,1,N)
			best+=abs(perm[dif]-perm[dif-1]);

		FILL=(1<<N)-1;
		memset(posib,-1,sizeof(posib));
		memset(ways,0,sizeof(ways));

		int tot=0;
		FOR(all,0,N){
			int tmp=hts[all]+maxPerim(FILL-(1<<all),all);
			tot+=(tmp==best)?ways[FILL-(1<<all)][all]:0;
		}

		printf("%d %d\n",best,tot);
		Input(N);
	}

	return 0;
}
