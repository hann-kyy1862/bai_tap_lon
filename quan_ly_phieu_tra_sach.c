#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quan_ly_phieu_tra_sach.h"
//ham cap nhat lai phieu muon sach
int capNhapPMS(phieuMuonSach **pMS, int *q, char *MSSV, char *ISBNt){
    for(int i =0; i<*q; i++){
        if(strcmp((*pMS)[i].MSSV, MSSV) == 0){
            for(int j = 0; j < (*pMS)[i].soSach; j++){
                if(strcmpi((*pMS)[i].ISBNm[j], ISBNt) == 0){
                    free((*pMS)[i].ISBNm[j]);
                    (*pMS)[i].ISBNm[j] = NULL;
                    for(int k = j; k < (*pMS)[i].soSach-1; k++)
                        (*pMS)[i].ISBNm[k] = strdup((*pMS)[i].ISBNm[k+1]);
                    if((*pMS)[i].ISBNm[(*pMS)[i].soSach-1] != NULL)
                        free((*pMS)[i].ISBNm[(*pMS)[i].soSach-1]);
                    if(--(*pMS)[i].soSach == 0)
                        xoaPMS(pMS,q,i);
                    ghiFilePM(*pMS, *q);
                    return 0;
                }
            }
        }
    }
    return 1;
}
//ham kiem tra va xu phat tra sach tre
void kiemTraXuPhat(date ngayTraTT, char *MSSV, phieuMuonSach *pMS, int q, char ISBNt[][15], int soST, sach *dsSach, int m, docGia *headDG){
    int dem = 0;
    for(int i = 0; i<q; i++){
        if(soSanhChuoi(pMS[i].MSSV,MSSV)){
            for(int j = 0; j<soST; j++){
                for(int k =0; k<pMS[i].soSach; k++){
                    if(soSanhChuoi(ISBNt[j], pMS[i].ISBNm[k])){
                        if(soSanhNgay(ngayTraTT,pMS[i].ngayTraDK)){
                            !dem++ ? printf("\n<<     Danh sach Sach tra tre han     >>\n") : 0;
                            tenDG(headDG, MSSV);
                            tenSach(dsSach, m, ISBNt[j]);
                            printf("Ngay muon: %02d/%02d/%d - Ngay tra du kien: %02d/%02d/%d\n", pMS[i].ngayMuonSach.ngay, pMS[i].ngayMuonSach.thang, pMS[i].ngayMuonSach.nam, pMS[i].ngayTraDK.ngay, pMS[i].ngayTraDK.thang, pMS[i].ngayTraDK.nam);
                            printf("Ngay tra thuc te: %02d/%02d/%d\n", ngayTraTT.ngay, ngayTraTT.thang, ngayTraTT.nam);
                            int soNgayTre = ngayTre(ngayTraTT,pMS[i].ngayTraDK);
                            printf("So ngay tre: %d\n",soNgayTre);
                            printf("So tien xu phat: %d * 5000 = %d VND\n", soNgayTre,soNgayTre*5000);
                        }
                    }

                }
            }
        }
    }
    if(!dem)
        printf("\nDoc gia da tra sach dung han\n");
}
//ham ghi file quan ly phieu tra sach
void ghiFilePT(phieuTraSach *pTS, int p){
    FILE *f = fopen("quanLyPhieuTra.txt", "w");
    if(f == NULL){
        printf("Loi! thong tin phieu tra sach chua duoc luu!\n");
        return;
    }
    for(int i = 0; i<p; i++){
        fprintf(f,"| %-15s | %02d/%02d/%-5d | %d |", pTS[i].MSSV, pTS[i].ngayTraTT.ngay, pTS[i].ngayTraTT.thang, pTS[i].ngayTraTT.nam, pTS[i].soST);
        for(int j = 0; j<pTS[i].soST; j++)
            fprintf(f," %-10s |", pTS[i].ISBNt[j]);
        fprintf(f,"\n");
    }
    fclose(f);
}
//ham nhap thong tin 1 phieu tra sach
phieuTraSach themPTS(char *MSSV, date ngayTraTT, int soSach, char ISBNt[][15]){
    phieuTraSach pT;
    pT.MSSV = (char*)malloc(strlen(MSSV)+1);
    strcpy(pT.MSSV,MSSV);
    pT.ngayTraTT = ngayTraTT;
    pT.soST = soSach;
    pT.ISBNt = nhapISBN(soSach, ISBNt);
    return pT;
}                
//(*)ham nhap phieu tra sach
void nhapPTS(phieuTraSach **pTS, int *p, sach *dsSach, int m, phieuMuonSach **pMS, int *q, docGia *headDG){
    int a, dem = 0;
    a = nhap("phieu tra sach");
    *pTS = (phieuTraSach*)realloc(*pTS, (a + *p) * sizeof(phieuTraSach));
    char MSSV[15], ISBNt[20][15];
    date ngayTraTT;
    int soST;
    for(int i = *p; i<*p+a; i++){
        printf("\n<<     Phieu Tra Sach %d     >>\n", ++dem);
        do{
            printf("Nhap ma so sinh vien tra sach: ");
            scanf("%s", MSSV);getchar();
            if(kiemTraMSSVpm(MSSV,*pMS,*q)){
                printf("\nMSSV khong duoc tim thay trong phieu muon sach\n");
                continue;
            }
            break;
        }while(1);
        nhapNgay(&ngayTraTT, "tra sach");
        printf("Nhap so sach duoc tra: ");
        scanf("%d",&soST);
        while(getchar() != '\n');
        for(int j = 0; j < soST; j++){
            int xet = 1;
            do{ 
                printf("Nhap ma sach da tra %d: ", j+1);
                scanf("%s", ISBNt[j]); getchar();
                for(int h = 0; h < *q; h++){
                    if(soSanhChuoi(MSSV, (*pMS)[h].MSSV)){
                       for(int k = 0; k< (*pMS)[h].soSach; k++){
                            if(strcmpi((*pMS)[h].ISBNm[k], ISBNt[j]) == 0){
                                xet = 0;
                                break;
                            }
                        } 
                    }
                }
                xet ? printf("\nISBN khong duoc tim thay trong phieu muon sach! Hay nhap lai!\n") : 0;
            } while(xet);
        }
        (*pTS)[i] = themPTS(MSSV,ngayTraTT,soST,ISBNt);
        kiemTraXuPhat(ngayTraTT,MSSV,*pMS,*q,ISBNt, soST, dsSach,m,headDG);
        for(int j = 0; j < soST; j++){
            capNhapPMS(pMS, q,MSSV, ISBNt[j]);
            capNhatSLS(dsSach, ISBNt[j],m, 1);
        }
    }
    *p += a;
    ghiFilePT(*pTS, *p);
}