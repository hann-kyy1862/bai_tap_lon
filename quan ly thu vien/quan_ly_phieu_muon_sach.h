#pragma once
#include "quan_ly_doc_gia.h"
#include "quan_ly_sach.h"
//cau truc ve thong tin phieu muon sach
typedef struct phieuMuonSach{
    char *MSSV; //ma so sinh vien
    date ngayMuonSach; //ngay muon sach
    date ngayTraDK; //ngay tra sach du kien
    int soSach; //so luong sach duoc muon
    char **ISBNm; //danh sach ma so sach duoc muon
}phieuMuonSach;
int capNhatSLS(sach *dsSach, char *ISBN, int m, int kieu);
date ngayTraDuKien(docGia *headDG, char *MSSV, date ngayMuonSach);
char **nhapISBN(int soSach, char ISBN[][15]);
phieuMuonSach themPMS(docGia *headDG, char *MSSV, date ngayMuonSach, int soSach, char ISBN[][15]);
int kiemTraMSSVdg(docGia *headDG, char *MSSV);
int kiemTraMSSVpm(char *MSSV, phieuMuonSach *pMS, int q);
void ghiFilePM(phieuMuonSach *pMS, int q);
void nhapPMS(phieuMuonSach **pMS, int *q, docGia **headDG, int *n, sach *dsSach, int m);
void xuatSachMuon(phieuMuonSach *pMS, int q, sach *dsSach, int m, docGia *headDG);
void xoaPMS(phieuMuonSach **pMS, int *q, int a);


