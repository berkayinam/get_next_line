# get_next_line

42 okulunun dosya okuma projesi olan get_next_line, bir dosyadan satır satır okuma yapan bir fonksiyon geliştirmeyi amaçlamaktadır.
Just Read And Write, remember -> Think Ezz
125/100 My Grade

## 📚 Proje Hakkında

get_next_line projesi, bir dosya tanımlayıcısından (file descriptor) her çağrıldığında bir satır okuyan bir fonksiyon oluşturmayı hedeflemektedir. Bu proje, statik değişkenler, dosya işlemleri ve bellek yönetimi konularında deneyim kazandırmayı amaçlar.

## 💻 Teknolojiler

- C Programlama Dili
- File Descriptors
- Statik Değişkenler
- Bellek Yönetimi

## 🛠️ Kurulum

### Gereksinimler
- GCC Derleyici
- Make
- Unix-tabanlı İşletim Sistemi

### Derleme
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## 📝 Fonksiyon Prototipi

```c
char *get_next_line(int fd);
```

### Parametreler
- fd: Okunacak dosyanın file descriptor'ı

### Dönüş Değeri
- Başarı durumunda: Okunan satır
- Okuma bittiğinde: NULL
- Hata durumunda: NULL

## 🎯 42 Proje Gereksinimleri

### Zorunlu Kısım
- [x] Tekrarlı çağrılarda dosyadan sırayla satır okuma
- [x] Doğru bellek yönetimi (sızıntı olmamalı)
- [x] BUFFER_SIZE ile çalışabilme
- [x] Tek bir statik değişken kullanımı
- [x] Standart fonksiyonlar: read, malloc, free

### Bonus Kısım
- [x] Tek bir statik değişken ile birden fazla fd yönetimi
- [x] get_next_line_bonus.c ve get_next_line_bonus.h

## 📚 Kod Örnekleri

### Ana Fonksiyon
```c
char *get_next_line(int fd)
{
    static char *buffer;
    char        *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_to_buffer(fd, buffer);
    if (!buffer)
        return (NULL);
    line = extract_line(buffer);
    buffer = update_buffer(buffer);
    return (line);
}
```

### Yardımcı Fonksiyonlar
```c
char *read_to_buffer(int fd, char *buffer)
{
    char    *temp;
    int     bytes_read;

    temp = malloc(BUFFER_SIZE + 1);
    if (!temp)
        return (NULL);
    bytes_read = read(fd, temp, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        free(temp);
        return (NULL);
    }
    temp[bytes_read] = '\0';
    buffer = ft_strjoin(buffer, temp);
    free(temp);
    return (buffer);
}
```

## 🔍 Test Senaryoları

### Temel Testler
```c
int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Farklı BUFFER_SIZE Testleri
```bash
gcc -D BUFFER_SIZE=1 ...
gcc -D BUFFER_SIZE=42 ...
gcc -D BUFFER_SIZE=9999 ...
```

## 🐛 Hata Ayıklama

### Yaygın Hatalar
1. Bellek Sızıntıları
   - Buffer yönetimi
   - Satır çıkarma işlemi
   - Free kullanımı

2. Okuma Hataları
   - EOF kontrolü
   - BUFFER_SIZE kontrolü
   - File descriptor kontrolü

## 📈 Optimizasyon İpuçları

1. Buffer Yönetimi
   - Gereksiz okuma işlemlerinden kaçınma
   - Buffer boyutu optimizasyonu
   - Bellek kopyalama işlemlerini minimize etme

2. Performans
   - Dosya okuma stratejisi
   - String işlemlerini optimize etme
   - Bellek tahsisi optimizasyonu

## 🔒 Güvenlik Kontrolleri

1. Giriş Doğrulama
   - Geçerli file descriptor
   - Pozitif BUFFER_SIZE
   - Okuma izinleri

2. Bellek Güvenliği
   - NULL pointer kontrolleri
   - Buffer taşması kontrolü
   - Bellek sızıntısı kontrolü

## 📝 Lisans

Bu proje [MIT](LICENSE) lisansı altında lisanslanmıştır.

## 📚 Kaynaklar

- [File Descriptor](https://en.wikipedia.org/wiki/File_descriptor)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
- [42 Docs](https://harm-smits.github.io/42docs/)

---

⭐️ Bu projeyi beğendiyseniz yıldız vermeyi unutmayın!

