<h1 align="center">Laporan Praktikum Modul Dasar-Dasar Python untuk Sains Data</h1>
<p align="center">Abdul Munib</p>
Dasar Teori
Tugas ini, membahas berbagai konsep dasar pemrograman menggunakan Python. Praktikum ini dirancang untuk melatih kemampuan dalam membuat fungsi, kelas, serta memecahkan masalah algoritma seperti bilangan prima, pengurutan list, ATM simulator, serta operasi lainnya. Setiap tugas atau guided memberikan pengalaman dalam menyelesaikan masalah menggunakan pendekatan terstruktur.

Guided
1. Pola Bilangan Prima
Pada guided ini, pola angka prima dibentuk berdasarkan jumlah baris yang diberikan. Fungsi is_prime digunakan untuk memeriksa apakah sebuah angka adalah bilangan prima, dan generate_prime_pattern untuk menghasilkan pola.

python
```py
### Guided 1

def is_prime(n):
    """Fungsi untuk memeriksa apakah sebuah angka adalah bilangan prima."""
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def generate_prime_pattern(rows):
    """Fungsi untuk menghasilkan pola angka prima sesuai jumlah baris yang diinginkan."""
    primes = []
    num = 2  
    # Bilangan prima pertama
    
    while len(primes) < (rows * (rows + 1)) // 2:
        if is_prime(num):
            primes.append(num)
        num += 1
    
    index = 0
    for i in range(1, rows + 1):
        for j in range(i):
            print(primes[index], end=' ')
            index += 1
        print()

# Menghasilkan pola untuk 5 baris
generate_prime_pattern(5)

```
#### Output
![Screenshot 2024-09-24 023920](https://github.com/user-attachments/assets/4ca4b4b1-eb1c-4d95-b295-73de1eb59622)

2. Penggabungan dan Pengurutan Indeks Ganjil
Kode ini menggabungkan elemen dari indeks ganjil dari dua list dan mengurutkannya secara menurun.

```py
def merge_and_sort_odd_indices(list1, list2):
    result = [list1[i] for i in range(1, len(list1), 2)] + [list2[i] for i in range(1, len(list2), 2)]
    result.sort(reverse=True)
    return result

list1 = [10, 15, 20, 25, 30, 35]
list2 = [40, 45, 50, 55, 60, 65]
output = merge_and_sort_odd_indices(list1, list2)
print(output)
```
#### Output
![Screenshot 2024-09-24 023930](https://github.com/user-attachments/assets/a202d1f3-ff34-4967-bdc4-673e9e420710)


3. ATM Simulator
Simulasi ATM ini mencakup validasi PIN dan penarikan saldo, di mana PIN harus benar sebelum saldo dapat ditarik.

```py
class ATM:
    def __init__(self, saldo):
        self.saldo = saldo
        self.pin = "24434 50l4T C0"

    def validasi_pin(self):
        attempts = 3
        while attempts > 0:
            user_pin = input("Masukkan PIN: ")
            if user_pin == self.pin:
                print("PIN benar.\n")
                return True
            else:
                attempts -= 1
                print(f"PIN salah. Sisa percobaan: {attempts}\n")
        
        print("Akun terkunci.\n")
        return False
    
    def tarik_saldo(self, jumlah):
        if jumlah > self.saldo:
            print("Saldo tidak mencukupi.")
        else:
            self.saldo -= jumlah
            print(f"Penarikan berhasil! Sisa saldo: {self.saldo}")

    def mulai_transaksi(self):
        if self.validasi_pin():
            try:
                jumlah = int(input("Masukkan jumlah yang akan ditarik: "))
                self.tarik_saldo(jumlah)
            except ValueError:
                print("Input tidak valid.")

atm = ATM(saldo=1000000)
atm.mulai_transaksi()
```
#### Output
![Screenshot 2024-09-24 023938](https://github.com/user-attachments/assets/964f2607-c261-419a-ab01-b21d51b0192f)

4. Pengelolaan Nilai Mahasiswa dengan CSV
Menggunakan CSV untuk membaca dan menghitung nilai rata-rata serta menemukan mahasiswa dengan nilai tertinggi dan terendah.

```py
import csv

def read_csv_to_dict(filename):
    data = {}
    with open(filename, mode='r') as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            nama = row[0]
            nilai = list(map(float, row[1:]))
            data[nama] = nilai
    return data

def calculate_average(data):
    averages = {}
    for nama, nilai in data.items():
        if nilai:
            averages[nama] = sum(nilai) / len(nilai)
        else:
            averages[nama] = 0
    return averages

def find_highest_lowest(averages):
    highest = max(averages, key=averages.get)
    lowest = min(averages, key=averages.get)
    return highest, lowest

def main():
    filename = r'C:\Users\jamet\Downloads\nilai.csv'
    data = read_csv_to_dict(filename)
    averages = calculate_average(data)

    highest, lowest = find_highest_lowest(averages)

    print("Rata-rata nilai mahasiswa:")
    for nama, avg in averages.items():
        print(f"{nama}: {avg:.2f}")

    print(f"Mahasiswa dengan nilai tertinggi: {highest} ({averages[highest]:.2f})")
    print(f"Mahasiswa dengan nilai terendah: {lowest} ({averages[lowest]:.2f})")

if __name__ == "__main__":
    main()
```
#### Output
![Screenshot 2024-09-24 023950](https://github.com/user-attachments/assets/91db1955-dc06-46b8-9aa3-a86065d4bd88)

5. Game Tebak Angka
Game ini meminta pengguna untuk menebak angka antara 1 dan 100 dalam beberapa percobaan.

```py
import random

def tebak_angka():
    angka_rahasia = random.randint(1, 100)
    percobaan = 5

    print("Selamat datang di permainan Tebak Angka!")
    for i in range(percobaan):
        tebakan = int(input(f"Tebakan ke-{i+1}: "))
        if tebakan == angka_rahasia:
            print(f"Selamat! Kamu berhasil menebak angka {angka_rahasia} dengan benar!")
            break
        elif tebakan < angka_rahasia:
            print("Tebakanmu terlalu kecil.")
        else:
            print("Tebakanmu terlalu besar.")

        if i == percobaan - 1:
            print(f"Sayang sekali! Angka yang benar adalah {angka_rahasia}.")

if __name__ == "__main__":
    tebak_angka()
```
#### Output
![Screenshot 2024-09-24 024000](https://github.com/user-attachments/assets/900db2e5-c119-4262-8a1b-cb2e60c6c787)

6. Menghitung Faktorial dan Daftar Faktorial
Kode ini menggunakan rekursi untuk menghitung faktorial dari sebuah angka dan menampilkan hasilnya dalam bentuk list.

```py
def faktorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * faktorial(n - 1)

def urutan_faktorial(n, current=1, result=None):
    if result is None:
        result = []

    if current > n:
        return result

    result.append(faktorial(current))
    return urutan_faktorial(n, current + 1, result)

if __name__ == "__main__":
    n = 4
    hasil = urutan_faktorial(n)
    print(hasil)

```
#### Output
![Screenshot 2024-09-24 024007](https://github.com/user-attachments/assets/f50eda73-97a0-46d7-9867-160a011c72d3)

7. Minimum Coin Change
Menghitung kombinasi minimum koin untuk mencapai jumlah tertentu.

```py
def minimum_coin_change(total_amount, coins):
    coins.sort(reverse=True)
    coin_count = []
    
    for coin in coins:
        count = total_amount // coin
        if count > 0:
            coin_count.append((coin, count))
            total_amount -= coin * count
    
    if total_amount > 0:
        return None
    
    return coin_count

def main():
    total_amount = int(input("Masukkan jumlah uang: "))
    coins_input = input("Masukkan daftar nilai koin (pisahkan dengan spasi): ")
    coins = list(map(int, coins_input.split()))

    result = minimum_coin_change(total_amount, coins)
    
    if result is None:
        print("Tidak mungkin mencapai jumlah yang diminta dengan koin yang tersedia.")
    else:
        print("Kombinasi koin yang diperlukan:")
        for coin, count in result:
            print(f"Koin {coin}: {count} buah")

if __name__ == "__main__":
    main()

```
#### Output
![Screenshot 2024-09-24 024014](https://github.com/user-attachments/assets/7f1aaf7d-cf8e-4438-9247-00413ab78ad3)

8. Membalik Kata dalam Kalimat
Membalik setiap kata dalam sebuah kalimat.

```py
def reverse_words(input_string):
    words = input_string.split()
    reversed_words = [word[::-1] for word in words]
    return reversed_words

def main():
    input_string = input("Masukkan sebuah kalimat: ")
    result = reverse_words(input_string)
    print("Output:", result)

if __name__ == "__main__":
    main()

```
#### Output
![Screenshot 2024-09-24 024023](https://github.com/user-attachments/assets/5e283b20-d949-4457-8a1f-2e41b22256e8)

9. Informasi Buku
Kelas Buku ini digunakan untuk menyimpan informasi buku dan menghitung usianya.

```py
#Guided 9
class Buku:
    def __init__(self, judul, penulis, tahun_terbit):
        self.judul = judul
        self.penulis = penulis
        self.tahun_terbit = tahun_terbit

    def tampilkan_informasi(self):
        return f"Judul: {self.judul}, Penulis: {self.penulis}, Tahun Terbit: {self.tahun_terbit}"

    def hitung_usia(self, tahun_sekarang):
        return tahun_sekarang - self.tahun_terbit

def main():
    # Membuat objek Buku
    buku1 = Buku("Blender 3d modeling", "munib", 2020)
    buku2 = Buku("Sukses sebelum 25 tahun", "Budi", 2018)
    buku3 = Buku("Mengetahui daging segar", "sumanto", 2021)

    # Tahun saat ini
    tahun_sekarang = 2024

    # Menampilkan informasi dan usia setiap buku
    for buku in [buku1, buku2, buku3]:
        print(buku.tampilkan_informasi())
        print(f"Usia Buku: {buku.hitung_usia(tahun_sekarang)} tahun\n")

if __name__ == "__main__":
    main()

```
#### Output
![Screenshot 2024-09-24 024030](https://github.com/user-attachments/assets/c647512b-b68d-4b3f-936d-fbc8158dff48)
10. Menentukan KPK (Kelipatan Persekutuan Terkecil)
Menghitung KPK dari dua bilangan.

```py
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return abs(a * b) // gcd(a, b)

def main():
    a = int(input("Masukkan angka pertama: "))
    b = int(input("Masukkan angka kedua: "))
    hasil_kpk = lcm(a, b)
    print(f"KPK dari {a} dan {b} adalah {hasil_kpk}")

if __name__ == "__main__":
    main()

```
#### Output
![Screenshot 2024-09-24 024046](https://github.com/user-attachments/assets/212cee70-6796-47f2-80e0-6a4f8cf43af3)

Kesimpulan
Dari seluruh guided ini, kita mempelajari berbagai konsep pemrograman dasar dengan Python seperti penggunaan fungsi, kelas, manipulasi list, perulangan, dan rekursi. Setiap guided memberikan wawasan tentang bagaimana Python dapat digunakan untuk menyelesaikan masalah dalam berbagai konteks, dari game sederhana hingga operasi matematis dan simulasi.

Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.






