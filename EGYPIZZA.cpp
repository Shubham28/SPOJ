#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	int quar[]={0,0,0,1};

	int num,den;
	while(N--){
		scanf("%d/%d",&num,&den);

		if(den==2)
			++quar[1];
		else if(num==1)
			++quar[0];
		else
			++quar[2];
	}

	if(quar[0]>0 && quar[2]>0){
		int cnv=min(quar[0],quar[2]);
		quar[0]-=cnv,quar[2]-=cnv;
		quar[3]+=cnv;
	}

	if(quar[1]>1){
		int cnv=quar[1]/2;
		quar[1]-=2*cnv;
		quar[3]+=cnv;
	}
	if(quar[0]>1 && quar[1]>0){
		int cnv=min(quar[0]/2,quar[1]);
		quar[0]-=2*cnv,quar[1]-=cnv;
		quar[3]+=cnv;
	}

	if(quar[0]>3){
		int cnv=quar[0]/4;
		quar[0]-=4*cnv;
		quar[3]+=cnv;
	}

	if(quar[0]>0 && quar[1]>0)
		quar[3]+=1,quar[0]=quar[1]=0;

	if(quar[0]>0)
			quar[0]=1;

	printf("%d\n",accumulate(quar,quar+4,0));

	return 0;
}
