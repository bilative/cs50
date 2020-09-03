/*
2. Ödevde caesar'ın şifreleme yönteminin biraz daha ilerisine gidiyoruz (Zorlayıcılık bakımından biraz değil)

Buradaki farklılık bütün harflerin öteleme işlemleri sabit bir sayıda değil, şifreleme için belirlenmiş (ilk girdi)
bir kelimenin harflerininin sırasını öteleme miktarı olarak belirliyoruz. Caesar'ın sistemiyle ortak noktaları da var.

İlk girilen kelime (şifre belirleyici) kelimenin asıl şifrelenecek kelimeden (2. kelimeden) kısa olması durumunda
ilk kelimedeki kural döngüyle tekrarlanır. 

2. kelimedeki özel karakterler şifre belirleyicideki sıraları değiştirmez (sıra işgal etmez).
1. kelimede özel karakter bulunamaz.

Bunlara ek olarak daha detaylı kurallar burada bahsetmek için çok uzun ve detaylı, online ders notlarından ulaşabilirsiniz.
------------------------------------------------------------------------------
*/


#include <stdlib.h> // atoi için
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) //ilk girdi program adıyla beraber alınıyor
{
    if(argv[1]==NULL) //ilk girdi girilmezse hata dönüyoruz
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    
    else if (argv[1]!=NULL)
    {
    int alphabet = 0, number = 0; //***
    for (int i=0; argv[1][i]!= '\0'; i++) //***
    { 
       if (isdigit(argv[1][i]) != 0) //***  işaretli 5 satır boyunca ilk girdi sayı içeriyor mu kontrol edildi
            number++; //***
    }   //***

    if(number==0)
{
     if (argc == 2 && isalpha(*argv[1])) // programda 2 girdi ve ilk girdinin harflerden olması şartı
        
        {

            string k = argv[1]; //ilk girilen kelime stringe çevriliyor
            string kelime=get_string("plaintext: ");
            int k_len=strlen(k);
            int kelime_len=strlen(kelime);
            char ki[kelime_len];
            int g=0; // Bu g değerini eğer 2. girdide özel karakter var ise 1. değer etkilenmesin amaçlı
                                    //düzeltme değeri olarak kullandık gerekli yerlerde

            for (int i=0;i<kelime_len;i++)
                {
    
            /*  Girilen 2 girdinin i. değerleri küçük harfden veya büyük harfden oluşabilir.
            Bunların karşılaştırılması ve gerekli şartların sağlanması için düzeltmeler yapılması gerekiyor
            Sıradaki 50 satır boyunca bu durumlara ait 4 kolda düzeltmeler var sırada
             */
                             //L L
                            if (islower(kelime[i])&&islower(k[(i-g)%k_len]))
                                {                
                                    if(kelime[i]+k[(i-g)%k_len]-97>122)
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-97-26;

                                            //printf("1-");
                                        }
                                    else
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-97;
                                            //printf("2-");
                                        }
                                }
            /*  Şifrelenmiş son harflerin küçük veya büyük olması durumunu belirleyen 
                2. girdimiz (burada kelime[i]'ler). */

                            //L U
                            else if (islower(kelime[i])&&isupper(k[(i-g)%k_len]))
                                {
                                    if(kelime[i]+k[(i-g)%k_len]-65>122)
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-65-26;
                                            //printf("3-");
                                        }
                                    else
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-65;
                                            //printf("4-");
                                        }                                        
                                }
                            //U L                                
                            else if(isupper(kelime[i])&&islower(k[(i-g)%k_len]))
                                {
                                    if(kelime[i]+k[(i-g)%k_len]-97>90)
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-97-26;
                                            //printf("5-");
                                        }
                                    else
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-97;
                                            //printf("6-");
                                        }
                                }
                            //U U                                
                            else if(isupper(kelime[i])&&isupper(k[(i-g)%k_len]))
                                {
                                    if(kelime[i]+k[(i-g)%k_len]-65>90)
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-65-26;
                                            //printf("7-");
                                        }
                                    else
                                        {
                                            ki[i]=kelime[i]+k[(i-g)%k_len]-65;
                                            //printf("8-");
                                        }
                                }

                            else
                                {  //girdinin harf olmaması durumunda kendisi döner
                                    ki[i]=kelime[i];
                                    g=g+1;      //ve 1. girdi için g düzeltme güncellemesi
                                }

                }

                printf("ciphertext: "); //----
                for(int a=0;a<kelime_len;a++) //----
                { //---- Burada işi uzatmamın sebebi 3 özel karakter 2. girdide arka arkaya girildiğinde
                    printf("%c",ki[a]); //----    Çıktıda bozulmaya sebep olmasıydı
                } //----                       Bu aşamayı iptal edip gözlemleyebilirsiniz
            printf("\n");   //----
        }}
        else
        {
            printf("Usage: ./vigenere keyword\n");
        return 1;

        }}

    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}


/*
Çıktı:

$./vigenere fazla
plaintext: kara
ciphertext: paql

$./vigenere aaaa
plaintext: bilal
ciphertext: bilal

$./vigenere araba
plaintext: Zaman Yolcusu
ciphertext: Zrmbn Yfldusl

*/
