#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	int cost[2][2005],K;
	char inp1[2005],inp2[2005];
	scanf("%s%s%d",inp1,inp2,&K);

	int len1=strlen(inp1),len2=strlen(inp2);
	int ch=0;

	EFOR(row,1,len2){
		EFOR(col,1,len1){
			int both=abs(inp1[col-1]-inp2[row-1]);
			if(row==1)
				both+=K*(col-1);
			else if(col==1)
				both+=K*(row-1);
			else
				both+=cost[ch][col-1];

			int fir=K+((col==1)?K*row:cost[ch^1][col-1]);
			int sec=K+((row==1)?K*col:cost[ch][col]);

			cost[ch^1][col]=min(both,min(fir,sec));
		}
		ch^=1;
	}

	printf("%d\n",cost[ch][len1]);
	return 0;
}
