/*
5. Adım Ödevde biraz fazla ayrıntı var ve başlıca sebebir c'ye hakimiyetimin çok yetersiz olmasından kaynaklı en fazla internetten yardım aldığım soru oldu bu. Ve şunu söylemeliyim ki dersin amacı hiç kodlama bilmeyen kişiler için ilk adımlar gibi bir slogan iken bu seviye görevler cidden çok zorlayıcı.
Bu gibi bir soruyu biliyorum dediğim python ve r'da yapabilirim ancak ve bu programları aylardır/senelerdir kullanıyorum. İlk haftasında aşırı yardımsız ve sıfır kodlama bilgisiyle bu ödevleri yapmaya çalışan kişiler cidden çok çok zorlanacaktır. Eğer bu gruptan biri var ise bu yazdıklarımı okuyan içiniz rahat olsun diyorum, çünkü cidden ilk haftanın hakkı olan ödevler değil bu, ve hatta önceki basamak bile değil. Zamanla oturacak şeylerdir bunlar ve hem deneyim hem de dile hakimiyet gerektirir diye düşünüyorum.

Sorunumuza gelecek olursak. Sorunumuzda biraz fazla ayrıntı var. Olabildiğince kısa geçmeye çalışacağım. Genel olarak kredi kart numaraları Luhn’un Algoritması olarak bilinen bir kurala uygun şekilde oluşturuluyor. Bu kurala göre, kart numaralarında şu şarta uygunluk gerekli:
                1. Sondan ikinci rakamdan başlayarak her ikinci rakamı 2 ile çarpın, ve bunların çarpımlarında ortaya çıkan rakamların herbirini ayrı ayrı birbirine ekleyin.
                2. Toplamı, 2 ile çarpılmamış olan sayıların rakamlarının toplamına ekleyin.
                3. Eğer toplamın son hanesi 0 ise (daha resmi şekilde mod 10’da 0 veriyorsa), numara geçerlidir!
                (Daha fazlası için: https://en.wikipedia.org/wiki/Luhn_algorithm)

Luhn Algoritmasına ek olarak ödevimiz bize birkaç şart daha vermiş. Bunlar şu şekilde: 
                *American Express 15 haneli, MasterCard 16 haneli ve Visa 13 ve 16 haneli rakamlar kullanıyor. 
                *American Express rakamları 34 veya 37 ile başlıyor, MasterCard rakamları 51, 52, 53, 54 veya 55 ile ve tüm Visa numaraları 4 ile başlıyor.

Bu koşullara bağlı kalınarak girilen bir numaranın hangi şirkete ait bir kredi kartı olduğunun tespitedilip şirket isminin çıktı olarak döndürülmesi ve eğer kart luhn algoritmasına uymuyor ve diğer şartlara uymuyorsa bu kart numarasının geçersiz olduğu bilgisiniz yazdırılması isteniyor.
------------------------------------------------------------------------------

Araştırmalarımda girdi olarak int veya float değil long formatında girdi almam gerektiğini okudum ve bunun için girdi no'muzu long olarak belirledim.

//1 satırında girilen kart numarasının kaç basamaklı olduğunu bulduk. Aslında basit bir fonksiyon ile bunu bulmayı umarken stackoverflow'da bu şekilde basamak sayısana ulaşabileceğimi gördüm.

//2 satırında çift sayıdaki basamakları tespit edip bunu //3 satırında luhn algoritması hesabı için kullandık.

//4-5-6 satırlarında koşullara birlikte uyum halinde numaranın hangi şirkete ait bir kartın olduğunun bilgisini yazdırdık.
Uyum yok ise numaranın geçersiz olduğu bilgisini bastırdık.
*/


#include <stdio.h>
#include <cs50.h>
#include <math.h>

void credit(long no);

int main(void)
{
    long no = 0;
    credit(no);
}

void credit(long no)
{

    do

    {
        no = get_long("Enter a credit card number: ");
    }

    while (no < 0);

    {
        int sum = 0;
        long ck = no;
        int nDigits = floor(log10(ck)) + 1; //1
        int parity = nDigits % 2; //2 


        for (int i = nDigits; i >= 0; i--) {
            int digit = ck % 10;

            if (i % 2 != parity) { //3
                digit = digit * 2;
        
            }
            if (digit > 9) {
                digit = digit - 9;
            }

            sum = sum + digit;
            ck /= 10;
            
        }

          if (sum % 10 == 0 && nDigits == 15 && ((floor(no / pow(10,13)) == 34) || (floor(no / pow(10,13)) == 37))) //4
    {
        printf("%s\n", "AMEX");
    }
    else if (sum % 10 == 0 && (nDigits == 13 || nDigits == 16) && ((floor(no / pow(10,12)) == 4) || (floor(no / pow(10,15)) == 4))) //5
    {
        printf("%s\n", "VISA");
    }
    else if (sum % 10 == 0 && nDigits == 16 && ((floor(no / pow(10,14)) == 51) || (floor(no / pow(10,14)) == 52) || (floor(no / pow(10,14)) == 53) || (floor(no / pow(10,14)) == 54) || (floor(no / pow(10,14)) == 55))) //6

    {
        printf("%s\n", "MASTERCARD");
    }
        else
        {
            printf("%s\n","INVALID");
        }
    }
}


/*
Çıktı:

$ ./credit
Enter a credit card number: 5673598276138003 
INVALID
$ ./credit
Enter a credit card number: 371449635398431
AMEX
$ ./credit
Enter a credit card number: 4111111111111111 
VISA
*/
