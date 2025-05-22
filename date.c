#include <stdio.h>
#include "date.h"
//ham kiem tra nhap ngay thang nam 
int kiemTraNgay(date date){
    return (date.ngay < 1 || date.ngay > 31) || (date.thang < 1 || date.thang > 12) || (date.nam < 1000);
}
//ham nhap ngay
void nhapNgay(date *ngay, char *ten){
    do{
        printf("Nhap ngay %s (dd/mm/yy): ", ten);
        if(scanf("%d/%d/%d", &ngay->ngay, &ngay->thang, &ngay->nam) != 3){
            printf("Loi nhap ngay! Hay nhap lai!\n");
            while(getchar() != '\n');
            continue;
        }getchar();
        if(kiemTraNgay(*ngay))
            printf("Ngay khong hop le! Hay nhap lai!\n");
    }while(kiemTraNgay(*ngay));
}
//ham so sanh ngay kiem tra lon hay nho hon ngay duoc kiem tra
int soSanhNgay(date ngayKT, date ngayHH){
    if(ngayKT.nam > ngayHH.nam) return 1;
    if(ngayKT.nam == ngayHH.nam && ngayKT.thang > ngayHH.thang) return 1;
    if(ngayKT.nam == ngayHH.nam && ngayKT.thang == ngayHH.thang && ngayKT.ngay > ngayHH.ngay) return 1;
    return 0;
}
//ham kiểm tra nam nhuan
int namNhuan(int nam){
    return ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0));
}
//ham ngay trong thang
int ngayTrongThang(int thang, int nam){
    int ngay[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(thang == 2 && namNhuan(nam))
        return 29;
    return ngay[thang];
}
//ham tinh ngay tien phat tra sach muon
int ngayTre(date ngayTraTT, date ngayTraDK){
    int soNgay = 0;
    if(ngayTraTT.thang>ngayTraDK.thang){
        soNgay = ngayTrongThang(ngayTraDK.thang++,ngayTraDK.nam) - ngayTraDK.ngay + ngayTraTT.ngay;
        for(int i = ngayTraDK.thang; i < ngayTraTT.thang; i++)
            soNgay += ngayTrongThang(ngayTraDK.thang++,ngayTraDK.nam);
    }else if(ngayTraTT.thang<ngayTraDK.thang){
        soNgay = ngayTrongThang(ngayTraTT.thang++,ngayTraTT.nam) - ngayTraTT.ngay + ngayTraDK.ngay;
        for(int i = ngayTraTT.thang; i < ngayTraTT.thang; i++)
            soNgay += ngayTrongThang(ngayTraTT.thang++,ngayTraTT.nam);
        soNgay = -soNgay;
    }else{
        soNgay = ngayTraTT.ngay - ngayTraDK.ngay;
    }
    for(int i = ngayTraDK.nam; i < ngayTraTT.nam; i++)
        soNgay += namNhuan(i) ? 366 : 365; 
    return soNgay;
}
