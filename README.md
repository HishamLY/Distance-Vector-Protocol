# Tugas Besar 2 IF 3130 Jaringan Komputer
## Distance Vector Simulation
#### Kelompok Pertamax - K03
##### 13515030 - Rizki Elzandy Barik
##### 13515069 - Hisham Lazuardi Yusuf
##### 13515120 - Azis Adi Kuncoro

## A. Petunjuk penggunaan program.

Untuk menjalankan program **Distance Vector Simulation** ini cukup ketikkan command `make` pada terminal atau konsol.

## B. Bagaimana anda mensimulasikan sebuah node dalam program anda?
Mula-mula, setiap *node* akan memiliki atribut berupa *distance* dan *nextHop* yang diinisialisasi dengan nilai -1. Kemudian informasi dari tiap *node* yang behubungan disimpan dalam sebuah *adjacency matrix* yang diinisialisasi saat awal program dijalankan. Kemudian *node* yang berhubungan akan memiliki *cell* yang bernilai 1. Jika tidak, maka akan bernilai 0.

Setelah *adjacency matrix* terbentuk, semua nilai disimpan dalam *routing table* yang dimiliki oleh tiap *node* yang disimpan dalam sebuah *array*. *Routing table* akan menyimpan jumlah *node* yang terdapat pada graf dan informasi mengenai jarak	menuju *node* lain terhadap suatu *node* dan *nextHop* yang diperlukan untuk mencapai *node* lain tersebut

## C. Bagaimana proses pengiriman pesan antar node terjadi?
Pada saat pengiriman pesan, program akan melakukan *update* informasi pada *routing table* milik *node* yang dituju. Program hanya melakukan *update* informasi pada *routing table* suatu *node* jika *node* tujuan dapat dicapai atau terhubung secara langsung dari *node* asal menurut routing table *node* tersebut. Program juga hanya mengupdate baris dari *routing table node* tujuan jika jarak pada *node tujuan* menuju *node* ke-i masih -1 (tak terhingga) atau lebih besar dari jarak *node* asal menuju *node* tujuan menurut *routing table node* tujuan ditambah jarak *node* tujuan menuju *node* ke-i.

## D. Pembagian tugas.

1. 13515030 :

2. 13515069 :

3. 13515120 :

## E. Pertanyaan
#### 1. Apakah perbedaan dari *routing protocol distance-vector* dan *link state*? Manakah yang lebih baik untuk digunakan?
Pada *distance-vector protocol* suatu *node* hanya mengetahui informasi mengenai *node* tetangga yang berhubungan langsung dan hanya menyimpan informasi mengenai *router nextHop* untuk menuju suatu *node*. Sedangkan, pada *link-state routing protocol* suatu *node* harus mengetahui rute yang dapat digunakan untuk mencapai semua *node* di dalam suatu jaringan dan menyimpan informasi mengenai semua *node* di dalam jaringan dalam bentuk graf. Sehingga, informasi pada *node* lain dimiliki oleh *node* tersebut. Penentuan jarak optimal dari *distance-vector protocol* menggunakan algoritma **Bellmann-Ford**, sedangkan *link-state protocol* menggunakan algoritma **Dijkstra**.
Algoritma *routing protocol* yang lebih baik untuk digunakan tergantung dari kebutuhan dan scope jaringan yang tersedia, tetapi secara keseluruhan **Link State Protocol**  lebih baik untuk digunakan. Penjelasan ada di bagian selanjutnya.

#### 2. Pada implementasinya saat ini manakah yang lebih banyak digunakan, *distance-vector* atau *link state*? Kenapa?
*Link state protocol* lebih banyak digunakan karena lebih cepat dalam menghasilkan *path* optimal dan lebih efektif dibanding *distance-vector protocol* yang rawan terhadap *count-to-infinity problem*, di mana *packet* mengalami *routing loop* (*packet* berputar antara router-router antara dan tidak mencapai tujuannya)
