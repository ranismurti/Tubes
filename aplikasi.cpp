#include "aplikasi.h"

void menu(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    address_parent PP;
    address_child CC;
    address_relasi R,RR;
    char a;

    system("CLS");
        cout<<endl;
        cout<<" ==================================== "<<endl;
        cout<<"|                MENU                |"<<endl;
        cout<<"|====================================|"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 1) Masukan Data                    |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 2) Daftarkan Pasien ke Dokter      |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 3) Lihat Data                      |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 4) Edit Data                       |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 5) Hapus Data                      |"<<endl;
        cout<<"|                                    |"<<endl;
        cout<<"| 6) Keluar                          |"<<endl;
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
            lihat_data(LR,LP,LC);
            menu(LC,LP,LR);
        case 4:
            edit_data(LR,LP,LC);
            menu(LC,LP,LR);
        case 5:
            hapus_data(LR,LP,LC);
            menu(LC,LP,LR);
        case 6:
            exit(0);
        }
}

void masukandata(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    system("CLS");
    cout<<endl;
    cout<<" ==================================== "<<endl;
    cout<<"|            INPUT DATA              |"<<endl;
    cout<<"|====================================|"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 1) Masukkan Data Pasien            |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 2) Masukkan Data Dokter            |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 3) Kembali                         |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<" ==================================== "<<endl;
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

void lihat_data(list_relasi LR, list_parent LP, list_child LC){
    int pil;

    system("CLS");
    cout<<" ==================================== "<<endl;
    cout<<"|             LIHAT DATA             |"<<endl;
    cout<<"|====================================|"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 1) Lihat Data Pasien               |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 2) Lihat Data Dokter               |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 3) Lihat Daftar Pasien ke Dokter   |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 4) Kembali                         |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<" ==================================== "<<endl;
    cout<<"  > PILIH: ";
    cin>>pil;
    switch(pil)
    {
        case 1:
            lihat_pasien(LP);
            menu(LC,LP,LR);
        case 2:
            lihat_dokter(LC);
            menu(LC,LP,LR);
        case 3:
            lihat_relasi(LR);
            menu(LC,LP,LR);
        case 4:
            menu(LC,LP,LR);
    }
}

void lihat_pasien(list_parent LP){
    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                              DATA PASIEN                               |"<<endl;
    cout<<" ======================================================================== "<<endl;
    printInfo(LP);
    cout<<endl<<"  Tekan ENTER Untuk Kembali"<<endl;
    getch();
    system("CLS");
}

void lihat_dokter(list_child LC){
    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                              DATA DOKTER                               |"<<endl;
    cout<<" ======================================================================== "<<endl;
    printInfo(LC);
    cout<<endl<<"  Tekan ENTER Untuk Kembali"<<endl;
    getch();
    system("CLS");
}

void lihat_relasi(list_relasi LR){
    int pil;

    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                           DATA PASIEN-DOKTER                           |"<<endl;
    cout<<" ======================================================================== "<<endl;
    printInfo(LR);
    cout<<"  1) Sorting Data"<<endl<<endl;
    cout<<"  2) Kembali ke Menu"<<endl<<endl;
    cout<<"     PILIH : ";
    cin>>pil;
    cout<<endl;
    switch (pil){
    case 1:
        sorting(LR);
        printInfo(LR);
        getch();

    case 2:
        break;
    }
    system("CLS");
}

void hapus_data(list_relasi LR,list_parent LP, list_child LC){
    int pil;
    system("CLS");
    cout<<endl;
    cout<<" ==================================== "<<endl;
    cout<<"|            HAPUS DATA              |"<<endl;
    cout<<"|====================================|"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 1) Hapus Data Pasien               |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 2) Hapus Data Dokter               |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 3) Hapus Data Pasien ke Dokter     |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 4) Kembali                         |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<" ==================================== "<<endl;
    cout<<"  > PILIH: ";
    cin>>pil;
    switch(pil)
    {
        case 1:
            hapus_pasien(LP);
            menu(LC,LP,LR);
        case 2:
            hapus_dokter(LC);
            menu(LC,LP,LR);
        case 3:
            hapus_relasi(LR,LC,LP);
            menu(LC,LP,LR);
        case 4:
            menu(LC,LP,LR);
    }
}

void hapus_pasien(list_parent &LP){
    infotype_parent x;
    address_parent P;
    char a;

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
        cout<<endl<<"  > Keluhan       : "<<info(P).keluhan<<endl<<endl;
        cout<<"|========================================================================|"<<endl;
        cout<<"  Yakin Ingin Menghapus Data Tersebut(Y/N) : ";
        cin>>a;
        cout<<endl;
        if (a == 'y' || a == 'Y'){
            deleteByID(LP,P);
                cout<<"  Data Berhasil Dihapus, Tekan ENTER Untuk Kembali"<<endl<<endl;
                }
                else{
                    cout<<"  Data Tidak Dihapus, Tekan ENTER Untuk Kembali"<<endl;
                }
            }
            else{
                cout<<endl<<"  Data Tidak Ditemukan"<<endl;
            }
            getch();
}

void hapus_dokter(list_child &LC){
    infotype_child y;
    address_child C;
    char a;

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
        cout<<"|========================================================================|"<<endl;
        cout<<"  Yakin Ingin Menghapus Data Tersebut(Y/N) : ";
        cin>>a;
        if (a == 'y' || a == 'Y'){
            deleteByID(LC,C);
            cout<<"  Data Berhasil Dihapus, Tekan ENTER Untuk Kembali"<<endl<<endl;
        }
        else{
                cout<<"  Data Tidak Dihapus, Tekan ENTER Untuk Kembali"<<endl;
            }
        }
    else{
        cout<<endl<<"  Data Tidak Ditemukan"<<endl;
    }
    getch();
}

void hapus_relasi(list_relasi &LR,list_child LC, list_parent LP){
    infotype_parent x;
    infotype_child y;
    address_parent P;
    address_child C;
    address_relasi R;
    char a;

    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                        HAPUS DATA DOKTER-PASIEN                        |"<<endl;
    cout<<" ======================================================================== "<<endl;
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
        R = findByID(LR,P,C);
        if (cek_id(LR,C,P)){
            deleteRelasi(LR,LC,LP,y,x,R);
            cout<<"  Data Berhasil Dihapus, Tekan ENTER Untuk Kembali"<<endl<<endl;

        }
        else{
            cout<<"  Pasien Belum Terdaftar"<<endl;
        }
    }
    else{
        cout<<"  ID Tidak Ditemukan"<<endl;
    }
    getch();
}

void edit_data(list_relasi LR, list_parent LP, list_child LC){
    int pil;

    system("CLS");
    cout<<" ==================================== "<<endl;
    cout<<"|              EDIT DATA             |"<<endl;
    cout<<"|====================================|"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 1) Edit Data Pasien                |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 2) Edit Data Dokter                |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<"| 3) Kembali                         |"<<endl;
    cout<<"|                                    |"<<endl;
    cout<<" ==================================== "<<endl;
    cout<<"  > PILIH: ";
    cin>>pil;
    switch(pil)
    {
        case 1:
            edit_pasien(LP);
            menu(LC,LP,LR);
        case 2:
            edit_dokter(LC);
            menu(LC,LP,LR);
        case 3:
            menu(LC,LP,LR);
    }
}

void edit_pasien(list_parent LP){
    infotype_parent x,y;
    address_parent P;
    char a;

    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                            EDIT DATA PASIEN                            |"<<endl;
    cout<<" ======================================================================== "<<endl;
    cout<<endl<<"  > Masukkan ID Pasien : ";
    cin>>y.id;
    P = findByID(LP,y);
    if (P != NULL){
        cout<<endl<<"  > Nama Pasien   : "<<info(P).nama<<endl;
        cout<<endl<<"  > ID            : "<<info(P).id<<endl;
        cout<<endl<<"  > Umur          : "<<info(P).umur<<endl;
        cout<<endl<<"  > Jenis Kelamin : "<<info(P).jk<<endl;
        cout<<endl<<"  > Gol. Darah    : "<<info(P).darah<<endl;
        cout<<endl<<"  > Keluhan       : "<<info(P).keluhan<<endl<<endl;
        cout<<"|========================================================================|"<<endl;
        cout<<"  Apakah Anda Ingin Mengubah Data Tersebut(Y/N) : ";
        cin>>a;
        cout<<endl;
        if (a == 'y' || a == 'Y'){
                cout<<endl<<"  > Nama Pasien   : ";
                cin>>x.nama;
                cout<<endl<<endl<<"  > Umur          : ";
                cin>>x.umur;
                cout<<endl<<endl<<"  > Jenis Kelamin : ";
                cin>>x.jk;
                cout<<endl<<endl<<"  > Gol. Darah    : ";
                cin>>x.darah;
                cout<<endl<<endl<<"  > Keluhan       : ";
                cin>>x.keluhan;
                edit_data(LP,P,x);
                cout<<endl<<"  Data Berhasil Diubah, Tekan ENTER Untuk Kembali"<<endl<<endl;
                }
                else{
                    cout<<"  Data Tidak Diubah, Tekan ENTER Untuk Kembali"<<endl;
                }
            }
            else{
                cout<<endl<<"  Data Tidak Ditemukan"<<endl;
            }
            getch();
}

void edit_dokter(list_child LP){
    infotype_child x,y;
    address_child P;
    char a;

    system("CLS");
    cout<<" ======================================================================== "<<endl;
    cout<<"|                            EDIT DATA DOKTER                            |"<<endl;
    cout<<" ======================================================================== "<<endl;
    cout<<endl<<"  > Masukkan ID Dokter : ";
    cin>>y.id;
    P = findByID(LP,y);
    if (P != NULL){
        cout<<endl<<"  > Nama Dokter   : "<<info(P).nama<<endl;
        cout<<endl<<"  > ID            : "<<info(P).id<<endl;
        cout<<endl<<"  > Umur          : "<<info(P).usia<<endl;
        cout<<endl<<"  > Jenis Kelamin : "<<info(P).jk<<endl;
        cout<<endl<<"  > Spesialis     : "<<info(P).spesialis<<endl;
        cout<<endl<<"  > No. HP        : "<<info(P).no_hp<<endl;
        cout<<"|========================================================================|"<<endl;
        cout<<"  Apakah Anda Ingin Mengubah Data Tersebut(Y/N) : ";
        cin>>a;
        cout<<endl;
        if (a == 'y' || a == 'Y'){
                cout<<endl<<"  > Nama Dokter   : ";
                cin>>x.nama;
                cout<<endl<<endl<<"  > Umur          : ";
                cin>>x.usia;
                cout<<endl<<endl<<"  > Jenis Kelamin : ";
                cin>>x.jk;
                cout<<endl<<endl<<"  > Spesialis    : ";
                cin>>x.spesialis;
                cout<<endl<<endl<<"  > Keluhan       : ";
                cin>>x.no_hp;
                edit_data(LP,P,x);
                cout<<endl<<"  Data Berhasil Diubah, Tekan ENTER Untuk Kembali"<<endl<<endl;
                }
                else{
                    cout<<"  Data Tidak Diubah, Tekan ENTER Untuk Kembali"<<endl;
                }
            }
        else{
                cout<<endl<<"  Data Tidak Ditemukan"<<endl;
            }
            getch();
}
