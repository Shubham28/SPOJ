#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
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

int main()
{
//	freopen("Input.txt","r",stdin);

	int total,N;
	pair<int,int>party[101];
	int fun[505];

	Input(total),Input(N);
	while(total!=0 && N!=0){
		FOR(inp,0,N)
			Input(party[inp].first),Input(party[inp].second);

		int ans=-1,pay;
		memset(fun,0,sizeof(fun));
		FOR(chk,0,N)
			RFOR(fill,total,party[chk].first){
				fun[fill]=max(fun[fill],fun[fill-party[chk].first]+party[chk].second);

				if(ans<=fun[fill])
					ans=fun[fill],pay=fill;
			}

		printf("%d %d\n",pay,ans);

		Input(total),Input(N);
	}

//	fcloseall();
	return 0;
}
