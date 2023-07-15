// Judul    : Sistem Koperasi Simpan Pinjam Alpro Sejahtera
// Oleh     : Kelompok 4219
// Najma Amira Mumtaz [A11.2022.14708]
// Naris Hafidz Fahrezi [A11.2022.14709]
// Muhammad Alif Al Husain [A11.2022.14718]
// Rafie Tegar Virgananda SP [A11.2022.14845]

#include <iostream>
#include <string>
#include <vector>
#include "anggota.h"
#include "function.h"
#include "transaksi.h"
using namespace std;

int main()
{

    string JenisTransaksi[4] = {"Simpanan Wajib", "Simpanan Sukarela", "Pinjaman", "Pengembalian Pinjaman"};

    vector<Anggota> recAnggota;
    vector<Transaksi> recTransaksi;

    string nama, nik, password;
    int saldo_dipinjam;
    int tanggal,
        bulan,
        tahun,
        saldo,
        saldo_koperasi = 0,
        simpanan_wajib = 0,
        simpanan_sukarela = 0,
        pinjaman = 0,
        pengembalian_pinjaman = 0,
        shu = 0,
        saldo_pinjam = 0,
        bunga = 0.1 * saldo_pinjam,
        bulan_transaksi;



    while (1)
    {
        system("cls || clear");
        loadAnggotaFromDatabase(recAnggota);
        loadLaporanTransaksiFromDatabase(recTransaksi);
        cout << "Selamat datang di Sistem Koperasi Simpan Pinjam Alpro Sejahtera" << endl;
        cout << "Silahkan pilih menu yang tersedia" << endl;
        cout << "1. Keanggotaan" << endl;
        cout << "2. Transaksi" << endl;
        cout << "3. Laporan Transaksi" << endl;
        cout << "4. Laporan Keuangan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan anda: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls || clear");
            cout << "1. Tambah Anggota" << endl;
            cout << "2. Cari Anggota" << endl;
            cout << "3. Tampilkan Anggota" << endl;
            cout << "4. Hapus Anggota" << endl;
            cout << "5. Kembali" << endl;
            cout << "Masukkan pilihan anda: ";
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                while (true)
                {
                    system("cls || clear");
                    cout << "Masukkan nama anda: ";
                    getline(cin >> ws, nama);
                    cout << endl;
                    cout << "Masukkan NIK anda: ";
                    cin >> nik;
                    cout << endl;
                    cout << "Masukkan password anda: ";
                    cin >> password;
                    cout << endl;
                    while (true)
                    {
                        cout << "Masukkan tanggal/bulan/tahun lahir anda (dd mm yyyy): ";
                        cin >> tanggal >> bulan >> tahun;
                        cout << endl;
                        if (dateValidation(tanggal, bulan, tahun))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Tanggal yang anda masukkan tidak valid" << endl;
                            continue;
                        }
                    }

                    Anggota anggota(nama, nik, password, tanggal, bulan, tahun, saldo, saldo_dipinjam);
                    recAnggota.push_back(anggota);

                    system("cls || clear");
                    cout << "Anggota berhasil ditambahkan" << endl;

                    cout << "Apakah anda ingin menambahkan anggota lagi? (y/n) ";
                    char pilihan;
                    cin >> pilihan;
                    if (pilihan == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                saveAnggotaToDatabase(recAnggota);
                break;
            case 2:
                cout << "Masukkan NIK anggota yang ingin dicari: ";
                cin >> nik;
                cout << endl;
                for (int i = 0; i < recAnggota.size(); i++)
                {
                    if (recAnggota[i].getNik() == nik)
                    {
                        cout << "Nama                       : " << recAnggota[i].getNama() << endl;
                        cout << "NIK                        : " << recAnggota[i].getNik() << endl;
                        cout << "Password                   : " << recAnggota[i].getPassword() << endl;
                        cout << "Tanggal Lahir              : " << recAnggota[i].getTanggal() << "/" << recAnggota[i].getBulan() << "/" << recAnggota[i].getTahun() << endl;
                        cout << "Saldo                      : " << recAnggota[i].getSaldo() << endl;
                        break;
                    }
                    else
                    {
                        cout << "Anggota tidak ditemukan" << endl;
                        break;
                    }
                }
                break;
            case 3:
                displayAnggota(recAnggota);
                // cek jika anggota kosong
                if (recAnggota.size() == 0)
                {
                    cout << "Belum ada anggota" << endl;
                }
                cout << "Press enter to continue...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                cout << "Masukkan NIK anggota yang ingin dihapus: ";
                cin >> nik;
                cout << endl;
                for (int i = 0; i < recAnggota.size(); i++)
                {
                    if (recAnggota[i].getNik() == nik)
                    {
                        recAnggota.erase(recAnggota.begin() + i);
                        cout << "Anggota berhasil dihapus" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Anggota tidak ditemukan" << endl;
                        break;
                    }
                }
                saveAnggotaToDatabase(recAnggota);
                break;
            case 5:
                break;
            default:
                break;
            }

            break;
        case 2:
            system("cls || clear");

            cout << "Masukkan NIK anda: ";
            cin >> nik;
            cout << endl;
            cout << "Masukkan password anda: ";
            cin >> password;
            cout << endl;

            while (true)
            {
                cout << "Masukkan tanggal pembayaran (Angka): ";
                cin >> tanggal;
                cout << endl;
                cout << "Masukkan bulan pembayaran (Angka): ";
                cin >> bulan;
                cout << endl;
                cout << "Masukkan tahun pembayaran (Angka): ";
                cin >> tahun;
                cout << endl;
                if (dateValidation(tanggal, bulan, tahun))
                {
                    break;
                }
                else
                {
                    cout << "Tanggal yang anda masukkan tidak valid" << endl;
                    continue;
                }
            }

            bulan_transaksi = bulan;
            // updateBulanTransaksi(recAnggota, nik, bulan);

            // cari anggota dalam database
            for (int i = 0; i < recAnggota.size(); i++)
            {
                if (recAnggota[i].getNik() == nik && recAnggota[i].getPassword() == password)
                {
                    while (true)
                    {
                        cout << "Selamat datang " << recAnggota[i].getNama() << endl;
                        cout << "1. Setor simpanan wajib" << endl;
                        cout << "2. Setor simpanan sukarela" << endl;
                        cout << "3. Pinjaman" << endl;
                        cout << "4. Pengembalian pinjaman" << endl;
                        cout << "5. Cek saldo" << endl;
                        cout << "6. Kembali" << endl;
                        cout << "Masukkan pilihan anda: ";
                        cin >> pilihan;
                        cout << endl;
                        switch (pilihan)
                        {
                        case 1:
                            // cek apa sudah bayar simpanan wajib bulan input, jika sudah maka tidak bisa bayar lagi
                            if (bulan_transaksi == bulan)
                            {
                                cout << "Anda sudah membayar simpanan wajib bulan ini" << endl;
                                break;
                            }

                            cout << "Apakah anda ingin membayar untuk bulan " << bulan << " sebesar Rp. 25.000? (y/n) ";
                            char pilihan;
                            cin >> pilihan;
                            cout << endl;

                            if (pilihan == 'y')
                            {
                                int saldo_dipotong = 25000;

                                recAnggota[i].setSaldo(recAnggota[i].getSaldo() - saldo_dipotong);
                                saldo_koperasi += saldo_dipotong;
                                simpanan_wajib += saldo_dipotong;

                                Transaksi transaksi(JenisTransaksi[0], nik, tanggal, bulan, tahun, saldo_dipotong);
                                recTransaksi.push_back(transaksi);

                                cout << "Simpanan wajib bulan " << bulan << " berhasil dibayar" << endl;
                            }
                            else
                            {
                                cout << "Simpanan wajib bulan " << bulan << " tidak dibayar" << endl;
                                break;
                            }
                            saveLaporanTransaksiToDatabase(recTransaksi);
                            break;
                        case 2:
                            cout << "Masukkan jumlah setoran sukarela: ";
                            cin >> saldo;
                            cout << endl;
                            if (saldo > recAnggota[i].getSaldo())
                            {
                                cout << "Saldo anda tidak mencukupi" << endl;
                                break;
                            }
                            else
                            {
                                recAnggota[i].setSaldo(recAnggota[i].getSaldo() - saldo);
                                saldo_koperasi += saldo;
                                simpanan_sukarela += saldo;

                                Transaksi transaksi(JenisTransaksi[1], nik, tanggal, bulan, tahun, saldo);
                                recTransaksi.push_back(transaksi);

                                cout << "Setoran sukarela sebesar " << saldo << " berhasil dibayarkan" << endl;
                            }
                            saveLaporanTransaksiToDatabase(recTransaksi);
                            break;
                        case 3:
                            cout << "Masukkan jumlah pinjaman: ";
                            cin >> saldo_pinjam;
                            cout << endl;
                            if (saldo_koperasi < saldo_pinjam)
                            {
                                cout << "Saldo koperasi tidak mencukupi" << endl;
                                break;
                            }
                            else
                            {

                                recAnggota[i].setSaldo(recAnggota[i].getSaldo() + saldo_pinjam);
                                recAnggota[i].setSaldoDipinjam(recAnggota[i].getSaldoDipinjam() + saldo_pinjam);
                                saldo_koperasi -= saldo_pinjam;
                                pinjaman += saldo_pinjam;

                                Transaksi transaksi(JenisTransaksi[2], nik, tanggal, bulan, tahun, saldo);
                                recTransaksi.push_back(transaksi);

                                cout << "Pinjaman sebesar " << saldo_pinjam << " berhasil" << endl;
                                cout << "Pengembalian dilakukan 4 kali angsuran masing-masing sebesar " << (saldo_pinjam + bunga) / 4 << endl;
                            }
                            saveLaporanTransaksiToDatabase(recTransaksi);
                            break;
                        case 4:
                            cout << "Apakah anda ingin membayar untuk bulan " << bulan << " sebesar Rp. " << (saldo_pinjam + bunga) / 4 << " (y/n) ";
                            cin >> pilihan;
                            cout << endl;

                            if (pilihan == 'y')
                            {
                                int saldo_dipotong = (saldo_pinjam + bunga) / 4;

                                recAnggota[i].setSaldo(recAnggota[i].getSaldo() - saldo_dipotong);
                                recAnggota[i].setSaldoDipinjam(recAnggota[i].getSaldoDipinjam() - saldo_dipotong);
                                saldo_koperasi += saldo_dipotong;
                                pengembalian_pinjaman += saldo_dipotong;

                                Transaksi transaksi(JenisTransaksi[3], nik, tanggal, bulan, tahun, saldo_dipotong);
                                recTransaksi.push_back(transaksi);

                                cout << "Pengembalian pinjaman bulan " << bulan << " berhasil dibayar" << endl;
                            }
                            else
                            {
                                cout << "Pengembalian pinjaman bulan " << bulan << " tidak dibayar" << endl;
                                break;
                            }
                            saveLaporanTransaksiToDatabase(recTransaksi);
                            break;
                        case 5:
                            cout << "Saldo anda                 : " << recAnggota[i].getSaldo() << endl;
                            cout << "Saldo dipinjam             : " << recAnggota[i].getSaldoDipinjam() << endl;
                            cout << "Saldo belum dikembalikan   : " << recAnggota[i].getSaldo() - recAnggota[i].getSaldoDipinjam() << endl;

                            break;
                        case 6:
                            break;
                        default:
                            break;
                        }
                        break;
                    }
                }
                else
                {
                    cout << "Anggota tidak ditemukan" << endl;
                    break;
                }
            }
            break;
        case 3:
            system("cls || clear");
            displayTransaksi(recTransaksi);
            break;
        case 4:
            system("cls || clear");

            cout << "Total simpanan wajib        : " << simpanan_wajib << endl;
            cout << "Total simpanan sukarela     : " << simpanan_sukarela << endl;
            cout << "Total pinjaman              : " << pinjaman << endl;
            cout << "Total pengembalian pinjaman : " << pengembalian_pinjaman << endl;
            cout << "Saldo koperasi              : " << saldo_koperasi << endl;
            cout << "SHU                         : " << shu << endl;

            break;
        case 5:
            cout << "Terima kasih telah menggunakan Sistem Koperasi Simpan Pinjam Alpro Sejahtera" << endl;
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}
