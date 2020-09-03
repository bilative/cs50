# 2. Hafta Ders Notları
## Fonksiyonlar
Fonksiyon oluşturma işleminde 2 farklı kullanım bulunmakta. 
  1. Fonksiyon ilk olarak tanımlanır ve ardından program içerisinde kullanılır.
  2. İlk önce içerisinde fonksiyonun kullanıldığı bir program yazılır, fonksiyon bunun ardından yazılır. Bu durumda programın başında fonksiyonu da belirtiriz. 2 Örnek ile bunları gösterelim.

İlk olarak Fonksiyonun başta tanımlandığı duruma bir örnek. Burada girilen 3 değer üçgen olma şartına uyuyorsa, bu değerlerden üçgen oluşturulup oluşturulamayacağını döndüren bir fonksiyon ve buna bağlı bir işlem bulunmakta.

```c
#include <stdio.h>
#include <cs50.h>

bool ucgen(float x, float y, float z);

int main(void) 
{ //Bu parantez boyunca da ana işlemimiz (fonksiyon dahil edilerek) gerçekleştirilir.
    float a=get_float("1. Kenar uzunluğumuz: ");
    float b=get_float("2. Kenar uzunluğumuz: ");
    float c=get_float("3. Kenar uzunluğumuz: ");
    printf( "%.1f, %.1f, %.1f Ölçülerinde bir üçgen olabilir mi?\n
    - %s\n", a, b, c, ucgen( a, b, c ) ? "Evet olabilir." : "Hayır olamaz." );
    return 0;
}

bool ucgen(float x, float y, float z)
{ //Bu parantez boyunca fonksyionun içeriği oluşturulur
    
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }
        //2 kenarın toplamı 3. kenardan uzun olamaz
    else if ( x + y <= z || x + z <= y || y + z <= x)
    {
        return false;
    }

    else
    {
        return true;
    }
}

```

Diğer kullanım ise şu şekilde.

```c
#include <stdio.h>
#include <cs50.h>

bool ucgen(float x, float y, float z)
{
    //Sadece pozitif sayılar
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }
        //2 kenarın toplamı 3. kenardan uzun olamaz
    else if ( x + y <= z || x + z <= y || y + z <= x)
    {
        return false;
    }

    else
    {
        return true;
    }
}

int main(void) 
{
    float a=get_float("1. Kenar uzunluğumuz: ");
    float b=get_float("2. Kenar uzunluğumuz: ");
    float c=get_float("3. Kenar uzunluğumuz: ");
    printf( "%.1f, %.1f, %.1f Ölçülerinde bir üçgen olabilir mi?\n
    - %s\n", a, b, c, ucgen( a, b, c ) ? "Evet olabilir." : "Hayır olamaz." );
    return 0;
}

```

Aslında aradaki fark oldukça basit, eğer fonksiyonumuzu önce kullanmak istiyorsak sadece 1 satır kod ekliyoruz.
<p align="center">
  <img src="https://user-images.githubusercontent.com/62308612/91658468-fd2e7980-ead0-11ea-94a9-757e60162daf.jpg" />/>
</p>


## Selection Sort (Seçerek Sıralama)

Selection sort işlemi syı dizisinde soldan başlayarak sıralı olmayan en küçük sayıyı bulup kendi sırasına koymak ve sırasını işgal etmiş olanı da kendi eski konumuna yollamak mantığına dayanır. Örnek olması açısından yazmış olduğum şu kodda çıktıyı görebiliriz:
```c
#include<stdio.h>
int main(){
   int ara, no[6],tur=0;


   printf("6 adet sayı giriniz: ");
   for(int i=0;i<6;i++)
      scanf("%i",&no[i]);

    printf("Girmiş olduğunuz sayılar: ");
      for(int k=0;k<6;k++)
            {
                printf("%i ",no[k]);
            }
            printf("\n");
    
   for(int i=0;i<6;i++){
      for(int j=i+1;j<6;j++){
         if(no[i]>no[j]){
            ara=no[i];
            no[i]=no[j];
            no[j]=ara;
            tur=tur+1;
            printf("Aşama %i'deki durum: ",tur);
            for(int k=0;k<6;k++)
            {
                printf("%i ",no[k]);
            }
            printf("\n");
         }
      }
   }

   printf("Selected sort işlemi sonrası: ");
   for(int i=0;i<6;i++)
      printf(" %i",no[i]);
   return 0;
}

```

6 sayı girip bu sırasız 6 sayı sıralı bir hale gelirken aşama aşama konum değişimlerini gözlemliyoruz.

```

6 adet sayı giriniz: 12,3,45,61,2,7  

Girmiş olduğunuz sayılar: 12 3 45 61 2 7

Aşama 1'deki durum: 3 12 45 61 2 7
Aşama 2'deki durum: 2 12 45 61 3 7
Aşama 3'deki durum: 2 3 12 61 45 7
Aşama 4'deki durum: 2 3 7 61 45 12
Aşama 5'deki durum: 2 3 7 45 61 12
Aşama 6'deki durum: 2 3 7 12 61 45
Aşama 7'deki durum: 2 3 7 12 45 61

Selected sort işlemi sonrası: 2 3 7 12 45 61
```

## Bubble Sort (Kabarcık Sıralaması)
Bubble sort işleminde en baştan başlayarak her ardışık 2 değer küçük solda büyük sağda olacak şekilde (eğer zaten bu şekilde sıralı değiller ise) tekrar sıralandırılır.
4 değer için mesela (sayılarımız 3-12-2-1 olsun) ilk adımda 3-12 değerlerine bakılır ve eğer sıralamada sorun varsa düzenlenir (Şuan sıramız değişmedi 3-12-2-1). Sonra sıradaki 12-2 ikilisine bakılır ve düzenlenir(Şuan sıralama 3-2-12-1). Sonra sıradaki ikili olan 12-1'e bakılır ve düzenlenir. Şuan sıralama 3-2-12-1 şeklinde ve 1. düzeltme basamağımız tamamlandı. Bu sıralama kontrolleri süresince 3 aşamadan 2'sinde düzenleme yapılırken 1'inde değişlikliğe gidilmedi. 
Bubble sort işlemi sıralamanın  istenen formatta oluncaya dek bu şekilde tekrar edilir.  
Bir de görsel olarak görmek istersek [şu şekilde](https://www.turkhackteam.org/algoritma/1900214-siralama-algoritmalari-1-bubble-sort-algorithm.html):
<p align="center">
  <img src="https://user-images.githubusercontent.com/62308612/91670782-401c3b80-eb29-11ea-92be-64eee7e7fe06.png" />
</p>

Örnek kod döngümüz ile gösterimi de aşama şama şu şekilde olucak:
```c
#include<stdio.h>
int main(){
   int ara, no[6],tur=0;

//Sayıların girilmesi
   printf("6 adet sayı giriniz: ");
   for(int i=0;i<6;i++)
      scanf("%i",&no[i]);

    printf("Girmiş olduğunuz sayılar: ");
      for(int k=0;k<6;k++)
            {
                printf("%i ",no[k]);
            }
            printf("\n");
    
   for (int i = 0; i < 6; i++) {   
        for (int j = 0; j < 6 - i - 1; j++) 
        {
            if (no[j] > no[j + 1]) { 
                ara = no[j];
                no[j] = no[j + 1];
                no[j + 1] = ara;
                tur=tur+1;
                printf("Aşama %i'deki durum: ",tur);
            for(int k=0;k<6;k++)
            {
                printf("%i ",no[k]);
            }
            printf("\n");

            }
        }
    }

   printf("Selected sort işlemi sonrası: ");
   for(int i=0;i<6;i++)
      printf(" %i",no[i]);
   return 0;
}

```
Çıktımızda ise adım adım aşamalrı izleyebiliyoruz:
```

6 adet sayı giriniz: 12,3,45,61,2,7  

Girmiş olduğunuz sayılar: 12 3 45 61 2 7

Aşama 1'deki durum: 3 12 45 61 2 7
Aşama 2'deki durum: 3 12 45 2 61 7
Aşama 3'deki durum: 3 12 45 2 7 61
Aşama 4'deki durum: 3 12 2 45 7 61
Aşama 5'deki durum: 3 12 2 7 45 61
Aşama 6'deki durum: 3 2 12 7 45 61
Aşama 7'deki durum: 3 2 7 12 45 61
Aşama 8'deki durum: 2 3 7 12 45 61
Selected sort işlemi sonrası: 2 3 7 12 45 61
```

