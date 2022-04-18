#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK 3
//R.Krisviarno Darmawan
//672021082

typedef struct
{
    int top;
    char data [3][3];
}STACK;

STACK tumpuk;

void inisialisasi()
{
    tumpuk.top = -1;
}

int isEmpty()
{
    if(tumpuk.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(tumpuk.top == MAX_STACK - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char d[3])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top], d);
}

void pop()
{
    printf("Data yang diambil = %s\n", tumpuk.data[tumpuk.top]);
    tumpuk.top--;
}

void tampil()
{
    for(int i = tumpuk.top; i >= 0; i--)
    {
        printf("Data: %s\n", tumpuk.data[i]);
    }
}

void clear()
{
    tumpuk.top = -1;
}

int main()
{
    int pilihan;
    inisialisasi();
    char dt[3];
    do
    {
        system("cls");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Cetak Isi Array STACK\n");
        printf("4. Hapus Isi Array STACK\n");
        printf("5. Exit\n");
        printf("Pilihan anda : ");
        scanf("%d", &pilihan);

        switch(pilihan)
        {
            case 1: if(isFull() != 1)
            {
                printf("Data Yang Ingin Disimpan = ");
                scanf("%s", dt);
                push(dt);
            }
            else
                printf("Array STACK Sudah Penuh!\n");
            break;

            case 2:  if(isEmpty() != 1)
            {
                system("cls");
                pop();
            }
            else
                printf("Masih Kosong!\n");
            break;

            case 3: if(isEmpty() != 1)
            {
                tampil();
            }
                
            else
                printf("Masih Kosong!\n");
            break;

            case 4: clear();
                printf("Array STACK Sudah Dibersihkan!\n");
            break;
        }
        system("pause");
    }
    while(pilihan != 5);
    printf("Keluar Dari Program!!!\n");
    system("pause");
}