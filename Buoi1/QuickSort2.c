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

int findPivot(RecordType a[], int i, int j) {
	int k = i+1;
	keyType firstKey = a[i].key;
	while((k <= j) && (a[k].key == firstKey)) {
		k++;
	}
	if(k > j) {
		return -1;
	}
	if(a[k].key < firstKey) {
		return k;
	}
	return i;
}

int partition(RecordType a[], int i, int j, keyType pivot) {
	int L = i;
	int R = j;
	while(L <= R) {
		while(a[L].key <= pivot) {
			L++;
		}
		while(a[R].key > pivot) {
			R--;
		}
		if(L < R) {
			swap(&a[L], &a[R]);
		}
	}
	return L;
}

void quickSort(RecordType a[], int i, int j) {
	keyType pivot;
	int indexPivot = findPivot(a, i, j);
	int k;
	if(indexPivot != -1) {
		pivot = a[indexPivot].key;
		k = partition(a, i, j, pivot);
		quickSort(a, i, k-1);
		quickSort(a, k, j);
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
	quickSort(a, 0, n-1);
	printf("Day so sau khi sap xep:\n");
	inDS(a, n);
	return 0;
}
