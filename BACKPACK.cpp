#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define VS vector<string>
#define SZ(A) int(A.size())
#define LL long long

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
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int capac,N;
int gd[65][3];
int best[32005];

int main()
{
	int T;
	Input(T);
	while(T--){
		Input(capac),Input(N);
		map<int,VI>attach;
		map<int,VI>::iterator it;

		FOR(inp,0,N){
			Input(gd[inp][0]),Input(gd[inp][1]),Input(gd[inp][2]);
			if(gd[inp][2]==0){
				PB(attach[inp],inp);
				gd[inp][1]=gd[inp][0]*gd[inp][1];
			}
		}

		FOR(inp,0,N)
			if(gd[inp][2]!=0){
				PB(attach[gd[inp][2]-1],inp);
				gd[inp][1]=gd[inp][0]*gd[inp][1];
			}

		memset(best,0,sizeof(best));
		for(it=attach.begin();it!=attach.end();it++){
			int mainwt=gd[(*it).second[0]][0],mainpr=gd[(*it).second[0]][1];

			RFOR(all,capac,mainwt){
				int tmpbst,vol,pr;
				tmpbst=mainpr+best[all-mainwt];

				if(SZ((*it).second)>=2){
					vol=mainwt+gd[(*it).second[1]][0];
					if(vol<=all){
						pr=mainpr+gd[(*it).second[1]][1]+best[all-vol];
						if(tmpbst<=pr)
							tmpbst=pr;
					}
				}
				if(SZ((*it).second)>=3){
					vol=mainwt+gd[(*it).second[2]][0];
					if(vol<=all){
						pr=mainpr+gd[(*it).second[2]][1]+best[all-vol];
						if(tmpbst<=pr)
							tmpbst=pr;
					}

					vol+=gd[(*it).second[1]][0];
					if(vol<=all){
						pr=mainpr+gd[(*it).second[1]][1]+gd[(*it).second[2]][1]+best[all-vol];
						if(tmpbst<=pr)
							tmpbst=pr;
					}
				}

				if(best[all]<=tmpbst)
					best[all]=tmpbst;
			}
		}

		printf("%d\n",best[capac]);
	}

	return 0;
}
