#include <stdio.h>
#define NUM	300
int grid[NUM][NUM];

// MODIFY THIS CODE
int get_mine(int m, int n) {
	int result = 0;
	return result;
}



int main() {
	/* DO NOT MODIFY */
	int i=0, j=0, m=0, n=0, result=0;

	scanf("%d %d", &m, &n);
	for(i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			scanf("%d", &grid[i][j]);
		}
	}
	
	result=get_mine(m,n);
	printf("%d\n", result);
	/* DO NOT MODIFY */
}