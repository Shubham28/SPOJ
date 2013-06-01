#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(A,B,cnt) for(int A=B;A<cnt;A++)
#define EFOR(A,B,cnt) for(int A=B;A<=cnt;A++)
#define RFOR(A,B,cnt) for(int A=B;A>=cnt;A--)
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
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
	int T,N;
	int men[1001],women[1001];

	Input(T);

	while(T--){
		Input(N);
		FOR(inp,0,N)
			Input(men[inp]);

		FOR(inp,0,N)
			Input(women[inp]);

		sort(men,men+N);
		sort(women,women+N);

		long ans=0;
		FOR(all,0,N)
			ans+=(men[all]*women[all]);
		printf("%ld\n",ans);
	}

	return 0;
}
