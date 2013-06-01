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
	while((ch=getchar())>='0'&&ch<='9');

	N*=sign;
	return;
}

int LIM=46000;

int main()
{
	int T;
	int start,yrs,avl,minim;
	pair<int,int> bonds[10];
	int best[LIM];

	Input(T);

	while(T--){
		Input(start),Input(yrs);
		Input(avl);

		FOR(inp,0,avl){
			Input(bonds[inp].first),Input(bonds[inp].second);
			minim=min(minim,bonds[inp].first);
		}

		EFOR(all,0,LIM){
			best[all]=0;
			FOR(chk,0,avl)
				if((bonds[chk].first/1000)<=all)
					best[all]=max(best[all],best[all-bonds[chk].first/1000]+(bonds[chk].second));
		}

		EFOR(years,1,yrs)
			start+=best[start/1000];

		printf("%d\n",start);
	}

	return 0;
}
