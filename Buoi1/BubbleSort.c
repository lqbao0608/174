#include <stdio.h>

typedef int keyType;
typedef int otherType;
typedef struct {
	keyType key;
	otherType otherFields;
} RecordType;

void swap(RecordType *x, RecordType *y) {
	RecordType temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(RecordType a[], int n) {
	int i, j;
	for(i = 0; i <= n-2; i++) {
		for(j = n-1; j >= i+1; j--) {
			if(a[j].key < a[j-1].key) {
				swap(&a[j], &a[j-1]);
			}
		}
	}
}

void readFromFile(RecordType a[], int *n) { 
	FILE *f = fopen("DaySo.inp", "r");
	fscanf(f, "%d", n);
	int i;
	for(i = 0; i <= (*n)-1; i++) {
		fscanf(f, "%d", &a[i]);
	}
	fclose(f);
}

void inDS(RecordType a[], int n) {
	int i;
	for(i = 0; i <= n-1; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	RecordType a[100];
	int n;
	readFromFile(a, &n);
	printf("Day so:\n");
	inDS(a, n);
	bubbleSort(a, n);
	printf("Day so sau khi sap xep:\n");
	inDS(a, n);
	return 0;
}
