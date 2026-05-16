#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, data;

void init();
int isEmpty();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init();
    do {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua Elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Quit"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        pil=atoi(pilihan);

        switch(pil) {
            case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                reset();
                break;
            case 7:
                cariData();
                break;
            case 8:
                hapusData();
                break;
            case 9:
                sisipkanSebelum();
                break;
            case 10:
                sisipkanSetelah();
                break;
            default:
                if (pil >= 11) {
                    cout<<"\nTERIMA KASIH"<<endl;
                    cout<<"Program was made by Muhammad Ramadhon (2510817210015)."<<endl;
                }
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");

    } while (pil<11);
}

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void tambahDepan() {
    cout << "Masukkan data : ";
    string inputLine;
    
    getline(cin >> ws, inputLine); 

    stringstream ss(inputLine);
    string dataBaru; 
    bool inputPertama = true;

    while (ss >> dataBaru) { 
        TNode *baru = new TNode;
        baru->data = dataBaru; 

        if (isEmpty() == 1) {
            head = baru;
            tail = baru;
            tail->next = head;
            inputPertama = false;
        } 
        else if (inputPertama) {
            baru->next = head;
            head = baru;
            tail->next = head;
            inputPertama = false;
        } 
        else {
            tail->next = baru;
            tail = baru;
            tail->next = head;
        }
    }

    cout << "Data berhasil dimasukkan sesuai urutan input." << endl;
}

void tambahBelakang() {
    cout<<"Masukkan data : ";
    cin>>dataBaru;
    TNode *baru;
    baru = new TNode;
    baru->data = dataBaru;
    baru->next = baru;

    if(isEmpty() == 1) {
        head = baru;
        tail = baru;
        tail->next = head;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang."<<endl;
}

void hapusDepan() {
    if (isEmpty() == 1) {
        cout << "Tidak terdapat data pada Linked List." << endl;
        return;
    }

    int N;
    cout << "Masukkan posisi N dari depan: ";
    cin >> N;

    int totalNode = 0;
    TNode *bantu = head;
    do {
        totalNode++;
        bantu = bantu->next;
    } while (bantu != head);

    TNode *hapus;

    if (N == 1) {
        hapus = head;
        data = hapus->data;

        if (head != tail) {
            head = head->next;
            tail->next = head;
        } else {
            init();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    } 
    else if (N >= totalNode) {
        hapus = tail;
        data = hapus->data;

        if (head != tail) {
            TNode *prev = head;
            while (prev->next != tail) {
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
        } else {
            init();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    } 
    else {
        TNode *prev = head;
        for (int i = 1; i < N - 1; i++) {
            prev = prev->next;
        }
        
        hapus = prev->next;
        data = hapus->data;
        prev->next = hapus->next;
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    }
}

void hapusBelakang() {
    if (isEmpty() == 1) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }

    int N;
    cout << "Masukkan posisi N dari belakang: ";
    cin >> N;

    int totalNode = 0;
    TNode *bantu = head;
    do {
        totalNode++;
        bantu = bantu->next;
    } while (bantu != head);

    TNode *hapus;

    if (N >= totalNode || totalNode - N == 0) {
        hapus = head;
        data = hapus->data;

        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus." << endl;
    } 
    else {
        int posisiTarget = totalNode - N;
        TNode *prev = head;

        for (int i = 1; i < posisiTarget; i++) {
            prev = prev->next;
        }

        hapus = prev->next;
        data = hapus->data;

        if (hapus == tail) {
            tail = prev;
            tail->next = head;
        } else {
            prev->next = hapus->next;
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus." << endl;
    }
}

void tampilkan() {
    if(isEmpty() == 0) {
        TNode *bantu;
        bantu = head;

        do {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        } while(bantu != head);
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void reset() {
    if(isEmpty() == 0) {
        TNode *bantu, *hapus;
        bantu = head;
        int nomorNode = 1;

        do {
            hapus = bantu;
            bantu = bantu->next;
            
            cout << "Menghapus Node ke-" << nomorNode << " dengan isi data: " << hapus->data << endl;
            delete hapus;
            
            nomorNode++;
        } while(bantu != head);

        init();
        cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void cariData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu, *bantuTampilkan;
        bool apaDitemukan = false;

        bantu = head;

        do {
            if(cari == bantu->data){
                cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) "
                    <<"merupakan data yang anda cari."<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;

                do {
                    if(cari == bantuTampilkan->data)
                        cout<<"["<<bantuTampilkan->data<<"] ";
                    else
                        cout<<bantuTampilkan->data<<' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while(bantuTampilkan != head);

                apaDitemukan = true;
                cout<<endl;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan == false)
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void hapusData() {
    if(isEmpty() == 0) {
        string cari;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        bantu = head;

        do {
            bantu2 = bantu;
            if(cari == bantu->data){
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while(bantu != head);

        if(apaDitemukan == true) {
            for(int i = 0; i < hitung; i++) {
                if(hapus[i] == head){
                    if (head != tail) {
                        TNode *hapusHead = head;
                        head = head->next;
                        tail->next = head;
                        delete hapusHead;
                    } else {
                        init();
                    }
                } else if(hapus[i] == tail) {
                    if (head != tail) {
                        TNode *hapusTail = tail;
                        TNode *prev = head;
                        while (prev->next != tail) {
                            prev = prev->next;
                        }
                        tail = prev;
                        tail->next = head;
                        delete hapusTail;
                    } else {
                        init();
                    }
                } else {
                    delete hapus[i];
                }
            }
            cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus"<<endl;
        } else cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;

    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSebelum() {
    if(isEmpty() == 0) {
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda = false;

        bantu = head;
        sebelum = tail;

        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        do {
            if(nextData == bantu->data){
                apaAda = true;
                break;
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda==true) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu;

            sebelum->next = baru;

            if(bantu == head){
                head = baru;
            }

            cout << "Data \""<<dataBaru<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\"."<<endl;
        } else {
            cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List."<<endl;
        }
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}

void sisipkanSetelah() {
    if(isEmpty() == 0) {
        TNode *bantu;
        string prevData;
        bool apaAda = false;

        bantu = head;

        cout<<"Sisipkan data baru setelah data : ";
        cin>>prevData;

        do {
            if(prevData == bantu->data){
                apaAda = true;
                break;
            } else {
                bantu = bantu->next;
            }
        } while(bantu != head);

        if(apaAda == true) {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>dataBaru;

            TNode *baru;
            baru = new TNode;

            baru->data = dataBaru;
            baru->next = bantu->next;

            bantu->next = baru;

            if(bantu == tail){
                tail = baru;
            }

            cout << "Data \""<<dataBaru<<"\" berhasil disispkan setelah data \""<<prevData<<"\"."<<endl;
        } else {
            cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List."<<endl;
        }
    } else cout<<"Tidak terdapat data pada Linked List."<<endl;
}