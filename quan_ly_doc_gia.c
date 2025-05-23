#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quan_ly_doc_gia.h"
#include "menu.h"
//ham nhap so doc gia
int soDG(int dk){
    int n;
    lap:
    dk ? printf("\nNhap so doc gia: ") : printf("Nhap so doc gia moi: ");
    scanf("%d", &n); getchar();
    if(n<=0){
        printf("Loi! Vui long nhap lai!\n");
        goto lap;
    }return n;
}
//ham nhap thong tin 1 doc gia
docGia *taoDG(char *hoVaTen, char *MSSV, date ngaySinh, char *gioiTinh, date ngayTaoThe){
    docGia *DG = (docGia*)calloc(1,sizeof(docGia));
    DG->hoVaTen = (char*)malloc(strlen(hoVaTen)+1);
    strcpy(DG->hoVaTen,hoVaTen);
    DG->MSSV = (char*)malloc(strlen(MSSV)+1);
    strcpy(DG->MSSV,MSSV);
    DG->ngaySinh.ngay = ngaySinh.ngay; DG->ngaySinh.thang = ngaySinh.thang; DG->ngaySinh.nam = ngaySinh.nam;
    DG->gioiTinh = (char*)malloc(strlen(gioiTinh)+1);
    strcpy(DG->gioiTinh,gioiTinh);
    DG->ngayTaoThe.ngay = ngayTaoThe.ngay; DG->ngayTaoThe.thang = ngayTaoThe.thang; DG->ngayTaoThe.nam = ngayTaoThe.nam;
    DG->ngayHetHanThe = ngayTaoThe; DG->ngayHetHanThe.nam += 4;
    DG->next = NULL;
    return DG;
}
//ham them 1 doc gia vao danh sach
void themDocGia(docGia **headDG, docGia *DG){
    if(*headDG == NULL){
        *headDG = DG;
    }else{
        docGia *tmp = *headDG;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = DG;
    }
}
//ham nhap thong tin tung doc gia vao danh sach
void nhapDSDG(docGia **headDG, int *n, int dk){
    *n = soDG(dk);
    char hoVaTen[30], MSSV[15], gioiTinh[5];
    date ngaySinh;
    date ngayTaoThe;
    dk ? printf("\n==== NHAP THONG TIN DOC GIA ====\n") : printf("\n==== NHAP THONG TIN DOC GIA MOI ====\n");
    for(int i=0; i<*n; i++){
        printf("\n<<    Thong Tin Doc Gia %d    >>\n",i+1);
        printf("Nhap ho va ten: ");
        scanf("%[^\n]%*c", hoVaTen);
        printf("Nhap ma so sinh vien: ");
        scanf("%s", MSSV);
        nhapNgay(&ngaySinh, "sinh");
        printf("Nhap gioi tinh: ");
        scanf("%s", gioiTinh);
        nhapNgay(&ngayTaoThe, "tao the");
        docGia *DG = taoDG(hoVaTen, MSSV, ngaySinh, gioiTinh, ngayTaoThe);
        themDocGia(headDG, DG);
    }
}
//ham ghi vao file quan ly doc gia de luu tru thong tin doc gia
void ghiFileDG(docGia *headDG){
    FILE *f = fopen("quanLyDocGia.txt","w");
    if(f == NULL){
        printf("Loi thong tin doc gia chua duoc luu! Vui long thu lai.\n");
        return;
    }
    while(headDG != NULL){
        fprintf(f, "| %-20s | %-12s | %02d/%02d/%-4d | %-9s | %02d/%02d/%-5d | %02d/%02d/%-5d |\n",headDG->hoVaTen, headDG->MSSV, headDG->ngaySinh.ngay, headDG->ngaySinh.thang, headDG->ngaySinh.nam, headDG->gioiTinh, headDG->ngayTaoThe.ngay, headDG->ngayTaoThe.thang, headDG->ngayTaoThe.nam, headDG->ngayHetHanThe.ngay, headDG->ngayHetHanThe.thang, headDG->ngayHetHanThe.nam);
        headDG = headDG->next;
    }fclose(f);
}
//ham xuat thong tin 1 doc gia
void xuatDG(docGia *dG){
    printf("+ Ho va ten: %s\n", dG->hoVaTen);
    printf("+ MSSV: %s\n", dG->MSSV);
    printf("+ Ngay sinh: %02d/%02d/%d\n", dG->ngaySinh.ngay, dG->ngaySinh.thang, dG->ngaySinh.nam);
    printf("+ Gioi tinh: %s\n", dG->gioiTinh);
    printf("+ Ngay tao the: %02d/%02d/%d\n", dG->ngayTaoThe.ngay, dG->ngayTaoThe.thang, dG->ngayTaoThe.nam);
    printf("+ Ngay het han the: %02d/%02d/%d\n", dG->ngayHetHanThe.ngay, dG->ngayHetHanThe.thang, dG->ngayHetHanThe.nam);\
}
//(*)ham xuat danh sach doc gia 
void xuatDSDG(docGia *headDG){
    int i = 1;
    while(headDG != NULL){
        printf("\n<<   Thong Tin Doc Gia %d   >>\n", i++);
        xuatDG(headDG);
        headDG = headDG->next;
    }
}
//(*)ham them doc gia
void themDG(docGia **headDG, int *n){
    int a;
    nhapDSDG(headDG,&a,0);
    n += a;
    ghiFileDG(*headDG);
}
//ham xoa doc gia dau dslk
void xoaDau(docGia **headDG){
    docGia *delDG = *headDG; 
    *headDG = (*headDG)->next;
    free(delDG);
    ghiFileDG(*headDG);
}
//ham xoa doc gia giua/cuoi dslk
void xoaGiua_Cuoi(docGia **headDG, docGia *delDG){
    docGia *tmp1 = *headDG;
    while(tmp1->next != delDG)
        tmp1 = tmp1->next;
    tmp1->next = delDG->next;
    free(delDG);
    ghiFileDG(*headDG);
}
//(*)ham xoa the doc gia
void xoaDG(docGia **headDG, char *MSSV, int *n){
    docGia *tmp1 = *headDG;
    if(strcmp(tmp1->MSSV, MSSV) == 0){
        xoaDau(headDG);
        printf("\nDa xoa THANH CONG the doc gia.\n");
        *n--;
        return;
    }
    while(tmp1 != NULL){
        if(strcmp(tmp1->MSSV, MSSV) == 0){
            xoaGiua_Cuoi(headDG, tmp1);
            printf("\nDa xoa THANH CONG the doc gia.\n");
            *n--;
            return;
        }
        tmp1 = tmp1->next;
    }
    if(tmp1 == NULL)
        printf("\nMSSV khong duoc tim thay!\n");
}
//(*)ham chinh sua thong tin doc gia
void chinhSuaDG(docGia *headDG){
    docGia *tmp = headDG;
    char MSSV[15];
    printf("\nNhap MSSV can chinh sua: ");
    scanf("%s", MSSV);
    while(1){
        if(strcmp(headDG->MSSV,MSSV) == 0){
            tenDG(headDG,MSSV);
            break;
        }
            
        headDG = headDG->next;
        if(headDG == NULL){
            printf("MSSV khong ton tai!\n");
            return;
        }
    }
    chonTTSua(headDG);
    ghiFileDG(tmp);
}
//ham xuat ma va ten doc gia
void tenDG(docGia *headDG, char *MSSV){
    while(headDG != NULL){
        if(strcmp(headDG->MSSV, MSSV) == 0){
            printf("\nTen doc gia: %s\n",headDG->hoVaTen);
            printf("MSSV: %s\n", MSSV);
            break;
        }
    }
}
//ham kiem tra the doc gia con han hay het han
int kiemTraThe(docGia *headDG, char *MSSV, date ngayKT){
    while(headDG!=NULL){
        if(soSanhChuoi(headDG->MSSV, MSSV)){
            if(soSanhNgay(ngayKT, headDG->ngayHetHanThe))
                return 1;
            else return 0;
        }
        headDG = headDG->next;
    }
    return 0;
}