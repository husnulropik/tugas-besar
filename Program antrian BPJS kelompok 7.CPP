#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<conio.h>
#include<time.h>
struct bpjs{
       char nama[50];
       char tanggal[50];
       char alamat[50];
       char jenis [2];
       struct bpjs *next;
       };
struct queue{
       bpjs *head;
       int count;
       bpjs *tail;
       };
int isFull(queue *queue);
int isEmpty(queue *queue);
void pendaftar_masuk(queue *queue);
void cetak(queue *queue);
void pendaftarout(queue *queue);
void kosongkan(queue *queue);
void orang2an(queue *queue);
void orang2an_out(queue *queue);
int main(){
    queue queue;
    queue.count=0;
    queue.head=NULL;
    queue.tail=NULL;
    char pilih;
    int isfull,isempty;
do{system("cls");
printf("\t\t\t\t\t\t============================== \n");
printf("\t\t\t\t\t\t| __________________________ | \n");
printf("\t\t\t\t\t\t||                          || \n");
printf("\t\t\t\t\t\t|| PROGRAM PENDAFTARAN BPJS || \n");
printf("\t\t\t\t\t\t||__________________________|| \n");
printf("\t\t\t\t\t\t|                            | \n");
printf("\t\t\t\t\t\t============================== \n");
printf("==========================================\n");
printf("\||\t[1].Pendaftar Masuk\t\t||\t\n");
printf("\||\t[2].Lihat Semua Pendaftar\t||\t\n");
printf("\||\t[3].Cek Antrian(penuh/tidak)\t||\t\n");
printf("\||\t[4].Cek Antrian(kosong/tidak)\t||\t\n");
printf("\||\t[5].Pendaftar Keluar\t\t||\t\n");
printf("\||\t[6].Kosongkan Antrian\t\t||\t\n");
printf("\||\t[7].Exit\t\t\t||\n");
printf("========================================== \n");
printf("\n[Pilihan]: "); scanf("%c",&pilih); fflush(stdin);
if(pilih=='1'){pendaftar_masuk(&queue);}
else if(pilih=='2'){ cetak(&queue);}
else if(pilih=='3'){isfull=isFull(&queue);
               if(isfull==1){printf("\n ANTRIAN PENUH\n");getch();}
               else {printf("\n ANTRIAN TIDAK PENUH\n"); getch();}
               }
else if(pilih=='4'){isempty=isEmpty(&queue);
               if(isempty==1){printf("\n ANTRIAN KOSONG\n");getch();}
               else {printf("\n ANTRIAN TIDAK KOSONG\n"); getch();}
               }
else if(pilih=='5'){pendaftarout(&queue); orang2an_out(&queue);}
else if(pilih=='6'){kosongkan(&queue);}
}while(pilih!='7');
}


int isFull(queue *queue){
     if(queue->count==10) return 1;
     else return 0;
     }
int isEmpty(queue *queue){
    if(queue->count==0) return 1;
    else return 0;
}
void pendaftar_masuk(queue *queue){
     bpjs *pNew; int batas;
     pNew=(bpjs*)malloc(sizeof(bpjs));
     if(pNew!=NULL){
     if(queue->count==10) {printf("Antrian Penuh"); getch();}
     else{
          pNew->next=NULL;
          printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]");
          printf("\nMasukkan Nama Pendaftar\t\t: "); scanf("%[^\n]",&pNew->nama);fflush(stdin);
          printf("\nMasukkan Tanggal Lahir\t\t: "); scanf("%[^\n]",&pNew->tanggal);fflush(stdin);
          printf("\nMasukkan Alamat\t\t\t: "); scanf("%[^\n]",&pNew->alamat);fflush(stdin);
          printf("\n[R].Puskesmas [D]Dokter Keluarga\nJenis Rujukan Pertama (R/D)\t: ");scanf("%[^\n]",&pNew->jenis);fflush(stdin);
          printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]");
          printf("\nSILAHKAN ISI PERSYARATAN"); getch ();
          if(queue->count==0){
          queue->head=pNew;
          }
          else{
          queue->tail->next=pNew;
          }
          queue->tail=pNew;
          queue->count=(queue->count)+1;
          }
          }
}
void pendaftarout(queue *queue){
      bpjs *dltPtr;
     char platout[15];
     dltPtr = queue->head;
     if(queue->count == 1){
            queue->head = queue->tail =NULL;
     }
     else {
     queue->head=queue->head->next;
     }
     queue->count--;
     free(dltPtr);
}
void cetak(queue *queue){
     bpjs *pWalker;
     int i=1;
     pWalker=queue->head;
     if(queue->count==0){printf("\nAntrian Kosong");getch();}
     else{ system("cls");
     while(pWalker!=NULL){
			printf("[Pendaftar ke-%d] \t\nAtas Nama\t\t: %s\n Tanggal Lahir\t\t: %s\n Alamat\t\t\t: %s \n Jenis Rujukan Pertama\t: %s\t([P]Puskesmas [D]Dokter Keluarga) \n\n"
      	,i,pWalker->nama,pWalker->tanggal,pWalker->alamat,pWalker->jenis);
      	pWalker=pWalker->next; i++;
      	 }
      	getch();
         }
}
void kosongkan(queue *queue){
  while(queue->head!=NULL){
                       pendaftarout(queue);
                       printf("\nANTRIAN TELAH DIKOSONGKAN"); getch ();

                       }
}

//animasi orang2an
void orang2an(queue *queue){
int jml;
jml=queue->count;
int a;int z=65; int y;
int n;
printf("     IN  ");gotoxy(68,1);printf("  OUT  ");
gotoxy(1,6); printf("--------------------------------------------------------------------------------");
for(n=0;n<jml;n++){ //pengulangan untuk jumlah orang
   for(a=1;a<=z;a++){//pengulangan agar orang terlihat bergerak
  gotoxy(a+2,2);printf(" ( @  @ )");
  gotoxy(a,3);printf("    (  > )");
  gotoxy(a,4);printf("      || ");
  gotoxy(a,5);printf("    \/  \/" );
  }
  z=z-15;
}
}
void orang2an_out(queue *queue){
int jml;
jml=queue->count+1;
int a;int z=65; int y;
int n;
gotoxy(1,20);printf("     IN  ");gotoxy(68,20);printf("  OUT  ");
gotoxy(1,26); printf("--------------------------------------------------------------------------------");
for(n=0;n<jml;n++){ //pengulangan untuk jumlah orang
   for(a=1;a<=z;a++){//pengulangan agar orang terlihat bergerak
  gotoxy(a+2,21);printf(" ( @  @ )");
  gotoxy(a,22);printf("    (  > )");
  gotoxy(a,23);printf("      || ");
  gotoxy(a,24);printf("    \/  \/" );
  }
  z=z-15;
}
getch();

for(n=0;n<=1;n++){//pengulangan ketika 1 paling depan keluar
if (jml==1){
  gotoxy(a+2,21);printf(" ( @  @ )");
  gotoxy(a,22);printf("    (  > )");
  gotoxy(a,23);printf("      || ");
  gotoxy(a,24);printf("    \/  \/" );
}
else{
y=50; z=65;
for(n=0;n<jml-1;n++){
   for(a=y;a<=z;a++){
  gotoxy(a+2,21);printf(" ( @  @ )");
  gotoxy(a,22);printf("    (  > )");
  gotoxy(a,23);printf("      || ");
  gotoxy(a,24);printf("    \/  \/" );
  printf("\nPENDAFTAR TELAH KELUAR(pilih 5 lagi untuk melihat animasi pendaftar selanjutnya keluar)");
}
  y=y-15; z=z-15;
}
}
}
   getch();
}

