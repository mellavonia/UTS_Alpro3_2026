#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    int jamKeluar;

    cout << "masukkan kode parkir digital (10 digit): ";
    cin >> kode;

    cout << "masukkan jam keluar (format hhmm): ";
    cin >> jamKeluar;

    string jenisKode = kode.substr(0, 2);
    string waktuKode = kode.substr(2, 4);
    string lokasiKode = kode.substr(6, 4);

    int waktuMasuk = stoi(waktuKode); 

    cout << "\n--- ringkasan parkir ---\n";

    int tarifAwal = 0, tarifBerikut = 0;

    if (jenisKode == "10") {
        cout << "jenis kendaraan: mobil\n";
        tarifAwal = 5000;
        tarifBerikut = 3000;
    }
    else if (jenisKode == "20") {
        cout << "jenis kendaraan: motor\n";
        tarifAwal = 3000;
        tarifBerikut = 2000;
    }
    else if (jenisKode == "30") {
        cout << "jenis kendaraan: bus\n";
        tarifAwal = 10000;
        tarifBerikut = 7000;
    }

    int jamMasuk = waktuMasuk / 100;
    int menitMasuk = waktuMasuk % 100;

    int jamK = jamKeluar / 100;
    int menitK = jamKeluar % 100;

    cout << "waktu masuk: " << jamMasuk << ":" 
         << (menitMasuk < 10 ? "0" : "") << menitMasuk << endl;

    cout << "waktu keluar: " << jamK << ":" 
         << (menitK < 10 ? "0" : "") << menitK << endl;

    int totalMasuk = jamMasuk * 60 + menitMasuk;
    int totalKeluar = jamK * 60 + menitK;

    int durasiMenit = totalKeluar - totalMasuk;

    int durasiJam = durasiMenit / 60;
    if (durasiMenit % 60 != 0) {
        durasiJam++;
    }

    cout << "durasi parkir: " << durasiJam << " jam\n";
    cout << "lokasi parkir: " << lokasiKode << endl;

    int totalBiaya = 0;

    if (durasiJam >= 1) {
        totalBiaya = tarifAwal;

        for (int i = 2; i <= durasiJam; i++) {
            totalBiaya += tarifBerikut;
        }
    }

    cout << "total biaya: rp " << totalBiaya << endl;
}

// 1. Input kode parkir dan jam keluar
// 2. Ambil bagian kode:
//    - jenis kendaraan
//    - waktu masuk
//    - lokasi
// 3. Tentukan jenis kendaraan & tarif
// 4. Pisahkan waktu masuk & keluar (jam dan menit)
// 5. Hitung durasi parkir (dibulatkan ke atas)
// 6. Tampilkan durasi dan lokasi
// 7. Hitung biaya:
//    - jam pertama = tarif awal
//    - berikutnya = tarif tambahan
// 8. Tampilkan total biaya