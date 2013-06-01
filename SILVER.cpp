#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	while(N!=0){
		printf("%d\n",int(log(N+0.)/log(2.)+1e-9));

		scanf("%d",&N);
	}

	return 0;
}
