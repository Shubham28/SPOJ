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
#define VB vector<bool>
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	char inp[1050];

	scanf("%s",inp);
	int N=strlen(inp);

	vector< VB >pal;
	FOR(row,0,N+2)
		PB(pal,VB(N+2-row,false));

	FOR(row,0,N)		pal[row][0]=1;

	FOR(len,1,N)
		FOR(pos,0,N-len){
			if(inp[pos]!=inp[pos+len])
				pal[pos][len]=false;
			else {
				if(len==1)
					pal[pos][len]=true;
				else 
					pal[pos][len]=pal[pos+1][len-2];
			}
		}

	int ans=0;
	FOR(r,0,N)		FOR(c,0,N-r)
		ans+=pal[r][c];

	printf("%d\n",ans);

	return 0;
}
