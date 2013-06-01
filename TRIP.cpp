#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define SZ(A) int(A.size())

using namespace std;

char s1[85],s2[85];
int len1,len2;
int len[85][85];
char seq[85];

void trips(int row,int col,int tot)
{
	if(tot==len[len2-1][len1-1]){
		seq[tot]=0;
		printf("%s\n",seq);
		return;
	}
	if(row==len2 || col==len1)
		return;

	int rec=0;
	pair< char,pair<int,int> >pos[85];
	VI done;
	FOR(r,row,len2)
		FOR(c,col,len1){
			if(find(ALL(done),c)!=done.end())
				continue;

			if(s2[r]==s1[c] && len[r][c]==tot+1){
				pos[rec++]=make_pair(s2[r],make_pair(r,c));
				PB(done,c);
				break;
			}
		}

	FOR(i,0,rec)
		FOR(j,i+1,rec){
			if(pos[j].first<pos[i].first)
				swap(pos[i],pos[j]);
		}

	FOR(all,0,rec){
		seq[tot]=pos[all].first;
		trips((pos[all].second).first+1,(pos[all].second).second+1,tot+1);
	}

	return;
}

int main()
{
	int T;
	scanf("%d",&T);
	EFOR(cases,1,T){
		if(cases>1)
			printf("\n");

		scanf("%s%s",s1,s2)	;
		len1=strlen(s1),len2=strlen(s2);
		memset(len,0,sizeof(len));

		FOR(i,0,len2)
			FOR(j,0,len1){
				if(s2[i]==s1[j]){
					if(i>=1 && j>=1)
						len[i][j]=len[i-1][j-1]+1;
					else
						len[i][j]=1;
				} else {
					if(i==0 && j==0)
						len[i][j]=0;
					else if(i==0)
						len[i][j]=len[i][j-1];
					else if(j==0)
						len[i][j]=len[i-1][j];
					else
						len[i][j]=max(len[i-1][j],len[i][j-1]);
				}
			}
		trips(0,0,0);
	}
	return 0;
}
