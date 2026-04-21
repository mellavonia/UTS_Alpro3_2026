#include <iostream>
using namespace std;

int main() {
    long long kartu, temp, temp2;
    
    cout << "Masukkan nomor kartu digital: ";
    cin >> kartu;

    int panjang = 0;
    temp = kartu;

    while (temp > 0) {
        panjang++;
        temp /= 10;
    }

    temp = kartu;

    while (temp >= 100) {
        temp /= 10;
    }

    int depan = temp;

    int tipe = 0;

    if (panjang == 14 && depan == 65) {
        tipe = 1;
        cout << "Tipe kartu: NUSANTARA\n";
    }
    else if (panjang == 16 && (depan == 77 || depan == 78)) {
        tipe = 2;
        cout << "Tipe kartu: GARUDA\n";
    }
    else if (panjang == 15 && depan == 91) {
        tipe = 3;
        cout << "Tipe kartu: MERDEKA\n";
    }
    else {
        cout << "Tipe kartu: TIDAK DIKETAHUI\n";
        cout << "Nomor kartu TIDAK VALID.\n";
    }

int total = 0;
    bool kaliDua = false;

    temp = kartu;

    while (temp > 0) {
        int digit = temp % 10;
        temp /= 10;

        if (kaliDua) {
            digit *= 2;

            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }

        total += digit;
        kaliDua = !kaliDua;
    }
   
    if (total % 10 == 0) {
        cout << "Nomor kartu VALID.\n";
    } else {
        cout << "Nomor kartu TIDAK VALID.\n";
    }
}

// 1. input nomor kartu
// 2. hitung jumlah digit dengan membagi 10 berulang
// 3. ambil 2 digit depan dengan membagi sampai < 100
// 4. tentukan tipe kartu:
//    - 14 digit & 65 → NUSANTARA
//    - 16 digit & 77/78 → GARUDA
//    - 15 digit & 91 → MERDEKA
//    - selain itu → tidak diketahui
// 5. validasi Luhn:
//    - Ambil digit dari belakang
//    - Setiap digit kedua dikali 2
//    - Jika > 9, jumlahkan digitnya
//    - Jumlahkan semua
// 6. jika total % 10 == 0 maka VALID, selain itu maka TIDAK VALID    