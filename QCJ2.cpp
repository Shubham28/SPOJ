#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
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

// Problem reduces to Catalan Numbers

int N,MOD=761238923;
unsigned int ways[105][105];

/*
int cntways(int pos,int balls)
{
	if(pos==0)
		return (balls==0);

	unsigned int &ret=ways[pos][balls];
	if(ret!=UINT_MAX)
		return ret;

	ret=0;
	int mx=min(pos-1,balls);
	EFOR(all,0,mx){
		ret+=cntways(pos-1,all);
		ret%=MOD;
	}
	return ret;
}
*/

int main()
{
//	freopen("Input.txt","r",stdin);
	unsigned int ans[105];

/*	EFOR(all,1,100){

		EFOR(row,0,all)
			EFOR(col,0,all)
				ways[row][col]=UINT_MAX;

		ans[all]=cntways(all,all);
	}	*/

	ans[0]=1;
	EFOR(all,1,100){
		unsigned LL tmp=0;
		FOR(fir,0,all){
			tmp+=(unsigned LL)ans[fir]*(unsigned LL)ans[all-fir-1];
			tmp%=MOD;
		}
		ans[all]=(unsigned int)tmp;
	}

	int N;
	Input(N);
	while(N!=0){
		printf("%u\n",ans[N]);
		Input(N);
	}

//	fclose(stdin);
	return 0;
}
