#include <stdio.h>
#include <stdlib.h>
#include "ChiSoDien.h"

int main(void)
{
    size_t n = 2;
    ChiSoDien *kh = calloc(n, sizeof *kh);
/*
 *    for (int i = 0; i < n; i++) {
 *        do{
 *            kh[i] = NhapChiSoDien(i+1);
 *            printf("So ma khach hang la: %d\n", kh[i].ma_khach_hang);
 *            printf("\n");
 *        } while(kh[i].ma_khach_hang == -1);
 *    }
 *
 *    if (LuuFileChiSoDien(kh, n, "./TestWrite.bin") == -1) {
 *        printf("Loi luu file\n");
 *        return 0;
 *    }
 */

    int size;
    ChiSoDien *docKH = calloc(0, sizeof *docKH);
    size = DocFileChiSoDien("./Test.bin", &docKH);
    if (size == -1) {
        printf("Loi doc file");
        return 0;
    }

    ChiSoDien chi_so;
    TimChiSoDien("./Test.bin", 1, &chi_so);
    printf("So luong doc duoc la: %d\n", size);
    printf("Ma so khach hang thu nhat la: %d\n", docKH[0].ma_khach_hang);
    printf("Ma khach hang thu 2 la: %d\n", docKH[1].ma_khach_hang);
    printf("Ky thu phi tim duoc la: %d\n", TimKyThuPhi(1, "./Test.bin"));
    printf("Ky thu phi la: %d\n", chi_so.ky_thu_phi);
    printf("Chi so thang truoc la: %d\n", chi_so.chi_so_dien[chi_so.ky_thu_phi - 1]);
    printf("Chi so thang nay la: %d\n", chi_so.chi_so_dien[chi_so.ky_thu_phi - 2]);

    free(docKH);
    free(kh);
    return 0;
}
