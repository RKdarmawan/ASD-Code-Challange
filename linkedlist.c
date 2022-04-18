#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//R.Krisviarno Darmawan
//672021082

struct node
{
    int data;
    struct node* next;
};
struct node *head;
typedef struct node node_t;

void cetak()
{
    
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("List Kosong Boskuh !");
    }
    else
    {
        printf("Cetak Isi List...");
        while (ptr !=NULL)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
        system("pause");
        system("cls");
    }

}

void awal()
{
    
    system("cls");
    struct node *ptr;
    int item;
    
    ptr = (struct  node *)malloc(sizeof(struct node *));

    if(ptr==NULL)
    {
            printf("Overflow!");
    }
    else
    {
            printf("Masukan Data :");
            scanf("%d", &item);
            ptr->data = item;
            ptr->next = head;
            head = ptr;
            printf("Data Berhasil Disimpan Di NODE Awal!\n");
            system("pause");
            system("cls");
            
    }

}

void akhir()
{
    
    system("cls");
    struct node *ptr, *temp;
    int item;
    
    ptr = (struct  node *)malloc(sizeof(struct node *));

    if(ptr==NULL)
    {
            printf("Overflow!");
    }
    else
    {
        printf("Masukan Data : ");
        scanf("%d", &item);
        ptr->data = item;
        if(head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("Berhasil Simpan Node!\n");
            system("pause");
            system("cls");
        }
        else
        {
            temp = head;
            while(temp ->next !=NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Berhasil Simpan NODE Akhir!\n");
            system("pause");
            system("cls");
        }
    }
    
}

void sembarang()
{
    
    system("cls");
    struct node *ptr, *temp;
    int item, loc, i;
    
    ptr = (struct  node *)malloc(sizeof(struct node *));

    if(ptr==NULL)
    {
            printf("Overflow!");
    }
    else
    {
        printf("Masukan Data : ");
        scanf("%d", &item);
        ptr->data = item;
        printf("Mau Simpan Di Lokasi Berapa? : ");
        scanf("%d", &loc);
        temp = head;
        for(i=0;i<loc; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                printf("Tidak Bisa Simpan Datamu!");
                system("pause");
                system("cls");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("NODE berhasil Disimpan!\n");
        system("pause");
        system("cls");
    }
}

void hapusawal()
{
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList Kosong Boskuhh!\n");
        system("pause");
    }  
    else
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNODE Awal Berhasil Dihapus!\n");
        system("pause"); 
    }
}

void hapusakhir()
{
    system("cls");
    struct node *ptr = head;
    if(head == NULL)
    {
        printf("\nList Kosong Bro!\n");
        system("pause");
        system("cls");
    }
    else
    {
        while(ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NULL;
        free(ptr->next);
        printf("\nNODE Akhir Berhasil Dihapus!\n");
        system("pause");
        system("cls");
    }
    printf("\n");
}

int delsembarang()
{
    system("cls");
    int loc, i;
    struct node *ptr, *temp = head;
    printf("Lokasi Mana Yang Ingin Dihapus ? (Mulai Dari 0) ");
    scanf("%d", &loc);
    if(head == NULL)
    {
        printf("\nList Kosong Bro!\n");
        system("pause");
        system("cls");
        return head;
    }
    else
    {
        for(i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
        }
        struct node *hapus = temp->next;
        temp->next = temp->next->next;
        hapus->next = NULL;
        free(hapus);
        printf("Node Di Lokasi %d Berhasil Dihapus!", loc);
        printf("\n");
        return head;
        system("pause");
        system("cls");
    }
}

int main()
{

    int pilihan = 0;
    while(pilihan !=8)
    {
        printf("********* Menu latihan linked list ********");
        printf("\n======================================\n");
        printf("\n1. Input Data Di Awal \n2. Input Data Di Akhir \n3. Input Data Sembarang \n4. Hapus Data Awal\n5. Hapus Data Akhir\n6. Hapus Data Sembarang\n7. lihat Data Di Dalam lLinked List \n8. Keluar\n");
        printf("Pilihanmu? ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1 :
            awal();
            break;
            case 2 :
            akhir();
            break;
            case 3 :
            sembarang();
            break;
            case 4 :
            hapusawal();
            break;
            case 5 :
            hapusakhir();
            break;
            case 6 :
            delsembarang();
            break;
            case 7 :
            cetak();
            break;
            case 8 :
            exit(0);
            break;
        
        default: printf("Pilihan Anda Tidak Ada. Silahkan Pilih Yang Benar");
            break;
        }
    }
    system("cls");
}