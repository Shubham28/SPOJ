#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define PB(A,B) A.push_back(B);
#define SZ(A) int(A.size())

using namespace std;

int main()
{
	int T;
	list<string>URL[101];
	list<string>::iterator it;

	string tmp;
	int val;

	cin>>T;
	EFOR(cs,1,T){
		
		EFOR(cl,0,100)
			URL[cl].clear();

		int mx=0;
		FOR(a,0,10){
			cin>>tmp;
			scanf("%d",&val);

			PB(URL[val],tmp);
			mx=max(mx,val);
		}

		printf("Case #%d:\n",cs);
		for(it=URL[mx].begin();it!=URL[mx].end();it++)
			cout<<(*it)<<"\n";
	}

	return 0;
}
