#include <iostream>
using namespace std;
#define max 5

struct Code {
    int atas;
    int data[max];
};

Code Tumpuk;

int penuh (){
    if(Tumpuk.atas == max-1){
        return 1; }
    else{        
        return 0;
    }
    
}

int kosong(){
    if(Tumpuk.atas == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void input (int data){
    if(kosong()==1){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]<<" Masuk Ke Stack" << endl;
    }
    else if(penuh() == 0){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack" << endl;
    }
    else{
        cout << "Tumpukan Penuh";
    }
}

void hapus(){
    if(kosong() == 0){
        cout << "Data teratas sudah terambil";
        Tumpuk.atas--;
    }
    else{
        cout << "Data kosong";
    }
}
void tampil(){
    if(kosong() == 0){
        for(int i = Tumpuk.atas; i>=0; i--){
            cout << "\nTumpukan ke " << i << " = " << Tumpuk.data[i];
        }
    }
    else{
        cout << "Tumpukan Kosong";
    }
}
void bersih(){
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

int main(){
    Tumpuk.atas = -1;
    while (true)
    {
        int a, angka;
        cout << "\nChoose The Number That You Want !\n";
        cout << "1. Input\n2. Hapus\n3. Print\n4.Reset\n5. Exit\n";
        cout << "choose"; cin >> a;
        if(a == 1){
            cout << "Input sebuah angka : "; cin >> angka;
            input(angka);
        }
        else if(a==2){
            hapus();
        }
        else if(a == 3){
            tampil();
        }
        else if(a == 4){
            bersih();
        }
        else if(a == 5){
            break;
        }
        else{
            cout << "\nInput yang bener\n";
        }
    }
    return 0;
}