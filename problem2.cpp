#include <iostream>

using namespace std;

int HitungPanjang(const char TeksKata[]) {
    int TotalKarakter = 0;
    while (TeksKata[TotalKarakter] != '\0') {
        TotalKarakter = TotalKarakter + 1;
    }
    return TotalKarakter;
}

char UbahKapital(char HurufInput) {
    if (HurufInput >= 'a' && HurufInput <= 'z') {
        HurufInput = HurufInput - ('a' - 'A');
    }
    return HurufInput;
}

char GeserHuruf(char HurufAktif, char HurufLama) {
    int AngkaAktif = HurufAktif - 'A' + 1;
    int AngkaLama = HurufLama - 'A' + 1;

    int JumlahAngka = AngkaAktif + AngkaLama;

    while (JumlahAngka > 26) {
        JumlahAngka = JumlahAngka - 26;
    }

    char HurufHasil = 'A' + JumlahAngka - 1;
    return HurufHasil;
}

int main() {
    char KataAsli[1000];
    char KataSandi[1000];

    cout << "masukkan pesan teks yang ingin di enkripsi: ";
    cin >> KataAsli;

    int PanjangKata = HitungPanjang(KataAsli);

    if (PanjangKata == 0) {
        return 0;
    }

    for (int i = 0; i < PanjangKata; i++) {
        KataAsli[i] = UbahKapital(KataAsli[i]);
    }

    KataSandi[0] = KataAsli[0];

    for (int i = 1; i < PanjangKata; i++) {
        KataSandi[i] = GeserHuruf(KataAsli[i], KataAsli[i - 1]);
    }

    KataSandi[PanjangKata] = '\0';

    cout << "pesan sandi yang sudah terenkripsi : " << KataSandi << endl;

    return 0;
}