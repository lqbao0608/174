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

void pushDown(RecordType a[], int first, int last) {
	int r = first;
	while(r <= (last-1)/2) {
		if(last == 2*r+1) {
			if(a[r].key > a[last].key) {
				swap(&a[r], &a[last]);
			}
			r = last;
		}
		else {
			if((a[r].key > a[2*r+1].key) && (a[2*r+1].key <= a[2*r+2].key)) {
				swap(&a[r], &a[2*r+1]);
				r = 2*r+1 ;
			}
			else {
				if((a[r].key > a[2*r+2].key) && (a[2*r+2].key < a[2*r+1].key)) {
					swap(&a[r], &a[2*r+2]);
					r = 2*r+2 ;
				}
				else {
					r = last;
				}
			}
		}
	}
}

void heapSort(RecordType a[], int n) {
	int i;
	for(i = (n-2)/2; i >= 0; i--) {
		pushDown(a, i, n-1);
	}
	for(i = n-1; i >= 2; i--) {
		swap(&a[0], &a[i]);
		pushDown(a, 0, i-1);
	}
	swap(&a[0], &a[1]);
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
	heapSort(a, n);
	printf("Day so sau khi sap xep:\n");
	inDS(a, n);
	return 0;
}
