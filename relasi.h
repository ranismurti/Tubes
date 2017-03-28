#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "pasien.h"
#include "dokter.h"

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define parent(P) P->parent

using namespace std;

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_relasi prev;
    address_child child;
    address_parent parent;
};

struct list_relasi{
    address_relasi first;
    address_relasi last;
};

void createList(list_relasi &L);
void insertFirst(list_relasi &L, address_relasi P);
void insertLast(list_relasi &L, address_relasi P);
void inserAfter(list_relasi &L, address_relasi Prec, address_relasi P);
void deleteFirst(list_relasi &L, address_relasi &P);
void deleteLast(list_relasi &L, address_relasi &P);
void deleteAfter(list_relasi &L, address_relasi Prec, address_relasi &P);
address_relasi alokasi(address_parent P, address_child C);
void dealokasi_relasi(address_relasi &P);
address_relasi findByID(list_relasi L, address_parent P, address_child C);
void printInfo(list_relasi L);
void deleteRelasi(list_relasi &LR, list_child LC, list_parent LP, infotype_child CC, infotype_parent PP, address_relasi &RR);
bool cek_id(list_relasi LR, address_child C, address_parent P);
void sorting(list_relasi &L);


#endif // RELASI_H_INCLUDED
