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

inline void Input(int &N)
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
	LL ways[100005];
	MEM(ways,0);

	ways[0]=1;
	int pts[]={2,3,6,7,8};

	FOR(use,0,5)
		for(int p=0;p+pts[use]<=100000;p++)
			ways[p+pts[use]]+=ways[p];

	int N,val;
	Input(N);
	while(N--){
		Input(val);
		printf("%lld\n",ways[val]);
	}

	return 0;
}
