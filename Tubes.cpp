#include "Tubes.h"

void createList(List &L){
    first(L) = NULL;
}

adr createElemen(infotype x){
    adr p = new elemen;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void inserLast(List &L,adr p){
    adr q;
    if(first(L) == NULL){
        first(L) = p;
        next(p) = NULL;
    }else{
        q = first(L);
        while(next(q) != NULL){
            q = next(q);
        }
        next(q) = p;
        next(p) = NULL;
    }
}


void printList(List L){
    adr p = first(L);
    if(first(L) == NULL){
        cout << "List Kosong";
    }else{
        while(p != NULL){
            if(info(p).pangkat == 0){
                cout << info(p).angka << " ";
            }else if(info(p).pangkat == 1){
                cout << info(p).angka << "x ";
            }else{
                cout << info(p).angka << "x^" << info(p).pangkat<< " ";
            }
            if(next(p) != NULL && info(p).angka > 0){
                cout << "+";
            }
            cout << " ";
            p = next(p);
        }
    }

}


void deleteFirst(List &L,adr &p){
    if(first(L) == NULL){
        cout << "LIST KOSONG";
    }else if(next(first(L)) == NULL){
        p = first(L);
        first(L) = NULL;
    }else{
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
    }
}

void Gabungan(List L,List J,List &K,int banyak){
    adr p,q;
    while(banyak >= 0){
        p = Search(L,banyak);
        if(p != NULL){
            q = createElemen(info(p));
            inserLast(K,q);
        }
        p = Search(J,banyak);
        if(p != NULL){
            q = createElemen(info(p));
            inserLast(K,q);
        }
        banyak--;
    }

}

adr Search(List L,int pangkat){
    adr p;
    p = first(L);
    while(p!= NULL && info(p).pangkat != pangkat){
        p = next(p);
    }
    return p;
}

List addPoly(List L,List J){
    List H;
    createList(H);
    adr p = first(L);
    adr q,r;
    while(p != NULL){
        q = createElemen(info(p));
        inserLast(H,q);
        p = next(p);
    }
    p = first(J);
    while(p != NULL){
        q = Search(H,info(p).pangkat);
        if(q == NULL){
            r = createElemen(info(p));
            inserLast(H,r);
        }else{
            info(q).angka = info(q).angka + info(p).angka;
        }
        p = next(p);
    }
    return H;
}

List SubPoly(List L,List J){
    List H;
    createList(H);
    adr p = first(L);
    adr q,r;
    while(p != NULL){
        q = createElemen(info(p));
        inserLast(H,q);
        p = next(p);
    }
    p = first(J);
    while(p != NULL){
        q = Search(H,info(p).pangkat);
        if(q == NULL){
            r = createElemen(info(p));
            inserLast(H,r);
        }else{
            info(q).angka = info(q).angka - info(p).angka;
        }
        p = next(p);
    }
    return H;
}

void InputPoly1(List &L,int N){
    infotype angka;
    adr p;



    while(N >= 0){
        cout << "Masukan Koefisien  :   ";
        cin >> angka.angka;
        if(angka.angka == 0){
            cout << "Maaf koefisien tidak bisa 0, tolong masukan ulang  :";
            cin >> angka.angka;
        }
        cout << "Pangkat    :   ";
        cout << N<<endl;
        angka.pangkat = N;
        N--;
        p = createElemen(angka);
        inserLast(L,p);
    }
}

void InputPoly2(List &J,int M){
    infotype angka;
    adr p;

    while(M >= 0){
        cout << "Masukan Koefisien  :   ";
        cin >> angka.angka;
        if(angka.angka == 0){
            cout << "Maaf koefisien tidak bisa 0, tolong masukan ulang  :";
            cin >> angka.angka;
        }
        cout << "Pangkat    :   ";
        cout << M<<endl;
        angka.pangkat = M;
        M--;
        p = createElemen(angka);
        inserLast(J,p);
    }
}

int selectMenu(){
    int userInput = 0;
    cout<<"======MENU======="<<endl;
    cout<<"1. Tambah Polinom 1"<<endl;
    cout<<"2. Tambah Polinom 2" << endl;
    cout<<"3. Tampilkan Polinom 1" << endl;
    cout<<"4. Tampilkan Polinom 2" << endl;
    cout<<"5. Tampilkan Gabungan" << endl;
    cout<<"6. Tambahkan Polinom" << endl;
    cout<<"7. Kurangi Polinom" << endl;
    cout<<"0. Exit"<<endl << endl;

    cout<<"Masukkan menu : " ;
    cin>>userInput;
    cout << endl;

    return userInput;
}
