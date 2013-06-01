#include <algorithm>
#include <iostream>
#include <cmath>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)

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
	int T;
	int frnds[1001];

	Input(T);
	EFOR(cases,1,T){
		printf("Scenario #%d:\n",cases);

		int targ,num;
		Input(targ),Input(num);

		FOR(inp,0,num)
			Input(frnds[inp]);

		sort(frnds,frnds+num);
		int sum=0;

		RFOR(achv,num-1,0){
			sum+=frnds[achv];
			if(sum>=targ){
				printf("%d\n\n",num-achv);
				sum=-1;
				break;
			}
		}
		if(sum!=-1)
			printf("impossible\n\n");
	}

	return 0;
}
