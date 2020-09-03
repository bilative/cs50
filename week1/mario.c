/*
2. Basamak ödevde nintendo'nun mario brothers oyununda bulunan merdiven basamakları benzeri bir deseni # (hash) sembolleri ile oluşturmamız isteniyor.
1-8 aralığında (1 ve 8 dahil) girdiler sonucu istenilen sayıda basamak çıktısı elde etmemiz gerekiyor.
------------------------------------------------------------------------------

Diğer dillerde bir geçmişim olmasaydı sanırım zorlayıcı olabilirdi bu ödev.
"while" içerisine verilen şartlar ile sadece kullanıcıdan alınan sayılar istenilen aralıkta (1-8) olduğu sürece işlemin yapılmasını belirttik.

Burada kullanılan içiçe 2 for döngüsünden dışta olan (i içeren), her basamakta uygun sayıda # koyulduktan sonra alt basamağa geçilmesini sağlıyor.
Bunun için bu for döngüsünün üst sınırı basamak sayımız.

Dışta olan (j içeren) for döngümüzde ise her basamaktaki # miktarları önem arzediyor.
İstenilen desene ulaşılıyor olması için üst basamaklarda #'lerin soluna uygun sayıda " " (boşluk) koymamız gerekiyor ve içteki for döngümüzün şartları da buna göre belirlenmiş durumda.
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    } 
    while (n>8 ||n<1);
    for (int i=1 ; i<n+1 ;i++)
    {
        for (int j=1;j<n+1;j++)
        {
            if (i+j>n)
            printf("#");
            else
            printf(" ");
        }    
        printf("\n");
    }
}


/*
Çıktı:
$ ./mario
Height: 5
    #
   ##
  ###
 ####
#####
$ ./mario
Height: 8
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
*/
