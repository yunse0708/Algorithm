// #include <stdio.h>

// int main() {
// 	int a, b;
// 	scanf("%d %d", &a, &b);
// 	int sum = a;
// 	printf("%d", a);
	
// 	for(int i = a+1; i <= b; i++) {
// 		printf(" + %d", i);
// 		sum += i;
// 	}
// 	printf(" = %d", sum);
	
// 	return 0;
// }


#include <stdio.h>

int main() {
	int n, m, sum=0,i;
	scanf("%d %d", &n, &m);
	for(i = n; i<m;i++) {
		printf("%d + ", i); 
		sum+=i;
	}
	printf("%d = %d",i ,sum+i);
	return 0;
}
