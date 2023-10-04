#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

int hesapla(int,int);

int main(void){
    int ogrSayısı,gecmeNotu;
    int kalanSayi;
    
    printf("Öğrenci sayısı : ");
    scanf("%d",&ogrSayısı);
    //öğrenci sayısı 0'dan küçük 100'den büyük olduğunda kullanıcıdan tekrar giriş isteriz
    while(ogrSayısı<0 || ogrSayısı>100) {
        printf("Hatalı giriş yaptınız!!\n");
        printf("Lütfen tekrar giriniz: ");
        scanf("%d",&ogrSayısı);
    }
  
    printf("Geçme notu : ");
    scanf("%d",&gecmeNotu);
    //Kalan öğencileri hesapla fonksiyondan çağırıyoruz
    kalanSayi=hesapla(ogrSayısı,gecmeNotu);
    
    printf("Kalan öğrenci sayıısı : %d\n",kalanSayi);
    
    printf("\n");
    return 0;
}
int hesapla(int orSayisi,int dersGecmeNotu){
    int dizi[100];
    int kalanOgrenciSayisi=0;
    float ortalama;
    int toplam=0;
    //Öğrencilerin notunu alırız
    for (int i=0;i<orSayisi;i++) {
        printf("%d. öğrenci notu : ",i+1);
        scanf("%d",&dizi[i]);
        toplam+=dizi[i];
    }
    //Ortalamayı hesaplarız
    ortalama=(float)toplam/(float)orSayisi;
    
    printf("Sınıf ortalamasi : %.2f\n",ortalama);
    //Kalan öğrenci geçme notundan düşükse kalan öğrenci sayısını bir arttırırız
    for (int i=0; i<orSayisi; i++) {
        if (dizi[i]<dersGecmeNotu) {
            kalanOgrenciSayisi++;
        }
    }
    return kalanOgrenciSayisi;
}
