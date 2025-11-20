#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Durum Değişkenleri (Durum Yönetimi)
int saglik = 100;      // (0-100)
int enerji = 100;      // (0-100)
int yemek_sayisi = 5;  // Başlangıç yiyeceği
int siginak_durumu = 0; // 0: Yok, 1: Var

// Fonksiyon Prototipleri
void envanteri_goster();
void avlan();
void siginak_ara();
void dinlen();
void tehlike_dalgasi();
void sifreli_ilerleme();
int karakter_oldu_mu();

int main() {
    char komut;

    // Rastgele sayı üretimi için seed ayarı
    srand(time(NULL));

    printf("\n----------------------------- Karakter Tabanli Hayatta Kalma Simulatoru--------------------------------\n");
    printf("\nKomutlar: A (Avlan), S (Siginak Ara), E (Envanter), R (Dinlen), F (Tehlike), P (Ilerleme), X (Cikis)\n");
    
    // Ana Komut Dinleme Döngüsü (DO-WHILE Zorunlu)
    do {
        envanteri_goster(); // Mevcut durumu göster
        
        if (karakter_oldu_mu()) {
            printf("\n!!! SIMULASYON SONA ERDI: Karakteriniz hayatta kalamadi. !!!\n");
            break;
        }

        printf("\nKomut girin: ");
        scanf(" %c", &komut);
        
        // Komut Yönetim Sistemi (SWITCH-CASE Zorunlu)
        switch (komut) {
            case 'A':
            case 'a':
                avlan(); // Avlan (enerji azalır, yemek kazanma ihtimali IF ile değerlendirilir)
                break;
            case 'S':
            case 's':
                siginak_ara(); // Sığınak ara (başarı ihtimali mantıksal operatörlerle değerlendirilir)
                break;
            case 'R':
            case 'r':
                dinlen(); // Dinlen (enerji artışı, sağlık kontrolü)
                break;
            case 'E':
            case 'e':
                printf("\n--- ENVANTER ---");
                // envanteri_goster() zaten döngü başında çağrılıyor
                break;
            case 'F':
            case 'f':
                tehlike_dalgasi(); // Bölgedeki tehlike serisini FOR döngüsü ile simüle et
                break;
            case 'P':
            case 'p':
                sifreli_ilerleme(); // Şifreli ilerleme (DO-WHILE doğrulama döngüsü ile engeli aşma)
                break;
            case 'X':
            case 'x':
                printf("\nSimulasyondan cikiliyor...\n");
                break;
            default:
                printf("\nGecersiz komut. Lutfen gecerli bir karakter girin (A, S, R, E, F, P, X).\n");
                break;
        }
    } while (komut != 'X' && komut != 'x'); // Çıkış komutu verilmediği sürece devam et

    return 0;
}

// Durumları gösterir
void envanteri_goster() {
    printf("\n--------------------- DURUM ----------------------------\n");
    printf("Saglik: %d/100 | Enerji: %d/100 | Yemek: %d | Siginak: %s\n", 
           saglik, enerji, yemek_sayisi, siginak_durumu ? "VAR" : "YOK");
}

// Karakterin hayatta olup olmadığını kontrol eder
int karakter_oldu_mu() {
    if (saglik <= 0) {
        saglik = 0;
        return 1;
    }
    // Enerji biterse ve yemek yoksa sağlık kaybetme mantığı
    if (enerji <= 0 && yemek_sayisi == 0) {
        printf("Enerjiniz ve yiyeceginiz kalmadi. Cok yorgunluktan saglik kaybediyorsunuz.\n");
        saglik -= 5; // Aritmetik Operatör
    }
    return 0;
}

// A: Avlanma İşlemi
void avlan() {
    int sans = rand() % 100;
    
    // Enerji kaybı (Aritmetik Operatör)
    enerji -= 15;
    printf("\nAvlaniyorsunuz... 15 Enerji harcandi.\n");

    // Yemek bulma veya yaralanma şansı (IF-ELSE ve Mantıksal Operatörler)
    if ((sans < 60) && (enerji > 0)) { // %60 şans VE enerji pozitifse (Başarı)
        int kazanilan_yemek = (rand() % 3) + 1;
        yemek_sayisi += kazanilan_yemek; // Aritmetik Operatör
        printf("Basarili av! %d yemek kazandiniz.\n", kazanilan_yemek);
    } else if (sans < 90 || saglik < 50) { // %30 şans VEYA sağlık düşükse (Kısmi Başarı/Risk)
        printf("Bir seyler bulamadiniz, ama geri cekilmeyi basardiniz.\n");
    } else { // %10 şans (Başarısızlık/Yaralanma)
        int hasar = (rand() % 10) + 5;
        saglik -= hasar; // Aritmetik Operatör
        printf("Avlanirken yaralandiniz! -%d Saglik kaybettiniz.\n", hasar);
    }
    
    // Sınır kontrolü
    if (enerji < 0) enerji = 0;
}

// S: Sığınak Arama İşlemi
void siginak_ara() {
    if (siginak_durumu == 1) {
        printf("\nZaten bir siginaginiz var.\n");
        return;
    }

    int arama_sans = rand() % 100;
    
    // Sığınak bulma ihtimali (IF-ELSE yapısı ile farklı koşullar değerlendirilir)
    if (arama_sans < 40) {
        printf("\nUzun sure aradiniz ama guvenli bir yer bulamadiniz.\n");
        enerji -= 5; // Aritmetik Operatör
    } else if (arama_sans < 80 && yemek_sayisi > 0) { // Yiyecek varsa şans artar
        printf("\nBiraz yemek harcayarak guvenli bir magara buldunuz.\n");
        yemek_sayisi--; // Aritmetik Operatör
        siginak_durumu = 1; 
    } else { // Yüksek şans
        printf("\nHarika! Kendinizi guvende hissettiginiz bir siginak buldunuz!\n");
        siginak_durumu = 1;
    }
    
    // Sınır kontrolü
    if (enerji < 0) enerji = 0;
}

// R: Dinlenme İşlemi
void dinlen() {
    if (siginak_durumu == 0) {
        printf("\nSiginak olmadan dinlenmek zor. Sadece az miktarda toparlanabildiniz.\n");
        enerji += 5; 
        saglik += 2; 
    } else {
        printf("\nSiginaginizda guvenle dinleniyorsunuz.\n");
        enerji += 15; // Aritmetik Operatör
        saglik += 10; // Aritmetik Operatör
    }
    
    // Yemek tüketimi ve sağlık kontrolü
    if (yemek_sayisi > 0) {
        yemek_sayisi--; // Aritmetik Operatör
        printf("Dinlenirken 1 yemek tuketildi.\n");
    } else {
        saglik -= 5; 
        printf("Yemeginiz yok! Sagliginiz azaldi (-5).\n");
    }
    
    // Max değer kontrolü (IF-ELSE ile)
    if (enerji > 100) enerji = 100;
    if (saglik > 100) saglik = 100;
    if (saglik < 0) saglik = 0;
}

// F: Tehlike Dalgası Simülasyonu
void tehlike_dalgasi() {
    int dalga_boyutu = 5;
    printf("\n--- TEHLIKE BASLADI! %d TURLUK SALDIRI. ---\n", dalga_boyutu);

    // FOR Döngüsü: Belirli sayıda tur için simülasyon (Zorunlu Döngü)
    for (int tur = 1; tur <= dalga_boyutu; tur++) {
        if (karakter_oldu_mu()) break;
        
        printf("  [Tur %d]: ", tur);
        int hasar_sans = rand() % 100;
        int temel_hasar = (rand() % 8) + 3; // 3-10 arası temel hasar
        
        if (siginak_durumu == 1) {
            temel_hasar /= 2; // Siginak hasarı azaltır (Aritmetik Operatör)
            printf("Siginak korumasi hasari azaltti. ");
        }

        // Oyuncunun durumuna göre sonuçlar (IF-ELSE)
        if (hasar_sans < 70) { 
            saglik -= temel_hasar; // Aritmetik Operatör
            printf("Bir darbe aldiniz! -%d Saglik kaybi. ", temel_hasar);
        } else if (enerji >= 20) {
            enerji -= 10; // Aritmetik Operatör
            printf("Hizlica kacarak atlatmayi basardiniz! -10 Enerji harcandi. ");
        } else {
            saglik -= (temel_hasar + 5); 
            printf("Kacacak enerjiniz yoktu! Agir darbe aldiniz! -%d Saglik kaybi. ", temel_hasar + 5);
        }
    }
    
    printf("\n--- TEHLIKE DALGASI SONA ERDI. ---\n");
    if (saglik < 0) saglik = 0;
    if (enerji < 0) enerji = 0;
}

// P: Şifreli İlerleme Mekanizması
void sifreli_ilerleme() {
    char dogru_sifre = 'Z'; 
    char girilen_sifre;
    
    printf("\nBir engeli asmaniz gerekiyor. Anahtar karakteri 'Z'.\n");
    
    // DO-WHILE Döngüsü: Doğru karakteri girene kadar engeli aşma (Zorunlu Döngü)
    do {
        printf("Anahtar karakteri giriniz (Cikmak icin '0'): ");
        scanf(" %c", &girilen_sifre);
        
        if (girilen_sifre == '0') {
            printf("Ilerleme iptal edildi.\n");
            return;
        }

        // Doğrulama (IF-ELSE)
        if (girilen_sifre == dogru_sifre) {
            printf("!!! ENGEL ASILDI !!! Yeni bir bolgeye ulastiniz.\n");
            enerji += 5; // Aritmetik Operatör
            break; // Döngüden çık
        } else {
            printf("Yanlis karakter. Tekrar deneyin.\n");
            enerji -= 5; // Aritmetik Operatör
            if (enerji < 0) enerji = 0;
        }
    } while (girilen_sifre != dogru_sifre); 
}