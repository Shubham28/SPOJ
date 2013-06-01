#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
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

LL data[200005];

int main()
{
	int T;
	Input(T);

	int num;
	while(T--){
		Input(num);
		memset(data,-1,sizeof(LL)*(num+5));

		queue<int>que;
		int rem=1%num;
		data[rem]=1;
		que.push(rem);

		LL ans;
		while(!que.empty()){
			int pres=que.front();
			que.pop();

			if(pres==0){
				ans=data[0];
				break;
			} else {
				int tmp=(pres*10)%num;
				if(data[tmp]==-1){
					data[tmp]=(data[pres]<<1);
					que.push(tmp);
				}

				tmp=(pres*10+1)%num;
				if(data[tmp]==-1){
					data[tmp]=(data[pres]<<1)+1;
					que.push(tmp);
				}
			}
		}

		char ret[75];
		int ln=0;
		for(int pr=0;(1<<pr)<=ans;pr++)
			ret[ln++]='0'+((ans>>pr)&1);
		ret[ln]=0;
		reverse(ret,ret+ln);

		printf("%s\n",ret);
	}

	return 0;
}
