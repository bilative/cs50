
/*
1. Basamak ödev cidden çok basit seviyede. 
"get_string()" ile kullanıcıdan string girişi alıyoruz ve sonrasında "Merhaba, X" şeklinde çıktı veriyoruz.
------------------------------------------------------------------------------

Önemli nokta: "get_string()" ve printf() içerisinde "%s" kullanımı
*/


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?: ");
    printf("hello, %s\n", name);
}


/*
Çıktı:

$ ./hello
What is your name?: Bilal
hello, Bilal
*/

