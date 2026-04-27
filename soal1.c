/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Abdullah Athaaya Fauzan (13224094)
 *   Nama File           : soal1.c
 *   Deskripsi           : Sensor Badai Dinamis untuk menghitung count, sorted, dan median
 * 
*/

#include <stdio.h>
#include <stdlib.h>

int perbandingan(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void){
    int *data= NULL;
    int count = 0;
    int kapasitas = 0;
    int input;

    while (scanf("%d", &input) == 1 && input != -1){
        if (count == kapasitas){
            kapasitas = (kapasitas == 0) ? 1 : kapasitas * 2;
            int *temp = (int*)realloc(data, kapasitas * sizeof(int));
            if (temp == NULL){
                free(data);
                return 1;
            }
            data = temp;
        }
        data[count] = input;
        count++;
    }

    if (count == 0){
        free(data);
        return 0;
    }

    qsort(data, count, sizeof(int), perbandingan);

    printf("COUNT %d ", count);

    printf("SORTED");
    for (int i = 0; i < count; i++){
        printf(" %d", data[i]);
    }

    double median;
    if (count % 2 == 0){
        median = (data[count/2 - 1] + data[count/2]) / 2.0;
    }else{
        median = (double)data[count/2];
    }

    printf(" MEDIAN %.2f\n", median);

    free(data);
    return 0;
}
