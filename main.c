#include "stdio.h"

//1
struct dataMhs {
    char nama[255], grade;
    float tugas, uts, uas, akhir;
};

void hasil(struct dataMhs mahasiswa[]);

int n;

//2
#include "string.h"

struct barang {
    char kode;
    int jumlah;
};

void showMenu();
void hasil(struct barang pesan[]);

int n;

int main(int argc, char *argv[]) {

    //1
    printf("Banyak Mahasiswa: ");
    scanf("%d", &n);

    struct dataMhs mahasiswa[n];

    for (int i = 0; i < n; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("Nama: ");
        scanf(" %s", mahasiswa[i].nama);
        printf("Nilai tugas: ");
        scanf(" %f", &mahasiswa[i].tugas);
        printf("Nilai uts: ");
        scanf(" %f", &mahasiswa[i].uts);
        printf("Nilai uas: ");
        scanf(" %f", &mahasiswa[i].uas);
    }

    hasil(mahasiswa);


    //2
    showMenu();

    printf("\n\nBanyak barang: ");
    scanf("%d", &n);

    struct barang pesan[n];

    for (int i = 0; i < n; i++) {
        printf("Data ke-%d", i + 1);

        printf("\nUkuran [S/M/L] : ");
        scanf(" %c", &pesan[i].kode);
        printf("Jumlah beli    : ");
        scanf(" %d", &pesan[i].jumlah);
    }

    hasil(pesan);

    return 0;
}

//1
void hasil(struct dataMhs mahasiswa[n]) {
    int j;
    printf("\t\t\t\t\t\t\t\t\t\tDAFTAR NILAI\n");
    printf("\t\t\t\t\t\t\t\tMATA KULIAH KONSEP PEMROGRAMAN\n");
    printf("-------------------------------------------------------------------------------------\n");
    printf("No\tNama\t\t\t\t\t\t\t\t\t\t\t\tNilai\t\t\t\t\tGrade\n");
    printf("\tMahasiswa\t\t\t\t\t\tTugas\t\tUTS\t\t\tUAS\t\tNilai Akhir\n");
    printf("-------------------------------------------------------------------------------------\n");

    for (j = 0; j < n; j++) {
        mahasiswa[j].akhir = (mahasiswa[j].tugas * 0.2) + (mahasiswa[j].uts * 0.4) +
                             (mahasiswa[j].uas * 0.4);

        if (mahasiswa[j].akhir >= 80)
            mahasiswa[j].grade = 'A';
        else if (mahasiswa[j].akhir >= 70)
            mahasiswa[j].grade = 'B';
        else if (mahasiswa[j].akhir >= 60)
            mahasiswa[j].grade = 'C';
        else if (mahasiswa[j].akhir >= 50)
            mahasiswa[j].grade = 'D';
        else
            mahasiswa[j].grade = 'E';

        printf("%-4d\t%-25s\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\t%c\n",
               j + 1, mahasiswa[j].nama, mahasiswa[j].tugas, mahasiswa[j].uts,
               mahasiswa[j].uas, mahasiswa[j].akhir, mahasiswa[j].grade);
    }

    printf("-------------------------------------------------------------------------------------\n\n");
    printf("Total Mahasiswa = %d\n", n);
}



//2
void showMenu() {
    printf("\t\t\t\t\tToko Laris");
    printf("\n\t\t\t\t\tDaftar Harga");
    printf("\n================================================");
    printf("\nUkuran Baju\tNama Ukuran\tHarga Per Potong");
    printf("\n================================================");
    printf("\n    S\t\tSMALL\t\tRp. 36.000,-");
    printf("\n    M\t\tMEDIUM\t\tRp. 43.000,-");
    printf("\n    L\t\tLARGE\t\tRp. 62.000,-");
    printf("\n================================================");
    printf("\n\nDapatkan diskon 20 %% untuk pembelian lebih dari 10 potong...");
    printf("\nJangan lupa, pajaknya ya... (10%% x (harga - diskon))");
}

void hasil(struct barang pesan[]) {
    int j;
    float total = 0, harga, diskon;
    char jenis[10];

    printf("\nNota Belanja Anda :\n\n");
    printf("\t\t\t\t\t\t\t\t\tToko LARIS\n");
    printf("================================================================================\n");
    printf("No\tNama Ukuran\tHarga Satuan\tQty\t\tDiskon\t\tJumlah Harga\n");
    printf("================================================================================\n");
    for (j = 0; j < n; j++) {
        switch (pesan[j].kode) {
            case 'S':
            case 's':
                strcpy(jenis, "SMALL");
                harga = 36000;
                break;
            case 'M':
            case 'm':
                strcpy(jenis, "MEDIUM");
                harga = 43000;
                break;
            case 'L':
            case 'l':
                strcpy(jenis, "LARGE");
                harga = 62000;
                break;
        }
        if (pesan[j].jumlah > 10)
            diskon = harga * pesan[j].jumlah * 0.2;
        else
            diskon = 0;
        printf("%d\t%s\t\tRp%5.2f\t\t%d\tRp%10.2f\tRp%10.2f\n", j + 1, jenis, harga,
               pesan[j].jumlah, diskon, harga * pesan[j].jumlah);

        total = total + harga * pesan[j].jumlah - diskon;
    }
    printf("================================================================================\n");
    printf("\t\t\t\t\t\tJumlah Bayar\tRp %10.2f\n", total);
    printf("\t\t\t\t\t\tPajak 10%%\tRp %10.2f\n", total * 0.1);
    printf("\t\t\t\t\t\tTOTAL BAYAR\tRp %10.2f\n\n", total + total * 0.1);
    printf("\t\t\t\t\t\tTERIMA KASIH ATAS KUNJUNGAN ANDA");
}