#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()

using namespace std;

int T,V;
bool grph[105][105];
int posb[105][105];

bool calPosb(int st,int end)
{
	if(st==end || (end-st)==1 || (st==V-1 && end==0))
		return (posb[st][end]=1);

	int &tmp=posb[st][end];
	if(tmp!=-1)
		return tmp;

	for(int mid=(st+1)%V;mid!=end;mid=(mid+1)%V){
		if(grph[st][mid] || grph[end][mid])
			if(calPosb(st,mid) && calPosb(mid,end))
				return (tmp=1);
	}
	return (tmp=0);
}

int main()
{
	int ans[101];
	int len=0;

	scanf("%d",&T);
	while(T--){
		scanf("%d",&V);

		char tmp[101];
		FOR(fr,0,V){
			scanf("%s",tmp);
			FOR(to,0,V)
				grph[fr][to]=(tmp[to]-'0');
		}

		MEM(posb,-1);
		len=0;
		FOR(fr,0,V){
			FOR(to,0,V)
				if(fr!=to && grph[fr][to])
					if(calPosb(fr,to) && calPosb(to,fr)){
						ans[len++]=fr+1;
						break;
					}
		}

		printf("%d\n",len);
		FOR(pr,0,len)
			printf("%d\n",ans[pr]);
	}

	return 0;
}
