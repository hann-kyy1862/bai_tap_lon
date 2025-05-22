#pragma once
#include "quan_ly_doc_gia.h"
#include "quan_ly_sach.h"
#include "quan_ly_phieu_muon_sach.h"
#include "quan_ly_phieu_tra_sach.h"
#include "thong_ke.h"
void menuSua();
void chonTTSua(docGia *headDG);
void menuDG();
void chonCNDG(docGia **headDG, int *n);
void menuSach();
void chonCNSach(sach **dsSach, int *m);
void menuPMTS();
void chonCNMTS(phieuMuonSach **pMS, int *q, phieuTraSach **pTS, int *p, docGia **headDG, int *n, sach *dsSach, int m);
void menuTK();
void chonCNTK(phieuMuonSach *pMS, int q, docGia *headDG, sach *dsSach, int m);
void menuQL();
void chon_muc_quan_ly(phieuMuonSach **pMS, int *q, phieuTraSach **pTS, int *p, docGia **headDG, int *n, sach **dsSach, int *m);