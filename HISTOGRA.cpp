#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <stack>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define VI vector<int>
#define PII pair<int,int>
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	return;
}

int hist[100005];

int main()
{
	int N;
	Input(N);
	while(N>0){
		LL mx=0;

		FOR(i,0,N)
			Input(hist[i]);

		stack< PII >incrs;

		PII now;
		int left;
		EFOR(i,0,N){
			while(!incrs.empty() && (i==N || hist[i]<incrs.top().second)){
				now=incrs.top();
				incrs.pop();
				left=-1;

				if(!incrs.empty())
					left=incrs.top().first;

				mx=max(mx,(i-1ll-left)*now.second);
			}

			if(i<N)
				incrs.push(PII(i,hist[i]));
		}
		printf("%lld\n",mx);
		Input(N);
	}

	return 0;
}
