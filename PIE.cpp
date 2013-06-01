#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
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

int main()
{
	int T;
	Input(T);

	while(T--){
		int N,F;
		Input(N),Input(F);
		++F;

		int rad[N];
		FOR(inp,0,N){
			int tmp;
			Input(tmp);
			rad[inp]=tmp;
		}

		double PI=2.0*asin(1);
		double lo=0.0,hi=(*max_element(rad,rad+N));
		hi*=hi,hi*=PI;

		while((hi-lo)>1e-4){
			double mid=lo+(hi-lo)/2.0;
			int cnt=0;

			FOR(chk,0,N){
				double ar=PI*rad[chk]*rad[chk];
				cnt+=int(ar/mid);
			}

			if(cnt>=F)
				lo=mid;
			else
				hi=mid;
		}
		printf("%.4lf\n",lo);
	}

	return 0;
}
