# Karakter Tabanlı Hayatta Kalma Simülatörü

**Kısa açıklama**
Bu proje, C dilinde yazılmış basit bir karakter tabanlı hayatta kalma simülatörüdür. Oyuncu; sağlık, enerji, yemek ve sığınak gibi kaynakları yöneterek farklı eylemler (avlanma, sığınak arama, dinlenme, tehlike dalgası vb.) gerçekleştirir. Amaç, karakterin hayatta kalmasını sağlamak ve mümkün olduğunca uzun süre dayanabilmektir.

---

## Özellikler

- Sağlık, enerji, yemek ve sığınak durumu gibi temel durum değişkenleri.
- Kullanıcı komutları ile etkileşimli oyun döngüsü.
- Rastgele olaylar (avlanma sonucu, tehlike dalgaları, sığınak bulma) için `rand()` kullanımı.
- Mantıksal ve aritmetik işleçler, döngüler (`for`, `do-while`) ve `switch-case` yapılarıyla örnek kontrollü akış.
- Basit hata/sınır kontrolleri (enerji ve sağlık sınırları).

---

## Kontroller (Komutlar)

- `A` / `a` : Avlan
- `S` / `s` : Sığınak Ara
- `R` / `r` : Dinlen
- `E` / `e` : Envanteri Göster (zaten döngü başında gösteriliyor)
- `F` / `f` : Tehlike Dalga Simülasyonu
- `P` / `p` : Şifreli İlerleme (anahtar karakter: `Z`)
- `X` / `x` : Çıkış

Komutlar büyük/küçük harf farketmez. `P` durumunda ilerlemeyi iptal etmek için `0` girilebilir.

---

## Dosyalar

- `main.c` — Oyunun ana kodu (bu dosyayı sağlanan kod olarak düşünebilirsiniz).

---

## Fonksiyon Açıklamaları

- `envanteri_goster()` : Güncel sağlık, enerji, yemek ve sığınak durumunu ekrana yazdırır.
- `karakter_oldu_mu()` : Sağlık veya enerji-yemek kombinasyonuna bağlı olarak karakterin ölüp ölmediğini kontrol eder.
- `avlan()` : Enerji tüketir; rastgele başarıya bağlı olarak yemek kazanma veya yaralanma ihtimali vardır.
- `siginak_ara()` : Sığınak bulma şansını hesaplar; sığınak bulunduğunda sığınak durumu güncellenir.
- `dinlen()` : Sığınakta veya açıkta dinlenmeye göre sağlık/enerji geri kazanımı sağlar; dinlenme sırasında yemek tüketilir.
- `tehlike_dalgasi()` : Bir dizi tur boyunca oyuncuya hasar veya kaçış şansı veren tehlike simülasyonu gerçekleştirir.
- `sifreli_ilerleme()` : Kullanıcıdan doğru anahtar karakter (`Z`) girilene kadar tekrar isteyen bir `do-while` doğrulama döngüsü.

---

## Derleme & Çalıştırma (Linux/macOS / Windows - MinGW)

Terminal / Komut İstemi üzerinden derlemek için:

```bash
# GCC ile derlemek
gcc -o hayatta_kal main.c
# Çalıştırmak
./hayatta_kal   # Windows'ta: hayatta_kal.exe
```

Not: Kod `time.h` ve `stdlib.h` kullanır; rastgele sayı üreteci için `srand(time(NULL));` mevcut. Her çalıştırmada farklı rastgelelik için zaman seed'lenir.

---

## Geliştirme Önerileri / İyileştirmeler

- Durumları ve olayları daha okunaklı hale getirmek için `struct` kullanarak oyuncu verilerini bir yapıda toplayın.
- Menü/komut girişleri yerine sayısal menü veya satır içi açıklama ekleyin.
- Oyun ilerledikçe zorluk artışı sağlayacak bir seviye sistemi ekleyin.
- Eşya/ölümler, envantere eşyalar ekleme, sığınak seviyeleri gibi mekanikler dahil edin.
- Kaydetme/yükleme (save/load) sistemi ile oyunu dosyaya kaydetme.
- Olasılıkları ve sayıları (enerji kaybı, hasar) sabitler (`#define`) veya config dosyasına taşıyın.

---

## Sınırlamalar / Bilinmesi Gerekenler

- Konsol tabanlı ve tek dosyalı basit örnek projedir; hata yakalama sınırlıdır.
- Girdi doğrulama yalnızca temel seviyededir (ör. `scanf` kullanımı beklenmeyen girişlerde problem çıkarabilir).

---

## Lisans

Bu proje eğitim amaçlıdır. İstediğiniz gibi kopyalayabilir, değiştirebilir ve kullanabilirsiniz. (Tercih ederseniz bir açık kaynak lisansı ekleyin — örneğin MIT.)

---

## İletişim

www.linkedin.com/in/muhammed-özbek-157405356

---

Teşekkürler — iyi oyunlar! 🎮
