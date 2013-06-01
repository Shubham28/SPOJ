#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(short A=B;A<C;A++)
#define EFOR(A,B,C) for(short A=B;A<=C;A++)
#define RFOR(A,B,C) for(short A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<short>
#define SZ(A) short(A.size())
#define LL long long

using namespace std;

inline void Input(short &N)
{
	short ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
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
	vector< VI >ways;
	short MOD=1988;

	EFOR(fill,0,5000)
		PB(ways,VI(fill+1,0));

	ways[0][0]=ways[1][1]=1;
	EFOR(row,2,5000){
		EFOR(col,1,row/2){
			ways[row][col]=ways[row-1][col-1]+ways[row-col][col];
			ways[row][col]%=MOD;
		}
		EFOR(col,row/2+1,row){
			ways[row][col]=ways[row-1][col-1];
			ways[row][col]%=MOD;
		}
	}

	short N,K;
	Input(N),Input(K);
	while(N!=0 && K!=0){
		printf("%hd\n",ways[N][K]);
		Input(N),Input(K);
	}

	return 0;
}
