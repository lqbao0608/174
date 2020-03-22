#include <stdio.h>
#include <string.h>

typedef struct {
	char ten[100];
	int trongLuong;
	int giaTri;
	int soLuong;
	int phuongAn;
} DoVat;

void readFromFile(DoVat dsdv[], int *n, int *W) {
	FILE *f = fopen("Balo2.inp", "r");
	fscanf(f, "%d", W);
	int i = 0;
	while(!feof(f)) {
		fscanf(f, "%d", &dsdv[i].trongLuong);
		fscanf(f, "%d", &dsdv[i].giaTri);
		fscanf(f, "%d", &dsdv[i].soLuong);
		fgetc(f);
		fgets(dsdv[i].ten, 100, f);
		if(!feof(f)) {
			dsdv[i].ten[strlen(dsdv[i].ten)-1] = '\0';
		}
		dsdv[i].phuongAn = 0;
		i++;
	}
	*n = i;
	fclose(f);
}

typedef int bang[50][100];

int min(int a, int b) {
	if(a < b) return a;
	else return b;
}

void taoBang(DoVat dsdv[], int n, int W, bang F, bang X) {
	int xk, yk, k;
	int FMax, XMax, V;
	for(V = 0; V <= W; V++) {
		X[0][V] = min(V/(dsdv[0].trongLuong), dsdv[0].soLuong);
		F[0][V] = (X[0][V])*(dsdv[0].giaTri);
	}
	for(k = 1; k <= n-1; k++) {
		for(V = 0; V <= W; V++) {
			FMax = F[k-1][V];
			XMax = 0;
			yk = min(V/(dsdv[k].trongLuong), dsdv[k].soLuong);
			for(xk = 1; xk <= yk; xk++) {
				if(F[k-1][V-(xk*(dsdv[k].trongLuong))] + xk*(dsdv[k].giaTri) > FMax) {
					FMax = F[k-1][V-(xk*(dsdv[k].trongLuong))] + xk*(dsdv[k].giaTri);
					XMax = xk;
				}
			}
			F[k][V] = FMax;
			X[k][V] = XMax;
		}
	}
}

void inBang(int n, int W, bang F, bang X) {
	int V, k;
	for(k = 0; k <= n-1; k++) {
		for(V = 0; V <= W; V++) {
			printf("%4d%2d", F[k][V], X[k][V]);
		}
		printf("\n");
	}
}

void traBang(DoVat dsdv[], int n, int W, bang X) {
	int V = W;
	int k;
	for(k = n-1; k >= 0; k--) {
		dsdv[k].phuongAn = X[k][V];
		V = V - (X[k][V])*(dsdv[k].trongLuong);
	}
}

void inDSDV(DoVat dsdv[], int n, int W) {
	int i;
	int tongTrongLuong = 0;
	int tongGiaTri = 0;
	printf("+-----+--------------------+---------------+----------+----------+----------+\n");
	printf("|%-5s|%-20s|%-15s|%-10s|%-10s|%-10s|\n",
		"STT", "Ten Do Vat", "Trong luong", "Gia tri", "So luong", "Phuong an");
	printf("+-----+--------------------+---------------+----------+----------+----------+\n");
	for(i = 0; i <= n-1; i++) {
		printf("|%-5d", i+1);
		printf("|%-20s", dsdv[i].ten);
		printf("|%-15d", dsdv[i].trongLuong);
		printf("|%-10d", dsdv[i].giaTri);
		printf("|%-10d", dsdv[i].soLuong);
		printf("|%-10d|\n", dsdv[i].phuongAn);
		tongTrongLuong = tongTrongLuong + (dsdv[i].phuongAn)*(dsdv[i].trongLuong);
		tongGiaTri = tongGiaTri + (dsdv[i].phuongAn)*(dsdv[i].giaTri);
	}
	printf("+-----+--------------------+---------------+----------+----------+----------+\n");
	printf("Trong luong cua balo = %d\n", W);
	printf("Tong trong luong = %d\n", tongTrongLuong);
	printf("Tong gia tri = %d\n", tongGiaTri);
}

int main() {
	DoVat dsdv[100];
	int n, W;
	bang F, X;
	readFromFile(dsdv, &n, &W);
	taoBang(dsdv, n, W, F, X);
	inBang(n, W, F, X);
	traBang(dsdv, n, W, X);
	inDSDV(dsdv, n, W);
	return 0;
}
