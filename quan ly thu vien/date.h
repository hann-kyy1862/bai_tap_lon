#pragma once
//cau truc ve ngay thang nam
typedef struct date{
    int ngay, thang, nam;
}date;
int kiemTraNgay(date date);
void nhapNgay(date *ngay, char *ten);
int soSanhNgay(date ngayKT, date ngayHH);
int namNhuan(int nam);
int ngayTrongThang(int thang, int nam);
int ngayTre(date ngayTraTT, date ngayTraDK);
