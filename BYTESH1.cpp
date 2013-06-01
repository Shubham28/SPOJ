#include <iostream>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while( (ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	unsigned int fn[100005],gn[100005];
	fn[0]=1,gn[0]=1,fn[1]=1,gn[1]=0;
	int MOD=100000;

	EFOR(fill,2,100001){
		fn[fill]=(fn[fill-1]+fn[fill-2]+2*gn[fill-1])%MOD;
		gn[fill]=(fn[fill-2]+gn[fill-1])%MOD;
	}

	int T;
	Input(T);
	while(T--){
		int N;
		Input(N);
		printf("%u\n",fn[N]%10000);
	}

	return 0;
}
