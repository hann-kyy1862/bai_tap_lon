#pragma once
#include "quan_ly_doc_gia.h"
#include "quan_ly_sach.h"
#include "quan_ly_phieu_muon_sach.h"
//cau truc ve thong tin phieu tra sach
typedef struct phieuTraSach{
    char *MSSV; //ma so sinh vien
    date ngayTraTT; //ngay tra sach thuc te
    int soST; //so sach tra
    char **ISBNt; //danh sach ma so sach tra
}phieuTraSach;
int capNhapPMS(phieuMuonSach **pMS, int *q, char *MSSV, char *ISBNt);
void kiemTraXuPhat(date ngayTraTT, char *MSSV, phieuMuonSach *pMS, int q, char ISBNt[][15], int soST, sach *dsSach, int m, docGia *headDG);
void ghiFilePT(phieuTraSach *pTS, int p);
phieuTraSach themPTS(char *MSSV, date ngayTraTT, int soSach, char ISBNt[][15]);
void nhapPTS(phieuTraSach **pTS, int *p, sach *dsSach, int m, phieuMuonSach **pMS, int *q, docGia *headDG);
