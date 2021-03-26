# CS50
<p align="center">
  <img src="https://user-images.githubusercontent.com/62308612/91111567-82f19580-e689-11ea-8c57-f9026dd76143.png" />
</p>

[Kodluyoruz](https://www.kodluyoruz.org) ile birlikte başladığım Harvard CS50 dersi çalışmalarım ve hafta hafta ödevler ile ödev cevaplarını oluştururken kod parçalarındaki kurduğum mantıkları açıklayarak kodları yüklemeyi planlıyorum.

Hafta hafta readme kısmında içeriklerden kısa kısa bahsediliyor olup, her haftanın kendi kodlarının içerisinde oluşturma mantıkları daha ayrıntılı biçimde anlatılıyor olacak.
Ayrıca her haftanın kendi dizinindeki readme bölümlerinde o haftaya ait ders notları bulunuyor olacak.


Bu derse başlarken şunu belirtmek isterim ki şuan iyi bir düzeyde R ve Python biliyor olmama rağmen öncesinde "C" geçmişim yok. Onun için aslında bu repostory "c" gelişimimi de yansıtıyor olacak.
(24.08.2020)

## İçerik:

0. Hafta
   * "Scratch Projesi"
1. Hafta
   * "Mario"
   * "Mario Advanced"
   * "Cash"
   * "Credit"  
  
2. Hafta
   * "Caesar"
   * "Vigenere"
   * "Crack" (Optional)

3. Hafta
   * "Whodunit"
   * "Resize"
   * "Resize Advenced"
   * "Recover"
   

## 0. Hafta

Scratch projesi olarak 2 kişilik bir labirent oyunu yapmak düşüncesiyle çıktım yola. Yer yer benzer labirent projelerinden uygulamak istediğim kullanımlar hakkında içerik incelemeleri de gerçekleştirdim. CS50 dışında da ara ara kafa dağıtmalık güzel projeler için uğranabilecek bir site scratch.   
[Scratch Projem](https://scratch.mit.edu/projects/418376809)

## [1. Hafta](https://github.com/bilative/cs50/tree/master/week1)
Hızlı bir şekilde cye giriş yapılan derste çok temel şekilde bilgielr verildi ve 5 parça ödev başlıkları şu şekilde:
1. Kişiye ismini sor ve çıktı olarak "Merhaba, X" dönsün.

2. İstenen sayı kadar (1-8) nintendo mario oyunu merdiven basamaklarını oluştur.

	        #
	       ##
	      ###
	     #### şeklinde.
	     
3. İstenen sayı kadar (1-8) nintendo mario oyunu merdiven basamaklarını karşlıklı oluştur.

	      #  #
	     ##  ##
	    ###  ###
	   ####  ####  şeklinde.
	     
4. Cash. Müşterilere para üstleri için minimum kaç adet bozuk para ile ödeme yapılabilir?
25cent,10cent,5cent ve 1 cent para birimleri ile para üstü vereceğimizi düşünerek yaklaşıyoruz probleme. Örneğin 38 centlik bir paraüstü 1.(25cent)+1.(10cent)+3.(1cent) ile toplam 5 madeni para ile verilebilir.

5. Credit. Luhnun Algoritması ile oluşturulan kredi kartları numaralarının geçerliliğini ve eğer geçerlilerse hangi bankaya ait bir kredi kartı numarası olduklarının tespiti için bir kod oluşturmak görevi.

## [2. Hafta](https://github.com/bilative/cs50/tree/master/week2)


1. Caesar. Caesar'ın vakti zamanında mesajlarının şifreyi bilmeyenlerce okunmaması için kullandığı sistemin uyarlanması. İlk olarak girilen bir şifre sayısı ile asıl mesaj'daki harfler bu şifre sayısı kadar öteleniyor. Mesela şifre 3 ise Bilal -----> Elodo 'ya dönüşüyor.

2. Vigenere. Cesar'ın şifreleme sisteminden daha üst düzey ve çözülmesi daha zorlu bir şifre sistemi. Bu sefer ilk olarak şifre için bir sayı değil bir kelime giriliyor. Ve şifrelenecek olan kelimenin harfleri sırasıyla şifre kelimesi harflerinin sıraları kadar öteleniyor. Mesela şifre ari olsun, Bilal -----> Bztac oluyor. Hiçbir şey anlamadınız dimi, zaten amaç da bu :D  
  
    
    Opsiyonel Ödev: Crack. Crack ödevi opsiyonel olarak sunulmuş bir problem. Şifrelerin saklandığı dosyada şifrelerin kolay okunabilir olmaması için encode edilmiş versiyonlarının bulunduğu bilgisi veriliyor ve elimizde bu encode edilmiş halleri mevcut. Encode edilmiş bu hallerin orjinal şifre dönüşümleri yapmamız/şifreleri kırmamız istenmiş. Biraz araştırma gerektiren bir ödev, biraz da bakış açısı genişletici.
    
[3. Hafta](https://github.com/bilative/cs50/tree/master/week3)  
1. Whodunit". Hikayemize göre Tudor Konağı'nın ev sahibi John Boddy bir oyunun urbanı olup aramızdan ayrılıyor. John'un katilinin kim olduğu ise son saatlerinde bilgisayarında yaptığı 24bitlik pm formatında bir fotoğrafta gizli. Fakat fotoğrafa bakınca kırmızı noktalardan başka bir şey göremiyoruz, fotoğrafın bu kırmızı gürültüden temizlenmesi gerekiyor.  
Bu hafta ödevlerini yapmak için öncesinde kısa sayılmayacak şekilde bilgiler veriyor cs50 grubu ve ardından gerekli yerlerde yönlendirmelerde bulunuyor. Cevaplar tek başlarına çok zorlayıcıymış gibi görünse de sizlere aslında okumaları yerinde ve düzgün şekilde yaptığımız sürece diğer geçen haftaya nazaran kolay bile denilebilir bu haftanın soruları.

2. Resize. Resize bölümünde adından da anlaşılacağı üzere elimizdeki bpm formatındaki fotoğrafları girilecek n katlarınca resize edecek bir program yazmamız isteniyor. Yine sistem gerekli yerlerde yardımcı oluyor, ön bilgiler doğrultusunda bazı kuralları gözzetmemiz gerekiyor.

3. Resize Advenced. Resize ödevinin bir ileriki seviyesi olan bu bölümde resize işlemini tam sayıdan oluşan katlar olarak değil de 0-1 aralığında küçültme amaçlı bir resize süreci amaçlanarak bir program yazmamız isteniyor. Küçülterek resize aşamasında bazı piksellerin bozulması veya silinmesi gerekebiliyor, burası yoruma açık fakat yine yönlendirmeler mevcut. Bu haftanın ödevleri farklı bakışaçıları kazandıran cinsten.

4. Recover.

# KURSUN ILERLEYEN HAFTALARINDA YOGUNLUGUM SEBEBIYLE (ise girdim) NOT TUTMAYI AKSATIR OLDUM. ACIKLAMASIZ EKLEMEK ISTEMEDIGIM ICIN SUAN ICIN YAKIN ZAMANDA DIGER HAFTA ICERIKLERINI YUKLEMEYECEGIM. (Kursu bitirdim, fakat notlar paylasilabilir aciklikta degil belki suan)
