#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	char prt[3][20];
	MEM(prt,0);
	int L[3];

	while(T--){
		scanf("%s + %s = %s",prt[0],prt[1],prt[2]);
		FOR(ln,0,3)		L[ln]=strlen(prt[ln]);

		if(find(prt[0],prt[0]+L[0],'m')!=prt[0]+L[0]){
			int val=atoi(prt[1]);
			int ans=atoi(prt[2])-val;

			printf("%d + %s = %s\n",ans,prt[1],prt[2]);
		} else if(find(prt[1],prt[1]+L[1],'m')!=prt[1]+L[1]){
			int val=atoi(prt[0]);
			int ans=atoi(prt[2])-val;

			printf("%s + %d = %s\n",prt[0],ans,prt[2]);
		} else 
			printf("%s + %s = %d\n",prt[0],prt[1],atoi(prt[0])+atoi(prt[1]));
	}

	return 0;
}
