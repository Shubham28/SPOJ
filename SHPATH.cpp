#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define VI vector<int>

using namespace std;

#define MAXX 15000050
char *ipos, *opos, InpFile[MAXX], OutFile[10000], DIP[30];

inline int InpInt(int flag=0)
{
	while(*ipos<=32)	++ipos;

	if (flag)	return (*ipos++ - '0');

	int x=0,neg=0;
	char c;
	while(true){
		c=*ipos++;
		if(c=='-')	neg=1;
		else {
			if(c<=32)	return (neg?-x:x);
			x=(x<<1)+(x<<3)+(c-'0');
		}
	}
}

inline void InpSt(char *s)
{
	while(*ipos<=32)	++ipos;

	int pos=0;
	char c;
	while(true){
		c=*ipos++;
		if(c<=32){
			s[pos]='\0';
			break;
		} else
			s[pos++] = c;
	}
}

inline void Outp(int x)
{
	int y;
	int dig=0;
	while(x || !dig){
		y=x/10;
		DIP[dig++]=x-((y<<3)+(y<<1))+'0';
		x=y;
	}
	while(dig--)	*opos++=DIP[dig];
}

inline void InitFASTIO()
{
	ipos=InpFile;	opos=OutFile;
	fread(InpFile,MAXX,1,stdin);
}

inline void FlushFASTIO()
{
	fwrite(OutFile,opos-OutFile,1,stdout);
}

#define MX 10001

vector< VI >cost(MX),adj(MX);
int deg[MX];
int dis[MX],que[MX],ind[MX],prev[MX],len;
int V;

int Dijkstra(int S,int T)
{
	FOR(fl,0,V)
		ind[fl]=prev[fl]=-1,dis[fl]=999999999;

	dis[S]=len=0;
	ind[que[len++]=S]=0;
	prev[S]=-2;

	while(len){
		int prs=que[0];
		ind[prs]=-1;

		if(prs==T)	return dis[T];

		que[0]=que[--len];
		if(len)
			ind[que[0]]=0;

		for(int p=0,c=2*p+1;c<len;p=c,c=2*p+1){
			if(c+1<len && dis[que[c+1]]<dis[que[c]])
				c++;

			if(dis[que[c]]>=dis[que[p]])	break;

			swap(que[p],que[c]);
			swap(ind[que[p]],ind[que[c]]);
		}

		for(int k=0,chk=adj[prs][k];k<deg[prs];chk=adj[prs][++k]){
			int nwd=dis[prs]+cost[prs][k];

			if(nwd<dis[chk]){
				dis[chk]=nwd,prev[chk]=prs;
				if(ind[chk]<0){
					ind[que[len]=chk]=len;
					len++;
				}

				for(int c=ind[chk],p=(c-1)/2;dis[que[c]]<dis[que[p]];c=p,p=(c-1)/2){
					swap(que[c],que[p]);
					swap(ind[que[c]],ind[que[p]]);
				}
			}
		}
	}
}

int main()
{
	InitFASTIO();

	int T=InpInt();

	char tmp[12];
	int E,Q;
	while(T--){
		V=InpInt();

		map<string,int>ID;
		MEM(deg,0);
		int to,val;

		FOR(i,0,V){
			InpSt(tmp);
			string name(tmp);
			ID[name]=i;

			cost[i].clear();	adj[i].clear();

			E=InpInt();
			FOR(ed,0,E){
				to=InpInt(),val=InpInt();
				to--;
				PB(cost[i],val);	PB(adj[i],to);
				deg[i]++;
			}
		}

		Q=InpInt();
		FOR(pr,0,Q){
			InpSt(tmp);
			string src(tmp);
			InpSt(tmp);
			string fin(tmp);
			Outp(Dijkstra(ID[src],ID[fin]));
			*opos++='\n';
		}
	}

	FlushFASTIO();
	return 0;
}
