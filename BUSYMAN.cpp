#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PII pair<int,int>

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

PII sched[100005];

int main()
{
	int T,N;
	Input(T);

	while(T--){
		Input(N);

		FOR(i,0,N)
			Input(sched[i].second),Input(sched[i].first);

		sort(sched,sched+N);

		int tot=1,last=sched[0].first;
		FOR(i,1,N)
			if(sched[i].second>=last)
				tot++,last=sched[i].first;

		printf("%d\n",tot);
	}
	return 0;
}

