#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void menuSequential() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save = -1;

    randomize();
    printf("Generating 100 numbers...\n");
    for (int i = 0; i < 100; i++) {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\nDone!\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) 
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data ada, sebanyak: %d \n", counter);
        printf("Pada indeks terakhir ke-%d\n", save);
    } else {
        printf("Data tidak ada!\n");
    }
    
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void menuBinary() {
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int angka[n];
    for (int i = 0; i < n; i++) {
        cout << "Angka ke-" << i << ": ";
        cin >> angka[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\nData yang telah diurutkan adalah: ";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << endl;

    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true) {
        cout << "Angka ditemukan!" << endl;
    } else {
        cout << "Angka tidak ditemukan!" << endl;
    }

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void menuPenjelasan() {
    clrscr();
    cout << "==================================================================\n";
    cout << " PERBEDAAN SEQUENTIAL SEARCHING DAN BINARY SEARCHING\n";
    cout << "==================================================================\n\n";
    
    cout << "1. SEQUENTIAL SEARCHING (Pencarian Berurutan):\n";
    cout << "   - Cara Kerja: Memeriksa data satu per satu dari awal sampai akhir.\n";
    cout << "   - Kondisi Data: Bisa digunakan pada data acak/tidak terurut.\n";
    cout << "   - Kelebihan  : Mudah diimplementasikan, cocok untuk data jumlah kecil.\n";
    cout << "   - Kekurangan : Lambat jika data sangat besar (Kompleksitas O(n)).\n\n";
    
    cout << "2. BINARY SEARCHING (Pencarian Biner):\n";
    cout << "   - Cara Kerja: Membagi data menjadi dua bagian di setiap tahapnya.\n";
    cout << "   - Kondisi Data: WAJIB dalam keadaan TERURUT (sorted).\n";
    cout << "   - Kelebihan  : Sangat cepat untuk data berukuran besar (Kompleksitas O(log n)).\n";
    cout << "   - Kekurangan : Data harus disorting terlebih dahulu, lebih rumit.\n";
    cout << "==================================================================\n";
    
    cout << "\nPress Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

int main() {
    int pilihan;
    do {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuSequential();
                break;
            case 2:
                menuBinary();
                break;
            case 3:
                menuPenjelasan();
                break;
            case 4:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
                cin.ignore();
                cin.get();
        }
    } while (pilihan != 4);

    return 0;
}