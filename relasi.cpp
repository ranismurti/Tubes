#include "relasi.h"


void createList(list_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(list_relasi &L, address_relasi P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(list_relasi &L, address_relasi P){
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

void inserAfter(list_relasi &L, address_relasi Prec, address_relasi P){
    if (next(Prec) == NULL){
        insertLast(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P) = Prec;
        next(Prec) = P;
        prev(next(Prec)) = P;
    }
}

void deleteFirst(list_relasi &L, address_relasi &P){
    P = first(L);

    if (first(L) == NULL || first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}

void deleteLast(list_relasi &L, address_relasi &P){
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

void deleteAfter(list_relasi &L, address_relasi Prec, address_relasi &P){
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

address_relasi alokasi(address_parent P, address_child C){
    address_relasi R;

    R = new elmlist_relasi;

    child(R) = C;
    parent(R) = P;
    next(R) = NULL;
    prev(R) = NULL;

    return R;
}

void dealokasi(address_relasi &P){
    delete P;
}

address_relasi findByID(list_relasi L, address_parent P, address_child C){
    address_relasi R;

    if (first(L) == NULL){
        R = NULL;
    }
    else{
        R = first(L);
        while (((R) != NULL) && (info(parent(R)).id != info(P).id || info(child(R)).id != info(C).id)){
            R = next(R);
        }
    }

    return R;
}

void printInfo(list_relasi L){
    address_relasi R;

    R = first(L);

    if (first(L) == NULL){
        cout<<"  Data Tidak Ada"<<endl;
    }
    else{
        while (R != NULL){
            cout<<endl<<"  "<<info(parent(R)).nama<<" - "<<info(child(R)).nama<<endl;
            cout<<"|========================================================================|"<<endl;
            R = next(R);
        }
    }
}

void deleteRelasi(list_relasi &LR, list_child LC, list_parent LP, infotype_child CC, infotype_parent PP, address_relasi &RR){
    address_child C;
    address_parent P;
    address_relasi R;

    C = findByID(LC,CC);
    P = findByID(LP,PP);
    if (C != NULL && P != NULL){
        R = findByID(LR,P,C);
        if (R != NULL){
            if (R == first(LR)){
                deleteFirst(LR,RR);
            }
            else if (next(R) == NULL){
                deleteLast(LR,RR);
            }
            else{
                deleteAfter(LR,prev(RR),RR);
            }
        }
        else{
            cout<<" Pasien Belum Didaftarkan ke Dokter"<<endl;
        }
    }
    else{
        cout<<"  ID Tidak Ada"<<endl;
    }
}

bool cek_id(list_relasi LR, address_child C, address_parent P)
{
    bool ada;
    address_relasi R;

    if (first(LR) == NULL){
        ada = false;
    }
    else{
        R = findByID(LR,P,C);
        if (R == NULL){
            ada = false;
        }
        else{
            ada = true;
        }
    }

    return ada;
}
