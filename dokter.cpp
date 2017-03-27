#include "dokter.h"


void createList(list_child &L){
    first(L) = NULL;
}

address_child alokasi(infotype_child x){
    address_child P;

    P = new elmlist_child;
    info(P).nama = x.nama;
    info(P).usia = x.usia;
    info(P).jk = x.jk;
    info(P).spesialis = x.spesialis;
    info(P).no_hp = x.no_hp;
    info(P).alamat = x.alamat;
    next(P) = NULL;

    return P;
}

void dealokasi(address_child &P){
    delete P;
}

void insertFirst(list_child &L, address_child P){
    address_child Q;

    if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    }
    else{
        next(P) = first(L);
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(list_child &L, address_child P){
    address_child Q;

    if (first(L) = NULL){
        first(L) = P;
        next(P) = first(L);
    }
    else{
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }

}

void insertAfter(list_child &L, address_child prec,address_child P)
{
    if (next(prec)==first(L)){
        insertLast(L,P);
    }
    else {
        next(P)=next(prec);
        next(prec)=P;
    }
}

void sorting(list_child &L, address_child P){
    address_child prec;

    if(first(L) == NULL){
        insertFirst(L,P);
    }
    else{

    }
}
address_child findByID(list_child L, infotype_child x){
    address_child P;

    if (first(L) == NULL){
        P = NULL;
    }
    else{
        P = first(L);
        while (info(P).id != x.id && P != NULL){
            P = next(P);
        }
        if (info(P).id != x.id){
            P = NULL;
        }
    }

    return P;
}

void deleteFirst(list_child &L, address_child &P){
    address_child Q;

    P = first(L);

    if (first(L) == NULL || next(first(L)) == first(L)){
        first(L) = NULL;
    }
    else{
        first(L) = next(P);
        Q = first(L);
        while (next(Q) != P){
            Q = next(Q);
        }
        next(Q) = first(L);
        next(P) = NULL;
    }

}

void deleteLast(list_child &L, address_child &P){
    address_child Q;

    P = first(L);

    if (first(L) == NULL || next(first(L)) == first(L)){
        first(L) = NULL;
    }
    else{
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void deleteAfter(list_child &L, address_child &Prec, address_child &P){

    if (next(next(Prec)) == first(L)){
        deleteLast(L,P);
    }
    else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

