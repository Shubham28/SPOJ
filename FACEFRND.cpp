#include <algorithm>
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
#define SZ(A) int(A.size())

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

int main()
{
	int N;
	set<int>frnd,fof;

	Input(N);
	while(N--){
		int dir,cnt,ID;
		Input(dir);

		frnd.insert(dir);
		if(fof.find(dir)!=fof.end())
			fof.erase(dir);

		Input(cnt);
		FOR(a,0,cnt){
			Input(ID);
			if(frnd.find(ID)==frnd.end())
				fof.insert(ID);
		}
	}
	printf("%d\n",SZ(fof));

	return 0;
}
