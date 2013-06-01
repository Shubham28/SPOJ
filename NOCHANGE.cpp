#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int main()
{
	int amt,N;
	Input(amt),Input(N);

	int coins[N+1];
	bool posb[amt+2];
	memset(posb,0,sizeof(posb));

	FOR(inp,0,N){
		int tmp;
		Input(tmp);
		coins[inp]=((inp>0)?coins[inp-1]:0)+tmp;
	}

	posb[0]=1;
	FOR(all,0,amt){
		for(int fill=0;fill<N && posb[all];fill++)
			if(all+coins[fill]<=amt)
				posb[all+coins[fill]]=posb[all];
	}

	if(posb[amt])
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
