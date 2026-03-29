#include <iostream>
#include <string.h>

using namespace std;

struct Motor
{
    char Plat[20], Jenis_Kendaraan[10], Nama[20], Alamat[20], Kota[20];
};



main(){
   int i;
   Motor Print;
        strcpy(Print.Plat, "DA1234MK");
        strcpy(Print.Jenis_Kendaraan, "RUSH");
        strcpy(Print.Nama, "Andika Hartanto");
        strcpy(Print.Alamat, "Jl. Kayu Tangi 1");
        strcpy(Print.Kota, "Banjarmasin");

        cout<<"\n\n--------------------------------------------\n";
        cout<<" Output ";
        cout<<"\n--------------------------------------------\n";
        cout<<"a. Plat Nomor Kendaraan : "<<Print.Plat<<endl;
        cout<<"b. Jenis Kendaraan : "<<Print.Jenis_Kendaraan<<endl;
        cout<<"c. Nama Pemilik : "<<Print.Nama<<endl;
        cout<<"d. Alamat : "<<Print.Alamat<<endl;
        cout<<"e. Kota : "<<Print.Kota;

}
