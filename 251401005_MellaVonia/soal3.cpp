#include <iostream>
using namespace std;

int main() {
    int kode;

    cout << "masukkan kode transaksi (8 digit): ";
    cin >> kode;

    int jumlah = kode % 10000;
    kode /= 10000;

    int loyal = kode % 100;
    kode /= 100;

    int hari = kode;

    if (hari < 1 || hari > 3 || loyal < 1 || loyal > 3) {
        cout << "kode tidak valid!" << endl;
    }

    cout << "\n--- hasil ---\n";

    if (hari == 1) {
        cout << "jenis hari: hari kerja\n";
    } else if (hari == 2) {
        cout << "jenis hari: akhir pekan\n";
    } else {
        cout << "jenis hari: hari libur nasional\n";
    }

    if (loyal == 1) {
        cout << "jenis pelanggan: biasa\n";
    } else if (loyal == 2) {
        cout << "jenis pelanggan: silver\n";
    } else {
        cout << "jenis pelanggan: gold\n";
    }

    int poinPer100k = 0;

    if (hari == 1) {
        if (loyal == 1) poinPer100k = 1;
        else if (loyal == 2) poinPer100k = 2;
        else poinPer100k = 3;
    }
    else if (hari == 2) {
        if (loyal == 1) poinPer100k = 2;
        else if (loyal == 2) poinPer100k = 3;
        else poinPer100k = 5;
    }
    else {
        if (loyal == 1) poinPer100k = 3;
        else if (loyal == 2) poinPer100k = 5;
        else poinPer100k = 7;
    }

    int totalPoin = jumlah * poinPer100k;

    cout << "jumlah belanja: Rp " << jumlah * 100000 << endl;
    cout << "total poin: " << totalPoin << endl;
}

// 1. Input kode transaksi
// 2. Pecah kode:
//    - 4 digit terakhir → jumlah belanja
//    - 2 digit tengah → jenis pelanggan
//    - 2 digit depan → jenis hari
// 3. Validasi kode (harus 1–3)
// 4. Tentukan jenis hari & pelanggan
// 5. Tentukan poin per 100 ribu (berdasarkan hari & pelanggan)
// 6. Hitung total poin
// 7. Tampilkan jumlah belanja & total poin