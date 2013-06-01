#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <list>
#include <map>
#include <queue>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

int main()
{
//	freopen("Input.txt","r",stdin);
//	freopen("Output.txt","w",stdout);

	int V=0,T=0;
	list<int>adj[10010];
	map<string,int>id;

	bool avail[10010],added[10010];
	MEM(avail,0);

	queue<int>S;
	int inDeg[10010];
	MEM(inDeg,0);

	char inp[500];
	while(scanf("%s",inp)!=EOF){
		if(strlen(inp)==1 && inp[0]=='0')
			break;

		string to(inp);
		if(id.find(to)==id.end())
			id[to]=V++;

		avail[id[to]]=1;
		MEM(added,0);
		while(true){
			scanf("%s",inp);
			if(strlen(inp)==1 && inp[0]=='0')
				break;

			string fr(inp);
			if(id.find(fr)==id.end())
				id[fr]=V++;

			if(added[id[fr]])
				continue;

			PB(adj[id[fr]],id[to]);
			inDeg[id[to]]++;
		}
	}

	FOR(chk,0,V)
		if(inDeg[chk]==0 && avail[chk])
			S.push(chk);

	while(!S.empty()){
		int add=S.front();
		S.pop();

		if(!avail[add])
			continue;

		T++;
		for(list<int>::iterator it=adj[add].begin();it!=adj[add].end();it++){
			inDeg[*it]--;
			if(inDeg[*it]==0)
				S.push(*it);
		}
		adj[add].clear();
	}
	printf("%d\n",T);

	return 0;
}
