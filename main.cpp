#include "Tubes.h"

int main()
{
    system("color 0A");
    List L,J,K,H,O;
    createList(L);
    createList(K);
    createList(J);
    int pilihan = selectMenu();
    string x;
    int N,M,Terbanyak;

    while(pilihan != 0){
        switch (pilihan){
        case 1:
            cout << "Masukan Pangkat Tertinggi Polinomial 1 : ";
            cin >> N;
            InputPoly1(L,N);
            Terbanyak = N;
            break;
        case 2 :
            cout << "Masukan Pangkan Tertinggi Polinomial 2  : ";
            cin >> M;
            if (M > N){
                Terbanyak = M;
            }
            InputPoly2(J,M);
            break;
        case 3 :
            cout << "Menampilkan Bilangan Polinomial 1 :" << endl;
            printList(L);
            break;
        case 4 :
            cout << "Menampilkan Bilangan Polinomial 2 :" << endl;
            printList(J);
            break;
        case 5 :
            cout << "Menampilkan Bilangan Polinomial yang sudah digabungkan :" << endl;
            Gabungan(L,J,K,Terbanyak);
            printList(K);
            break;
        case 6 :
            cout << "Berikut Hasil dari kedua Bilangan polinom setelah ditambahkan : " << endl;
            O = addPoly(L,J);
            printList(O);
            break;
        case 7 :
            cout << "Berikut Hasil dari kedua Bilangan polinom setelah dikurangi : " << endl;
            H = SubPoly(L,J);
            printList(H);
            break;
        }

    cout << endl;
    cout << "Kembali ke Menu Utama ? (Y/N): ";
    cin >> x;
    if(x == "N" || x == "n"){
        break;
    }else if(x == "Y" || x == "y"){
        pilihan = selectMenu();
    }
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM";























}
