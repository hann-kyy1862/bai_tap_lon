#ifndef QUAN_LY_DOC_GIA_H
#define QUAN_LY_DOC_GIA_H
#include "date.h"
#include "quan_ly_sach.h"
//cau truc ve thong tin doc gia
typedef struct docGia{
    char *hoVaTen; //ho va ten
    char *MSSV;   //ma so sinh vien
    date ngaySinh; //ngay sinh
    char *gioiTinh;   //gioi tinh
    date ngayTaoThe; // ngay tao the
    date ngayHetHanThe; //ngay het han the
    struct docGia *next; //con tro tro den NODE chua doc gia khac
}docGia;
int soDG(int dk);
docGia *taoDG(char *hoVaTen, char *MSSV, date ngaySinh, char *gioiTinh, date ngayTaoThe);
void themDocGia(docGia **headDG, docGia *DG);
void nhapDSDG(docGia **headDG, int *n, int dk);
void ghiFileDG(docGia *headDG);
void xuatDG(docGia *dG);
void xuatDSDG(docGia *headDG);
void themDG(docGia **headDG, int *n);
void xoaDau(docGia **headDG);
void xoaGiua_Cuoi(docGia **headDG, docGia *delDG);
void xoaDG(docGia **headDG, char *MSSV, int *n);
void chinhSuaDG(docGia *headDG);
void tenDG(docGia *headDG, char *MSSV);
int kiemTraThe(docGia *headDG, char *MSSV, date ngayKT);
#endif