#include <stdio.h>
#include <string.h>

typedef struct {
	int so;
	char chu[100];
	int phuongAn;
} MenhGia;

void readFromFile(MenhGia dsmg[], int *n) {
	FILE *f = fopen("ATM.inp", "r");
	int i = 0;
	while(!feof(f)) {
		fscanf(f, "%d", &dsmg[i].so);
		fgetc(f);
		fgets(dsmg[i].chu, 100, f);
		if(!feof(f)) {
			dsmg[i].chu[strlen(dsmg[i].chu)-1] = '\0';
		}
		dsmg[i].phuongAn = 0;
		i++;
	}
	*n = i;
	fclose(f);
}

void swap(MenhGia *mg1, MenhGia *mg2) {
	MenhGia temp = *mg1;
	*mg1 = *mg2;
	*mg2 = temp;
}

void bubbleSort(MenhGia dsmg[], int n){
	int i, j;
	for(i = 0; i <= n-2; i++) {
		for(j = n-1; j >= i+1; j--) {
			if(dsmg[j].so > dsmg[j-1].so) {
				swap(&dsmg[j], &dsmg[j-1]);
			}
		}
	}
}

void greedy(MenhGia dsmg[], int n, int tienCanRut) {
	int i;
	for(i = 0; i <= n-1; i++) {
		dsmg[i].phuongAn = tienCanRut/(dsmg[i].so);
		tienCanRut = tienCanRut - (dsmg[i].phuongAn)*(dsmg[i].so);
	}
}

void inDSMG(MenhGia dsmg[], int n, int tienCanRut){
	int i;
	int tongTienTra = 0;
	printf("+-----+--------------------+----------+----------+---------------+\n");
	printf("|%-5s|%-20s|%-10s|%-10s|%-15s|\n",
		"STT", "Loai tien", "Menh gia", "So to", "Thanh tien");
	printf("+-----+--------------------+----------+----------+---------------+\n");
	for(i = 0; i <= n-1; i++) {
		printf("|%-5d", i+1);
		printf("|%-20s", dsmg[i].chu);
		printf("|%-10d", dsmg[i].so);
		printf("|%-10d", dsmg[i].phuongAn);
		printf("|%-15d|\n", (dsmg[i].so)*(dsmg[i].phuongAn));
		tongTienTra = tongTienTra + (dsmg[i].phuongAn)*(dsmg[i].so);
	}
	printf("+-----+--------------------+----------+----------+---------------+\n");
	printf("So tien can rut = %d\n", tienCanRut);
	printf("So tien da tra = %d\n", tongTienTra);
}

int main() {
	MenhGia dsmg[100];
	int n;
	readFromFile(dsmg, &n);
	bubbleSort(dsmg, n);
	int tienCanRut;
	printf("Nhap so tien: ");
	scanf("%d", &tienCanRut);
	greedy(dsmg, n, tienCanRut);
	inDSMG(dsmg, n, tienCanRut);
	return 0;
}
