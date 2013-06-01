#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

inline void Input(LL &N)
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

int main()
{
	int T;
	scanf("%d",&T);

	int dig[]={2,3,5,7};

	while(T--){
		LL N;
		Input(N);

		char ans[70];

		int L=0;
		while(N!=0){
			N--;
			ans[L++]='0'+dig[N%4];
			N/=4;
		}
		ans[L]=0;
		reverse(ans,ans+L);

		printf("%s\n",ans);
	}

	return 0;
}
