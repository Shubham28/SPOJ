#include <vector>
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
	int nC2[50001];
	EFOR(fill,0,50000)
		nC2[fill]=fill*(fill-1)/2;

	int N,M;
	Input(N),Input(M);
	while(N!=-1 && M!=-1){
		if(M==0){
			EFOR(pr,1,N)
				printf("%d ",pr);
			printf("\n");
		}

		int lo=lower_bound(nC2,nC2+50000,M)-nC2;
		EFOR(pr,1,N-lo)
			printf("%d ",pr);

		if(nC2[lo]==M){
			RFOR(pr,N,N-lo+1)
				printf("%d ",pr);
			printf("\n");
		} else {
			int dif=M-nC2[lo-1];
			int first=(N-lo+1)+dif;
			printf("%d ",first);

			RFOR(pr,N,N-lo+1)
				if(pr!=first)
					printf("%d ",pr);

			printf("\n");
		}

		Input(N),Input(M);
	}

	return 0;
}
