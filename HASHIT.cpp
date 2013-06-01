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
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

char tabl[105][20];
char key[20];

int hashPr()
{
	int ln=strlen(key);
	int val=0;

	FOR(pos,0,ln)
		val+=(key[pos]*(pos+1));
	val*=19;

	return (val%101);
}

int main()
{
	int T;
	char inp[20];

	scanf("%d",&T);
	while(T--){
		int N,cnt=0;
		scanf("%d",&N);
		FOR(fl,0,105)	tabl[fl][0]=0;

		FOR(all,0,N){
			scanf("%s",inp);
			strcpy(key,inp+4);
			int ind=hashPr();

			if(inp[0]=='A'){
				bool mat=0;
				int fir=-1;
				FOR(op,0,20){
					int chk=(ind+op*op+23*op)%101;
					if(tabl[chk][0]==0 && fir==-1)
						fir=chk;
					else if(strcmp(tabl[chk],key)==0){
						mat=1;
						break;
					}
				}
				if(!mat && fir!=-1)
					strcpy(tabl[fir],key),++cnt;

			} else if(inp[0]=='D'){
				FOR(op,0,20){
					int chk=(ind+op*op+23*op)%101;
					if(strcmp(tabl[chk],key)==0){
						tabl[chk][0]=0,--cnt;
						break;
					}
				}
			}
		}

		printf("%d\n",cnt);
		FOR(pr,0,101)
			if(tabl[pr][0]!=0)
				printf("%d:%s\n",pr,tabl[pr]);
	}

	return 0;
}
