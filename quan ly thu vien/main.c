#include <stdlib.h>
#include "menu.h"

int main(){
    docGia *headDG = NULL; //danh sach doc gia
    int n; //n la so luong doc gia
    nhapDSDG(&headDG, &n, 1); //nhap danh sach doc gia
    ghiFileDG(headDG); //ghi vao file quan ly doc gia de luu tru
    
    int m; //m la so luong sach trong thu vien
    sach *dsSach; //danh sach cac sach
    nhapTTSach(&dsSach, &m); //nhap thong tin cac sach
    ghiFileSach(dsSach, m); //ghi vao file quan ly sach de luu tru
    
    phieuMuonSach *pMS = NULL; //danh sach phieu muon sach
    int q = 0; //so luong phie muon sach
    
    phieuTraSach *pTS = NULL; //danh sach phieu tra sach
    int p = 0; //so luong phieu tra sach
     
    chon_muc_quan_ly(&pMS,&q,&pTS,&p,&headDG,&n,&dsSach,&m); //thuc hien cac chuc nang quan ly thu vien

    //giai phong bo nho doc gia
    while(headDG){
        docGia *tmp = headDG;
        headDG = headDG->next;
        free(tmp->hoVaTen);
        free(tmp->MSSV);
        free(tmp->gioiTinh);
        free(tmp);
    }
    //giai phong danh sach cac sach
    for(int i = 0; i<m;i++){
        free(dsSach[i].ISBN);
        free(dsSach[i].tenSach);
        free(dsSach[i].tacGia);
        free(dsSach[i].theLoai);
    }free(dsSach);
    //giai phong danh sach phieu muon sach
    for(int i = 0; i<q;i++){
        free(pMS[i].MSSV);
        for(int j = 0; j < pMS[i].soSach;j++)
            free(pMS[i].ISBNm[j]);
        free(pMS[i].ISBNm);
    }free(pMS);
    //giai phong danh sach phieu tra sach
    for(int i =0 ; i < p; i++){
        free(pTS[i].MSSV);
        for(int j = 0; j < pTS[i].soST; j++)
            free(pTS[i].ISBNt[j]);
        free(pTS[i].ISBNt);
    }free(pTS);

    return 0;
}