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
	int gam,K,L;
	Input(K),Input(L),Input(gam);

	bool win[1000005];

	EFOR(all,1,1000000){
		if(win[all-1]==0)
			win[all]=1;
		else if(all>=K && win[all-K]==0)
			win[all]=1;
		else if(all>=L && win[all-L]==0)
			win[all]=1;
		else
			win[all]=0;
	}

	FOR(inp,0,gam){
		int tmp;
		Input(tmp);
		printf((win[tmp])?"A":"B");
	}

	return 0;
}
