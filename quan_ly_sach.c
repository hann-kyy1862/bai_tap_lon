#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quan_ly_sach.h"
//ham nhap so luong sach, so luong phieu muon sach / phieu tra sach
int nhap(char *ten){
    int m;
    do{
        printf("\nNhap so luong %s: ",ten);
        scanf("%d",&m); getchar();
        if(m<=0){
            printf("Loi!!. Vui long nhap lai!\n");
        }
            
    }while(m<=0);
    return m;
}
//ham nhap thong tin 1 sach
sach themSach(char *ISBN, char *tenSach, char *tacGia, date ngayXuatBan, char *theLoai, int giaSach, int soLuong){
    sach themS;
    themS.ISBN = (char*)malloc(strlen(ISBN)+1);
    strcpy(themS.ISBN, ISBN);
    themS.tenSach = (char*)malloc(strlen(tenSach)+1);
    strcpy(themS.tenSach, tenSach);
    themS.tacGia = (char*)malloc(strlen(tacGia)+1);
    strcpy(themS.tacGia, tacGia);
    themS.ngayXuatBan.ngay = ngayXuatBan.ngay; themS.ngayXuatBan.thang = ngayXuatBan.thang; themS.ngayXuatBan.nam = ngayXuatBan.nam;
    themS.theLoai = (char*)malloc(strlen(theLoai)+1);
    strcpy(themS.theLoai, theLoai);
    themS.giaSach = giaSach;
    themS.soLuong = soLuong;
    return themS;
}
//ham nhap thong tin sach
void nhapTTSach(sach **dsSach, int *m){
    printf("\n>>    NHAP THONG TIN SACH    <<\n");
    *m = nhap("sach");
    //cap phat bo nho cho mang dsSach
    *dsSach = (sach*)calloc(*m,sizeof(sach));
    //khai bao cac bien tam 
    char ISBN[10], tenSach[40], tacGia[30], theLoai[15];
    date ngayXuatBan;
    int giaSach, soLuong;
    //nhap du lieu vao cac bien tam
    for(int i = 0; i<*m; i++){
        printf("\nNhap ma sach thu %d: ", i+1);
        scanf("%s", ISBN); getchar();
        printf("Nhap ten sach: ");
        scanf("%[^\n]%*c", tenSach);
        printf("Nhap tac gia: ");
        scanf("%[^\n]%*c", tacGia);
        do{
        printf("Nhap ngay xuat ban: ");
        scanf("%d/%d/%d", &ngayXuatBan.ngay, &ngayXuatBan.thang, &ngayXuatBan.nam); getchar();
        if(ngayXuatBan.ngay < 1 || ngayXuatBan.ngay > 31 || ngayXuatBan.thang < 1 || ngayXuatBan.thang > 12 || ngayXuatBan.nam < 1000)
            printf("Loi! Vui long nhap lai!\n");
        }while(kiemTraNgay(ngayXuatBan));
        printf("Nhap the loai cua sach: ");
        scanf("%[^\n]%*c", theLoai);
        printf("Nhap gia sach: ");
        scanf("%d",&giaSach);
        printf("Nhap so luong sach: ");
        scanf("%d",&soLuong);
        while(getchar() != '\n');
        (*dsSach)[i] = themSach(ISBN, tenSach, tacGia, ngayXuatBan, theLoai, giaSach, soLuong); //phan tu thu i cua dsSach la con tro mang sach 1 chieu
    }//a kiểu s**, *a = a[0] = b kiểu s*, *(a)[0] = *b kiểu sach
}
//ham ghi vao file quan ly sach
void ghiFileSach(sach *dsSach, int m){
    FILE *f = fopen("quanLySach.txt", "w");
    if(f == NULL){
        printf("Loi thong tin sach chua duoc luu! Vui long thu lai!\n");
        return;
    }
    for(int i = 0; i<m; i++){
        fprintf(f,"| %-8s | %-30s | %-20s | %02d/%02d/%-5d | %-10s | %-8d VND | %d |\n",(dsSach+i)->ISBN, (*(dsSach+i)).tenSach, (dsSach+i)->tacGia, dsSach[i].ngayXuatBan.ngay, dsSach[i].ngayXuatBan.thang, dsSach[i].ngayXuatBan.nam, dsSach[i].theLoai, dsSach[i].giaSach, dsSach[i].soLuong);
    }fclose(f);
}
//ham xuat thong tin 1 sach
void xuatSach(sach sach, int kieu){
    printf("+ Ma so sach: %s\n", sach.ISBN);
    printf("+ Ten sach: %s\n", sach.tenSach);
    printf("+ Tac gia: %s\n", sach.tacGia);
    printf("+ Ngay xuat ban: %02d/%02d/%d\n", sach.ngayXuatBan.ngay,sach.ngayXuatBan.thang, sach.ngayXuatBan.nam);
    printf("+ The loai: %s\n", sach.theLoai);
    printf("+ Gia sach: %d VND\n", sach.giaSach);
    kieu ? printf("+ So luong con lai: %d\n", sach.soLuong) : printf("+ So luong da muon: 1\n");
}
//(*)ham xuat danh sach cac sach trong thu vien
void xuatDSSach(sach *dsSach, int m){
    for(int i = 0; i<m; i++){
        printf("\n<<   Thong Tin Sach Thu %d   >>\n", i+1);
        xuatSach(dsSach[i],1);
    }
}
//ham so sanh 2chuoi
int soSanhChuoi(char *bienCanSS, char *bienDuocSS){
    if(strcmpi(bienCanSS, bienDuocSS) == 0)
        return 1;
    return 0;
}
//ham xuat ma va ten sach
void tenSach(sach *dsSach, int m, char *ISBN){
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(dsSach[i].ISBN, ISBN)){
            printf("Ma sach: %s\n", ISBN);
            printf("Ten sach: %s\n", dsSach[i].tenSach);
            break;
        }
    }
}
//(*)ham tim kiem sach theo ma sach
void timKiemISBN(sach *dsSach, int m){
    char ISBN[15];
    printf("Nhap ISBN cua sach can tim: ");
    scanf("%s", ISBN); getchar();
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(ISBN, dsSach[i].ISBN)){
            printf("\n<<    Thong Tin Sach Can Tim    >>\n");
            xuatSach(dsSach[i],1);
            return;
        }
    }
    printf("\nKhong tim thay ISBN trong thu vien!\n");
}
//(*)ham tim kiem sach theo ten sach
void timKiemTS(sach *dsSach, int m){
    char tenSach[40];
    printf("Nhap ten sach can tim: ");
    scanf("%[^\n]%*c", tenSach);
    for(int i = 0; i<m; i++){
        if(soSanhChuoi(tenSach, dsSach[i].tenSach)){
            printf("\n<<    Thong Tin Sach Can Tim    >>\n");
            xuatSach(dsSach[i],1);
            return;
        }
    }
    printf("\nKhong tim thay ten sach trong thu vien!\n");
}
//(*)ham them sach moi vao thu vien
void themSM(sach **dsSach, int *m){
    int a, dem = 0;
    do{
        printf("\nNhap so luong sach can them: ");
        if(scanf("%d",&a) != 1){
            printf("Loi! Hay thu lai!\n");
            while(getchar() != '\n');
        }else break;       
    }while(1);
    *dsSach = (sach*)realloc(*dsSach,(*m + a) * sizeof(sach));
    char ISBN[10], tenSach[40], tacGia[30], theLoai[15];
    date ngayXuatBan;
    int giaSach, soLuong;
    for(int i = *m; i<*m+a; i++){
        printf("\n<<    Thong Tin Sach Moi %d    >>\n", ++dem);
        printf("Nhap ma sach moi: ");
        scanf("%s", ISBN); getchar();
        printf("Nhap ten sach: ");
        scanf("%[^\n]%*c", tenSach);
        printf("Nhap tac gia: ");
        scanf("%[^\n]%*c", tacGia);
        nhapNgay(&ngayXuatBan,"xuat ban");
        printf("Nhap the loai cua sach: ");
        scanf("%[^\n]%*c", theLoai);
        printf("Nhap gia sach: ");
        scanf("%d",&giaSach);
        printf("Nhap so luong sach: ");
        scanf("%d",&soLuong);
        while(getchar() != '\n');
        (*dsSach)[i] = themSach(ISBN, tenSach, tacGia, ngayXuatBan, theLoai, giaSach, soLuong);
    }
    *m += a;
    ghiFileSach(*dsSach, *m);
}