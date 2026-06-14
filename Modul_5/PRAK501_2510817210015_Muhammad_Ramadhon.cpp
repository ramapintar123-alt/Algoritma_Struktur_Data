#include <iostream>

using namespace std;

int NIM[] = {2, 5, 1, 0, 8, 1, 7, 2, 1, 0, 0, 1, 5};
char Nama[] = {'M', 'U', 'H', 'A', 'M', 'M', 'A', 'D', 'R', 'A', 'M', 'A', 'D', 'H', 'O', 'N'};
int n_nim = sizeof(NIM)/sizeof(NIM[0]);
int n_nama = sizeof(Nama)/sizeof(Nama[0]);

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void BubbleNIM(){
    int TempNIM[13];
    for(int i = 0; i <= n_nim - 1; i++) TempNIM[i] = NIM[i];

    cout << "\nSebelum :";
    for(int i = 0; i <= n_nim - 1; i++) cout << " " << TempNIM[i];

    for(int i = 0; i <= n_nim - 1; i++){
        for(int j = 0; j <= n_nim - i - 2; j++){
            if(TempNIM[j] > TempNIM[j + 1]){
                Swap(TempNIM[j], TempNIM[j + 1]);
            }
        }
    }

    cout << "\nSesudah :";
    for(int i = 0; i <= n_nim - 1; i++) cout << " " << TempNIM[i];
    cout << endl;
}

void SelectionNIM(){
    int TempNIM[13];
    for(int i = 0; i <= n_nim - 1; i++) TempNIM[i] = NIM[i];

    cout << "\nSebelum :";
    for(int i = 0; i <= n_nim - 1; i++) cout << " " << TempNIM[i];

    for(int i = 0; i <= n_nim - 1; i++){
        int idx_min = i;
        for(int j = i + 1; j <= n_nim - 1; j++){
            if(TempNIM[j] < TempNIM[idx_min]){
                idx_min = j;
            }
        }
        Swap(TempNIM[i], TempNIM[idx_min]);
    }

    cout << "\nSesudah :";
    for(int i = 0; i <= n_nim - 1; i++) cout << " " << TempNIM[i];
    cout << endl;
}

void InsertionNama(){
    char TempNama[16];
    for(int i = 0; i <= n_nama - 1; i++) TempNama[i] = Nama[i];

    cout << "\nSebelum :";
    for(int i = 0; i <= n_nama - 1; i++) cout << " " << TempNama[i];

    for(int i = 1; i <= n_nama - 1; i++){
        char Key = TempNama[i];
        int j = i - 1;
        while(j >= 0 && TempNama[j] > Key){
            TempNama[j + 1] = TempNama[j];
            j = j - 1;
        }
        TempNama[j + 1] = Key;
    }

    cout << "\nSesudah :";
    for(int i = 0; i <= n_nama - 1; i++) cout << " " << TempNama[i];
    cout << endl;
}

void Merge(char Data[], int Left, int Mid, int Right){
    int N1 = Mid - Left + 1;
    int N2 = Right - Mid;

    char L[N1], R[N2];

    for(int i = 0; i <= N1 - 1; i++){
        L[i] = Data[Left + i];
    }
    for(int j = 0; j <= N2 - 1; j++){
        R[j] = Data[Mid + 1 + j];
    }

    int i = 0, j = 0, k = Left;
    while(i <= N1 - 1 && j <= N2 - 1){
        if (L[i] <= R[j]){
            Data[k] = L[i];
            i++;
        }
        else{
            Data[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < N1){
        Data[k] = L[i];
        i++;
        k++;
    }

    while(j < N2){
        Data[k] = R[j];
        j++;
        k++;
    }
}

void MergeNamaSub(char Data[], int Left, int Right){
    if (Left < Right){
        int Mid = Left + (Right - Left)/2;

        MergeNamaSub(Data, Left, Mid);
        MergeNamaSub(Data, Mid + 1, Right);

        Merge(Data, Left, Mid, Right);
    }
}

void MergeNama(){
    char TempNama[16];
    for(int i = 0; i <= n_nama - 1; i++) TempNama[i] = Nama[i];

    cout << "\nSebelum :";
    for(int i = 0; i <= n_nama - 1; i++) cout << " " << TempNama[i];

    MergeNamaSub(TempNama, 0, n_nama - 1);

    cout << "\nSesudah :";
    for(int i = 0; i <= n_nama - 1; i++) cout << " " << TempNama[i];
    cout << endl;
}

int PartitionNama(int Data[], int Left, int Right) {
    int Pivot = Data[Right]; 
    int i = Left - 1;
    for (int j = Left; j < Right; j++) {
        if (Data[j] < Pivot) {
            i++;
            Swap(Data[i], Data[j]);
        }
    }
    Swap(Data[i + 1], Data[Right]);
    return (i + 1);
}

void QuickNIMSub(int Data[], int Left, int Right) {
    if (Left < Right) {
        int PivotIndex = PartitionNama(Data, Left, Right);

        QuickNIMSub(Data, Left, PivotIndex - 1);
        QuickNIMSub(Data, PivotIndex + 1, Right);
    }
}

void QuickNIM(){
    int TempNIM[13];
    for(int i = 0; i <= n_nim - 1; i++) TempNIM[i] = NIM[i];

    cout << "\nSebelum :";
    for(int i = 0; i <= n_nim - 1; i++) cout << " " << TempNIM[i];

    QuickNIMSub(TempNIM, 0, n_nim - 1);

    cout << "\nSesudah :";
    for(int i = 0; i <= n_nim - 1; i++) cout << " " << TempNIM[i];
    cout << endl;
}

void ShellNama(){
    char TempNama[16];
    for(int i = 0; i <= n_nama - 1; i++) TempNama[i] = Nama[i];

    cout << "\nSebelum :";
    for(int i = 0; i <= n_nama - 1; i++) cout << " " << TempNama[i];

    for (int Gap = n_nama / 2; Gap > 0; Gap /= 2) {
        for (int i = Gap; i <= n_nama - 1; i++) {
            char temp = TempNama[i];
            int j;
            for (j = i; j >= Gap && TempNama[j - Gap] > temp; j -= Gap) {
                TempNama[j] = TempNama[j - Gap];
            }
            TempNama[j] = temp;
        }
    }

    cout << "\nSesudah :";
    for(int i = 0; i <= n_nama - 1; i++) cout << " " << TempNama[i];
    cout << endl;
}

int main(){
    int pilihan;
    do {
        cout<<"---------------------"<<endl;
        cout<<"|       SORTING     |"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1. Insertion Sort (Nama)"<<endl;
        cout<<"2. Merge Sort (Nama)"<<endl;
        cout<<"3. Shell Sort (Nama)"<<endl;
        cout<<"4. Quick Sort (NIM)"<<endl;
        cout<<"5. Bubble Sort (NIM)"<<endl;
        cout<<"6. Selection Sort (NIM)"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>pilihan;

        switch(pilihan) {
            case 1:
                InsertionNama();
                break;
            case 2:
                MergeNama();
                break;
            case 3:
                ShellNama();
                break;
            case 4:
                QuickNIM();
                break;
            case 5:
                BubbleNIM();
                break;
            case 6:
                SelectionNIM();
                break;
            case 7:
                cout<<"\nTERIMA KASIH"<<endl;
                cout<<"Program was made by Muhammad Ramadhon (2510817210015)."<<endl;
                return 0;
        }

        cout<<"\nPress enter to continue..."<<endl;
        cin.ignore();
        cin.get();
        system("cls");

    } while (pilihan != 7);
    return 0;
}