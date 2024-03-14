#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *lengthOfText){
    printf("The length of your text is less than specified, please update your text\n");
    printf("Length Before : %d\n", *lengthOfText);
    *lengthOfText = MIN_LENGTH;
}

void equalThanRequired(int *lengthOfText){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired(int *lengthOfText){
    printf("Your text is too long, please reduce the text\n");
    printf("Length Before : %d\n", *lengthOfText);
    *lengthOfText = MIN_LENGTH;
}

int checkLengthRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLengthRequirement(text);

    void (*functions[3])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};
    int length = strlen(text);
    (*(functions[selectOption]))(&length);

    printf("\nThe Length is updated to %d", length);

    return 0;
}

/*
PENJELASAN
1. fungsi lessThanRequired, yang mencetak pesan kesalahan dan memperbarui panjang 
teks ke panjang minimum yang ditentukan jika panjang teks kurang dari yang diizinkan.
2.fungsi equalThanRequired, yang mencetak pesan bahwa panjang teks sudah benar jika
 panjangnya sama dengan yang diizinkan.
3.fungsi moreThanRequired, yang mencetak pesan kesalahan dan memperbarui panjang teks 
ke panjang minimum yang diizinkan jika panjang teks melebihi batas yang ditentukan.
4.Baris ini adalah bagian kunci dari kode. Itu menggunakan array fungsi-pointer functions 
untuk memanggil salah satu dari tiga fungsi berdasarkan nilai yang dikembalikan oleh 
checkLengthRequirement(). Ini dilakukan tanpa menggunakan if atau switch, sesuai permintaan.
*/