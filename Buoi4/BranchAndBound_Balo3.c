#include <stdio.h>
#include <string.h>

typedef struct {
	char ten[100];
	float trongLuong;
	float giaTri;
	float donGia;
	int phuongAn; 
} DoVat;

float TGT; // tong gia tri cua cac vat da duoc chon
float TLCL; // trong luong con lai cua balo
float CT; // can tren
float GLNTT; // gia lon nhat tam thoi
int PATNTT[100]; // phuong an tot nhat tam thoi

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

void khoiTao(DoVat dsdv[], int W) {
	TGT = 0.0;
	TLCL = W;
	CT = TLCL*(dsdv[0].donGia);
	GLNTT = 0.0;
}

void ghiNhanKyLuc(DoVat dsdv[], int n){
	int i;
	if(TGT > GLNTT) {
		GLNTT = TGT;
		for(i = 0; i <= n-1; i++) {
			dsdv[i].phuongAn = PATNTT[i];
		}
	}
}

int min(float a, float b) {
	if(a <b) return a;
	else return b;
}

void Try(DoVat dsdv[], int n, int i) {
	int soLuongToiDa = min(TLCL/(dsdv[i].trongLuong), 1);
	int j;
	for(j = soLuongToiDa; j >= 0; j--) {  
		TGT = TGT + j*(dsdv[i].giaTri);
		TLCL = TLCL - j*(dsdv[i].trongLuong);
		CT = TGT + TLCL*(dsdv[i+1].donGia);
		if(CT > GLNTT) {
			PATNTT[i] = j;
			if((i == n-1) || (TLCL == 0.0)) {
				ghiNhanKyLuc(dsdv, n);
			}
			else {
				Try(dsdv, n, i+1);
			}
		}
		PATNTT[i] = 0;
		TGT = TGT - j*(dsdv[i].giaTri);
		TLCL = TLCL + j*(dsdv[i].trongLuong);
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
	khoiTao(dsdv, W);
	Try(dsdv, n, 0);
	inDSDV(dsdv, n, W);
	return 0;
}
