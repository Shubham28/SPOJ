#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SORT(A) sort( A.begin(),A.end() )
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

char X[500011],Y[500011];
char rept[500011];
int lenx,leny,lenrp;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--){
		scanf("%s%s",X,Y);
		lenx=strlen(X),leny=strlen(Y);

		int lo=0,hi=leny/lenx;

		while(lo<hi){
			int mid=lo+(hi-lo+1)/2;
			lenrp=0;

			FOR(fill,0,lenx)
				EFOR(cpy,1,mid)
					rept[lenrp++]=X[fill];

			int subs=0,all=0;
			for(;subs<lenrp && all<leny;all++)
				if(rept[subs]==Y[all])
					++subs;

			if(subs==lenrp)
				lo=mid;
			else
				hi=mid-1;
		}
		printf("%d\n",lo);
	}

	return 0;
}
