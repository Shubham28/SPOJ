#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
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

int ar[200005];
int lft[1000002],rht[100002];

unsigned LL merge(int strt,int end)
{
	int mid=(strt+end)/2;
	EFOR(lf,strt,mid)
		lft[lf-strt]=ar[lf];
	EFOR(rt,mid+1,end)
		rht[rt-mid-1]=ar[rt];

	lft[mid+1-strt]=999999999;
	rht[end-mid]=999999999;

	int fir=0,sec=0;
	unsigned LL ans=0;

	EFOR(all,strt,end){
		if(lft[fir]<=rht[sec])
			ar[all]=lft[fir++];
		else {
			ar[all]=rht[sec++];
			ans+=(mid+1-fir-strt);
		}
	}
	return ans;
}

unsigned LL msort(int strt,int end)
{
	unsigned LL ret=0;
	if(strt<end){
		ret+=msort(strt,(strt+end)/2);
		ret+=msort((strt+end)/2+1,end);
		ret+=merge(strt,end);
	}
	return ret;
}

int main()
{
	int T;
	Input(T);
	while(T--){
		int N;
		Input(N);
		FOR(inp,0,N)
			Input(ar[inp]);

		unsigned LL ans=msort(0,N-1);
		printf("%lld\n",ans);
	}

	return 0;
}
