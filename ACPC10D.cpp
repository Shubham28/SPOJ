#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
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

int main()
{
//	freopen("Input.txt","r",stdin);

	int inp[100005][3];
	int opt[100005][3];
	int N,T;
	scanf("%d",&N);

	while(N!=0){
		++T;
		FOR(in,0,N)
			scanf("%d %d %d",&inp[in][0],&inp[in][1],&inp[in][2]);

		opt[0][0]=500000000;
		opt[0][1]=inp[0][1],opt[0][2]=inp[0][1]+inp[0][2];
		opt[1][0]=opt[0][1]+inp[1][0];
		opt[1][1]=inp[1][1]+min(opt[1][0],min(opt[0][1],opt[0][2]));
		opt[1][2]=inp[1][2]+min(opt[1][1],min(opt[0][1],opt[0][2]));

		FOR(al,2,N){
			opt[al][0]=inp[al][0]+min(opt[al-1][0],opt[al-1][1]);
			opt[al][1]=inp[al][1]+min(opt[al][0],min(opt[al-1][0],min(opt[al-1][1],opt[al-1][2])));
			opt[al][2]=inp[al][2]+min(opt[al][1],min(opt[al-1][1],opt[al-1][2]));
		}
		printf("%d. %d\n",T,opt[N-1][1]);

		scanf("%d",&N);
	}
//	fclose(stdin);
	return 0;
}
