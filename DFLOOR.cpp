#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

//	Lights Out Puzzle General Problem

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int	R,C;
bool board[18][18],dupl[18][18];
pair<int,int>pos[150];
int len;

inline void change(bool &tile)
{
	tile=!tile;
	return;
}

inline void flip(int row,int col)
{
	int flr[]={0,-1,0,0,1};
	int flc[]={0,0,-1,1,0};

	FOR(chk,0,5)
		if(0<=row+flr[chk] && row+flr[chk]<R && 0<=col+flc[chk] && col+flc[chk]<C)
			change(dupl[row+flr[chk]][col+flc[chk]]);

	return;
}

int main()
{
	char tmp;
	Input(C),Input(R);

	while(R!=0 && C!=0){

		FOR(inpr,0,R)
			FOR(inpc,0,C){
				scanf("%1s",&tmp);
				board[inpr][inpc]=tmp-'0';
			}

		bool done=false;
		FOR(all,0,1<<C){

			len=0;
			FOR(copr,0,R)
				FOR(copc,0,C)
					dupl[copr][copc]=board[copr][copc];

			int cnt=0;
			FOR(mask,0,C)
				if(all&(1<<mask))
					flip(0,mask),cnt+=1,pos[len]=make_pair(1,mask+1),len+=1;

			FOR(rchn,1,R)
				FOR(cchn,0,C){
					if(dupl[rchn-1][cchn]==0)
						flip(rchn,cchn),cnt+=1,pos[len]=make_pair(rchn+1,cchn+1),len+=1;
				}

			FOR(chk,0,C)
				if(dupl[R-1][chk]==0){
					cnt=500;
					break;
				}

			if(cnt!=500){
				printf("%d\n",cnt);
				FOR(seq,0,len)
					printf("%d %d\n",pos[seq].second,pos[seq].first);
				done=true;
				break;
			}
		}

		if(!done)
			printf("-1\n");

		Input(C),Input(R);
	}

	return 0;
}
