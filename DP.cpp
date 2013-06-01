#include <vector>
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
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int R,C,D;
char grid[55][55];
pair<int,int>source;
pair<int,int>dest[22];
int dist[55][55];
bool span[55][55];

int num[22];

int movr[]={-1,0,0,1};
int movc[]={0,-1,1,0};

inline int calcWt(char from,char to)
{
	if(from=='X' || to=='X' || from=='$' || to=='$')
		return 2;
	if(abs(from-to)>=2)
		return 999999;
	else if(abs(from-to)==1)
		return 3;
	else
		return 1;
}

void dijkstra()
{
	memset(span,0,sizeof(span));
	FOR(fillr,0,R)
		FOR(fillc,0,C)
			dist[fillr][fillc]=999999;

	dist[source.first][source.second]=0;
	pair<int,int>ver=source;

	while(!span[ver.first][ver.second]){
		span[ver.first][ver.second]=1;

		FOR(dir,0,4){
			int newr=ver.first+movr[dir],newc=ver.second+movc[dir];
			if(0<=newr && newr<R && 0<=newc && newc<C){
				int wt=calcWt(grid[ver.first][ver.second],grid[newr][newc]);
				if(dist[newr][newc]>dist[ver.first][ver.second]+wt)
					dist[newr][newc]=dist[ver.first][ver.second]+wt;
			}
		}

		int minim=9999999;
		pair<int,int>chosen;
		FOR(row,0,R)
			FOR(col,0,C)
				if(span[row][col]==0 && minim>dist[row][col])
					minim=dist[row][col],chosen=make_pair(row,col);

		ver=chosen;
	}
	return;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	Input(T);
	while(T--){
		Input(R),Input(C);
		FOR(inp,0,R)
			scanf("%s",grid[inp]);

		D=0;
		FOR(row,0,R)
			FOR(col,0,C){
				if(grid[row][col]=='$')
					dest[D++]=make_pair(row,col);
				else if(grid[row][col]=='X')
					source=make_pair(row,col);
			}

		dijkstra();

		int ret=999999;
		if(D==0)
			ret=0;
		else if(D==1)
			ret=dist[dest[0].first][dest[0].second];
		else if(D==2)
			ret=max(dist[dest[0].first][dest[0].second],dist[dest[1].first][dest[1].second]);
		else {
			int sum=0;
			FOR(all,0,D){
				num[all]=dist[dest[all].first][dest[all].second];
				sum+=num[all];
			}

			if(sum<99999){
				sort(num,num+D);
				reverse(num,num+D);

				FOR(cmb,1,(1<<D)-1){
					bool dn=0;
					int first=0,secd=0,last=__builtin_ctz(cmb);

					FOR(mask,0,D){
						int bit=(cmb>>mask)&1;

						if(bit==0 && !dn)
							first+=num[mask],dn=1;
						else if(bit==0)
							first+=2*num[mask];
						else if(bit==1 && mask==last)
							secd+=num[mask];
						else
							secd+=2*num[mask];
					}
					ret=min(ret,max(first,secd));
				}
			}
		}
		if(ret>99999)
			printf("-1\n");
		else
			printf("%d\n",ret);
	}

//	fclose(stdin);
	return 0;
}
