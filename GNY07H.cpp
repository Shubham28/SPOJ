#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');while((ch=getchar())>='0'&&ch<='9');

	N*=sign;
	return;
}

int main()
{
	unsigned int fn[1005],gn[1005],hn[1005];
	fn[0]=fn[1]=gn[1]=hn[1]=1;
	gn[0]=hn[0]=0;

	EFOR(fill,2,1001){
		fn[fill]=fn[fill-1]+fn[fill-2]+2*gn[fill-1]+hn[fill-1];
		gn[fill]=fn[fill-1]+gn[fill-1];
		hn[fill]=fn[fill-1]+hn[fill-2];
	}

	int T;
	Input(T);
	EFOR(inp,1,T){
		int N;
		Input(N);
		printf("%d %u\n",inp,fn[N]);
	}

	return 0;
}
