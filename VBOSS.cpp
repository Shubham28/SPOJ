#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
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
	while( (ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int m,q;
vector< VI >data(30005,VI(3));
int boss[30005],sub[30005];

int main()
{
//	freopen("Input.txt","r",stdin);
	int T;
	Input(T);

	while(T--){
		Input(m),Input(q);

		int nm,sl,ht;
		FOR(inp,0,m){
			Input(nm),Input(sl),Input(ht);
			data[inp][0]=ht,data[inp][1]=sl,data[inp][2]=nm;
		}
		sort(data.begin(),data.begin()+m);

		map<int,int>emp;
		set< pair<int,int> >tmpsal;
		set< pair<int,int> >::iterator it;

		boss[m-1]=-1;
		tmpsal.insert(make_pair(data[m-1][1],m-1));
		RFOR(chk,m-2,0){
			tmpsal.insert(make_pair(data[chk][1],chk));
			it=tmpsal.find(make_pair(data[chk][1],chk));
			++it;
			boss[chk]=(*it).second;
		}

		memset(sub,0,sizeof(sub));
		FOR(all,0,m-1)
			sub[boss[all]]+=sub[all]+1;

		FOR(all,0,m)
			emp[data[all][2]]=all;

		FOR(inp,0,q){
			int quer;
			Input(quer);
			int term=emp[quer];
			printf("%d %d\n",((boss[term])==-1)?0:data[boss[term]][2],sub[term]);
		}

		emp.clear();
	}

	return 0;
}
