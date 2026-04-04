#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;
struct Code{
    int Front;
    int Back;
    int Data[n];
};
Code Nilai;
int Kosong(){
    if(Nilai.Back == -1){
        return 1;
    }else{
        return 0;
    }
}
int Penuh(){
    if(Nilai.Back == n-1){
        return 1;
    }else{
        return 0;
    }
}
void INSERT(int Data){
    if(Kosong() == 1){
        Nilai.Front = Nilai.Back = 0;
        Nilai.Data[Nilai.Back] = Data;
    }
    else if(Penuh() == 0){
        Nilai.Back++;
        Nilai.Data[Nilai.Back] = Data;
    }
}
void DELETE(){
    if(Kosong()==1){
        cout << "Antrean Kosong!";
    }else{
        int e = Nilai.Data[Nilai.Front];
        int i;
    for(i=Nilai.Front; i<=Nilai.Back-1; i++){
        Nilai.Data[i] = Nilai.Data[i+1];
    }Nilai.Back--;
        cout << "Data " << e << "Berhasil Dihapus";
    }
}
void CETAKLAYAR(){
   if(Kosong() == 1){
    cout << "\nAntrean Kosong\n";
   }
   else{
    cout << "\nAntrean saat ini : \n";
    for(int i = Nilai.Front ; i<=Nilai.Back; i++){
        cout << "[" << Nilai.Data[i] << "] ";
    }
    cout << endl;
   }
}
void Inisialisasi(){
    Nilai.Front = Nilai.Back = -1;
}
void RESET(){
    Nilai.Front = Nilai.Back = -1;
    cout << "The Queue has been cleared by Me!";
}
int PIL, F, R;
char PILIHAN [1], HURUF;
char Q[n];
int main(){
    Inisialisasi();
    
    do{

        cout << "QUEUE"<<endl;
        cout << "=============="<<endl;
        cout << "1. INSERT"<<endl;
        cout << "2. DELETE"<<endl;
        cout << "3. CETAK QUEUE"<<endl;
        cout << "4. QUIT"<<endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);
        switch (PIL)
        {
        case 1:
            int Angka;
            cout << "Masukkan angka yang diinginkan : "; cin >> Angka;
            INSERT(Angka);
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR();
            break;
        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout<< "press any key to continue"<<endl;
        getch();
        system("cls");

    }
    while (PIL<4);
    
}

