#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VL vector<long>
#define VB vector<bool>
#define LL long long

using namespace std;

short cycle[3000001];

void calc_cycle(LL num)
{
	if(num%2==0){
		if(cycle[num/2]==-1)
			calc_cycle(num/2);

		cycle[num]=1+cycle[num/2];
	} else {
		if(3*num+1>=3000001){

			short count=1;
			LL copy=3*num+1;
			while(copy!=1){
				++count;
				if(copy%2)
					copy=3*copy+1;
				else
					copy/=2;

				if(copy<=3000000){
					if(cycle[copy]==-1)
						calc_cycle(copy);

					cycle[num]=count+cycle[copy];
					return;
				}
			}
		}
		if(cycle[3*num+1]==-1)
			calc_cycle(3*num+1);
		
		cycle[num]=1+cycle[3*num+1];
	}
	return;
}

int main()
{
	memset(cycle,-1,sizeof(cycle));
	cycle[1]=1;

	for(LL i=2;i<1000001;i++)
		if(cycle[i]==-1)
			calc_cycle(i);

	LL st,end;
	while (scanf("%lld%lld",&st,&end)!=EOF){
		LL cst=st,cend=end;
		if(st>end)
			swap(st,end);

		short max_cycle=0;
		for(LL i=st;i<=end;i++)	
			max_cycle=(max_cycle<cycle[i])?cycle[i]:max_cycle;

		printf("%lld %lld %d\n",cst,cend,max_cycle);
	}
	return 0;
}
