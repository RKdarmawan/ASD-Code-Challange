#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//R.Krisviarno Darmawan
// 672021082


typedef struct Node{
      int data;
      struct Node *kiri;
      struct Node *kanan;
}Node;

void tambah(Node **root, int dataku)
{
      if((*root) == NULL)
      {
            Node *baru;
            baru = (Node *) malloc(sizeof(Node));
            baru->data = dataku;
            baru->kiri = NULL;
            baru->kanan = NULL;
            (*root) = baru;
            (*root)->kiri = NULL;
            (*root)->kanan = NULL;
            printf("Data bertambah!");
      }
      
      else if(dataku<(*root)->data)
            tambah(&(*root)->kiri, dataku);
     
      else if(dataku>(*root)->data)
            tambah(&(*root)->kanan, dataku);
     
      else if(dataku == (*root)->data)
            printf("Data sudah ada!");
}

void preOrder(Node *root)
{
      if(root != NULL){
            printf("%d ", root->data);
            preOrder(root->kiri);
            preOrder(root->kanan);
      }
}

void inOrder(Node *root)
{
      if(root != NULL){
            inOrder(root->kiri);
            printf("%d ", root->data);
            inOrder(root->kanan);
      }
}

void postOrder(Node *root)
{
      if(root != NULL){
            postOrder(root->kiri);
            postOrder(root->kanan);
            printf("%d ", root->data);
      }
}

void hapus(struct Node* root)
{
    if (root == NULL) return;

    
    hapus(root->kiri);
    hapus(root->kanan);

    
    printf("\nMenghapus node : %d", root->data);
    free(root);
}

int main()
{
      int pil, data;
      Node *tree;
      tree = NULL;

      do{
            system("cls"); 
            printf("\tPROGRAM TREE Bahasa C");
            printf("\n\t=====================");
            printf("\nMENU");
            printf("\n----\n");
            printf("1. Input Data\n");
            printf("2. Lihat pre-order\n");
            printf("3. Lihat in-order\n");
            printf("4. Lihat post-order\n");
            printf("5. Hapus Tree\n");
            printf("6. Keluar\n");
            printf("Pilihan kamu? = ");
            scanf("%d", &pil);
            switch(pil)
            {
                case 1 :
                    printf("\nINPUT : ");
                      printf("\n-------");
                      printf("\nData baru : ");
                      scanf("%d", &data);
                      tambah(&tree, data);
                      break;
                case 2 :
                      printf("\nOUTPUT PRE ORDER : ");
                      printf("\n------------------\n");
                      if(tree!=NULL)
                      {
                       
                        preOrder(tree);
                      }
                      else
                      {
                        printf("Masih kosong!");
                      }
                      break;
                case 3 :
                      printf("\nOUTPUT IN ORDER : ");
                      printf("\n-----------------\n");
                      if(tree!=NULL)
                      {
                      
                        inOrder(tree);
                      }
                      else
                      {
                        printf("Masih kosong!");
                      }
                      break;
                case 4 :
                  printf("\nOUTPUT POST ORDER : ");
                  printf("\n------------------\n");
                  if(tree!=NULL)
                  {
                       
                        postOrder(tree);
                  }
                  else
                  {
                        printf("Masih kosong!");
                  }
                  break;

                case 5 :
                    printf("\nHapus Tree yang sudah di input : ");
                    printf("\n------------------\n");
                    if(tree!=NULL)
                    {
                        
                        hapus(tree);
                        printf("\nProses Penghapusan Tree Telah Berhasil!!");
                    }
                    else
                    {
                        printf("Masih kosong!");
                    }
                    break;

               default : printf("Pilihan anda pilih tidak ada!");

            }
            printf("\n");
            system("pause");
      }
      while(pil!=6);
}