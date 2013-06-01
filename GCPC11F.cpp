#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define ALL(A) A.begin(),A.end()
#define SORT(A) sort( A.begin(),A.end() )
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

int main()
{
	string inp;
	int T;
	map<char,int>cnt;

	scanf("%d",&T);
	while(T--){
		cnt.clear();

		getline(cin,inp);
		while(SZ(inp)==0 || (SZ(inp)==1 && !('A'<=inp[0] && inp[0]<='Z')))
			getline(cin,inp);

		int L=SZ(inp);
		if(!('A'<=inp[L-1] && inp[L-1]<='Z'))		--L;

		FOR(a,0,L)
			if(inp[a]!=' ')
				++cnt[inp[a]];

		int mx=-1;
		char let=' ';
		bool psb=1;

		for(map<char,int>::iterator it=cnt.begin();it!=cnt.end();it++){
			if((*it).second>mx){
				mx=(*it).second,let=(*it).first;
				psb=1;
			} else if((*it).second==mx)
				psb=0;
		}

		if(!psb)
			printf("NOT POSSIBLE\n");
		else if(let==' ')
			cout<<inp<<"\n";
		else {
			int dis=(let-'E'+26)%26;
			printf("%d ",dis);

			FOR(pr,0,L){
				if(inp[pr]==' ')
					printf(" ");
				else
					printf("%c",'A'+(inp[pr]-'A'-dis+52)%26);
			}
			printf("\n");
		}
	}

	return 0;
}
