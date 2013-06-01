#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SORT(A) sort( A.begin(),A.end() )
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-'&& ch!=EOF)
		ch=getchar_unlocked();

	if(ch=='-')
		sign=-1,ch=getchar_unlocked();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar_unlocked())>='0' && ch<='9');

	N*=sign;
	return;
}

int main()
{
	int N;
	scanf("%d",&N);
	int A[N+1],B[N+1],C[N+1],D[N+1];

	FOR(inp,0,N)
		Input(A[inp]),Input(B[inp]),Input(C[inp]),Input(D[inp]);

	int tot=N*N;
	int CD[tot+1];
	int cdlen=0;

	FOR(fir,0,N)
		FOR(sec,0,N)
			CD[cdlen++]=C[fir]+D[sec];

	LL ans=0;
	sort(CD,CD+cdlen);
	FOR(fir,0,N)
		FOR(sec,0,N){
			int targ=-1*(A[fir]+B[sec]);

			int lo=0,hi=cdlen-1;
			while(lo<hi){
				int mid=lo+(hi-lo)/2;
				if(CD[mid]>=targ)
					hi=mid;
				else
					lo=mid+1;
			}
			if(CD[lo]!=targ)
				continue;

			int st=0,end=cdlen-1;
			while(st<end){
				int mid=st+(end-st+1)/2;
				if(CD[mid]<=targ)
					st=mid;
				else
					end=mid-1;
			}
			ans+=(st-lo+1);
		}

	printf("%lld\n",ans);

	return 0;
}
