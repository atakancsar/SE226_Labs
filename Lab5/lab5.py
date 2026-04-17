# ==========================================
# SORU 1: Özyineli (Recursive) Faktöriyel
# ==========================================
def factorial(x):
    if x == 0 or x == 1:
        return 1
    return x * factorial(x - 1)


# ==========================================
# SORU 2: S Serisinin Hesaplanması
# ==========================================
# Tek bir terimin mutlak değerini hesaplayan lambda fonksiyonu
term_abs = lambda x, i: (x ** (2 * i)) / factorial(2 * i)

def exp_x(x, n):
    total = 0
    for i in range(n):
        # İşaret (sign) mantığı: i çift ise pozitif, tek ise negatif (-1)^i
        sign = 1 if i % 2 == 0 else -1
        # Terimi toplama ekle
        total += sign * term_abs(x, i)
    return total

print("--- Soru 2 İçin Girişler ---")
x_val = float(input("Lütfen x değerini girin: "))
n_val = int(input("Lütfen n değerini girin: "))
print(f"S Denklemi Sonucu: {exp_x(x_val, n_val)}\n")


# ==========================================
# SORU 3: G Denkleminin Global Değişkenle Hesaplanması
# ==========================================
G_total = 0.0  # Global değişken

def calculate_G(n, r):
    """
    Bu fonksiyon G_n = 1 + r + r^2 + ... + r^n geometrik serisini özyineli olarak hesaplar.
    
    Özyineli Mantık (Recursive Logic):
    Fonksiyon n değerini her adımda 1 azaltarak kendisini çağırır. Temel durum (base case) 
    n == 0 anıdır. Her özyineli adımda hesaplanan r^n değeri global 'G_total' değişkenine eklenir.
    
    İşaret İşleme (Sign Handling):
    Bu serinin tüm terimleri toplama işlemine dayalı olduğu için (artı işaretli), 
    alternatif bir işaret mantığına (-1^i gibi) ihtiyaç duyulmaz; tüm terimler pozitiftir.
    """
    global G_total
    
    if n == 0:
        G_total += 1.0  # r^0 = 1
    else:
        G_total += (r ** n)
        calculate_G(n - 1, r)

print("--- Soru 3 İçin Girişler ---")
n_g_val = int(input("Lütfen n değerini (terim sayısı) girin: "))
r_val = float(input("Lütfen r değerini (ortak çarpan) girin: "))

# Fonksiyon hiçbir değer döndürmez, global değişkeni günceller
calculate_G(n_g_val, r_val)
print(f"G Denklemi Sonucu (Global Değişken): {G_total}")