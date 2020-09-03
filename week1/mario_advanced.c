/*
3. Basamak ödevde ise bir önceki mario oyunu basamaklarının çift taraflı simetrik versiyonunu oluşturmamız isteniyor (Arada çift boşluk olucak, "  ").
------------------------------------------------------------------------------
Yine aynı şekilde get_int() ile istenilen basamak miktarını alıyoruz ve en dıştaki if koşulu (//1'de) ile if sadece girdi 1-8 aralığındaysa işlemlerin gerçekleşmesi şartını veriyoruz.
Buradaki else ile, eğer girdi istenilen aralıkta değilse tekrar girdi alınması sürecine geçiş var.

Buradaki #'ler arası 2 boşluk ve üst basamakların #'leri öncesi uygun sayıda boşluk için birkaç for döngüsü kullanmaız gerekti.

-Bunları en iyi şekilde anlamanız için önerim: anlamakta zorlandığınız for'lar için, printf()'lerin içerisindeki boşluk veya #'lerin yerine  1,* veya + gibi ayırabileceğiniz bir değer koyarak  işlemi birer kez izleyin. Mesela "//4" satırındaki printf içerisine boşluk yerine "*" koyarsak şöyle bir çıktı verecek:
                                                    ***#  #
                                                    **##  ##
                                                    *###  ###
                                                    ####  #### bu gibi aşama izlemeleri soru işaretlerinizi giderecektir.
Belirtmek isteyeceğim noktalar ise:
//2 ile (i ile) kaç basamak merdiven yapacağımızın döngüsünü veriyoruz. (for sonrası "{" ile bu for'un kapsamına dikkat edelim.)

//3'ü (j ile) üst basamakların soldaki boşlukları için kullanıyoruz.

//5 ile soldaki basamak #'lerini, //6 ile sağdaki basamakların #'lerini ayarlıyoruz.

#İç içe for'lar kafa karıştırıcı olabilir fakat bahsettiğim gibi printf() içlerini değiştirip gözlemlediğinizde taşlar yerine oturacaktır.
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int i,j,n,row;
   row=get_int("Heigh: ");
   if (row<=8&&row>=1) //1
   {
       for (i=1;i<=row;i++){ //2
           for (j=0;j<row-i;j++) //3
       {
           printf(" "); //4
       }
       for (j=0;j<i;j++) //5
       {
           printf("#");
       }
       printf("  "); 
       for (j=0;j<i;j++) //6
       {
           printf("#");
       }
       printf("\n"); //7
       }
   }
   else
   {
       main();
   }        
}


/*
Çıktı:

$ ./mario_advanced
Heigh: 3
  #  #
 ##  ##
###  ###
$ ./mario_advanced
Heigh: 7
      #  #
     ##  ##
    ###  ###
   ####  ####
  #####  #####
 ######  ######
#######  #######
*/
