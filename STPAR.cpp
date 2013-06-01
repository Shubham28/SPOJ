#include <list>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
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
	list<int>trc;

	Input(N);
	while(N!=0){
		trc.clear();

		int tmp;
		FOR(ip,0,N){
			Input(tmp);
			PB(trc,tmp);
		}

		stack<int>side;
		int req=1;
		bool ans=1;

		for(list<int>::iterator it=trc.begin();it!=trc.end();){
			if((*it)==req)
				req++,it++;
			else if(!side.empty() && side.top()==req)
				side.pop(),req++;
			else
				side.push(*it),it++;
		}

		for(;req<=N;req++){
			if(!side.empty() && side.top()==req)
				side.pop();
			else {
				ans=0;
				break;
			}
		}
		printf(ans?"yes\n":"no\n");

		Input(N);
	}

	return 0;
}
