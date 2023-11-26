#include <stdio.h>
int main() {
	int a[2][100];
	int i, j, data, n;
	
	scanf("%d", &n);
	for( i=0; i<n; i++ ) {
		scanf("%d", &a[0][i]);
		a[1][i] = 1;
	}	
	for( i=0; i<n; i++) {
		for( j=0; j<n; j++) {
			if(a[0][i] < a[0][j]) a[1][i]++;
		}
	}
	for( i=0; i<n; i++ )
		printf("%d ", a[1][i]);
	return 0;
}
