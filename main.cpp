#include "hotel.h"

int main() {
  int i, n, nomor, pilihan;
  listKamar L;
  dataKamar dataK;
  dataPengunjung dataP1, dataP2;
  adr_kamar k, cari;
  adr_pengunjung p1, p2;
  string tipe, tMasuk, tKeluar;

  createListKamar(L);

  dataK.nomor = 101;
  dataK.tipe = "Single";
  dataK.harga = "Rp.500.000";
  k = createElemenKamar(dataK);
  inputKamar(L, k);

  dataK.nomor = 102;
  dataK.tipe = "Double";
  dataK.harga = "Rp.800.000";
  k = createElemenKamar(dataK);
  inputKamar(L, k);

  dataK.nomor = 103;
  dataK.tipe = "Double";
  dataK.harga = "Rp.800.000";
  k = createElemenKamar(dataK);
  inputKamar(L, k);

  dataK.nomor = 104;
  dataK.tipe = "Double";
  dataK.harga = "Rp.800.000";
  k = createElemenKamar(dataK);
  inputKamar(L, k);

  dataK.nomor = 105;
  dataK.tipe = "Double";
  dataK.harga = "Rp.800.000";
  k = createElemenKamar(dataK);
  inputKamar(L, k);

  dataP1.nama = "JJ Novatri";
  dataP1.nik = "1302213010";
  dataP1.tanggalMasuk = "12-30-2022";
  dataP1.tanggalKeluar = "12-31-2022";
  p1 = createElemenPengunjung(dataP1);
  k = searchKamar(L, 101, "Single");
  insertSingle(k, p1);

  dataP1.nama = "Novita";
  dataP1.nik = "1302213030";
  dataP1.tanggalMasuk = "01-01-2023";
  dataP1.tanggalKeluar = "01-02-2023";
  p1 = createElemenPengunjung(dataP1);

  dataP2.nama = "Jannatin";
  dataP2.nik = "1302213051";
  dataP2.tanggalMasuk = "01-01-2023";
  dataP2.tanggalKeluar = "01-02-2023";
  p2 = createElemenPengunjung(dataP2);

  k = searchKamar(L, 102, "Double");
  insertDouble(k, p1, p2);

  cout << "******** SELAMAT DATANG DI HOTEL JANNOP ********" << endl;
  cout << endl;
  while (pilihan != 0) {
    cout << "=============== MENU ===============" << endl;
    cout << "1. Tampilkan Data Kamar Hotel" << endl;
    cout << "2. Booking Kamar" << endl;
    cout << "3. Cancel Booking" << endl;
    cout << "4. Reschedule" << endl;
    cout << "5. Search Pengunjung Berdasarkan NIK" << endl;
    cout << "6. Search Kamar Berdasarkan Nomor" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan Menu: ";
    cin >> pilihan;

    switch (pilihan) {
    case 0: {
      cout << "Terima Kasih";
      break;
    }
    case 1: {
      showDataKamar(L);
      break;
    }
    case 2: {
      showKamar(L);
      cout << "Masukkan Nomor Kamar : ";
      cin >> nomor;
      cout << "Masukkan Tipe Kamar  : ";
      cin >> tipe;

      cari = searchKamar(L, nomor, tipe);
      if (nextPengunjung(cari) == NULL) {
        if (info(cari).tipe == "Single") {
          cout << "[" << 1 << "]" << endl;
          cout << "Nama  : ";
          cin >> dataP1.nama;
          cout << "NIK   : ";
          cin >> dataP1.nik;
          cout << "Tanggal Check-in   : ";
          cin >> dataP1.tanggalMasuk;
          cout << "Tanggal Check-out  : ";
          cin >> dataP1.tanggalKeluar;
          insertSingle(cari, createElemenPengunjung(dataP1));
        } else if (info(cari).tipe == "Double") {
          cout << endl;
          cout << "[" << 1 << "]" << endl;
          cout << "Nama   : ";
          cin >> dataP1.nama;
          cout << "NIK    : ";
          cin >> dataP1.nik;
          cout << "[" << 2 << "]" << endl;
          cout << "Nama   : ";
          cin >> dataP2.nama;
          cout << "NIK    : ";
          cin >> dataP2.nik;
          cout << endl;

          cout << "Note: Format DD-MM-YYYY" << endl;
          cout << "Tanggal Check-in  : ";
          cin >> dataP2.tanggalMasuk;
          cout << "Tanggal Check-out : ";
          cin >> dataP2.tanggalKeluar;
          dataP1.tanggalMasuk = dataP2.tanggalMasuk;
          dataP1.tanggalKeluar = dataP2.tanggalKeluar;

          insertDouble(cari, createElemenPengunjung(dataP1),
                       createElemenPengunjung(dataP2));
          cout << endl;
          cout << "Kamar Berhasil Dibooking" << endl;
        }
      } else {
        cout << endl;
        cout << "Maaf, Kamar Sudah Dibooking" << endl;
      }
      break;
    }
    case 3: {
      cout << "Masukkan Nomor Kamar  : ";
      cin >> nomor;
      cout << "Masukkan Tipe Kamar   : ";
      cin >> tipe;

      cari = searchKamar(L, nomor, tipe);
      deletePengunjung(cari);
      cout << endl;
      cout << "Cancel Booking Berhasil" << endl;
      break;
    }
    case 4: {
      cout << "Masukkan Nomor Kamar : ";
      cin >> nomor;
      cout << "Masukkan Tipe Kamar  : ";
      cin >> tipe;

      cari = searchKamar(L, nomor, tipe);
      if (info(cari).tipe == "Single") {
        cout << "Note: Format DD-MM-YYYY" << endl;
        cout << "Masukkan Tanggal Check-in Baru   : ";
        cin >> tMasuk;
        cout << "Masukkan Tanggal Check-out Baru  : ";
        cin >> tKeluar;
        info(nextPengunjung(cari)).tanggalMasuk = tMasuk;
        info(nextPengunjung(cari)).tanggalKeluar = tKeluar;
      } else if (info(cari).tipe == "Double") {
        cout << "Note: Format DD-MM-YYYY" << endl;
        cout << "Masukkan Tanggal Check-in Baru   : ";
        cin >> tMasuk;
        cout << "Masukkan Tanggal Check-out Baru  : ";
        cin >> tKeluar;
        info(nextPengunjung(cari)).tanggalMasuk = tMasuk;
        info(nextPengunjung(cari)).tanggalKeluar = tKeluar;
        info(next(nextPengunjung(cari))).tanggalMasuk = tMasuk;
        info(next(nextPengunjung(cari))).tanggalKeluar = tKeluar;

        cout << endl;
        cout << "Reschedule Berhasil" << endl;
      }
      break;
    }
    case 5: {
      string nik;
      adr_pengunjung p;
      cout << "Masukkan NIK: ";
      cin >> nik;
      p = searchPengunjung(L, nik);
      if(p != NULL) {
        cout << "Nama Pengunjung   : " << info(p).nama << endl;
        cout << "Tanggal Check-in  : " << info(p).tanggalMasuk << endl;
        cout << "Tanggal Check-out : " << info(p).tanggalKeluar << endl << endl;
      }else {
          cout << endl << "Data yang Anda cari tidak ditemukan" << endl << endl;
      }
      break;
    }
    case 6: {
      cout << "Masukkan Nomor Kamar : ";
      cin >> nomor;

      cari = searchNomorKamar(L, nomor);
      if(cari != NULL) {
        cout << "Nomor Kamar : " << info(cari).nomor << endl;
        cout << "Tipe Kamar  : " << info(cari).tipe << endl;
        cout << "Harga       : " << info(cari).harga << endl << endl;
      }else {
          cout << endl << "Kamar Tidak Tersedia" << endl << endl;
      }
      break;
    }
    }
  }
}
