/* ********** Definisi TYPE MATRIKS dengan matriks_indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int matriks_indeks; /* indeks baris, kolom */
typedef int matriks_ElType;
typedef struct { 
	matriks_ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void matriks_MakeMATRIKS (int NB, int NK, MATRIKS * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define matriks_NBrsEff(M) (M).NBrsEff
#define matriks_NKolEff(M) (M).NKolEff
#define matriks_Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean matriks_IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah matriks_indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
matriks_indeks matriks_GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan matriks_indeks baris terkecil M */
matriks_indeks matriks_GetFirstIdxKol (MATRIKS M);
/* Mengirimkan matriks_indeks kolom terkecil M */
matriks_indeks matriks_GetLastIdxBrs (MATRIKS M);
/* Mengirimkan matriks_indeks baris terbesar M */
matriks_indeks matriks_GetLastIdxKol (MATRIKS M);
/* Mengirimkan matriks_indeks kolom terbesar M */
boolean matriks_IsIdxEff (MATRIKS M, matriks_indeks i, matriks_indeks j);
/* Mengirimkan true jika i, j adalah matriks_indeks efektif bagi M */
matriks_ElType matriks_GetElmtDiagonal (MATRIKS M, matriks_indeks i);
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void matriks_CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void matriks_BacaMATRIKS (MATRIKS * M, int NB, int NK);
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void matriks_TulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS matriks_TambahMATRIKS (MATRIKS M1, MATRIKS M2);
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS matriks_KurangMATRIKS (MATRIKS M1, MATRIKS M2);
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS matriks_KaliMATRIKS (MATRIKS M1, MATRIKS M2);
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS matriks_KaliKons (MATRIKS M, matriks_ElType X);
/* Mengirim hasil perkalian setiap elemen M dengan X */
void matriks_PKaliKons (MATRIKS * M, matriks_ElType K);
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean matriks_EQ (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan matriks_indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean matriks_NEQ (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean matriks_EQSize (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int matriks_NBElmt (MATRIKS M);
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean matriks_IsBujurSangkar (MATRIKS M);
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean matriks_IsSimetri (MATRIKS M);
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean matriks_IsSatuan (MATRIKS M);
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean matriks_IsSparse (MATRIKS M);
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS matriks_Inverse1 (MATRIKS M);
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M);
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void matriks_PInverse1 (MATRIKS * M);
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void matriks_Transpose (MATRIKS * M);
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */

float matriks_RataBrs (MATRIKS M, matriks_indeks i);
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah matriks_indeks baris efektif dari M */

float matriks_RataKol (MATRIKS M, matriks_indeks j);
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah matriks_indeks kolom efektif dari M */

void matriks_MaxMinBrs (MATRIKS M, matriks_indeks i, matriks_ElType * max, matriks_ElType * min);
/* I.S. i adalah matriks_indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */

void matriks_MaxMinKol (MATRIKS M, matriks_indeks j, matriks_ElType * max, matriks_ElType * min);
/* I.S. j adalah matriks_indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */

int matriks_CountXBrs (MATRIKS M, matriks_indeks i, matriks_ElType X);
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */

int matriks_CountXKol (MATRIKS M, matriks_indeks j, matriks_ElType X);
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */

#endif