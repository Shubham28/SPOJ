#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define VS vector<string>
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

int main()
{
	int N;
	Input(N);
	int num[N];
	FOR(inp,0,N){
		int tmp;
		Input(tmp);
		num[inp]=tmp;
	}

	int rhs[1000001],rlen=0;

	FOR(d,0,N)
		for(int e=0;e<N && num[d]!=0;e++)
			FOR(f,0,N){
				int tmp=num[d]*(num[e]+num[f]);
				rhs[rlen++]=tmp;
			}
	sort(rhs,rhs+rlen);

	int ans=0;
	FOR(a,0,N)
		FOR(b,0,N)
			FOR(c,0,N){
				int left=num[a]*num[b]+num[c];

				int lo=0,hi=rlen-1;
				while(lo<hi){
					int mid=lo+(hi-lo)/2;
					if(rhs[mid]>=left)
						hi=mid;
					else
						lo=mid+1;
				}
				if(rhs[lo]!=left)
					continue;
				else {
					int fir=0,lst=rlen-1;
					while(fir<lst){
						int mid=fir+(lst-fir)/2;
						if(rhs[mid]>left)
							lst=mid;
						else
							fir=mid+1;
					}
					if(rhs[fir]>left)
						ans+=(fir-lo);
					else
						ans+=(fir-lo+1);
				}
			}

	printf("%d\n",ans);

	return 0;
}
