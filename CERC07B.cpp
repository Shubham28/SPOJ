#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

//	Lights Out Puzzle General Problem

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
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

int	R,C;
char board[18][18],dupl[18][18];

inline void change(char &tile)
{
	tile=(tile=='X')?'.':'X';
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
	Input(R),Input(C);
	int minim;

	while(R!=0 && C!=0){

		FOR(inp,0,R)
			scanf("%s",board[inp]);

		minim=500;
		FOR(all,0,1<<C){
			FOR(cp,0,R)
				strcpy(dupl[cp],board[cp]);

			int cnt=0;
			FOR(mask,0,C)
				if(all&(1<<mask))
					flip(0,mask),cnt+=1;

			FOR(rchn,1,R)
				FOR(cchn,0,C){
					if(dupl[rchn-1][cchn]=='X')
						flip(rchn,cchn),cnt+=1;
				}

			FOR(chk,0,C)
				if(dupl[R-1][chk]=='X'){
					cnt=500;
					break;
				}

			minim=min(minim,cnt);
		}

		if(minim==500)
			printf("Damaged billboard.\n");
		else
			printf("You have to tap %d tiles.\n",minim);

		Input(R),Input(C);
	}

	return 0;
}

