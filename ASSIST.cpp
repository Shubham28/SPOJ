#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define VI vector<int>
#define SZ(A) int(A.size())
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
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int main()
{
//	freopen("Input.txt","r",stdin);
	list<int>cont;
	EFOR(all,2,33825)
		PB(cont,all);

	int ans[3005];
	int len=0;

	for(list<int>::iterator it=cont.begin();SZ(cont)!=0;it=cont.begin()){
		ans[len++]=*(it);
		it=cont.erase(it);
		for(int cnt=1;it!=cont.end();cnt++){
			if(cnt==ans[len-1]){
				it=cont.erase(it);
				cnt=0;
			} else
				it++;
		}
	}

	int N;
	Input(N);
	while(N!=0){
		printf("%d\n",ans[N-1]);
		Input(N);
	}

//	fclose(stdin);
	return 0;
}
