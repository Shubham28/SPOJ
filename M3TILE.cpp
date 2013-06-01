#include <iostream>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define SZ(A) int(A.size())
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
	unsigned int rect[31],increc[31];
	rect[0]=1,increc[0]=1;
	rect[1]=0,increc[1]=1;

	EFOR(all,2,30){
		rect[all]=rect[all-2]+2*increc[all-1];
		increc[all]=rect[all-1]+increc[all-2];
	}

	int inp;
	Input(inp);
	while(inp!=-1){
		if(inp%2)
			printf("0\n");
		else
			printf("%d\n",rect[inp]);

		Input(inp);
	}

	return 0;
}
