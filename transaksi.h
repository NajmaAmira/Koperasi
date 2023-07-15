#ifndef TRANSAKSI_H
#define TRANSAKSI_H
#include <string>
using namespace std;

class Transaksi{
    private:
        string jenis_transaksi;
        string nik;
        int tanggal;
        int bulan;
        int tahun;
        int nominal;
    public:
        Transaksi(string jenis_transaksi, string nik, int tanggal, int bulan, int tahun, int nominal) : jenis_transaksi(jenis_transaksi), nik(nik), tanggal(tanggal), bulan(bulan), tahun(tahun), nominal(nominal){

        }

        string getJenisTransaksi(){
            return this->jenis_transaksi;
        }
        string getNik(){
            return this->nik;
        }
        int getTanggal(){
            return this->tanggal;
        }
        int getBulan(){
            return this->bulan;
        }
        int getTahun(){
            return this->tahun;
        }
        int getNominal(){
            return this->nominal;
        }

        void setJenisTransaksi(string jenis_transaksi){
            this->jenis_transaksi = jenis_transaksi;
        }
        void setNik(string nik){
            this->nik = nik;
        }
        void setTanggal(int tanggal){
            this->tanggal = tanggal;
        }
        void setBulan(int bulan){
            this->bulan = bulan;
        }
        void setTahun(int tahun){
            this->tahun = tahun;
        }
        void setNominal(int nominal){
            this->nominal = nominal;
        }
};

#endif
