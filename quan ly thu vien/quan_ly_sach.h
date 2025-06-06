#pragma once
#include "date.h"
//cau truc ve thong tin mot cuon sach
typedef struct sach{
    char *ISBN; //ma so sach
    char *tenSach; //ten sach
    char *tacGia; //tac gia
    date ngayXuatBan; //ngay san xuat
    char *theLoai; //the loai sach
    int giaSach; //gia sach
    int soLuong; //so luong con lai
}sach;
int nhap(char *ten);
sach themSach(char *ISBN, char *tenSach, char *tacGia, date ngayXuatBan, char *theLoai, int giaSach, int soLuong);
void nhapTTSach(sach **dsSach, int *m);
void ghiFileSach(sach *dsSach, int m);
void xuatSach(sach sach, int kieu);
void xuatDSSach(sach *dsSach, int m);
int soSanhChuoi(char *bienCanSS, char *bienDuocSS);
void tenSach(sach *dsSach, int m, char *ISBN);
void timKiemISBN(sach *dsSach, int m);
void timKiemTS(sach *dsSach, int m);
void themSM(sach **dsSach, int *m);
