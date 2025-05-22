#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quan_ly_phieu_muon_sach.h"
//ham cap nhap so luong sach con lai
int capNhatSLS(sach *dsSach, char *ISBN, int m, int kieu){
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(ISBN, dsSach[i].ISBN)){
            !kieu ? dsSach[i].soLuong -- :  dsSach[i].soLuong ++;
            if(dsSach[i].soLuong == -1){
                printf("\nThu vien da het sach nay!\n");
                dsSach[i].soLuong ++;
            }
            ghiFileSach(dsSach, m);
            return 0;
        }
    }return 1;
}
//ham tinh ngay tra du kien (so ngay muon toi da la 91 ngay)
date ngayTraDuKien(docGia *headDG, char *MSSV, date ngayMuonSach){
    date ngayTraDK = ngayMuonSach;
    ngayTraDK.ngay = 91 - (ngayTrongThang(ngayMuonSach.thang, ngayMuonSach.nam) - ngayMuonSach.ngay);
    if(++ngayTraDK.thang > 12){
        ngayTraDK.thang = 1;
        ngayTraDK.nam++;
    }
    while(ngayTraDK.ngay > ngayTrongThang(ngayTraDK.thang, ngayTraDK.nam)){
        ngayTraDK.ngay -= ngayTrongThang(ngayTraDK.thang++, ngayTraDK.nam);
        if(ngayTraDK.thang > 12){
            ngayTraDK.thang = 1;
            ngayTraDK.nam++;
        }
    }
    return kiemTraThe(headDG, MSSV, ngayTraDK) ? headDG->ngayHetHanThe : ngayTraDK;
}
//ham nhap danh sach "ma sach" cua nhung sach duoc muon
char **nhapISBN(int soSach, char ISBN[][15]){
    char **ISBNm = (char**)calloc(soSach,sizeof(char*)); 
    for(int i = 0; i<soSach; i++){
        ISBNm[i] = (char*)malloc(strlen(ISBN[i])+1); 
        strcpy(ISBNm[i], ISBN[i]); 
    }return ISBNm;
}
//ham nhap thong tin 1 phieu muon sach
phieuMuonSach themPMS(docGia *headDG, char *MSSV, date ngayMuonSach, int soSach, char ISBN[][15]){
    phieuMuonSach pM;
    pM.MSSV = (char*)malloc(strlen(MSSV)+1);
    strcpy(pM.MSSV,MSSV);
    pM.ngayMuonSach.ngay = ngayMuonSach.ngay; pM.ngayMuonSach.thang = ngayMuonSach.thang; pM.ngayMuonSach.nam = ngayMuonSach.nam;
    pM.ngayTraDK = ngayTraDuKien(headDG, MSSV, ngayMuonSach);
    pM.soSach = soSach;
    pM.ISBNm = nhapISBN(soSach, ISBN);
    return pM;
}
//ham kiem tra MSSV theo danh sach MSSV o doc gia
int kiemTraMSSVdg(docGia *headDG, char *MSSV){
    while(headDG != NULL){
        if(soSanhChuoi(MSSV, headDG->MSSV))
            return 0;
        headDG = headDG->next;
    }
    return 1;
}
//ham kiem tra MSSV o phieu muon sach
int kiemTraMSSVpm(char *MSSV, phieuMuonSach *pMS, int q){
    for(int i = 0; i<q; i++){
        if(strcmp(MSSV,pMS[i].MSSV) == 0)
            return 0;
    }
    return 1;
}
//(*)ham ghi vao file quan ly phieu muon sach
void ghiFilePM(phieuMuonSach *pMS, int q){
    FILE *f = fopen("quanLyPhieuMuon.txt", "w");
    if(f == NULL){
        printf("Loi! thong tin phieu muon sach chua duoc luu!\n");
        return; 
    }
    for(int i = 0; i<q; i++){
        fprintf(f,"| %-15s | %02d/%02d/%-5d | %02d/%02d/%-5d | %d |", pMS[i].MSSV, pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam, pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam, pMS[i].soSach);
        for(int j =0; j<pMS[i].soSach; j++)
            fprintf(f," %-15s |", pMS[i].ISBNm[j]);
        fprintf(f,"\n");
    }
    fclose(f);
}
//(*)ham nhap phieu muon sach
void nhapPMS(phieuMuonSach **pMS, int *q, docGia **headDG, int *n, sach *dsSach, int m){
    int a, dem = 0;
    a = nhap("phieu muon sach");
    *pMS = (phieuMuonSach*)realloc(*pMS, (a + *q) * sizeof(phieuMuonSach));
    char MSSV[15], ISBNm[10][15];
    date ngayMuonSach;
    int soSach;
    for(int i = *q; i< *q+a; i++){
        printf("\n<<    Phieu Muon Sach %d    >>\n", ++dem);
        do{
            int xet=0;
            printf("Nhap ma so sinh vien muon sach: ");
            scanf("%s", MSSV);getchar();
            if(kiemTraMSSVdg(*headDG, MSSV))
                printf("\nMSSV khong duoc tim thay trong the doc gia\n");
            else break;
        }while(1);
        nhapNgay(&ngayMuonSach,"muon sach");
        if(kiemTraThe(*headDG,MSSV,ngayMuonSach)){
            printf("\nThe doc gia da het han!\nTao the moi hoac tra lai tat ca sach da muon truoc do.\n");
            xoaDG(headDG,MSSV,n);
            return;
        }
        do{
            printf("Nhap so sach da muon: ");
            scanf("%d",&soSach);
            if(soSach < 1 || soSach > 10)
                printf("So sach gioi han 1 lan muon la 1 -> 10 cuon.\nVui long nhap lai!\n");
        }while(soSach < 1 || soSach > 10);
        while(getchar() != '\n');
        for(int j = 0; j < soSach; j++){
            do{
                printf("Nhap ma sach da muon %d: ", j+1);
                scanf("%s", ISBNm[j]); getchar();
                if(capNhatSLS(dsSach, ISBNm[j], m, 0))
                    printf("\nISBN khong duoc tim thay. Hay nhap lai!n");
                else break;
            }while(1);
        }
        (*pMS)[i] = themPMS(*headDG, MSSV, ngayMuonSach, soSach, ISBNm);
    }// *a = a[0] = b kieu *sach => *(a)[0] = a[0][0] = b[0] kieu sach
    *q += a;
    ghiFilePM(*pMS, *q);
    ghiFileDG(*headDG);
    ghiFileSach(dsSach, m);
}
//(*)ham xuat danh sach cac sach duoc muon boi 1 doc gia theo MSSV
void xuatSachMuon(phieuMuonSach *pMS, int q, sach *dsSach, int m, docGia *headDG){
    char MSSV[15];
    int dem = 0;
    do{
        printf("\nNhap MSSV: ");
        scanf("%s", MSSV); getchar();
        if(kiemTraMSSVpm(MSSV, pMS, q))
            printf("\nMSSV khong duoc tim thay trong danh sach phieu muon.\n");
    }while(kiemTraMSSVpm(MSSV, pMS, q));
    tenDG(headDG, MSSV);
    for(int i = 0; i<q; i++){
        if(soSanhChuoi(MSSV, pMS[i].MSSV)){
            printf("Ngay muon sach: %02d/%02d/%d\n",pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam);
            printf("Ngay tra sach du kien: %02d/%02d/%d\n",pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam);
            for(int j = 0; j < pMS[i].soSach; j++){
                printf("\n<<    Thong Tin Sach %d    >>\n",dem++);
                for(int k = 0; k<m; k++){
                    if(soSanhChuoi(pMS[i].ISBNm[j], dsSach[k].ISBN))
                        xuatSach(dsSach[k],0);
                }
            }
        }
    }
    if(!dem)
        printf("\nMSSV: %s khong duoc tim thay trong danh sach phieu muon.\n");
}
//ham xoa phieu mmuon sach
void xoaPMS(phieuMuonSach **pMS, int *q, int a){
    free((*pMS)[a].MSSV);
    for(int i = a; i< *q-1; i++){
        (*pMS)[i] = (*pMS)[i+1];
    }
    free((*pMS)[*q-1].MSSV);
    *q--;
}
