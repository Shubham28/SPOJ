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
#define ALL(A) A.begin(),A.end()
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>
#define SZ(A) int(A.size())

using namespace std;

int st,end,K;
int cnt[1000005];
vector< VI >sol(12);

inline int cntls(int num)
{
	int lo=0,hi=SZ(sol[K])-1;
	while(lo<hi){
		int mid=lo+(hi-lo+1)/2;
		if(sol[K][mid]<=num)
			lo=mid;
		else
			hi=mid-1;
	}
	if(sol[K][lo]>num)
		return 0;
	return lo+1;
}

int main()
{
	PB(sol[0],1);
	MEM(cnt,0);

	EFOR(i,2,1000000){
		if(cnt[i]==0){
			cnt[i]=1;
			for(int ml=2;i*ml<=1000000;ml++)
				++cnt[i*ml];
		}
		PB(sol[cnt[i]],i);
	}

	int T;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d %d %d\n",&st,&end,&K);
		if(SZ(sol[K])==0){
			printf("0\n");
			continue;
		} else if(K==0){
			if(st<=1 && 1<=end)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}

		int fir=cntls(st-1);
		int sec=cntls(end);
		printf("%d\n",sec-fir);
	}

	return 0;
}
