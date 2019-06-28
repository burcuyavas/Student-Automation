#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#include<ctype.h>
#pragma pack(1)
struct Tarih
{
	int gun;
	int ay;
	int yil;
};

struct Ogrenci
{
	int ogrenciNumara;
	char isim[30];
	char soyisim[20];
	struct Tarih dogumTarihi;
	float matNotu;
	float fenNotu;
	float turkceNotu;
};

void Display(struct Ogrenci X)
{
	printf("Ogrenci Numarasi : %d\n",X.ogrenciNumara);
	printf("Ogrenci ismi : %s\n",X.isim);
	printf("Ogrenci Soyismi : %s\n",X.soyisim);
	printf("Ogrenci Dogum Tarihi : %d/%d/%d",X.dogumTarihi.gun,X.dogumTarihi.ay,X.dogumTarihi.yil);
	printf("\nOgrencinin Matematik Notu : %f",X.matNotu);
	printf("\nOgrencinin Fen Notu : %f",X.fenNotu);
	printf("\nOgrencinin Turkce Notu : %f \n",X.turkceNotu);
	return;
}
void KayitEkle();
void KayitSil();
void KayitGuncelle();
void KayitListele();
void Sirala();
void Menu();

void Menu()
{
     char Secim;
     
     printf(" >>Kayit Ekle(1)<< || >>Kayit Sil(2)<< || >>Kayit Guncelle(3)<< \n\n >>Kayit Listele(4)<< || >>Siralama Cesitleri(5)<<||Cikis(E)<< \n");
          
      while(1)
      {
      	  scanf(" %c", &Secim);
      	  if(Secim=='E' || Secim=='e') break;
          switch(Secim)
          {
            case '1': KayitEkle();break;
            case '2': KayitSil();break;
            case '3': KayitGuncelle();break;
            case '4': KayitListele();break;
            case '5': Sirala();break; 
			default:
			break;                						                   
          }
          printf("\n\t");
          system("pause");
          system("cls");
          Menu();
     }
}

void KayitEkle()
{
     //struct Ogrenci *ogr =(struct Ogrenci*)malloc(sizeof(struct Ogrenci));
     struct Ogrenci ogr;
     FILE *fp;
     fp = fopen("ogrenci.bin","r+b");
         
     if(fp==NULL)
     {
     	fp = fopen("ogrenci.bin","w+b");
      
     }
     printf("Ogrenci ismini giriniz : \n");
     //scanf("%s", &ogr->isim);
     scanf("%s", ogr.isim);
     fflush(stdin);
     printf("Ogrenci soyadinizi giriniz : \n");
     //scanf("%s", &ogr->soyisim);
     scanf("%s", ogr.soyisim);
     fflush(stdin);
     printf("Ogrenci No : \n");
     //scanf("%d", &ogr->ogrenciNumara);
     scanf("%d", &ogr.ogrenciNumara);
     fflush(stdin);
     printf("Ogrencinin dogum tarihini girin: (gg.aa.yyyy formatinda) \n");
     //scanf("%02d.%02d.%04d", &ogr->dogumTarihi.gun, &ogr->dogumTarihi.ay, &ogr->dogumTarihi.yil);
     scanf("%02d.%02d.%04d", &ogr.dogumTarihi.gun, &ogr.dogumTarihi.ay, &ogr.dogumTarihi.yil);
     fflush(stdin);
     printf("Ogrencinin Matematik Notunu girin: \n");
     //scanf("%f", &ogr->matNotu);
     scanf("%f", &ogr.matNotu);
     fflush(stdin);
     printf("Ogrencinin Fen Notunu girin: \n");
     //scanf("%f", &ogr->fenNotu);
	 scanf("%f", &ogr.fenNotu);
     fflush(stdin);
     printf("Ogrencinin Turkce Notunu girin: \n");
     //scanf("%f", &ogr->turkceNotu);
     scanf("%f", &ogr.turkceNotu);
     
     fseek(fp,0,SEEK_END);
    
     	 fwrite(&ogr,sizeof(struct Ogrenci),1,fp);
     	 printf("\ndosya acildi.");
	 

     fclose(fp);
}

void KayitSil()
{
     FILE *fp,*fpsil;
     Ogrenci ogr;
     int ogrno;
     int k,i;
     printf("\n\n\t Kaydini Silmek Istediginiz Ogrenci Numarasi : ");
     scanf("%d",&ogrno);
     fp=fopen("ogrenci.bin","rb");
     if(fp==NULL) 
     {
     	printf("silinecek kayit yoktur"); return;
	 }
	 fpsil=fopen("temp.bin","wb");
     fseek(fp,0,SEEK_END);
     k=ftell(fp)/sizeof(struct Ogrenci);
     fseek(fp,0,SEEK_SET);
     for(i=0;i<k;i++)
     {
     	fread(&ogr,sizeof(Ogrenci),1,fp);
     	printf("\n%d %d",ogrno,ogr.ogrenciNumara);
     	system("pause");
     	if(ogr.ogrenciNumara!=ogrno) fwrite(&ogr,sizeof(Ogrenci),1,fpsil);
	 }
	 fclose(fp);
	 fclose(fpsil);
	 remove("ogrenci.bin");
	 rename("temp.bin","ogrenci.bin");
     return;
}

void KayitGuncelle()
{
    FILE *fp;
    struct Ogrenci temp;
    char ch,isim[30];
    int rec, no, c=0,count=0,k,i;
    fp = fopen("ogrenci.bin", "r+");
    //temp->isim = (char *)malloc(30*sizeof(char));
    printf("Kaydini Güncellemek Istediginiz Ogrencinin Ogrenci No'sunu Giriniz:\n");
    scanf("%d", &no);
    fseek(fp, 0, SEEK_END);
    k=ftell(fp)/sizeof(struct Ogrenci);
    fseek(fp, 0, SEEK_SET);
    for(i=0;i<k;i++)
    {
        fread(&temp, sizeof(struct Ogrenci), 1, fp);
        printf("%d", temp.ogrenciNumara);
        if (no == temp.ogrenciNumara)
        {
            printf("Ogrenci ismini giriniz : \n");
     		scanf("%s", temp.isim);
     		fflush(stdin);
     		printf("Ogrenci soyadinizi giriniz : \n");
    	    scanf("%s", temp.soyisim);
     		fflush(stdin);
     		fflush(stdin);
     		printf("Ogrencinin dogum tarihini girin: (gg.aa.yyyy formatinda) \n");
            scanf("%02d.%02d.%04d", &temp.dogumTarihi.gun, &temp.dogumTarihi.ay, &temp.dogumTarihi.yil);
     		fflush(stdin);
     		printf("Ogrencinin Matematik Notunu girin: \n");
		    scanf("%f", &temp.matNotu);
     		fflush(stdin);
     		printf("Ogrencinin Fen Notunu girin: \n");
     		scanf("%f", &temp.fenNotu);
     		fflush(stdin);
     		printf("Ogrencinin Turkce Notunu girin: \n");
            scanf("%f", &temp.turkceNotu);
            fseek(fp,i*sizeof(struct Ogrenci),SEEK_SET);
            fwrite(&temp,sizeof(struct Ogrenci),1,fp);
            c=1;
            break;
        }

    }
    if (c == 1)
        printf("Kayit Guncellendi\n");
    else
        printf("Kayit Bulunamadi\n");
    fclose(fp);
    	
}

void KayitListele()
{
	FILE *fp;
	int k,i;
	struct Ogrenci A;
	fp=fopen("ogrenci.bin","r+");
	if(fp==NULL) fp=fopen("ogrenci.bin","w+");
	fseek(fp,0,SEEK_END);
	k=ftell(fp)/sizeof(struct Ogrenci);
	printf("The number of records is %d\n",k);
	fseek(fp,0,SEEK_SET);
	for(i=0;i<k;i++)
	{
		fread(&A,sizeof(struct Ogrenci),1,fp);
		//printf("ogrno:%d\n",A.ogrenciNumara);
		//printf("ogrnad:%s\n",A.isim);
		if(feof(fp)) break;
		Display(A);
		printf("\n");
	}
	fclose(fp);
}
void SiralaOgrNoAzalan(struct Ogrenci *ogr,int c)
{
    int i,j;
	struct Ogrenci temp;
	for(i=0;i<c;i++)
	   for(j=i+1;j<c;j++)
	      if(ogr[i].ogrenciNumara<ogr[j].ogrenciNumara)
		  {
	      	  temp=ogr[i];ogr[i]=ogr[j];ogr[j]=temp;
		  }
	return;
}
void SiralaOgrNoArtan(struct Ogrenci *ogr,int c)
{
    int i,j;
	struct Ogrenci temp;
	for(i=0;i<c;i++)
	   for(j=i+1;j<c;j++)
	      if(ogr[i].ogrenciNumara>ogr[j].ogrenciNumara)
		  {
	      	  temp=ogr[i];ogr[i]=ogr[j];ogr[j]=temp;
		  }
		  
	return;
}
void SiralaOgrIsim(struct Ogrenci *ogr,int c)
{
	int i,j;
	struct Ogrenci temp;
	for(i=0;i<c;i++)
	   for(j=i+1;j<c;j++)
	      if(strcmp(ogr[i].isim,ogr[j].isim)>0)
		  {
	      	  temp=ogr[i];ogr[i]=ogr[j];ogr[j]=temp;
		  }
	return;
}
void SiralaMatNoBK(struct Ogrenci *ogr,int c)
{
	int x,y;
	struct Ogrenci matNotu,tut1;
	for(x=0; x<c; x++)
	{

		for(y=0; y<c-1; y++)
		{
			if(ogr[y].matNotu<ogr[y+1].matNotu)
			{
				tut1=ogr[y];
				ogr[y]=ogr[y+1];
				ogr[y+1]=tut1;
			}
		}
	}
}
void SiralaMatNotuKB(struct Ogrenci *ogr,int c)
{
	int x,y;
	struct Ogrenci matNotu,tut1;
	for(x=0; x<c; x++)
	{

		for(y=0; y<c-1; y++)
		{
			if(ogr[y].matNotu>ogr[y+1].matNotu)
			{
				tut1=ogr[y];
				ogr[y]=ogr[y+1];
				ogr[y+1]=tut1;
			}
		}
	}
}
void SiralaFenNotuBK(struct Ogrenci *ogr,int c)
{
	int x,y;
	struct Ogrenci fenNotu,tut1;
	for(x=0; x<c; x++)
		{

		for(y=0; y<c-1; y++)
		{
			if(ogr[y].fenNotu<ogr[y+1].fenNotu)
			{
				tut1=ogr[y];
				ogr[y]=ogr[y+1];
				ogr[y+1]=tut1;
			}
		}
	}	
}
void SiralaFenNotuKB(struct Ogrenci *ogr,int c)
{
	int x,y;
	struct Ogrenci fenNotu,tut1;
	for(x=0; x<c; x++)
	{

		for(y=0; y<c-1; y++)
		{
			if(ogr[y].fenNotu>ogr[y+1].fenNotu)
			{
				tut1=ogr[y];
				ogr[y]=ogr[y+1];
				ogr[y+1]=tut1;
			}
		}
	}
}
void SiralaTurkceNotuBK(struct Ogrenci *ogr,int c)
{
	int x,y;
	struct Ogrenci turkceNotu,tut1;
	for(x=0; x<c; x++)
		{

		for(y=0; y<c-1; y++)
		{
			if(ogr[y].turkceNotu<ogr[y+1].turkceNotu)
			{
				tut1=ogr[y];
				ogr[y]=ogr[y+1];
				ogr[y+1]=tut1;
			}
		}
	}	
}
void SiralaTurkceNotuKb(struct Ogrenci *ogr,int c)
{
	int x,y;
	struct Ogrenci turkceNotu,tut1;
	for(x=0; x<c-1; x++)
	{

		for(y=0; y<c; y++)
		{
			if(ogr[y].turkceNotu>ogr[y+1].turkceNotu)
			{
				tut1=ogr[y];
				ogr[y]=ogr[y+1];
				ogr[y+1]=tut1;
			}
		}
	}
}
void Sirala()
{	
		FILE *fp,*fpsorted;
		struct Ogrenci *ogr,tut1;
		int secim,c,temp;
		float tut;
		fclose(fp);
		printf("\t***********************************************************\n");
		printf("\t***                  SIRALAMA TURLERI                   ***\n");	
		printf("\t***     1-) Ogrenci Numarasina Gore     *(AZALAN)*      ***\n");
		printf("\t***     2-) Ogrenci Numarasina Gore     *(ARTAN)*       ***\n");
		printf("\t***     3-) Isme Gore Siralama                          ***\n");
		printf("\t***     4-) Matematik Notuna Gore Gore  *(B.KUCUGE)*    ***\n");
		printf("\t***     5-) Matematik Notuna Gore Gore  *(K.BUYUGE)*    ***\n");
		printf("\t***     6-) Fen Notuna Gore             *(B.KUCUGE)*    ***\n");
		printf("\t***     7-) Fen Notuna Gore             *(K.BUYUGE)*    ***\n");
		printf("\t***     8-) Turkce Notuna Gore          *(B.KUCUGE)*    ***\n");
		printf("\t***     9-) Turkce Notuna Gore          *(K.BUYUGE)*    ***\n");		
		printf("\t***                                                     ***\n");
		printf("\t***     Lutfen Secim Yapiniz :  ");scanf("%d",&secim);
		switch(secim)
		{
			case 1:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				SiralaOgrNoAzalan(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fpsorted);
				fclose(fp);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
			case 2:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				printf("\nc=%d",c);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				SiralaOgrNoArtan(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fpsorted);
				fclose(fp);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
				
			case 3:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				SiralaOgrIsim(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fpsorted);
				fclose(fp);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
			case 4:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				SiralaMatNoBK(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fp);
				fclose(fpsorted);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
			case 5:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				SiralaMatNoBK(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fp);
				fclose(fpsorted);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
			case 6:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				SiralaMatNoBK(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fpsorted);
				fclose(fp);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
			case 7:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				SiralaMatNoBK(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fpsorted);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
			case 8:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				SiralaMatNoBK(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fpsorted);
				fclose(fp);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;
			case 9:
				fp=fopen("ogrenci.bin","rb");
				if(fp==NULL)
				{
					printf("\nDosyada kayit yoktur");return;
				}		
				fseek(fp,0,SEEK_END);
				c=ftell(fp)/sizeof(struct Ogrenci);
				ogr=(struct Ogrenci *)malloc(c* sizeof(struct Ogrenci));
				fseek(fp,0,SEEK_SET);
				fread(ogr,sizeof(struct Ogrenci),c,fp);
				fpsorted=fopen("sorted.bin","wb");
				SiralaMatNoBK(ogr,c);	
				fwrite(ogr,sizeof(struct Ogrenci),c,fpsorted);
				fclose(fpsorted);
				fclose(fp);
				remove("ogrenci.bin");
				rename("sorted.bin","ogrenci.bin");
				break;									
		}

}

int main()
{
	Menu();	
	return 0;
}
