#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>

using namespace std;

int main()
{
	int T;
	char stick[205];
	int sweet[205];
	int best[205];

/*	vector< VI >val(205),best(205);
	FOR(row,0,205){
		val[row].assign(205-row,0);
		best[row].assign(205-row,0);
	}
*/

//	Time Complexity = O(n^2)

	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);

		sweet[0]=0;
		FOR(inp,0,N){
			scanf("%1s",&stick[inp]);

			int val=(stick[inp]=='1')?1:-1;
			sweet[inp+1]=sweet[inp]+val;
		}

		best[0]=(stick[0]=='1')?1:0;
		FOR(pos,1,N){
			best[pos]=(sweet[pos+1]>0)?(pos+1):0;

			FOR(brk,0,pos){
				int tmp=(sweet[pos+1]-sweet[brk+1]>0)?(pos-brk):0;
				best[pos]=max(best[pos],tmp+best[brk]);
			}
		}
		printf("%d\n",best[N-1]);

/*		Time Complexity = O(n^3)

		FOR(fill,0,N){
			best[fill][0]=stick[fill]-'0';
			val[fill][0]=(stick[fill]=='1')?1:-1;
		}

		FOR(len,1,N)
			FOR(pos,0,N-len){
				int tbst=(sweet[pos+len+1]-sweet[pos]>0)?(len+1):0;
				int tval=max(0,sweet[pos+len+1]-sweet[pos]);

				FOR(brk,0,len){
					if(val[pos][brk]+val[pos+brk+1][len-brk-1]>0)
						if(tbst<best[pos][brk]+best[pos+brk+1][len-brk-1]){
							tbst=best[pos][brk]+best[pos+brk+1][len-brk-1];
							tval=val[pos][brk]+val[pos+brk+1][len-brk-1];
						}
					if(val[pos][brk]>0)
						if(tbst<best[pos][brk]){
							tbst=best[pos][brk];
							tval=val[pos][brk];
						}
					if(val[pos+brk+1][len-brk-1]>0)
						if(tbst<best[pos+brk+1][len-brk-1]){
							tbst=best[pos+brk+1][len-brk-1];
							tval=val[pos+brk+1][len-brk-1];
						}
				}
				val[pos][len]=tval,best[pos][len]=tbst;
			}

		printf("%d\n",best[0][N-1]);
 */
	}

	return 0;
}
