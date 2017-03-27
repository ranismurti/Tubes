#include "aplikasi.h"

void menu(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    system("CLS");
    do
    {
        cout<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"|             MENU             |"<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 1)Masukan Data               |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 2)Daftarkan Pasien ke Dokter |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 3)Tampil Data                |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 4)Keluar                     |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"| > PILIH : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            masukandata(LC,LP,LR);
        case 2:
            insertRelasi(LR,LC,LP);
            menu(LC,LP,LR);
        case 3:
            cout<<"tampil";
            menu(LC,LP,LR);
        case 4:
            exit(0);
        }
    }
    while(pil!=4);
}

void masukandata(list_child &LC, list_parent &LP, list_relasi &LR)
{
    int pil;
    system("CLS");
    do
    {
        cout<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"|           MENU DATA          |"<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 1)Masukan Data Pasien        |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 2)Masukan Data Dokter        |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"| 3)Kembali Ke Menu            |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"| > PILIH: ";
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
    address_child CC;

    system("CLS");
    cout<<"|========================================================================|"<<endl;
    cout<<"|                           INPUT DATA DOKTER                            |"<<endl;
    cout<<"|========================================================================|"<<endl;
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
    cout<<"|========================================================================|"<<endl;
    cout<<"|                           INPUT DATA PASIEN                            |"<<endl;
    cout<<"|========================================================================|"<<endl;
    cout<<endl<<"  > Nama Pasien    : ";
    cin>>P.nama;
    cout<<endl<<"  > ID             : ";
    cin>>P.id;
    cout<<endl<<"  > Umur           : ";
    cin>>P.umur;
    cout<<endl<<"  > Jenis Kelamin  : ";
    cin>>P.jk;
    cout<<endl<<"  > Tanggal Lahir  : ";
    cin>>P.tgllahir;
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

    system("CLS");
    cout<<endl;
    cout<<"|========================================================================|"<<endl;
    cout<<"|                       DAFTARKAN PASIEN KE DOKTER                       |"<<endl;
    cout<<"|========================================================================|"<<endl<<endl;
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
        R = alokasi(P,C);
        insertLast(LR,R);
        cout<<"  Pasien Berhasil Didaftarkan"<<endl;
    }
    else{
        cout<<"  ID Tidak Ditemukan"<<endl;
    }
    getch();
}
