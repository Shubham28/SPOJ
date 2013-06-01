#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

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
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while( (ch=getchar())>='0' && ch<='9');

	return;
}

int N,X;

int main()
{
	Input(N),Input(X);

	int len=1<<N;
	unsigned int subs[len+1];

	int pwrth[20];
	EFOR(all,0,19)
		pwrth[all]=int(pow(3.0,all));

	FOR(all,0,len){
		unsigned int tmp=0;
		FOR(mask,0,N)
			tmp+=(all&(1<<mask))?pwrth[mask]:0;
		subs[all]=tmp;
	}

	if(subs[len-1]<X){
		printf("-1\n");
		return 0;
	}

	int left,right;
	FOR(chk,0,len){
		int lo=chk+1,hi=len-1;

		while(lo<hi){
			int mid=lo+(hi-lo)/2;
			if(subs[mid]==subs[chk]+X){
				lo=mid;
				break;
			}

			if(subs[mid]>subs[chk]+X)
				hi=mid;
			else
				lo=mid+1;
		}

		if(subs[lo]==subs[chk]+X){
			left=chk,right=lo;
			break;
		}
	}

	FOR(mask,0,N)
		if(left&(1<<mask))
			printf("%d ",mask+1);
	printf("\n");
	FOR(mask,0,N)
		if(right&(1<<mask))
			printf("%d ",mask+1);
	printf("\n");


	return 0;
}
