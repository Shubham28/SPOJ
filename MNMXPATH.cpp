#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define MP(A,B) make_pair(A,B)

using namespace std;


int main()
{
	int T;
	scanf("%d",&T);

	int R,C;
	char A[100001],B[100001];
	while(T--){
		scanf("%d %s",&R,A);
		scanf("%d %s",&C,B);

		int firR1=-1,lstC1=-1,lstR1;
		int firR0=-1,firC0=-1,lstR0,lstC0;

		FOR(rw,0,R){
			if(A[rw]=='1'){
				firR1=(firR1==-1)?rw:firR1;
				lstR1=rw;
			} else {
				firR0=(firR0==-1)?rw:firR0;
				lstR0=rw;
			}
		}

		FOR(cl,0,C){
			if(B[cl]=='1')
				lstC1=cl;
			else {
				firC0=(firC0==-1)?cl:firC0;
				lstC0=cl;
			}
		}

		int mx;

		if(firR1==-1 || lstC1==-1)
			printf("0 ");
		else {
			mx=0;
			EFOR(cl,0,lstC1)		mx+=(B[cl]-'0');
			FOR(rw,firR1+1,R)		mx+=(A[rw]-'0');
			printf("%d ",mx);
		}

		if(firR0==-1 && firC0==-1)
			printf("%d\n",R+C-1);
		else if(firR0==-1)
			printf("%d\n",count(B,B+C,'1'));
		else if(firC0==-1)
			printf("%d\n",count(A,A+R,'1'));
		else
			printf("%d\n",min(firR0,firC0)+min(C-1-lstC0,R-1-lstR0));
	}

	return 0;
}
