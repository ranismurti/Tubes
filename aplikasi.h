#ifndef APLIKASI_H_INCLUDED
#define APLIKASI_H_INCLUDED

#include <cstdlib>
#include <stdlib.h>
#include <conio.h>

#include "dokter.h"
#include "pasien.h"
#include "relasi.h"

void menu(list_child &LC, list_parent &LP, list_relasi &LR);
void masukandata(list_child &LC, list_parent &LP, list_relasi &LR);
void insert_child(list_child &LC);
void insert_parent(list_parent &LP);
void insertRelasi(list_relasi &LR,list_child LC,list_parent LP);
void lihat_data(list_relasi LR, list_parent LP, list_child LC);
void lihat_pasien(list_parent LP);
void lihat_dokter(list_child LC);
void lihat_relasi(list_relasi LR);
void hapus_data(list_relasi LR,list_parent LP, list_child LC);
void hapus_pasien(list_parent &LP);
void hapus_dokter(list_child &LC);
void hapus_relasi(list_relasi &LR,list_child LC, list_parent LP);
void edit_data(list_relasi LR, list_parent LP, list_child LC);
void edit_pasien(list_parent LP);
void edit_dokter(list_child LP);


#endif // APLIKASI_H_INCLUDED
