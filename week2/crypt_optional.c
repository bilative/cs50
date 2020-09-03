/* CRACK
Bu opsiyonel ödevde  şifrelerin tutulduğu klasörde kolay okunur olmamaları için bir şifreleme işlemine tabii tutulmaları (hash),
ve tekrar geri orjinal hallerine döndürülmeleri amaçlanan adımlar var. Yani klasörde tutulan aslında bizim şifrelerimizin dönüştürülmüş
halleri.

Problemle ilgili bilgilerde dikkat edilmesi gereken noktalar var, bunları gzardı ettiğim için biraz fazla zaman kaybettim açıkcası.

Görev, parolayı kıran bir programtasarlamak ve bunu yaparken "crypt" fonksiyonuna yönlendirme yapılmış. Bu fonksiyonun işleyişi ve parametreleri
hakkında yeterli seviyede bilgiyi buradan https://stackoverflow.com/questions/1149191/what-does-crypt-do-in-c öğrenebilirsiniz (benim gibi).

*Programmımız hash'lenmiş parolayı komut satırından alıyor ve orjinal şifreyi cevap olarak döndürüyor.
*Şifrelerin sadece küçük ve büyük harfleri içeren maksimum 5 karakterden oluşabileceği belirtiliyor.
*Belli durumlarda hata döndürülmesi isteniyor.
*Olabildiğince çabuk sonuca varılsın isteniyor.
------------------------------------------------------------------------------

Genel olarak bütün satırları açıkladım fakat şunu belirtmek istiyorum sadece, ilk önce (bana en çok zaman kaybettiren şey bu oldu)
strcmp() kullanımını bilmiyor olduğum için eşitliği if(enc==hash) ile test ettim ve işlemler inanılmaz uzun sürdü, ve 1 gün kaybettirdi
bu hata bana diyebilirim. Çünkü ben bu izlem uzaması ve mantıksızlıkları hiç de bu ayrımdan kaynaklıdır diye düşünemedim. Fakat şuan çok çok
hızlı cevap dönüyor program.

Diğer bir zaman kaybım ise \0 kullanmam gerektiğini hızlı bir şekilde farkedememem oldu. Bu aşamada printf() ile denenen şifre
kombinasyonlarını kontrol ederken mantıksal hatayı farkedip çözüme ulaşabildim.

Her satırda işlemlerin mantığını kavraman için uygun yerlerdeki //'ları kaldırarak printlerin  çıktıları da izleyebilirsiniz. Bu
çok daha iyi anlamanızı sağlayacaktır.
*/




#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: crack <hash>\n");
        return 1;
    }
    string hash=argv[1];
    char salt[3]; // neden bilmiyorum fakat salt[2] olarak ayarladığımda ve salt'ı print ettirdiğimde istediğim şekilde olmadığını gördüm
    salt[0]=argv[1][0];                                 //Bu şekilde salt'a doğru atama gerçekleşiyor
    salt[1]=argv[1][1];
    //printf("salt %s\n",salt); //Salt çıktısını görmek için bastaki slash işaretlerini kaldırın

    string harfler="\0etaoinsrhldcumfpgwybvkxjqzETAOINSRHLDCUMFPHWYBVKXJQZ"; //harfleri ingilizcedeki frekanslarına göre aldım.
                                                                              // http://letterfrequency.org
            //Dögümü. satır ile kontrol ettiğimde başlangıçta  son satır hep e olduğunu farkedince döngünün 5 haneli hariç
                //Hiçbir şifreyi bulamaycağını farkettim, biraz araştırınca \0'ın Null/Na değer yerine geçtiğini öğrendim
                
    char sifre[5];
    for(int i=0;i<53;i++)
    {
        for(int j=0;j<53;j++)
        {
            for(int k=0;k<53;k++)
            {
                    for(int m=0;m<53;m++)
                    {
                            for (int n=0;n<53;n++)
                            {
                                sifre[0]=harfler[n];    //Bu satırlarda sırasıyla harfleri 5 boşluğa oturtup
                                sifre[1]=harfler[m];      //Her farklı komniasyonun denenmesi için
                                sifre[2]=harfler[k];        //52*52*52*52*52=380204032 farklı şifre komniasyonunu
                                sifre[3]=harfler[j];          //test ettik
                                sifre[4]=harfler[i];           
                                            
                                //printf("Dongu Şuan: %i-%i-%i-%i-%i\n",n,m,k,j,i);
                                //printf("%s\n",sifre);
                                //printf("Şifre şuan: %c%c%c%c%c\n",harfler[n],harfler[m],harfler[k],harfler[j],harfler[i]);
                                string enc=crypt(sifre, salt);
                                if (strcmp(enc,hash) == 0) //salt ile kombinasyonda sırası gelen olası şifreyi şifreleyip
                                {                              //  hash(girdimiz) ile karşılaştırıyoruz
                                    printf("%s\n", sifre);
                                    return 0;
                                }
                            }
                    }
             }
        }
    }
       printf("Password couldn't be cracked!");

    // This may be out of scope of the task but we signal failure w/ a different
    // exit status than 1 (wrong arguments) or 0 (success) which have been reserved.
    return 2;
}


/*
Kontrollerini sağlamamız istenen encode edilmiş şifreler şu şekilde sıralanmış:

brian:51.xJagtPnb6s
bjbrown:50GApilQSG3E2
emc:502sDZxA/ybHs
greg:50C6B0oz0HWzo
jana:50WUNAFdX/yjA
lloyd:50n0AAUD.pL8g
malan:50CcfIk1QrPr6
natmelo:50JIIyhDORqMU
rob:51v3Nh6ZWGHOQ
veronica:61v1CDwwP95bY
walker:508ny6Rw0aRio
zamyla:50cI2vYkF0YU2
*/
