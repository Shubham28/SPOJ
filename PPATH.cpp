#include <map>
#include <queue>
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

#define N 10050

unsigned int prime[N/64];

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
    memset(prime,-1,sizeof(prime));

    unsigned int i;
    unsigned int sqrtN=(unsigned int)sqrt((double)N)+1;
    for(i=3;i<sqrtN;i+=2) if(gP(i))
    {
        unsigned int i2=i+i;
        for(unsigned int j=i*i;j<N;j+=i2) rP(j);
    }
}

int main()
{
	int T;
	char from[6],to[6];
	short cost[10005];
	sieve();

	Input(T);
	while(T--){
		scanf("%s%s",from,to);

		if(strcmp(from,to)==0)
			printf("0\n");
		else {
			queue<int>que;
			memset(cost,-1,sizeof(cost));

			bool fnd=false;
			int st=atoi(from);
			cost[st]=0;
			que.push(st);

			char buf[6];
			while(!que.empty()){
				int tmp=que.front();
				sprintf(buf,"%d",tmp);
				que.pop();

				if(strcmp(buf,to)==0){
					printf("%d\n",cost[tmp]);
					fnd=1;
					break;
				}

				FOR(pos,0,4)
					EFOR(chng,0,9){
						if( (pos==0 && chng==0) || (buf[pos]-'0'==chng) )
							continue;
						else {
							char swp=buf[pos];
							buf[pos]='0'+chng;
							int chk=atoi(buf);
							if( (chk&1) && gP(chk) && cost[chk]==-1){
								que.push(chk);
								cost[chk]=cost[tmp]+1;
							}
							buf[pos]=swp;
						}
					}
			}
			if(!fnd)
				printf("Impossible\n");
		}
	}

	return 0;
}
