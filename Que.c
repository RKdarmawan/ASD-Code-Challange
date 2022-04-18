#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 3
//R.Krisviarno Darmawan
//672021082

typedef struct
{
    int data[MAX];
    int head;
    int tail;
} queue;

queue antri;

void awal()
{
    antri.head = antri.tail = -1;
}

int kosong()
{
    if(antri.tail == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int penuh()
{
    if(antri.tail==MAX-1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void masuk(int data)
{
    if(kosong()==1)
    {
        antri.head = antri.tail = 0;
        antri.data[antri.tail] = data;
        printf("%d Masuk", antri.data[antri.tail]);

    }

    else if(penuh()==0)
    {
        antri.tail++;
        antri.data[antri.tail] = data;
        printf("%d Masuk", antri.data[antri.tail]);
    }
}

void tampil()
{
    if(kosong()==0)
            {
            for(int i = antri.head; i <= antri.tail; i++)
                {
                    printf("%d", antri.data[i]);
                }
            }

            else
            {
                printf("Antrian Kosong!");
            }
}

int keluar()
{
    int d = antri.data[antri.head];
    for(int i =antri.head; i <= antri.tail-1; i++)
    {
        antri.data[i] = antri.data[i+1];
    }
    antri.tail--;
    return d;
}

void hapus()
{
    antri.head = antri.tail = -1;
    printf("Data Dalam Antrian Telah Dibersihkan!");
}

int main()
{
    int pilih;
    int data;
    awal();
    do
    {
    printf("\n\n");
    printf("1. Masuk Satu Data \n");
    printf("2. Keluar Satu Data \n");
    printf("3. Lihat Isi Antrian \n");
    printf("4. Hapus Isi Antrian \n");
    printf("5. Keluar \n");
    printf("Pilihan Anda? : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1 :
        printf("Data = ");
        scanf("%d", &data);
        masuk(data);
        break;

    case 2 : 
        printf("Data Yang Keluar : %d", keluar());
        break;

    case 3 :
        tampil();
        break;

    case 4 : 
        hapus();
    }

    }
    while(pilih !=5);
}
