/*
1. Ödevde caesar'ın vakti zamanında kullandığı bir kelime şifreleme yöntemini programa uyarlıyoruz.

Bütün harflerin küçük veya büyük harf durumları korunarak harf harf kelimelere belirtilen sayıda ileri
öteleme işlemi yapılıyor. Bu şekilde öteleme sayısı bilinmediği sürece mektupları okumak oldukça zorlaşıyor.

---------------------------------------------------------
Genel olarak kodları aslında satırları üzerinde açıkladım.

Mantığın kavranması gereken nokta; bütün harfler ASCII sıraları baz alınarak öteleme işlemleri yapılıyor.
Büyük harfler alfabetik sırayla 65-90 aralığında, küçük harfler ise 97-122 aralığında bulunuyor.

Gerekli yerlerde öteleme işlemi sonrasında küçük veya büyük harfler kendi sınırlarından taşmışsa (örneğin
88 numaraya sahip X sayısı 6 ötelemeli bir şifreleme işleminde 94'de ulaşıyor ve bu durumda normalde D 
harfinde olmasına rağmen sınırı aşmasından dolayı ^ (94)' ulaşıyor. Bu gibi bir durumda -26 ile düzeltme
yapıp 94-26=68 yani D harfine ulaştırıyoruz değerimizi) düzeltmesini yapmamız gerekiyor.

Boşluklar ve herhangi harf dışı bir sayı veya sembol olduğu gibi kalıyor.

Ödevde istenen formattan dolayı k (öteleme miktarı) değerini programın adı ile birlikte alıyoruz. (***)
*/

#include <stdlib.h> // atoi için
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
            // 2 girdi ve komut satırı girdisinin (argv[1]) say olma koşulu
    if (argc == 2 && isdigit(*argv[1]))  //*** 
        {

            int k = atoi(argv[1]); //girdinin int'e dönüştürülmesi
            string kelime=get_string("plaintext: ");
            int kelime_length = strlen(kelime);
            char ciphertext[kelime_length];
            
            if (k>26) //// Bütün döngüler k'nın 0-26 aralığında olması üzerine olduğundan, 
                                //k'nın büyük olması durumunda kalanın kullanılması
                {
                    k=k%26; 
                }

                for (int i = 0; i < kelime_length; i++)
                    {
                        if (isupper(kelime[i])) 
                        {
                            if (kelime[i]+k>90) //büyük harf ascii sınırının taşmasını düzeltme
                                {
                                    //printf("%c\n",kelime[i]-26+k);
                                    ciphertext[i]=kelime[i]-26+k;
                                }
                            else
                                {
                                    //printf("%c\n",kelime[i]+k);
                                    ciphertext[i]=kelime[i]+k;
                                }
                        }
                        else if(islower(kelime[i]))
                        {
                            if (kelime[i]+k>122) //küçük harf ascii sınırının taşmasını düzeltme
                                {
                                    //printf("%c\n",kelime[i]-26+k);
                                    ciphertext[i]=kelime[i]-26+k;
                                }
                            else
                                {
                                    //printf("%c\n",kelime[i]+k);
                                    ciphertext[i]=kelime[i]+k;
                                }
                        }
                        else
                            {
                                //harf değilse olduğu gibi yazdır
                                ciphertext[i]=kelime[i];
                            }    
                    }
                    printf("ciphertext:%s\n",ciphertext);
        }
         else
            {
                printf("Usage: ./caesar k\n");
                return 1;
            }

}


/*
Çıktı:

$./vigenere 4
plaintext: araba
ciphertext: evefe

$./vigenere 1
plaintext: ghajini
ciphertext: hibkjoj
*/
