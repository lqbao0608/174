#include <stdio.h>
#include <string.h>

typedef struct {
	char ten[100];
	float trongLuong;
	float giaTri;
	float donGia;
	int phuongAn;
} DoVat;

void readFromFile(DoVat dsdv[], int *n, float *W) {
	FILE *f = fopen("Balo3.inp", "r");
	fscanf(f, "%f", W);
	int i = 0;
	while(!feof(f)) {
		fscanf(f, "%f", &dsdv[i].trongLuong);
		fscanf(f, "%f", &dsdv[i].giaTri);
		fgetc(f);
		fgets(dsdv[i].ten, 100, f);
		if(!feof(f)) {
			dsdv[i].ten[strlen(dsdv[i].ten)-1] = '\0';
		}
		dsdv[i].donGia = (dsdv[i].giaTri)/(dsdv[i].trongLuong);
		dsdv[i].phuongAn = 0;
		i++;
	}
	*n = i;
	fclose(f);
}

void swap(DoVat *dv1, DoVat *dv2) {
	DoVat Temp;
	Temp = *dv1;
	*dv1 = *dv2;
	*dv2 = Temp;
}

void bubbleSort(DoVat dsdv[], int n) {
	int i, j;
	for(i = 0; i <= n-2; i++) {
		for(j = n-1; j >= i+1; j--) {
			if(dsdv[j].donGia > dsdv[j-1].donGia) {
				swap(&dsdv[j], &dsdv[j-1]);
			}
		}
	}
}

int min(int a, int b) {
	if(a < b) return a;
	else return b;
}

void greedy(DoVat dsdv[], int n, float W) {
	int i;
	for(i = 0; i <= n-1; i++) {
		dsdv[i].phuongAn = min(W/(dsdv[i].trongLuong), 1);
		W = W - (dsdv[i].phuongAn)*(dsdv[i].trongLuong);
	}
}

void inDSDV(DoVat dsdv[], int n, float W) {
	int i;
	float tongTrongLuong = 0.0;
	float tongGiaTri = 0.0;
	printf("+-----+--------------------+---------------+----------+----------+----------+\n");
	printf("|%-5s|%-20s|%-15s|%-10s|%-10s|%-10s|\n",
		"STT", "Ten Do Vat", "Trong luong", "Gia tri", "Don gia", "Phuong an");
	printf("+-----+--------------------+---------------+----------+----------+----------+\n");
	for(i = 0; i <= n-1; i++) {
		printf("|%-5d", i+1);
		printf("|%-20s", dsdv[i].ten);
		printf("|%-15.2f", dsdv[i].trongLuong);
		printf("|%-10.2f", dsdv[i].giaTri);
		printf("|%-10.2f", dsdv[i].donGia);
		printf("|%-10d|\n", dsdv[i].phuongAn);
		tongTrongLuong = tongTrongLuong + (dsdv[i].phuongAn)*(dsdv[i].trongLuong);
		tongGiaTri = tongGiaTri + (dsdv[i].phuongAn)*(dsdv[i].giaTri);
	}
	printf("+-----+--------------------+---------------+----------+----------+----------+\n");
	printf("Trong luong cua balo = %0.2f\n", W);
	printf("Tong trong luong = %0.2f\n", tongTrongLuong);
	printf("Tong gia tri = %0.2f\n", tongGiaTri);
}

int main() {
	DoVat dsdv[100];
	int n;
	float W;
	readFromFile(dsdv, &n, &W);
	bubbleSort(dsdv, n);
	greedy(dsdv, n, W);
	inDSDV(dsdv, n, W);
	return 0;
}
