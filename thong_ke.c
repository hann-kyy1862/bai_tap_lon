#include <stdio.h>
#include <string.h>
#include "thong_ke.h"
//(*)ham thong ke so luong sach trong thu vien
int soLuongSachTV(sach *dsSach, int m){
    int soSach = 0;
    for(int i = 0; i<m; i++)
        soSach += dsSach[i].soLuong;
    return soSach;
}
//ham dem 1 sach dang duoc muon bao nhieu cuon
int demSachM(phieuMuonSach *pMS, int q, char *ISBN, int danhDau[]){
    int dem = 0, k = 0;
    for(int i = 0; i<q; i++){
        for(int j = 0; j < pMS[i].soSach; j++){
            if(strcmp(ISBN, pMS[i].ISBNm[j]) == 0){
                dem ++;
                danhDau[k] = 1;
            }
            k++;
        }
    }
    return dem;
}
//(*)ham thong ke so sach dang duoc muon
void dsSM(sach *dsSach, int m, phieuMuonSach *pMS, int q){
    int danhDau[100] = {0};
    int k = 0, dem = 1;
    for(int i = 0; i<q; i++){
        for(int j = 0; j < pMS[i].soSach; j++){
            if(danhDau[k++] == 1)
                continue;
            printf("\n<<    Thong Tin Sach Duoc Muon %d    >>\n", dem++);
            tenSach(dsSach, m, pMS[i].ISBNm[j]);
            printf("So luong: %d\n", demSachM(pMS,q,pMS[i].ISBNm[j], danhDau));
        }
    }
}
//ham thong ke so luong doc gia tre han tra sach
int soDGTH(phieuMuonSach *pMS, int q, date ngay_hien_tai){
    int dem = 0;
    for(int i = 0; i<q; i++){
        if(soSanhNgay(ngay_hien_tai, pMS[i].ngayTraDK))
            dem++;
    }
    return dem;
}
//(*)ham xuat thong tin doc gia tre han tra sach
void dgTreHan(phieuMuonSach *pMS, int q, docGia *headDG){
    date ngay_hien_tai;
    nhapNgay(&ngay_hien_tai,"hien tai");
    if(soDGTH(pMS,q,ngay_hien_tai))
        printf("\nSo doc gia qua han tra sach: %d\n", soDGTH(pMS,q,ngay_hien_tai));
    else{
        printf("\nKhong co doc gia qua han tra sach!\n");
        return;
    }
    int dem = 0;
    for(int i = 0; i<q; i++){
        if(soSanhNgay(ngay_hien_tai, pMS[i].ngayTraDK)){
            printf("\nDoc gia tre han tra sach %d\n\n",++dem);
            tenDG(headDG,pMS[i].MSSV);
            printf("Ngay muon: %02d/%02d/%d\n", pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam);
            printf("Ngay tra du kien: %02d/%02d/%d\n", pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam);
            printf("So luong: %d\n", pMS[i].soSach);
            printf("Cac ma sach duoc muon: ");
            for(int j = 0; j<pMS[i].soSach; j++){
                printf("%-6s |%c",pMS[i].ISBNm[j], (j+1)%3==0 ? '\n' : ' ');
            }
        }
    }
}