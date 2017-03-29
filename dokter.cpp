#include "dokter.h"


void createList(list_child &L){
    first(L) = NULL;
}

address_child alokasi(infotype_child x){
    address_child P;

    P = new elmlist_child;
    info(P).nama = x.nama;
    info(P).id = x.id;
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

    if (first(L) == NULL){
        first(L) = P;
        next(P) = NULL;
    }
    else{
        next(P)=first(L);
        first(L)=P;
    }
}

void insertLast(list_child &L, address_child P){
    address_child Q;

    if (first(L) == NULL ){
        first(L) = P;
        next(P) = NULL;
    }
    else{
        Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;
    }

}

void insertAfter(list_child &L, address_child prec,address_child P)
{
    if (next(prec)==NULL){
        insertLast(L,P);
    }
    else {
        next(P)=next(prec);
        next(prec)=P;
    }
}
address_child findByID(list_child L, infotype_child x){
    address_child P;

    if (first(L) == NULL){
        P = NULL;
    }
    else{
        P = first(L);
        while (info(P).id != x.id && (P) != NULL){
            P = next(P);
        }
        if (info(P).id != x.id){
            P = NULL;
        }
    }

    return P;
}

void deleteFirst(list_child &L, address_child &P){
    P=first(L);
    if (first(L)==NULL || next(first(L))!=NULL){
        first(L)=NULL;
    }
    else{
        first(L)=next(P);
        next(P)=NULL;
    }

}

void deleteLast(list_child &L, address_child &P){

    P = first(L);

    if (first(L) == NULL || next(first(L)) == NULL){
        first(L) = NULL;
    }
    else{
        P = first(L);
        while (next(next(P)) != NULL){
            P= next(P);
        }
        P=next(P);
        next(P)=NULL;
    }
}

void deleteAfter(list_child &L, address_child Prec, address_child &P){

    if (next(next(Prec)) == NULL){
        deleteLast(L,P);
    }
    else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P)=NULL;
    }
}

void insert_ascending(list_child &LC, address_child P){
    address_child prec;

    if (first(LC) == NULL || info(first(LC)).id > info(P).id){
        insertFirst(LC,P);
    }
    else{
        prec = first(LC);
        while (next(prec) != NULL && info(prec).id < info(P).id){
            prec = next(prec);
        }
        if (next(prec) == NULL){
            insertLast(LC,P);
        }
        else{
            insertAfter(LC,prec,P);
        }
    }
}

bool cek_id(list_child LC,infotype_child x)
{
    bool ada;
    address_child C;

    if (first(LC) == NULL){
        ada = false;
    }
    else{
        C = first(LC);
        while (next(C) != NULL && info(C).id != x.id){
            C = next(C);
        }
        if (info(C).id == x.id){
            ada = true;
        }
        else{
            ada = false;
        }
    }

    return ada;
}

void printInfo(list_child L){
    address_child C;

    C = first(L);

    if (first(L) == NULL){
        cout<<"  Data Tidak Ada"<<endl;
    }
    else{
        do{
            cout<<endl<<"  > Nama Dokter   : "<<info(C).nama<<endl;
            cout<<endl<<"  > ID            : "<<info(C).id<<endl;
            cout<<endl<<"  > Umur          : "<<info(C).usia<<endl;
            cout<<endl<<"  > Jenis Kelamin : "<<info(C).jk<<endl;
            cout<<endl<<"  > Spesialis     : "<<info(C).spesialis<<endl;
            cout<<endl<<"  > No. HP        : "<<info(C).no_hp<<endl;
            cout<<endl<<"  > Alamat        : "<<info(C).alamat<<endl<<endl;
            cout<<"|========================================================================|"<<endl;
            C = next(C);
        }while (C != NULL);
    }
}

void deleteByID(list_child &LC,address_child &P){
    address_child prec;

    if (next(P) == NULL){
        deleteLast(LC,P);
    }
    else if (P == first(LC)){
        deleteFirst(LC,P);
    }
    else{
        prec = first(LC);
        while (next(prec) != P){
            prec = next(prec);
        }
        deleteAfter(LC,prec,P);
    }
}
