#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(short A=B;A<C;A++)
#define EFOR(A,B,C) for(short A=B;A<=C;A++)
#define RFOR(A,B,C) for(short A=B;A>=C;A--)
#define SZ(A) short(A.size())
#define LL long long

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	char A[2005],B[2005];
	short cost[2005][2005];

	while(T--){
		scanf("%s%s",A,B);
		short lna=strlen(A),lnb=strlen(B);

		EFOR(fill,0,lna)
			cost[fill][0]=fill;
		EFOR(fill,0,lnb)
			cost[0][fill]=fill;

		EFOR(fir,1,lna)
			EFOR(sec,1,lnb){
				short opt=5000;
				opt=min(opt,short(cost[fir-1][sec]+1));							// Deletion
				opt=min(opt,short(cost[fir][sec-1]+1));							// Insertion
				opt=min(opt,short(cost[fir-1][sec-1]+1));						// Replace
				if(A[fir-1]==B[sec-1])
					opt=min(opt,cost[fir-1][sec-1]);

				cost[fir][sec]=opt;
			}

		printf("%hd\n",cost[lna][lnb]);
	}

	return 0;
}
