#include <iostream>
using namespace std;

int main() {
    int N;
    string S;

    cin >> N;
    cin >> S;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            poinA += 3;
            streakA++;
            streakB = 0;

            if (streakA == 3) {
                poinA += 2;
                streakA = 0;
            }
        }
        else if (S[i] == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0;

            if (streakB == 3) {
                poinB += 2;
                streakB = 0;
            }
        }
        else if (S[i] == 'C') {
            poinA += 1;
            poinB += 1;
            streakA = 0;
            streakB = 0;
        }
    }

    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    if (poinA > poinB) {
        cout << "Pemenangnya adalah pemain A\n";
    } 
    else if (poinB > poinA) {
        cout << "Pemenangnya adalah pemain B\n";
    } 
    else {
        cout << "Hasil pertandingan Seri!\n";
    }
}

// 1. Input jumlah babak dan hasil pertandingan
// 2. Inisialisasi poin dan streak pemain
// 3. Loop setiap babak:
//    - A menang → +3 poin, hitung streak, bonus jika 3x
//    - B menang → sama seperti A
//    - Seri → kedua pemain +1, reset streak
// 4. Tampilkan total poin
// 5. Tentukan pemenang (A, B, atau seri)