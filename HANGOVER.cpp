#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int main()
{
	double sm[301];
	int L=1;

	sm[L++]=1/(L+1.);

	EFOR(a,2,300)
		sm[L++]=sm[L-1]+1/(a+1.);

	double N;
	scanf("%lf",&N);

	while(N!=0.00){

		int low=0,high=L-1;
		while(low<high){
			int mid=low+(high-low)/2;
			if(sm[mid]>=N)
				high=mid;
			else
				low=mid+1;
		}
		printf("%d card(s)\n",low);

		scanf("%lf",&N);
	}

	return 0;
}
