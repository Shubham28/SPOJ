#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define LL long long

using namespace std;

int main()
{
	int R=1234,C=5678;
	int rInd[R+5],cInd[C+5];

	FOR(fl,0,R)		rInd[fl]=fl;
	FOR(fl,0,C)		cInd[fl]=fl;

	char ch;
	int fr,to,val;
	while(cin>>ch){

		if(ch=='W')
			scanf("%d",&val);
		else
			scanf("%d %d",&fr,&to);

		if(ch=='R')
			swap(rInd[fr-1],rInd[to-1]);
		else if(ch=='C')
			swap(cInd[fr-1],cInd[to-1]);
		else if(ch=='Q'){
			int rw=rInd[fr-1],cl=cInd[to-1];
			printf("%d\n",rw*C+cl+1);
		} else {
			--val;
			int rw=val/C,cl=val%C;

			FOR(a,0,R)
				if(rInd[a]==rw)
					printf("%d ",a+1);
			FOR(a,0,C)
				if(cInd[a]==cl)
					printf("%d\n",a+1);
		}
	}

	return 0;
}
