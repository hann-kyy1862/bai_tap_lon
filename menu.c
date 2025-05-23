#include <stdio.h>
#include <string.h>
#include "menu.h"
//ham in ra menu chon thong tin can sua
void menuSua(){
    printf("\n======= SUA THONG TIN =======\n");
    printf("1. Sua ho va ten doc gia\n");
    printf("2. Sua ma so sinh vien doc gia\n");
    printf("3. Sua ngay sinh doc gia\n");
    printf("4. Sua gioi tinh doc gia\n");
    printf("5. Sua ngay tao the doc gia\n");
    printf("6. Thoat!\n");
    printf("==============================\n");
    printf("Chon muc can sua thong tin: ");
}
//ham chon thong tin de sua
void chonTTSua(docGia *headDG){
    int choice;
    char hoVaTen[30], MSSVm[15], gioiTinh[5];
    date ngaySinh;
    date ngayTaoThe;
    do{
        menuSua();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon. Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1:
                printf("Nhap ho ten moi: ");
                scanf("%[^\n]%*c", hoVaTen);
                strcpy(headDG->hoVaTen, hoVaTen);
                printf("=> Sua doi ho ten HOAN THANH!\n");
                break;
            case 2:
                printf("Nhap ma so sinh vien moi: ");
                scanf("%s", MSSVm); getchar();
                strcpy(headDG->MSSV,MSSVm);
                printf("=> Sua doi MSSV HOAN THANH!\n");
                break;
            case 3:
                nhapNgay(&ngaySinh, "sinh");
                headDG->ngaySinh = ngaySinh;
                break;
            case 4: 
                printf("Nhap gioi tinh moi: ");
                scanf("%s", gioiTinh); getchar();
                strcpy(headDG->gioiTinh, gioiTinh);
                printf("=> Sua doi gioi tinh HOAN THANH!\n");
                break;
            case 5:
                nhapNgay(&ngayTaoThe,"tao the");
                headDG->ngayTaoThe = ngayTaoThe;
                headDG->ngayHetHanThe = ngayTaoThe; headDG->ngayHetHanThe.nam += 4;
                printf("=> Sua doi ngay tao the HOAN THANH!\n");
                break;
            default: choice = 6;
        }     
    }while(choice != 6);
}
//ham in menu cac chuc nang quan ly doc gia
void menuDG(){
    printf("\n======= QUAN LY DOC GIA ======\n");
    printf("1. Xem danh sach doc gia\n");
    printf("2. Them doc gia\n");
    printf("3. Xoa doc gia\n");
    printf("4. Chinh sua thong tin doc gia\n");
    printf("5. Thoat!\n");
    printf("===============================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang quan ly doc gia
void chonCNDG(docGia **headDG, int *n){
    int choice;
    int a;
    char MSSV[15];
    do{
        menuDG();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>    DANH SACH DOC GIA    <<\n");
                xuatDSDG(*headDG);
                break;
            case 2:
                printf("\n>>     THEM DOC GIA     <<\n");
                themDG(headDG,n);
                break;
            case 3:
                printf("\n>>     XOA DOC GIA     <<\n");
                printf("\nNhap MSSV can xoa the: ");
                scanf("%s", MSSV);getchar();
                xoaDG(headDG,MSSV,n);
                break;
            case 4:
                printf("\n>>  CHINH SAU THONG TIN DOC GIA  <<\n");
                chinhSuaDG(*headDG);
                break;
            case 5:
                choice = 5;
                break;
            default:  choice = 5;
        }
    }while(choice != 5);
}
//ham in menu cac chuc nang quan ly sach
void menuSach(){
    printf("\n============= QUAN LY SACH =============\n");
    printf("1. Xem danh sach cac sach trong thu vien\n");
    printf("2. Tim kiem sach theo ISBN\n");
    printf("3. Tim kiem sach theo ten sach\n");
    printf("4. Them sach moi\n");
    printf("5. Thoat!\n");
    printf("========================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang quan ly sach
void chonCNSach(sach **dsSach, int *m){
    int choice;
    do{
        menuSach();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>   DANH SACH SACH TRONG THU VIEN   <<\n");
                xuatDSSach(*dsSach,*m);
                break;
            case 2:
                printf("\n>>    TIM KIEM SACH THEO ISBN    <<\n");
                timKiemISBN(*dsSach, *m);
                break;
            case 3:
                printf("\n>>   TIM KIEM SACH THEO TEN SACH   <<\n");
                timKiemTS(*dsSach, *m);
                break;
            case 4:
                printf("\n>>     THEM SACH MOI     <<\n");
                themSM(dsSach, m);
                break;
            case 5:
                choice = 5;
                break;
            default:  choice = 5;
        }
    }while(choice != 5);
}
//ham in menu cac chuc nang quan ly phieu muon sach & phieu tra sach
void menuPMTS(){
    printf("\n====== QUAN LY PHIEU MUON SACH & TRA SACH ======\n");
    printf("1. Tao phieu muon sach\n");
    printf("2. Tao phieu tra sach\n");
    printf("3. Xem danh sach cac sach dang duoc\n   muon boi 1 doc gia theo MSSV\n");
    printf("4. Thoat!\n");
    printf("================================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang quan ly phieu muon sach & phieu tra sach
void chonCNMTS(phieuMuonSach **pMS, int *q, phieuTraSach **pTS, int *p, docGia **headDG, int *n, sach *dsSach, int m){
    int choice;
    do{
        menuPMTS();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>     TAO PHIEU MUON SACH     <<\n");
                nhapPMS(pMS,q,headDG,n,dsSach,m);
                break;
            case 2:
                printf("\n>>     TAO PHIEU TRA SACH     <<\n");
                nhapPTS(pTS,p,dsSach,m,pMS,q,*headDG);
                break;
            case 3:
                printf("\n>>   DANH SACH CAC SACH DUOC MUON CUA 1 DOC GIA   <<\n");
                xuatSachMuon(*pMS,*q,dsSach,m,*headDG);
                break;
            case 4:
                choice = 4;
                break;
            default:  choice = 4;
        }
    }while(choice != 4);
}
//ham in menu cac chuc nang thong ke
void menuTK(){
    printf("\n======= THONG KE (DG, SACH, PMS, PTS) =======\n");
    printf("1. Thong ke so luong sach trong thu vien\n");
    printf("2. Thong ke so sach dang duoc muon\n");
    printf("3. Thong ke so luong doc gia qua han tra sach\n");
    printf("4. Thoat!\n");
    printf("=============================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuc nang thong ke 
void chonCNTK(phieuMuonSach *pMS, int q,docGia *headDG, sach *dsSach, int m){
    int choice;
    do{
        menuTK();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>   THONG KE SO LUONG SACH TRONG THU VIEN   <<\n");
                printf("So luong sach dang co trong thu vien la: %d\n", soLuongSachTV(dsSach,m));
                break;
            case 2:
                printf("\n>>   THONG KE SO LUONG SACH DANG MUON   <<\n");
                dsSM(dsSach,m,pMS,q);
                break;
            case 3:
                printf("\n>>   THONG KE SO DOC GIA QUA HAN TRA SACH   <<\n\n");
                dgTreHan(pMS,q,headDG);
                break;
            case 4:
                choice = 4;
                break;
            default:  choice = 4;
        }
    }while(choice != 4);
}
//ham menu chuong trinh quan ly thu vien
void menuQL(){
    printf("\n========= QUAN LY THU VIEN ========\n");
    printf("1. Quan ly doc gia\n");
    printf("2. Quan ly sach\n");
    printf("3. Lap phieu muon sach & tra sach\n");\
    printf("4. Thong ke\n");
    printf("5. Thoat!\n");
    printf("===================================\n");
    printf("Moi chon chuc nang: ");
}
//ham chon chuong trinh quan ly thu vien
void chon_muc_quan_ly(phieuMuonSach **pMS, int *q, phieuTraSach **pTS, int *p, docGia **headDG, int *n, sach **dsSach, int *m){
    int choice;
    do{
        menuQL();
        while(scanf("%d",&choice) != 1){
            printf("Loi nhap lua chon! Hay thu lai!\n");
            printf("Nhap lua chon: ");    
            while(getchar() != '\n');
        }getchar();
        switch(choice){
            case 1: 
                printf("\n>>    QUAN LY THE DOC GIA    <<\n");
                chonCNDG(headDG, n);
                break;
            case 2:
                printf("\n>>        QUAN LY SACH       <<\n");
                chonCNSach(dsSach,m);
                break;
            case 3:
                printf("\n>>   QUAN LY PHIEU MUON TRA SACH   <<\n");
                chonCNMTS(pMS,q,pTS,p,headDG,n,*dsSach,*m);
                break;
            case 4: 
                printf("\n>>         THONG KE         <<\n");
                chonCNTK(*pMS,*q,*headDG,*dsSach,*m);
                break;
            case 5:
                choice = 5;
                break;
            default:  choice = 5;
        }
    }while(choice != 5);
}