#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) ((L).first)

struct infotype{
    int angka,pangkat;
};

typedef struct elemen *adr;

struct elemen{
    infotype info;
    adr next;
};

struct List{
    adr first;
};

void createList(List &L);
adr createElemen(infotype x);
void inserLast(List &L,adr p);
void printList(List L);
void deleteFirst(List &L,adr &p);

void Gabungan(List L,List J,List &K,int banyak);
void penyamaanPangkat(List K,List &L);
List addPoly(List L,List J);
List SubPoly(List L,List J);
void InputPoly1(List &L,int N);
void InputPoly2(List &J,int N);

adr Search(List L,int pangkat);

int selectMenu();


#endif // TUBES_H_INCLUDED
