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

void selectionSort(RecordType a[], int n) {
	keyType minKey;
	int i, j, indexMinKey;
	for(i = 0; i <= n-2; i++) {
		minKey = a[i].key;
		indexMinKey = i;
		for(j = i+1; j <= n-1; j++){
			if(a[j].key < minKey){
				minKey = a[j].key;
				indexMinKey = j;
			}
		}
		swap(&a[i], &a[indexMinKey]);
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
	selectionSort(a, n);
	printf("Day so sau khi sap xep:\n");
	inDS(a, n);
	return 0;
}
