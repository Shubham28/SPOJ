#include <list>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);

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

list<int>edg[10005];
int dpth[10005];

int bfs(int root)
{
	MEM(dpth,-1);

	queue<int>brd;
	brd.push(root);
	dpth[root]=0;

	int last=root;
	while(!brd.empty()){
		int prs=brd.front();
		brd.pop();

		if(dpth[last]<dpth[prs])
			last=prs;

		for(list<int>::iterator it=edg[prs].begin();it!=edg[prs].end();it++)
			if(dpth[(*it)]==-1){
				dpth[(*it)]=dpth[prs]+1;
				brd.push((*it));
			}
	}

	return last;
}

int main()
{
	int N;

	Input(N);
	int root;
	FOR(in,0,N-1){
		int fr,to;
		Input(fr),Input(to);
		fr--,to--;
		root=fr;

		PB(edg[fr],to);		PB(edg[to],fr);
	}

	int lft=bfs(root);
	int rt=bfs(lft);

	printf("%d\n",dpth[rt]);
	
	return 0;
}
