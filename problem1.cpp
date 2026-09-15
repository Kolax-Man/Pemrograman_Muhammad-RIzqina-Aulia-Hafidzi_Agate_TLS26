#include <iostream>

using namespace std;

int UpdateLangkah(int NilaiK, int NomorOrang) {
    if (NomorOrang % 2 == 0) {
        NilaiK = NilaiK + 2;
    } else {
        NilaiK = NilaiK - 1;
    }

    if (NilaiK < 2) {
        NilaiK = 2;
    }

    return NilaiK;
}

int main() {
    int TotalOrang, LangkahK;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> TotalOrang;

    cout << "Masukkan nilai awal K: ";
    cin >> LangkahK;

    if (LangkahK < 2) {
        LangkahK = 2;
    }

    int DataOrang[1000];
    for (int i = 0; i < TotalOrang; i++) {
        DataOrang[i] = i + 1;
    }

    int SisaOrang = TotalOrang;
    int IndeksAwal = 0;

    cout << "\nUrutan eliminasi:\n";

    while (SisaOrang > 1) {
        int TargetHapus = (IndeksAwal + LangkahK - 1) % SisaOrang;
        int NomorKeluar = DataOrang[TargetHapus];

        cout << "Astronot " << NomorKeluar << " keluar (K sekarang: " << LangkahK << ")\n";

        for (int j = TargetHapus; j < SisaOrang - 1; j++) {
            DataOrang[j] = DataOrang[j + 1];
        }
        SisaOrang = SisaOrang - 1;

        LangkahK = UpdateLangkah(LangkahK, NomorKeluar);
        IndeksAwal = TargetHapus;
    }

    cout << "\nAstronot terakhir: Astronot " << DataOrang[0] << endl;

    return 0;
}