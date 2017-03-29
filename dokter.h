#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

struct dokter{
    string nama,jk,spesialis,no_hp;
    int id,usia;
};

typedef dokter infotype_child;

typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
};

struct list_child{
    address_child first;
};

void createList(list_child &L);
void insertFirst(list_child &L, address_child P);
void insertLast(list_child &L, address_child P);
void insertAfter(list_child &L, address_child Prec, address_child P);
void deleteFirst(list_child &L, address_child &P);
void deleteLast(list_child &L, address_child &P);
void deleteAfter(list_child &L, address_child Prec, address_child &P);
void printInfo(list_child L);

address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findByID(list_child L, infotype_child x);

void insert_ascending(list_child &LC, address_child P);
bool cek_id(list_child LC,infotype_child x);
void deleteByID(list_child &LC,address_child &P);
void edit_data(list_child &LC, address_child C, infotype_child y);

#endif // DOKTER_H_INCLUDED
