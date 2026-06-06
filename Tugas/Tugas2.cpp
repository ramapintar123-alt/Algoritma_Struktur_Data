#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <limits>
#include <sstream>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmpty();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();


int main()
{
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" <<endl;
    cout << "=======================================" <<endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" <<endl;
    cout << "1. DLLNC dengan Head" <<endl;
    cout << "2. DLLNC dengan Head dan Tail" <<endl;
    cout << "3. Quit" <<endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if (menu == 1) {
        do {
            cout<< "Double Linked List Non Circular (DLLNC) (Head)" <<endl;
            cout<< "==============================================" <<endl;
            cout<< "1. Tambah Depan" <<endl;
            cout<< "2. Tambah Belakang" <<endl;
            cout<< "3. Tampilkan Data" <<endl;
            cout<< "4. Hapus Depan" <<endl;
            cout<< "5. Hapus Belakang" <<endl;
            cout<< "6. Reset" <<endl;
            cout<< "7. Hapus Berdasarkan Target" <<endl;
            cout<< "8. Kembali ke Menu" <<endl;
            cout<< "Pilihan : ";
            cin>> pilihan;
            pil = atoi(pilihan);

            switch (pil) {
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5:
                    hapusBelakangH();
                    break;
                case 6:
                    clearH();
                    break;
                case 7:
                    hapusTargetH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }
            cout << "\npress any key to continue" <<endl;
            getch();
            system("cls");
        } while (pil < 8);

    } else if (menu == 2) {
        do {
            cout<< "Double Linked List Non Circular (DLLNC) (Head dan Tail)" <<endl;
            cout<< "-------------------------------------------------------" <<endl;
            cout<< "1. Tambah Depan" <<endl;
            cout<< "2. Tambah Belakang" <<endl;
            cout<< "3. Tampilkan Data" <<endl;
            cout<< "4. Hapus Depan" <<endl;
            cout<< "5. Hapus Belakang" <<endl;
            cout<< "6. Reset" <<endl;
            cout<< "7. Hapus Berdasarkan Target" <<endl;
            cout<< "8. Kembali ke Menu" <<endl;
            cout<< "Pilihan : ";
            cin>> pilihan;
            pil = atoi(pilihan);

            switch (pil) {
                case 1:
                    tambahDepanHT();
                    break; 
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5:
                    hapusBelakangHT();
                    break;
                case 6:
                    clearHT();
                    break;
                    break;
                case 7:
                    hapusTargetHT();
                    break;
                default:
                    system("cls");
                    goto menu;
            }
            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil < 8);

    } else {
        cout<< "\nTERIMA KASIH" <<endl;
        cout<< "Program was made by Muhammad Ramadhon (2510817210015)." <<endl;
    }
}

void initH() {
    head = NULL;
}

void initHT() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (head == NULL) return 1;
    else return 0;
}

int isEmptyHT() {
    if (head == NULL) return 1;
    else return 0;
}

void tambahDepanH() {
    string dataPertama, sisaBaris;
    cout << "Masukkan data: ";
    if (!(cin >> dataPertama)) return;
    getline(cin, sisaBaris);
    
    string inputBaris = dataPertama + sisaBaris;
    stringstream ss(inputBaris);
    
    TNode *subHead = NULL;
    TNode *subTail = NULL;
    
    while (ss >> dataBaru) {
        TNode *baru = new TNode;
        baru->data = dataBaru;
        baru->next = NULL;
        baru->prev = NULL;
        
        if (subHead == NULL) {
            subHead = baru;
            subTail = baru;
        } else {
            subTail->next = baru;
            baru->prev = subTail;
            subTail = baru;
        }
    }
    
    if (subHead == NULL) return;
    
    if (isEmpty() == 1) {
        head = subHead;
    } else {
        subTail->next = head;
        head->prev = subTail;
        head = subHead;
    }
    cout << "Data \"" << inputBaris << "\" berhasil dimasukkan di bagian depan.";
}

void tambahDepanHT() {
    string dataPertama, sisaBaris;
    cout << "Masukkan data: ";
    if (!(cin >> dataPertama)) return;
    getline(cin, sisaBaris);
    
    string inputBaris = dataPertama + sisaBaris;
    stringstream ss(inputBaris);
    
    TNode *subHead = NULL;
    TNode *subTail = NULL;
    
    while (ss >> dataBaru) {
        TNode *baru = new TNode;
        baru->data = dataBaru;
        baru->next = NULL;
        baru->prev = NULL;
        
        if (subHead == NULL) {
            subHead = baru;
            subTail = baru;
        } else {
            subTail->next = baru;
            baru->prev = subTail;
            subTail = baru;
        }
    }
    
    if (subHead == NULL) return;
    
    if (isEmptyHT() == 1) {
        head = subHead;
        tail = subTail;
    } else {
        subTail->next = head;
        head->prev = subTail;
        head = subHead;
    }
    cout << "Data \"" << inputBaris << "\" berhasil dimasukkan di bagian depan.";
}

void tambahBelakangH() {
    string dataPertama, sisaBaris;
    cout << "Masukkan data: ";
    if (!(cin >> dataPertama)) return;
    getline(cin, sisaBaris);
    
    string inputBaris = dataPertama + sisaBaris;
    stringstream ss(inputBaris);
    
    TNode *subHead = NULL;
    TNode *subTail = NULL;
    
    while (ss >> dataBaru) {
        TNode *baru = new TNode;
        baru->data = dataBaru;
        baru->next = NULL;
        baru->prev = NULL;
        
        if (subHead == NULL) {
            subHead = baru;
            subTail = baru;
        } else {
            subTail->next = baru;
            baru->prev = subTail;
            subTail = baru;
        }
    }
    
    if (subHead == NULL) return;
    
    if (isEmpty() == 1) {
        head = subHead;
    } else {
        TNode *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = subHead;
        subHead->prev = bantu;
    }
    cout << "Data \"" << inputBaris << "\" berhasil dimasukkan di bagian belakang.";
}

void tambahBelakangHT() {
    string dataPertama, sisaBaris;
    cout << "Masukkan data: ";
    if (!(cin >> dataPertama)) return;
    getline(cin, sisaBaris);
    
    string inputBaris = dataPertama + sisaBaris;
    stringstream ss(inputBaris);
    
    TNode *subHead = NULL;
    TNode *subTail = NULL;
    
    while (ss >> dataBaru) {
        TNode *baru = new TNode;
        baru->data = dataBaru;
        baru->next = NULL;
        baru->prev = NULL;
        
        if (subHead == NULL) {
            subHead = baru;
            subTail = baru;
        } else {
            subTail->next = baru;
            baru->prev = subTail;
            subTail = baru;
        }
    }
    
    if (subHead == NULL) return;
    
    if (isEmptyHT() == 1) {
        head = subHead;
        tail = subTail;
    } else {
        tail->next = subHead;
        subHead->prev = tail;
        tail = subTail;
    }
    cout << "Data \"" << inputBaris << "\" berhasil dimasukkan di bagian belakang.";
}

void tampilkanH() {
    TNode *bantu;
    bantu = head;
    if (isEmpty() == 0) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void tampilkanHT() {
    TNode *bantu;
    bantu = head;
    if (isEmptyHT() == 0) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusDepanH() {
    TNode *hapus;
    string data;
    if (isEmpty() == 0) {
        hapus = head;
        data = hapus->data;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusDepanHT() {
    TNode *hapus;
    string data;
    if (isEmptyHT() == 0) {
        hapus = head;
        data = hapus->data;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus.";
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusBelakangH() {
    if (isEmpty() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    int N;
    cout << "Masukkan posisi N dari belakang: ";
    cin >> N;

    if (N <= 0) {
        cout << "Posisi N harus lebih besar dari 0.";
        return;
    }

    int totalNode = 0;
    TNode *bantu = head;
    while (bantu != NULL) {
        totalNode++;
        bantu = bantu->next;
    }

    int indeksTarget;
    if (N <= totalNode) {
        indeksTarget = totalNode - N + 1;
    } else {
        int sisaLangkah = N - totalNode;
        int putaran = sisaLangkah / (totalNode - 1);
        int sisa = sisaLangkah % (totalNode - 1);

        if (totalNode == 1) {
            indeksTarget = 1;
        } else if (putaran % 2 == 0) {
            indeksTarget = 1 + sisa;
        } else {
            indeksTarget = totalNode - sisa;
        }
    }

    TNode *hapus = head;
    for (int i = 1; i < indeksTarget; i++) {
        hapus = hapus->next;
    }

    string data = hapus->data;

    if (hapus == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        hapus->prev->next = hapus->next;
        if (hapus->next != NULL) {
            hapus->next->prev = hapus->prev;
        }
    }

    delete hapus;
    cout << "Data \"" << data << "\" pada posisi ke-" << N << " dari belakang (indeks riil: " << indeksTarget << ") telah berhasil dihapus.";
}

void hapusBelakangHT() {
    if (isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    int N;
    cout << "Masukkan posisi N dari belakang: ";
    cin >> N;

    if (N <= 0) {
        cout << "Posisi N harus lebih besar dari 0.";
        return;
    }

    int totalNode = 0;
    TNode *bantu = head;
    while (bantu != NULL) {
        totalNode++;
        bantu = bantu->next;
    }

    int indeksTarget;
    if (N <= totalNode) {
        indeksTarget = totalNode - N + 1;
    } else {
        int sisaLangkah = N - totalNode;
        int putaran = sisaLangkah / (totalNode - 1);
        int sisa = sisaLangkah % (totalNode - 1);

        if (totalNode == 1) {
            indeksTarget = 1;
        } else if (putaran % 2 == 0) {
            indeksTarget = 1 + sisa;
        } else {
            indeksTarget = totalNode - sisa;
        }
    }

    TNode *hapus = head;
    for (int i = 1; i < indeksTarget; i++) {
        hapus = hapus->next;
    }

    string data = hapus->data;

    if (hapus == head && hapus == tail) {
        head = NULL;
        tail = NULL;
    } else if (hapus == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else if (hapus == tail) {
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
    } else {
        hapus->prev->next = hapus->next;
        if (hapus->next != NULL) {
            hapus->next->prev = hapus->prev;
        }
    }

    delete hapus;
    cout << "Data \"" << data << "\" pada posisi ke-" << N << " dari belakang (indeks riil: " << indeksTarget << ") telah berhasil dihapus.";
}

void hapusTargetH() {
    if (isEmpty() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    string target;
    cout << "Masukkan data yang ingin dihapus: ";
    cin >> target;

    TNode *bantu = head;
    int jumlahTerhapus = 0;

    while (bantu != NULL) {
        TNode *nextNode = bantu->next;

        if (bantu->data == target) {
            jumlahTerhapus++;
            
            if (bantu == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                bantu->prev->next = bantu->next;
                if (bantu->next != NULL) {
                    bantu->next->prev = bantu->prev;
                }
            }
            delete bantu;
        }
        bantu = nextNode;
    }

    if (jumlahTerhapus > 0) {
        cout << "Data \"" << target << "\" sebanyak " << jumlahTerhapus << " berhasil dihapus.";
    } else {
        cout << "Data \"" << target << "\" tidak ditemukan.";
    }
}

void hapusTargetHT() {
    if (isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    string target;
    cout << "Masukkan data yang ingin dihapus: ";
    cin >> target;

    TNode *bantu = head;
    int Jumlah_Terhapus = 0;

    while (bantu != NULL) {
        TNode *nextNode = bantu->next;

        if (bantu->data == target) {
            Jumlah_Terhapus++;

            if (bantu == head && bantu == tail) {
                head = NULL;
                tail = NULL;
            } else if (bantu == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else if (bantu == tail) {
                tail = tail->prev;
                if (tail != NULL) {
                    tail->next = NULL;
                }
            } else {
                bantu->prev->next = bantu->next;
                if (bantu->next != NULL) {
                    bantu->next->prev = bantu->prev;
                }
            }
            delete bantu;
        }
        bantu = nextNode;
    }

    if (Jumlah_Terhapus > 0) {
        cout << "Data \"" << target << "\" sebanyak " << Jumlah_Terhapus << " berhasil dihapus.";
    } else {
        cout << "Data \"" << target << "\" tidak ditemukan.";
    }
}

void clearH() {
    if (isEmpty() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    int urutan = 1;
    bool hapusDariDepan = true;

    while (head != NULL) {
        TNode *hapus = NULL;

        if (hapusDariDepan) {
            hapus = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        } else {
            hapus = head;
            while (hapus->next != NULL) {
                hapus = hapus->next;
            }
            if (hapus->prev != NULL) {
                hapus->prev->next = NULL;
            } else {
                head = NULL;
            }
        }

        cout << "Urutan ke-" << urutan << " menghapus data: \"" << hapus->data << "\"\n";
        delete hapus;
        
        urutan++;
        hapusDariDepan = !hapusDariDepan;
    }

    cout << "\nSeluruh data pada Linked List telah dibersihkan.";
}

void clearHT() {
    if (isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List";
        return;
    }

    int urutan = 1;
    bool hapusDariDepan = true;

    while (head != NULL) {
        TNode *hapus = NULL;

        if (hapusDariDepan) {
            hapus = head;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }
        } else {
            hapus = tail;
            if (head == tail) {
                head = NULL;
                tail = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }
        }

        cout << "Urutan ke-" << urutan << " menghapus data: \"" << hapus->data << "\"\n";
        delete hapus;

        urutan++;
        hapusDariDepan = !hapusDariDepan;
    }

    cout << "\nSeluruh data pada Linked List telah dibersihkan.";
}