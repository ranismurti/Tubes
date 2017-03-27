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
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
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
    if (first(L) == NULL){
        P = NULL;
    }
    else{
        P = first(L);
        if (next(P) = NULL){
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            first(L) = next(P);
            next(P) = NULL;
            prev(first(L)) = NULL;
        }
    }
}

void deleteLast(list_relasi &L, address_relasi &P){
    if (first(L) == NULL){
        P = NULL;
    }
    else{
        P = last(L);
        if ((P) = first(L)){
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            last(L) = prev(P);
            prev(P) = NULL;
            next(last(L)) = NULL;
        }
    }
}

void deleteAfter(list_relasi &L, address_relasi Prec, address_relasi &P){
    if (next(Prec) == NULL){
        P = NULL;
    }
    else if (next(next(Prec)) == NULL){
        deleteLast(L,P);
    }
    else{
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
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


    if (first(L) == NULL){
        P = NULL;
    }
    else{
        while (P != NULL){
            P = next(P);
        }
        if ((P) != NULL){
            P = NULL;
        }
    }

    return P;
}

void printInfo(list_relasi L){
    address_relasi R;

    R = first(L);

    if (first(L) == NULL){
        cout<<"List Kosong"<<endl;
    }
    else{
        while (R != NULL){
            R = next(R);
        }
    }
}
