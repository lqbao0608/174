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

void insertionSort(RecordType a[], int n) {
	int i, j;
	for(i = 1; i < n; i++) {
		j = i;
		while((j > 0) && (a[j].key < a[j-1].key)) {
			swap(&a[j], &a[j-1]);
			j--;
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
	insertionSort(a, n);
	printf("Day so sau khi sap xep:\n");
	inDS(a, n);
	return 0;
}
