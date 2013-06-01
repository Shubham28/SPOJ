#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

inline int josephusOrig(int N)
{
	if(N==0 || N==1)
		return N;

	int m=int(log(N+0.0)/log(2.0)+1e-7);
	int pwr=1<<m;

	return ((N-pwr)<<1)+1;
}

int main()
{
	char inp[5];
	inp[0]=' ';
	scanf("%s",inp);

	while(strcmp(inp,"00e0")!=0){
		int N=inp[0]-'0';
		N=(N<<3)+(N<<1)+(inp[1]-'0');
		N*=int(pow(10.0,inp[3]-'0'+0.)+1e-7);
		printf("%d\n",josephusOrig(N));

		scanf("%s",inp);
	}

	return 0;
}
