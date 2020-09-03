/*
4. Adım ödevimizin amacı müşteriye paraüstü olarak minimum sayıda bozuk para vermek.
Bozukluklarımız 0.25,0.10, 0.05 ve 0.01'lik para birimlerinden oluşmakta (sırasıyla quarter, dime, nickel, penny). Mesela 37 cent'lik bir paraüstünü en az bozuk para ile vermek istersek bu işlem 0.25+0.10+0.01+0.01=0.37 şeklinde 4 tane bozuk para ile yapılabilir. Yani sonuç 4 olur.
------------------------------------------------------------------------------

Burada ilk haftalarım olduğu için biraz saçma da olduğunu bildiğim basamaklarım oldu. Fakat ileriki dönemlerde dil üzerinde daha da hakimiyetimi arttırdıkça bu hatalara düşmemeyi umuyorum.

İşlemleri daha kolay gerçekleştirmek ve bölme işlemlerinde sorun çıkmaması için bütün sayıları 100 ile çarpıp her bir para birimi tam sayıymış gibi işlemlere devam ettim.

Genellikle paraüstü miktarları küsuratlı olacağı için bu sefer girdi olarak int değil de get_float() ile edğerleri float olarak almamız gerektiğini belirttim.

Sonraki aşamalardan sırasıyla ana paraüstü miktarımız (100 ile çarpılmışları; cy ve is) miktarlarını bozukluk miktarlarına bölüp kalan veriyor mu diye baktım. Eğer kalan veriyorsa sırasıyla daha küçük bir miktara bölüp en küçük kalana kadar ayrıştırdım. Aynı zamanda para miktarını bozukluklara bölerek kaç adet alt birim bozukluktan oluştuğunu da topladım ve bunu yazdırdım.

İlk başta kod yazımını bu kadarıyla yeterli görmüştüm fakat sistem ödevi hatalı görüp kabul etmedi. Bunun sebebi negatif para miktarları durumunda da işlemlerin yapılıyor olmasıydı ve girdi olarak 0 girildiğinde de çıktı olarak 0 dönmüyor olmasıydı ve bununla ilgili de bir for ve if koşulu eklemeye karar verdim. //1 ve //2 oalrak belirtilen satırlar daha sonradan eklendiği için genel akışta bir düzensizlik arzediyor gibi görünebilir açıkcası.
Buradaki amaç girdi değeri negatif veya 0 ise ona göre ayrı çıktı vermek veya işlemi tekrardan başlatmak. Hatta şuan bakınca if tamam fakat for döngüsü biraz gereksizmiş gibi geldi.

Genel amacım zaten kusursuz kodu vermekten ziyade dersler boyunca kendi ilerlediğim yolu sunmak ve sisteme yüklediğim kodları birebir yüklemek buraya.


*/



#include <stdio.h>
#include <cs50.h>

int main()
{
    int cy,q,qk,n,nk,d,dk,p,pk,is,i;
        
        
        for(i=0;i<1;i++) //1
        {
        if(i<1) //2
        {

        float pu = get_float("Change: ");
        cy = (pu * 100);
        is=pu;

    if (cy>0)
{
q=cy/25;
qk=cy%25;

d=qk/10;
dk=qk%10;

n=dk/5;
nk=dk%5;

p=nk/1;
pk=nk%1;

printf("%d\n", q+d+n+p);
}
    else if(is==0)
    {   
        printf("%i",0);
    }
    else
    {
        i=i-1;
    }


        }}
}


/*
Çıktı:

$ ./cash
Change: 5
20
$ ./cash
Change: 0.38
5
$ ./cash
Change: 0.22
4
$ ./cash
Change: -4
Change: 0
0$ ./cash
Change: 0.09
*/
