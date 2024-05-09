#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Personel {
    int id;
    char ad[20];
    char soyad[20];
    char departman[20];
    int izin;
    int deneyim;
    int maas;
};

void dosya();

int main() {
    dosya();
    return 0;
}

void dosya() {
    FILE *mevcutDosya, *yeniDosya;
    mevcutDosya = fopen("personel.txt", "r");
    yeniDosya = fopen("yenipersonel.txt", "w");

    if (mevcutDosya == NULL || yeniDosya == NULL) {
        printf("Dosya acilamadi!");
        exit(1);
    }

    struct Personel *personel = malloc(sizeof(struct Personel));
    struct Personel en_deneyimli;
    struct Personel en_fazla_ekmaas;
    struct Personel en_az_izin_kullanan;
    int en_cok_deneyim = -1;
    int en_yuksek_maas = 0;
    char en_yuksek_maas_adi[20];
    int en_fazla_ekmas = 0;
    en_az_izin_kullanan.izin = 99;
    int calisan_sayilari[5] = {0};
    int max_calisan = calisan_sayilari[0];
    int max_index = 0;

    while (fscanf(mevcutDosya, "%d %s %s %s %d %d %d",
                  &personel->id, personel->ad, personel->soyad, personel->departman,
                  &personel->izin, &personel->deneyim, &personel->maas) != EOF) {

        int yeni_maas = personel->maas;
        //İletişim departmanında çalışanların maaşlarına %5 indirim
        if (strcmp(personel->departman, "iletisim") == 0) {
            yeni_maas = personel->maas * 0.95;
        }

        //Bilişim departmanında çalışan ve deneyimi 5 yılı aşan personellerin yeni maaşları eski maaşlarının %5 karı
        if (strcmp(personel->departman, "Bilisim") == 0 && personel->deneyim >= 5) {
            yeni_maas = personel->maas * 1.05;
        }

        //30 günden az izin kullanan çalışanlar kullanmadıkları her izin günü için maaşlarına ek 100₺
        if (personel->deneyim != 1) {
            yeni_maas += 100 * (30 - personel->izin);
        }

        //Deneyim yılı 5’ten fazla olan her çalışana 200₺ ikramiye
        if (personel->deneyim >= 5) {
            yeni_maas += 200;
        }

        //Yöneticiyi seçme
        if (personel->deneyim > en_cok_deneyim || (personel->deneyim == en_cok_deneyim && personel->izin < en_deneyimli.izin)) {
            en_cok_deneyim = personel->deneyim;
            en_deneyimli = *personel;
        }

        fprintf(yeniDosya, "%d %s %s %s %d %d %d %d\n",
                personel->id, personel->ad, personel->soyad, personel->departman,
                personel->izin, personel->deneyim, personel->maas, yeni_maas);

        //En yuksek maas
        if(yeni_maas > en_yuksek_maas){
            strcpy(en_yuksek_maas_adi, personel->ad);
            en_yuksek_maas = yeni_maas;
        }

        //En fazla ek maas
        if((yeni_maas - personel->maas) > en_fazla_ekmas){
            en_fazla_ekmas = yeni_maas - personel->maas;
            strcpy(en_fazla_ekmaas.ad, personel->ad);
            strcpy(en_fazla_ekmaas.departman, personel->departman);
        }

        //En az izin kullanan ve deneyim 1'den fazla
        if(personel->deneyim > 1 && personel->izin < en_az_izin_kullanan.izin){
            strcpy(en_az_izin_kullanan.ad, personel->ad);
            strcpy(en_az_izin_kullanan.soyad, personel->soyad);
            en_az_izin_kullanan.izin = personel->izin;
        }

        if (strcmp(personel->departman, "Bilisim") == 0) {
        calisan_sayilari[0]++;
        } else if (strcmp(personel->departman, "Pazarlama") == 0) {
            calisan_sayilari[1]++;
          }
          else if (strcmp(personel->departman, "Finans") == 0) {
            calisan_sayilari[2]++;
          }
          else if (strcmp(personel->departman, "iletisim") == 0) {
            calisan_sayilari[3]++;
          }
          else if (strcmp(personel->departman, "Arge") == 0) {
            calisan_sayilari[4]++;
          }

            for (int i = 1; i < 5; i++) {
                if (calisan_sayilari[i] > max_calisan) {
                    max_calisan = calisan_sayilari[i];
                    max_index = i;
                }
            }
    }

    //Yonetici dosyanın içine yadırma
    fprintf(yeniDosya, "%d %s %s %s %d %d %d\n",
            16, en_deneyimli.ad, en_deneyimli.soyad, "Yonetici",
            en_deneyimli.izin, en_deneyimli.deneyim, 10000);

    fclose(mevcutDosya);
    fclose(yeniDosya);
    free(personel); // Bellek temizleme

    int sayi, devam = 1;

    while(devam == 1){
    printf("1-Yonetici ekrana yazdirma\n2-En yuksek maas yazdirma\n3-En fazla ek maas\n4-En az izin kullanan ve deneyim 1-den fazla\n5-Calisan sayisi en fazla olan departman\n");
    scanf("%d",&sayi);

    if(sayi == 1){
    //Yonetici ekrana yazdırma
    printf("->Id: %d\n->Ad: %s\n->Soyad: %s\n->Departman: %s\n->Izin: %d\n->Deneyim: %d\n->Maas: %d\n",
            16, en_deneyimli.ad, en_deneyimli.soyad, "Yonetici",
            en_deneyimli.izin, en_deneyimli.deneyim, 10000);
    }

    if(sayi == 2){
    //En yuksek maas yazdırma
    printf("En yuksek maas alan calisanin adi: %s -- maasi: %d\n",en_yuksek_maas_adi,en_yuksek_maas);
    }

    if(sayi == 3){
    //En fazla ek maas
    printf("En fazla ek maas alan: %s -- %s\n",en_fazla_ekmaas.ad, en_fazla_ekmaas.departman);
    }

    if(sayi == 4){
    //En az izin kullanan ve deneyim 1'den fazla
    printf("Deneyim yili 1den fazla olan: %s -- %s\n",en_az_izin_kullanan.ad, en_az_izin_kullanan.soyad);
    }

    if(sayi == 5){
    //Çalışan sayısı en fazla olan departman
    char departmanlar[5][20] = {"Bilisim", "Pazarlama", "Finans", "iletisim", "Arge"};
    printf("Calisan sayisi en fazla olan departman: %s\n", departmanlar[max_index]);
    }

    printf("Devam etmek istiyormusunuz(1/0): ");
    scanf("%d",&devam);

    printf("\n");
    }
}
