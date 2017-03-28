#include "pasien.h"

void createList(list_parent &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasi(infotype_parent x)
{
    address_parent P;

    P = new elmlist_parent;
    info(P).nama = x.nama;
    info(P).id = x.id;
    info(P).umur = x.umur;
    info(P).jk = x.jk;
    info(P).darah = x.darah;
    info(P).alm = x.alm;
    info(P).keluhan = x.keluhan;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void insertFirst(list_parent &L, address_parent P)
{

    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(list_parent &L, address_parent P)
{

    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

address_parent findByID(list_parent L, infotype_parent x)
{
    address_parent P;

    P = first(L);

    if (first(L) == NULL)
    {
        P = NULL;
    }
    else
    {
        while (next(P) != NULL && info(P).id != x.id)
        {
            P = next(P);
        }
        if (info(P).id != x.id)
        {
            P = NULL;
        }
    }

    return P;
}

void deleteFirst(list_parent &L, address_parent &P)
{
    P = first(L);

    if (first(L) == NULL || first(L) == last(L))
    {
        first(L) == NULL;
        last(L) == NULL;
    }
    else
    {
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}

void deleteLast(list_parent &L, address_parent &P)
{
    P = last(L);

    if (first(L) == NULL || next(first(L)) == NULL)
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfter(list_parent &L, address_parent Prec, address_parent &P)
{
    P = first(L);

    if (next(Prec) == NULL)
    {
        P = NULL;
    }
    else
    {
        P = next(Prec);
        prev(next(P)) = Prec;
        next(Prec) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void insertAfter(list_parent &L,address_parent Prec,address_parent P)
{
    if (next(Prec) == NULL){
        insertLast(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void insert_ascending(list_parent &LP, address_parent P){
    address_parent prec;

    if (first(LP) == NULL || info(first(LP)).id > info(P).id){
        insertFirst(LP,P);
    }
    else{
        prec = first(LP);
        while (next(prec) != NULL && info(next(prec)).id < info(P).id){
            prec = next(prec);
        }
        if (next(prec) == NULL){
            insertLast(LP,P);
        }
        else{
            insertAfter(LP,prec,P);
        }
    }
}

bool cek_id(list_parent LP,infotype_parent x)
{
    bool ada;
    address_parent P;

    if (first(LP) == NULL){
        ada = false;
    }
    else{
        P = first(LP);
        while (next(P) != NULL && info(P).id != x.id){
            P = next(P);
        }
        if (info(P).id == x.id){
            ada = true;
        }
        else{
            ada = false;
        }
    }

    return ada;
}

void printInfo(list_parent L){
    address_parent P;

    P = first(L);

    if (first(L) == NULL){
        cout<<"  Data Tidak Ada"<<endl;
    }
    else{
        while (P != NULL)
        {
            cout<<endl<<"  > Nama Pasien   : "<<info(P).nama<<endl;
            cout<<endl<<"  > ID            : "<<info(P).id<<endl;
            cout<<endl<<"  > Umur          : "<<info(P).umur<<endl;
            cout<<endl<<"  > Jenis Kelamin : "<<info(P).jk<<endl;
            cout<<endl<<"  > Gol. Darah    : "<<info(P).darah<<endl;
            cout<<endl<<"  > Alamat        : "<<info(P).alm<<endl;
            cout<<endl<<"  > Keluhan       : "<<info(P).keluhan<<endl<<endl;
            cout<<"|========================================================================|"<<endl;
            P = next(P);
        }
    }
}

void deleteByID(list_parent &LP, address_parent &P){

    if (P == last(LP)){
        deleteLast(LP,P);
    }
    else if (P == first(LP)){
        deleteFirst(LP,P);
    }
    else{
        deleteAfter(LP,prev(P),P);
    }
}
