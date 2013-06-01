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
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0'&&ch<='9');

	N*=sign;
	return;
}

int main()
{
	int X,N;
	Input(N),Input(X);

	int scales[2][21];
	int len[2];
	len[0]=len[1]=0;

	int prs=1;
	while(X!=0 && prs<=N){
		if(X%3==1)
			scales[1][len[1]++]=prs;
		else if(X%3==2)
			scales[0][len[0]++]=prs,X+=1;

		X/=3,prs++;
	}
	if(X!=0)
		printf("-1\n");
	else
		FOR(pr,0,2){
			FOR(wt,0,len[pr]-1)		printf("%d ",scales[pr][wt]);

			if(len[pr])		printf("%d",scales[pr][len[pr]-1]);
			printf("\n");
		}

	return 0;
}
