#pragma once
#include "quan_ly_doc_gia.h"
#include "quan_ly_sach.h"
#include "quan_ly_phieu_muon_sach.h"
int soLuongSachTV(sach *dsSach, int m);
int demSachM(phieuMuonSach *pMS, int q, char *ISBN, int danhDau[]);
void dsSM(sach *dsSach, int m, phieuMuonSach *pMS, int q);
int soDGTH(phieuMuonSach *pMS, int q, date ngay_hien_tai);
void dgTreHan(phieuMuonSach *pMS, int q, docGia *headDG);
