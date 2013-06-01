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

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0'||ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int N;
int B[302][302];
int sR[302],sC[302];

int main()
{
	Input(N);
	MEM(sR,0),MEM(sC,0);

	FOR(rw,0,N)		FOR(cl,0,N){
		Input(B[rw][cl]);
		sR[rw]+=B[rw][cl];
		sC[cl]+=B[rw][cl];
	}

	int ans=0;

//	Case 1: Both in same Row
	FOR(rw,0,N)
		FOR(cl1,0,N)	FOR(cl2,cl1+1,N){
			int val=sR[rw]+sC[cl1]+sC[cl2]-2*B[rw][cl1]-2*B[rw][cl2];
			ans=max(ans,val);
		}

//	Case 2: Both in same Column
	FOR(cl,0,N)
		FOR(rw1,0,N)	FOR(rw2,rw1+1,N){
			int val=sC[cl]+sR[rw1]+sR[rw2]-2*B[rw1][cl]-2*B[rw2][cl];
			ans=max(ans,val);
		}

/*	Case 3: Both in different cells

	Sum = sR[r1] + sR[r2]						(1)
		+ sC[c1] – B[r2][c1] – 2*B[r1][c1]		(2)
		+ sC[c2] – B[r1][c2] – 2*B[r2][c2]		(3)

	If we try all possible ways of choosing r1 and r2,
	we can then independently choose different columns c1 & c2 such that
	the parts (2) and (3) are maximized.
 */

	FOR(r1,0,N)
		FOR(r2,0,N){
			if(r1==r2)	continue;

			int c1,mx1=-1;
			FOR(cl,0,N){
				int val=sC[cl]-B[r2][cl]-2*B[r1][cl];
				if(val>mx1)
					mx1=val,c1=cl;
			}

			int c2,mx2=-1;
			FOR(cl,0,N){
				int val=sC[cl]-B[r1][cl]-2*B[r2][cl];
				if(cl!=c1 && val>mx2)
					mx2=val,c2=cl;
			}

			if(c1<0 || c2<0 || c1==c2 || c1==N || c2==N)	continue;

			int chk=sR[r1]+sR[r2]
					+ sC[c1]-B[r2][c1]-2*B[r1][c1]
					+ sC[c2]-B[r1][c2]-2*B[r2][c2];

			ans=max(ans,chk);
		}

	printf("%d\n",ans);

	return 0;
}
