#include <stdio.h>

int main() {
    void *vp;
	int a = 100, *ip;
	float f = 12.2, *fp, *i;
	char ch = 'a';
	vp = &a; // valid
	//printf("%d\n", *vp); you can not dereference a void
	// vp = ip; // valid
	// vp = fp; // valid
	printf("%d, %f, %f\n", *ip, *fp, *i);
	ip = (int *) &f;
	printf("%d\n", *ip);
	fp = (float *) ip;
	printf("%d\n", *fp);

	return 0;
}
