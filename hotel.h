#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED

#include <iomanip>
#include <iostream>
#define info(p) (p)->info
#define infoP(p) (p)->infoP
#define infoK(p) (p)->infoK
#define next(p) (p)->next
#define nextPengunjung(p) (p)->nextPengunjung
#define first(L) ((L).first)

using namespace std;

struct dataKamar {
  int nomor;
  string tipe, harga;
};

struct dataPengunjung {
  string nama, nik, tanggalMasuk, tanggalKeluar;
};

typedef dataPengunjung infoP;

typedef dataKamar infoK;

typedef struct elemenPengunjung *adr_pengunjung;

typedef struct elemenKamar *adr_kamar;

struct elemenKamar {
  infoK info;
  adr_kamar next;
  adr_pengunjung nextPengunjung;
};

struct elemenPengunjung {
  infoP info;
  adr_pengunjung next;
};

struct listKamar {
  adr_kamar first;
};

void createListKamar(listKamar &L);
adr_kamar createElemenKamar(infoK data);
adr_pengunjung createElemenPengunjung(infoP data);
void insertFirstKamar(listKamar &L, adr_kamar p);
void showDataKamar(listKamar L);
void showKamar(listKamar L);

void inputKamar(listKamar &l, adr_kamar p);
void deletePengunjung(adr_kamar &p);
void insertSingle(adr_kamar &p, adr_pengunjung q);
void insertDouble(adr_kamar &p, adr_pengunjung q1, adr_pengunjung q2);
adr_kamar searchKamar(listKamar L, int nomor, string tipe);
adr_kamar searchNomorKamar(listKamar L, int nomor);
adr_pengunjung searchPengunjung(listKamar L, string nik);

#endif // HOTEL_H_INCLUDED
