#include "aplikasi.h"

void menu(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    infotype_parent x;
    address_parent P,PP;
    infotype_child y;
    address_child C,CC;
    address_relasi R,RR;
    char a;
    system("CLS");
    do
    {
        cout<<endl;
        cout<<" ==================================== "<<endl;
        cout<<"|                MENU                |"<<endl;
        cout<<"|====================================|"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 1) Masukan Data                    |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 2) Daftarkan Pasien ke Dokter      |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 3) Lihat Data Pasien               |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 4) Lihat Data Dokter               |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 5) Lihat Daftar Pasien ke Dokter   |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 6) Hapus Data Pasien               |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 7) Hapus Data Dokter               |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 8) Hapus Data Pasien ke Dokter     |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 9) Keluar                          |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<" ==================================== "<<endl;
        cout<<"  > PILIH : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            masukandata(LC,LP,LR);
        case 2:
            insertRelasi(LR,LC,LP);
            menu(LC,LP,LR);
        case 3:
            system("CLS");
            cout<<" ======================================================================== "<<endl;
            cout<<"|                              DATA PASIEN                               |"<<endl;
            cout<<" ======================================================================== "<<endl;
            printInfo(LP);
            cout<<endl<<"  Tekan ENTER Untuk Kembali"<<endl;
            getch();
            system("CLS");
            menu(LC,LP,LR);
        case 4:
            system("CLS");
            cout<<" ======================================================================== "<<endl;
            cout<<"|                              DATA DOKTER                               |"<<endl;
            cout<<" ======================================================================== "<<endl;
            printInfo(LC);
            cout<<endl<<"  Tekan ENTER Untuk Kembali"<<endl;
            getch();
            system("CLS");
            menu(LC,LP,LR);
        case 5:
            system("CLS");
            cout<<" ======================================================================== "<<endl;
            cout<<"|                           DATA PASIEN-DOKTER                           |"<<endl;
            cout<<" ======================================================================== "<<endl;
            printInfo(LR);
            cout<<endl<<"  Tekan ENTER Untuk Kembali"<<endl;
            getch();
            system("CLS");
            menu(LC,LP,LR);
        case 6:
            system("CLS");
            cout<<" ======================================================================== "<<endl;
            cout<<"|                           HAPUS DATA PASIEN                            |"<<endl;
            cout<<" ======================================================================== "<<endl;
            cout<<endl<<"  > Masukkan ID Pasien : ";
            cin>>x.id;
            P = findByID(LP,x);
            if (P != NULL){
                cout<<endl<<"  > Nama Pasien   : "<<info(P).nama<<endl;
                cout<<endl<<"  > ID            : "<<info(P).id<<endl;
                cout<<endl<<"  > Umur          : "<<info(P).umur<<endl;
                cout<<endl<<"  > Jenis Kelamin : "<<info(P).jk<<endl;
                cout<<endl<<"  > Gol. Darah    : "<<info(P).darah<<endl;
                cout<<endl<<"  > Alamat        : "<<info(P).alm<<endl;
                cout<<endl<<"  > Keluhan       : "<<info(P).keluhan<<endl<<endl;
                cout<<"|========================================================================|"<<endl;
                cout<<"  Yakin Ingin Menghapus Data Tersebut(Y/N) : ";
                cin>>a;
                cout<<endl;
                if (a == 'y' || a == 'Y'){
                    deleteByID(LP,P);
                    cout<<"  Data Berhasil Dihapus, Tekan ENTER Untuk Kembali"<<endl;
                }
                else{
                    cout<<"  Data Tidak Dihapus, Tekan ENTER Untuk Kembali"<<endl;
                }
            }
            else{
                cout<<endl<<"  Data Tidak Ditemukan"<<endl;
            }
            menu(LC,LP,LR);
        case 7:
            system("CLS");
            cout<<" ======================================================================== "<<endl;
            cout<<"|                           HAPUS DATA DOKTER                            |"<<endl;
            cout<<" ======================================================================== "<<endl;
            cout<<endl<<"  > Masukkan ID Dokter : ";
            cin>>y.id;
            C = findByID(LC,y);
            if (C != NULL){
                cout<<endl<<"  > Nama Dokter   : "<<info(C).nama<<endl;
                cout<<endl<<"  > ID            : "<<info(C).id<<endl;
                cout<<endl<<"  > Umur          : "<<info(C).usia<<endl;
                cout<<endl<<"  > Jenis Kelamin : "<<info(C).jk<<endl;
                cout<<endl<<"  > Spesialis     : "<<info(C).spesialis<<endl;
                cout<<endl<<"  > No. HP        : "<<info(C).no_hp<<endl;
                cout<<endl<<"  > Alamat        : "<<info(C).alamat<<endl<<endl;
                cout<<"|========================================================================|"<<endl;
                cout<<"  Yakin Ingin Menghapus Data Tersebut(Y/N) : ";
                cin>>a;
                if (a == 'y' || a == 'Y'){
                    deleteByID(LC,C);
                    cout<<"  Data Berhasil Dihapus, Tekan ENTER Untuk Kembali"<<endl;
                }
                else{
                    cout<<"  Data Tidak Dihapus, Tekan ENTER Untuk Kembali"<<endl;
                }
            }
            else{
                cout<<endl<<"  Data Tidak Ditemukan"<<endl;
            }
            getch();
            menu(LC,LP,LR);
        case 8:
            system("CLS");
            cout<<" ======================================================================== "<<endl;
            cout<<"|                       HAPUS DATA PASIEN-DOKTER                         |"<<endl;
            cout<<" ======================================================================== "<<endl;
            cout<<endl<<"  > Masukkan ID Pasien : ";
            cin>>x.id;
            cout<<endl<<endl<<"  > Masukkan ID Dokter : ";
            cin>>y.id;
            P = findByID(LP,x);
            C = findByID(LC,y);
            R = findByID(LR,P,C);
            if (R != NULL){
                cout<<endl<<"  "<<info(parent(R)).nama<<" - "<<info(child(R)).nama<<endl;
                cout<<"|========================================================================|"<<endl;
                cout<<"  Yakin Ingin Menghapus Data Tersebut(Y/N) : ";
                cin>>a;
                if (a == 'y' || a == 'Y'){
                    deleteRelasi(LR,LC,LP,y,x,RR);
                    cout<<"  Data Berhasil Dihapus, Tekan ENTER Untuk Kembali"<<endl;
                }
                else{
                    cout<<"  Data Tidak Dihapus, Tekan ENTER Untuk Kembali"<<endl;
                }
            }
            else{
                cout<<endl<<"  Data Tidak Ditemukan"<<endl;
            }
            getch();
            menu(LC,LP,LR);
        case 9:
            exit(0);
        }
    }
    while(pil!=9);
}

void masukandata(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    system("CLS");
    do
    {
        cout<<endl;
        cout<<" ============================== "<<endl;
        cout<<"|           MENU DATA          |"<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 1)Masukan Data Pasien        |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 2)Masukan Data Dokter        |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 3)Kembali Ke Menu            |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<" ============================== "<<endl;
        cout<<"  > PILIH: ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            insert_parent(LP);
            menu(LC,LP,LR);
        case 2:
            insert_child(LC);
            menu(LC,LP,LR);
        case 3:
            menu(LC,LP,LR);
        }
    }
    while (pil!=0);
}

void insert_child(list_child &LC)
{
    infotype_child D;
    address_child C;

    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                           INPUT DATA DOKTER                            |"<<endl;
    cout<<" ======================================================================== "<<endl;
    cout<<endl<<"  > Nama Dokter   : ";
    cin>>D.nama;
    cout<<endl<<"  > ID            : ";
    cin>>D.id;
    cout<<endl<<"  > Umur          : ";
    cin>>D.usia;
    cout<<endl<<"  > Jenis Kelamin : ";
    cin>>D.jk;
    cout<<endl<<"  > Spesialis     : ";
    cin>>D.spesialis;
    cout<<endl<<"  > No. HP        : ";
    cin>>D.no_hp;
    cout<<endl<<"  > Alamat        : ";
    cin>>D.alamat;
    cout<<endl;

    C = alokasi(D);
    if (cek_id(LC,D)){
        cout<<"  ID Sudah Ada, Harap Masukkan ID Lain"<<endl;
    }
    else{
        insert_ascending(LC,C);
        cout<<"  Data Berhasil Di Masukkan";
    }
    getch();

}

void insert_parent(list_parent &LP)
{
    infotype_parent P;
    address_parent Q;

    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                           INPUT DATA PASIEN                            |"<<endl;
    cout<<" ======================================================================== "<<endl;
    cout<<endl<<"  > Nama Pasien    : ";
    cin>>P.nama;
    cout<<endl<<"  > ID             : ";
    cin>>P.id;
    cout<<endl<<"  > Umur           : ";
    cin>>P.umur;
    cout<<endl<<"  > Jenis Kelamin  : ";
    cin>>P.jk;
    cout<<endl<<"  > Golongan Darah : ";
    cin>>P.darah;
    cout<<endl<<"  > Alamat         : ";
    cin>>P.alm;
    cout<<endl<<"  > Keluhan        : ";
    cin>>P.keluhan;
    cout<<endl;

    Q = alokasi(P);
    if (cek_id(LP,P)){
        cout<<"  ID Sudah Ada, Harap Masukkan ID Lain"<<endl;
    }
    else{
        insert_ascending(LP,Q);
        cout<<"  Data Berhasil Di Masukkan";
    }
    getch();
}

void insertRelasi(list_relasi &LR,list_child LC,list_parent LP)
{
    infotype_parent x;
    infotype_child y;
    address_child C;
    address_parent P;
    address_relasi R;
    infotype_child a;
    infotype_parent s;

    system("CLS");
    cout<<endl;
    cout<<" ======================================================================== "<<endl;
    cout<<"|                       DAFTARKAN PASIEN KE DOKTER                       |"<<endl;
    cout<<" ======================================================================== "<<endl<<endl;
    cout<<"  1) Masukan No.KTP pasien    : ";
    cin>>x.id;
    cout<<endl;
    cout<<"  2) Masukan ID Dokter        : ";
    cin>>y.id;
    cout<<endl;
    C = findByID(LC,y);
    P = findByID(LP,x);
    if (C != NULL && P !=NULL)
    {
        if (cek_id(LR,C,P)){
            cout<<"  Pasien Sudah Terdaftar"<<endl;
        }
        else{
            R = alokasi(P,C);
            insertLast(LR,R);
            cout<<"  Pasien Berhasil Didaftarkan"<<endl;
        }
    }
    else{
        cout<<"  ID Tidak Ditemukan"<<endl;
    }
    getch();
}
