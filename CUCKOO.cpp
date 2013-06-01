#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <set>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define PII pair<int,int>
#define MP(A,B) make_pair(A,B)
#define SZ(A) int(A.size())

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9')&&ch!='-'&&ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0'&&ch<='9');

	N*=sign;
	return;
}

int N,tbl[10005];
bool cyc[10005][2];
int hsh[10005][2];

int main()
{
	int T;
	Input(T);
	while(T--){
		int wrd,N,inp=0;
		MEM(tbl,-1);

		Input(wrd),Input(N);
		bool ret=1;
		for(;inp<wrd;inp++){
			Input(hsh[inp][0]),Input(hsh[inp][1]);

			if(tbl[hsh[inp][0]]==inp || tbl[hsh[inp][1]]==inp)	continue;
			else if(tbl[hsh[inp][0]]==-1)	tbl[hsh[inp][0]]=inp;
			else if(tbl[hsh[inp][1]]==-1)	tbl[hsh[inp][1]]=inp;

			else {
				int tmp=tbl[hsh[inp][0]],prev=hsh[inp][0];
				MEM(cyc,0);
				tbl[hsh[inp][0]]=inp,cyc[inp][0]=1;

				queue<int>chk,prSt;
				chk.push(tmp);	prSt.push(prev);

				while(!chk.empty()){
					int prs=chk.front(),last=prSt.front();
					chk.pop();	prSt.pop();

					bool alt=(hsh[prs][0]==last);

					if(tbl[hsh[prs][alt]]==-1)	tbl[hsh[prs][alt]]=prs;
					else {
						if(cyc[prs][alt]==1){
							ret=0;
							break;
						}

						tmp=tbl[hsh[prs][alt]],prev=hsh[prs][alt];
						tbl[hsh[prs][alt]]=prs,cyc[prs][alt]=1;
						chk.push(tmp);	prSt.push(prev);
					}
				}
				if(!ret)	break;
			}
		}
		for(inp+=1;inp<wrd;inp++)
			Input(hsh[inp][0]),Input(hsh[inp][1]);

		printf((ret)?"successful hashing\n":"rehash necessary\n");
	}

	return 0;
}
