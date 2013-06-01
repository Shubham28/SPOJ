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

LL L,B;

int main()
{
	Input(L),Input(B);
	while(L!=0 && B!=0){
		if(L<B)		swap(L,B);

		LL lcm=L*B/__gcd(L,B);
		LL ans=(lcm/L-1)+(lcm/B-1);
		ans<<=2;

		printf("%lld\n",ans);

		Input(L),Input(B);
	}

	return 0;
}
