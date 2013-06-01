#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define LL long long

using namespace std;

inline void Input(LL &N)
{
	LL ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--){
		LL N;
		Input(N);

		if(N&(N-1)){
			LL ans=1;
			int lft=1;

			for(;ans<N;ans<<=1,lft++);

			int rt=0;
			for(;(N&(1<<rt))==0;rt++);

			printf("%lld %d\n",ans,(lft-rt-1));
		} else
			printf("%lld 0\n",N);
	}

	return 0;
}
