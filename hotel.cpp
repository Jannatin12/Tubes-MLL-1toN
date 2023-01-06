#include "hotel.h"

void createListKamar(listKamar &L) { first(L) = NULL; }

adr_kamar createElemenKamar(infoK data) {
  adr_kamar p = new elemenKamar;
  info(p) = data;
  next(p) = NULL;
  nextPengunjung(p) = NULL;
  return p;
}

adr_pengunjung createElemenPengunjung(infoP data) {
  adr_pengunjung p = new elemenPengunjung;
  info(p) = data;
  next(p) = NULL;
  return p;
}

void insertFirstKamar(listKamar &L, adr_kamar p) {
  if (first(L) == NULL) {
    first(L) = p;
  } else {
    next(p) = first(L);
    first(L) = p;
  }
}

void showDataKamar(listKamar L) {
  adr_kamar k = first(L);
  if (k != NULL) {
    cout << "=========== DAFTAR KAMAR ==========" << endl;
  }
  while (k != NULL) {
    adr_pengunjung p = nextPengunjung(k);
    cout << "No" << setw(8) << "Tipe" << setw(12) << "Harga" << endl;
    cout << info(k).nomor;
    cout << setw(8) << info(k).tipe;
    cout << setw(12) << info(k).harga;
    cout << endl;
    if (p != NULL) {
      cout << endl;
      cout << "=== Data Pengunjung "
           << "Kamar " << info(k).nomor << " ===" << endl;
    } else {
      cout << endl;
      cout << "=== Kamar " << info(k).nomor << " Kosong ===" << endl;
    }
    int i = 0;
    while (p != NULL) {
      i++;
      cout << "[" << i << "]" << endl;
      cout << "Nama : " << info(p).nama << endl;
      cout << "NIK  : " << info(p).nik << endl;
      cout << "Tanggal Check-in   : " << info(p).tanggalMasuk << endl;
      cout << "Tanggal Check-out : " << info(p).tanggalKeluar << endl;
      p = next(p);
    }
    cout << "===================================" << endl;
    cout << endl;
    k = next(k);
  }
}

void showKamar(listKamar L) {
  adr_kamar k = first(L);
  if (k != NULL) {
    cout << "=========== DAFTAR KAMAR ==========" << endl;
  }
  while (k != NULL) {
    adr_pengunjung p = nextPengunjung(k);
    cout << "No" << setw(8) << "Tipe" << setw(12) << "Harga" << endl;
    cout << info(k).nomor;
    cout << setw(8) << info(k).tipe;
    cout << setw(12) << info(k).harga;
    cout << endl;
    cout << "===================================" << endl;
    k = next(k);
  }
}

void inputKamar(listKamar &L, adr_kamar p) {
  if (first(L) == NULL) {
    first(L) = p;
  } else {
    adr_kamar q = first(L);
    adr_kamar prec = NULL;

    while (q != NULL) {
      if (info(p).nomor < info(q).nomor) {
        if (q == first(L)) { // insert first
          insertFirstKamar(L, p);
        } else { // insert after
          next(prec) = p;
          next(p) = q;
        }
        return;
      }
      prec = q;
      q = next(q);
    }
    next(prec) = p; // insert last
  }
}

void deleteFirstKamar(listKamar &L, adr_kamar &p) {
  if (first(L) == NULL) {
    cout << endl << "List Kosong" << endl << endl;
  } else {
    p = first(L);
    first(L) = next(first(L));
    next(p) = NULL;
  }
}

void deleteLastKamar(adr_kamar &q) { next(q) = NULL; } // khusus

void deleteAfterKamar(listKamar &L, adr_kamar prec, adr_kamar &p) {
  p = next(prec);
  next(prec) = next(next(prec));
  next(p) = NULL;
}

void deleteKamar(listKamar &L, adr_kamar p) {
  adr_kamar prec;
  adr_kamar dihapus;
  adr_kamar k = first(L);
  if (k == p) { // delete first
    deleteFirstKamar(L, dihapus);
  } else {
    while (next(next(k)) != NULL) { // delete after
      if (next(k) == p) {
        deleteAfterKamar(L, k, dihapus);
        break;
      }
      k = next(k);
    }
    if (next(k) == p) { // delete last
      deleteLastKamar(k);
    }
  }
}

void deletePengunjung(adr_kamar &p) { nextPengunjung(p) = NULL; }

void insertSingle(adr_kamar &p, adr_pengunjung q) {
  deletePengunjung(p);
  nextPengunjung(p) = q;
}

void insertDouble(adr_kamar &p, adr_pengunjung q1, adr_pengunjung q2) {
  deletePengunjung(p);
  nextPengunjung(p) = q1;
  next(q1) = q2;
}

adr_kamar searchKamar(listKamar L, int nomor, string tipe) {
  adr_kamar q = first(L);
  while (q != NULL) {
    if (info(q).nomor == nomor && info(q).tipe == tipe) {
      return q;
    }
    q = next(q);
  }
  return NULL;
}

adr_kamar searchNomorKamar(listKamar L, int nomor) {
  adr_kamar q = first(L);
  while (q != NULL) {
    if (info(q).nomor == nomor) {
      return q;
    }
    q = next(q);
  }
  return NULL;
}

adr_pengunjung searchPengunjung(listKamar L, string nik) {
  adr_kamar q = first(L);
  while (q != NULL) {
    adr_pengunjung p = nextPengunjung(q);
    while (p != NULL) {
      if (info(p).nik == nik) {
        return p;
      }
      p = next(p);
    }
    q = next(q);
  }
  return NULL;
}

int jumlahKamarTersedia(listKamar L) {
  adr_kamar k = first(L);
  int jumlah = 0;
  while (k != NULL) {
    if (nextPengunjung(k) == NULL) {
      jumlah++;
    }
    k = next(k);
  }
  return jumlah;
}

int totalPengunjung(listKamar L) {
  adr_kamar k = first(L);
  adr_pengunjung p;
  int jumlah = 0;
  while (k != NULL) {
    p = nextPengunjung(k);
    while (p != NULL) {
      jumlah++;
      p = next(p);
    }
    k = next(k);
  }
  return jumlah;
}

int totalKamar(listKamar L) {
  adr_kamar k = first(L);
  int jumlah = 0;
  while (k != NULL) {
    jumlah++;
    k = next(k);
  }
  return jumlah;
}
