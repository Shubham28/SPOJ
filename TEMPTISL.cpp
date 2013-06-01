#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
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
	int N,K,src,dest;
	unsigned LL ways[2][55];

	Input(N),Input(K);
	while(N!=-1 && K!=-1){
		Input(src),Input(dest);
		--src,--dest;

		memset(ways[0],0,sizeof(ways[0]));
		ways[0][src]=1;

		int ch=0;
		EFOR(steps,1,K){
			memset(ways[ch^1],0,sizeof(ways[ch^1]));
			FOR(all,0,N)
				if(ways[ch][all]!=0){
					ways[ch^1][(all-1+N)%N]+=ways[ch][all];
					ways[ch^1][(all+1+N)%N]+=ways[ch][all];
				}
			ch^=1;
		}

		printf("%lld\n",ways[ch][dest]);
		Input(N),Input(K);
	}

	return 0;
}
