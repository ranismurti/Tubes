#ifndef APLIKASI_H_INCLUDED
#define APLIKASI_H_INCLUDED

#include "dokter.h"
#include "pasien.h"
#include "relasi.h"

void menu(list_child &LC, list_parent &LP, list_relasi &LR);
void masukandata(list_child &LC, list_parent &LP, list_relasi &LR);;
void insert_child(list_child &LC);
void insert_parent(list_parent &LP);
void insertRelasi(list_relasi &LR,list_child LC,list_parent LP,adrress_child C,address_parent P);
void view_parent();
void view_child();


#endif // APLIKASI_H_INCLUDED
