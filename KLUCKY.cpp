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
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

LL klc[8001];

void calLucky()
{
	EFOR(all,1,8000){
		LL pwr=5,ans=0;
		for(int ps=0;(all>>ps)!=0;ps++){

			if((all>>ps)&1)
				ans+=pwr;
			pwr*=5;
		}
		klc[all-1]=ans;
	}
	return;
}

int main()
{
	calLucky();

	int T;		Input(T);
	while(T--){
		int tmp;		Input(tmp);

		printf("%lld\n",klc[tmp-1]);
	}
	
	return 0;
}
