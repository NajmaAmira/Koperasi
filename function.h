#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "anggota.h"
#include "transaksi.h"

using namespace std;

time_t now = time(0);
int currentYear = 1900 + localtime(&now)->tm_year;
const int minYear = 1900;

const char *pathDatabaseAnggota = "database_anggota.txt";
const char *pathDatabaseTransaksi = "database_transaksi.txt";

bool isLeap(int yyInput){
	return (((yyInput % 4 == 0) && (yyInput % 100 != 0)) || (yyInput % 400 == 0));
}

bool dateValidation(int ddInput, int mmInput, int yyInput){
	if ((yyInput > currentYear) || (yyInput < minYear)) {
		return false;
	}
	if ((mmInput < 1) || (mmInput > 12)){
		return false;
	}
	if ((ddInput < 1) || (ddInput > 31)){
		return false;
	}
	if (mmInput == 2){
		if (isLeap(yyInput)){
			return (ddInput <= 29);
		}else{
			return (ddInput <= 28);
		}
	}
	if ((mmInput == 4) || (mmInput == 6) || (mmInput == 9) || (mmInput == 11)){
		return (ddInput <= 30);
	}
	
	return true;
}

void switchErrorHandler() {
    cout << "Input tidak valid. Silakan masukkan angka yang benar" << endl;
    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();
}

void saveAnggotaToDatabase(vector<Anggota>& anggotaVector) {
    ofstream databaseFile(pathDatabaseAnggota); 

    if (databaseFile.is_open()) {
        int id = 1;
        for (int i = 0; i < anggotaVector.size(); i++) {
            databaseFile << id << " " 
                         << "\"" << anggotaVector[i].getNama() << "\"" << " "  // Menggunakan tanda kutip ("") untuk mengelompokkan nama
                         << anggotaVector[i].getNik() << " " 
                         << anggotaVector[i].getPassword() << " " 
                         << anggotaVector[i].getTanggal() << " " 
                         << anggotaVector[i].getBulan() << " " 
                         << anggotaVector[i].getTahun() << " " 
                         << anggotaVector[i].getSaldo() << endl;
            id++;
        }
        databaseFile.close();
        cout << "Data anggota berhasil disimpan di database." << endl;
    } else {
        cout << "Gagal membuka database_anggota.txt" << endl;
    }
}

void loadAnggotaFromDatabase(vector<Anggota>& anggotaVector) {
    ifstream databaseFile(pathDatabaseAnggota);
    if (databaseFile.is_open()) {
        anggotaVector.clear();
        int id, tanggal, bulan, tahun, saldo, bulan_transaksi, saldo_dipinjam;
        string nama, nik, password;

        while (true) {

            // Membaca nama anggota dengan spasi
            getline(databaseFile, nama, '\"');
            getline(databaseFile, nama, '\"');

            databaseFile >> nik >> password >> tanggal >> bulan >> tahun >> saldo >> saldo_dipinjam;
            anggotaVector.emplace_back(nama, nik, password, tanggal, bulan, tahun, saldo, saldo_dipinjam);

            if(databaseFile.eof()) {
                break;
            } else {
                // Enter ke baris selanjutnya
                databaseFile.get();
            }
        }
        databaseFile.close();
        cout << "Data anggota berhasil diambil dari database." << endl;
    } else {
        cout << "Gagal membuka database_anggota.txt" << endl;
    }
}

void displayAnggota(vector<Anggota>& anggotaVector) {
    loadAnggotaFromDatabase(anggotaVector);
    int id = 1;
    for (int i = 0; i < anggotaVector.size(); i++) {
        cout << "ID                         : " << id << endl;
        cout << "Nama                       : " << anggotaVector[i].getNama() << endl;
        cout << "NIK                        : " << anggotaVector[i].getNik() << endl;
        cout << "Password                   : " << anggotaVector[i].getPassword() << endl;
        cout << "Tanggal Lahir              : " << anggotaVector[i].getTanggal() << "/" << anggotaVector[i].getBulan() << "/" << anggotaVector[i].getTahun() << endl;
        cout << "Saldo                      : " << anggotaVector[i].getSaldo() << endl;
        id++;
        cout << endl;
    }
}

void deleteAnggotaFromDatabase(vector<Anggota>& anggotaVector, string nik) {
    loadAnggotaFromDatabase(anggotaVector);
    for (int i = 0; i < anggotaVector.size(); i++) {
        if (anggotaVector[i].getNik() == nik) {
            anggotaVector.erase(anggotaVector.begin() + i);
            break;
        }
    }
    saveAnggotaToDatabase(anggotaVector);
}

bool searchAnggotaByNIK(vector<Anggota>& anggotaVector, string nik) {
    loadAnggotaFromDatabase(anggotaVector);
    for (int i = 0; i < anggotaVector.size(); i++) {
        if (anggotaVector[i].getNik() == nik) {
            cout << "Nama                       : " << anggotaVector[i].getNama() << endl;
            cout << "NIK                        : " << anggotaVector[i].getNik() << endl;
            cout << "Password                   : " << anggotaVector[i].getPassword() << endl;
            cout << "Tanggal Lahir              : " << anggotaVector[i].getTanggal() << "/" << anggotaVector[i].getBulan() << "/" << anggotaVector[i].getTahun() << endl;
            cout << "Saldo                      : " << anggotaVector[i].getSaldo() << endl;
            break;
        }
    }
    return true;
}

void saveLaporanTransaksiToDatabase(vector<Transaksi>& transaksiVector) {
    ofstream databaseFile(pathDatabaseTransaksi);  

    if (databaseFile.is_open()) {
        int id = 1;
        for (int i = 0; i < transaksiVector.size(); i++) {
            databaseFile << id << " " 
                         << "\"" << transaksiVector[i].getJenisTransaksi() << "\"" << " "  // Menggunakan tanda kutip ("") untuk mengelompokkan nama
                         << transaksiVector[i].getNik() << " " 
                         << transaksiVector[i].getTanggal() << " " 
                         << transaksiVector[i].getBulan() << " " 
                         << transaksiVector[i].getTahun() << " " 
                         << transaksiVector[i].getNominal() << endl;
            id++;
        }
        databaseFile.close();
        cout << "Data transaksi berhasil disimpan di database." << endl;
    } else {
        cout << "Gagal membuka database_transaksi.txt" << endl;
    }
}

void loadLaporanTransaksiFromDatabase(vector<Transaksi>& transaksiVector) {
    ifstream databaseFile(pathDatabaseTransaksi);
    if (databaseFile.is_open()) {
        transaksiVector.clear();
        int id, tanggal, bulan, tahun, nominal;
        string jenis_transaksi, nik;

        while (true) {
            // Membaca nama anggota dengan spasi
            getline(databaseFile, jenis_transaksi, '\"');
            getline(databaseFile, jenis_transaksi, '\"');

            databaseFile >> nik >> tanggal >> bulan >> tahun >> nominal;
            transaksiVector.emplace_back(jenis_transaksi, nik, tanggal, bulan, tahun, nominal);

            if(databaseFile.eof()) {
                break;
            } else {
                // Enter ke baris selanjutnya
                databaseFile.get();
            }
        }
        databaseFile.close();
        cout << "Data transaksi berhasil diambil dari database." << endl;
    } else {
        cout << "Gagal membuka database_transaksi.txt" << endl;
    }
}

void displayTransaksi(vector<Transaksi>& transaksiVector){
    loadLaporanTransaksiFromDatabase(transaksiVector);
    int id = 1;
    for (int i = 0; i < transaksiVector.size(); i++){
        cout << "ID                         : " << id << endl;
        cout << "NIK                        : " << transaksiVector[i].getNik() << endl;;
        cout << "Tanggal transaksi          : " << transaksiVector[i].getTanggal() << "/" << transaksiVector[i].getBulan() << "/" << transaksiVector[i].getTahun() << endl;
        cout << "Jenis transaksi            : " << transaksiVector[i].getJenisTransaksi() << endl;
        cout << "Nominal                    : " << transaksiVector[i].getNominal() << endl;
        id++;
        cout << endl;
    }
    
}

void displayLaporanKeuangan(){
    // simpanan wajib
    // simpanan sukarela
    // pinjaman
    // pembayaran pinjaman
    // saldo koperasi
}