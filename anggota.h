#ifndef ANGGOTA_H
#define ANGGOTA_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Anggota{
    private:
        string nama;
        string nik;
        string password;
        int tanggal;
        int bulan;
        int tahun;
        int saldo;
        int saldo_dipinjam;

    public:
        Anggota(string nama, string nik, string password, int tanggal, int bulan, int tahun, int saldo, int saldo_dipinjam) : nama(nama), nik(nik), password(password), tanggal(tanggal), bulan(bulan), tahun(tahun), saldo(saldo), saldo_dipinjam(saldo_dipinjam){
            this->saldo = 50000;
            this->saldo_dipinjam = 0;
        }

        // Nama
        string getNama(){
            return this->nama;
        };
        void setNama(string nama){
            this->nama = nama;
        };

        // NIK
        string getNik(){
            return this->nama;
        };
        void setNik(string nik){
            this->nik = nik;
        };

        // Password
        string getPassword(){
            return this->password;
        };
        void setPassword(string password){
            this->password = password;
        };

        // DD MM YY untuk mempermudah penambahan tanggal
        void setDDMMYY(int tanggal, int bulan, int tahun){
            this->tanggal = tanggal;
            this->bulan = bulan;
            this->tahun = tahun;
        };

        // Tanggal
        int getTanggal(){
            return this->tanggal;
        };
        // Bulan
        int getBulan(){
            return this->bulan;
        };
        // Tahun
        int getTahun(){
            return this->tahun;
        };

        // Saldo
        int getSaldo(){
            return this->saldo;
        };
        void setSaldo(int saldo){
            this->saldo = saldo;
        };

        // Saldo Dipinjam
        int getSaldoDipinjam(){
            return this->saldo_dipinjam;
        };
        void setSaldoDipinjam(int saldo_dipinjam){
            this->saldo_dipinjam = saldo_dipinjam;
        }
};

#endif
