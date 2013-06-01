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

int main()
{
	LL inp;
	scanf("%lld",&inp);

	if(inp%10==0)
		printf("2\n");
	else
		printf("1\n%d\n",(inp%10));
		
	return 0;
}
