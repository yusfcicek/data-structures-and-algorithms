#include <iostream>
#include <string>
#include <chrono>
using namespace std;
struct info {
    string isim;
    int sayi;
};
struct dugum {
    string veri;
    struct dugum* onceki;
    struct dugum* sonraki;
};
struct dugum2 {
    info bilgi;
    struct dugum2* onceki;
    struct dugum2* sonraki;
};
class list {
public:
    dugum* bas;
    dugum* son;
    list() {
        bas = NULL;
        son = NULL;
    }
};
class liste2 {
public:
    dugum2* bas;
    dugum2* son;
    liste2() {
        bas = NULL;
        son = NULL;
    }
};
list liste = list();
list dizi = list();
liste2 linkedlist = liste2();
void linkedlist_basaakle(string kelime, int adet) {
    dugum2* gecici = new dugum2;
    gecici->bilgi.isim = kelime;
    gecici->bilgi.sayi = adet;
    if (linkedlist.bas == NULL) {
        gecici->sonraki = NULL;
        gecici->onceki = NULL;
        linkedlist.bas = gecici;
        linkedlist.son = gecici;
    }
    else {
        gecici->sonraki = linkedlist.bas;
        gecici->onceki = NULL;
        linkedlist.bas->onceki = gecici;
        linkedlist.bas = gecici;
    }
}
void linkedlist_sonaekle(string kelime, int adet) {
    dugum2* gecici = new dugum2;
    gecici->bilgi.isim = kelime;
    gecici->bilgi.sayi = adet;
    gecici->sonraki = NULL;
    gecici->onceki = linkedlist.son;
    linkedlist.son->sonraki = gecici;
    linkedlist.son = gecici;
}
void linkedlist_arayaekle(string kelime, int adet) {
    if (adet >= linkedlist.bas->bilgi.sayi) {
        linkedlist_basaakle(kelime, adet);
    }
    else if (adet <= linkedlist.son->bilgi.sayi) {
        linkedlist_sonaekle(kelime, adet);
    }
    else {
        dugum2* gecici = new dugum2;
        dugum2* bu = new dugum2;
        dugum2* temp = new dugum2;
        gecici = linkedlist.bas;
        while (gecici->bilgi.sayi >= adet) {
            bu = gecici;
            gecici = gecici->sonraki;
        }
        temp->bilgi.isim = kelime;
        temp->bilgi.sayi = adet;
        temp->onceki = bu;
        temp->sonraki = gecici;
        bu->sonraki = temp;
        gecici->onceki = temp;
    }
}
void linkedlist_olustur() {
    linkedlist.bas = NULL;
    linkedlist.son = NULL;
    struct dugum* temp;
    int counter = 1;
    int cntr = 0;
    temp = dizi.bas;
    while (temp != NULL) {
        if (temp->sonraki == NULL) {
            linkedlist_arayaekle(temp->veri, counter);
            break;
        }
        else if (temp->veri == temp->sonraki->veri) {
            counter++;
            temp = temp->sonraki;
            continue;
        }
        else {
            if (cntr == 0) {
                linkedlist_basaakle(temp->veri, counter);
                cntr = 1;
            }
            else {
                linkedlist_arayaekle(temp->veri, counter);
            }
            counter = 1;
            temp = temp->sonraki;
        }
    }
}
void adetegore_say() {
    struct dugum2* temp;
    temp = linkedlist.bas;
    while (temp != NULL) {
        cout << temp->bilgi.isim << " -> " << temp->bilgi.sayi << endl;
        temp = temp->sonraki;
    }
}
void dizi_basaakle(string kelime) {
    dugum* gecici = new dugum;
    gecici->veri = kelime;
    if (dizi.bas == NULL) {
        gecici->sonraki = NULL;
        gecici->onceki = NULL;
        dizi.bas = gecici;
        dizi.son = gecici;
    }
    else {
        gecici->sonraki = dizi.bas;
        gecici->onceki = NULL;
        dizi.bas->onceki = gecici;
        dizi.bas = gecici;
    }
}
void dizi_sonaekle(string kelime) {
    dugum* gecici = new dugum;
    gecici->veri = kelime;
    gecici->sonraki = NULL;
    gecici->onceki = dizi.son;
    dizi.son->sonraki = gecici;
    dizi.son = gecici;
}
void dizi_arayaekle(string kelime) {
    if (kelime <= dizi.bas->veri) {
        dizi_basaakle(kelime);
    }
    else if (kelime >= dizi.son->veri) {
        dizi_sonaekle(kelime);
    }
    else {
        dugum* gecici = new dugum;
        dugum* bu = new dugum;
        dugum* temp = new dugum;
        gecici = dizi.bas;
        while (gecici->veri <= kelime) {
            bu = gecici;
            gecici = gecici->sonraki;
        }
        temp->veri = kelime;
        temp->onceki = bu;
        temp->sonraki = gecici;
        bu->sonraki = temp;
        gecici->onceki = temp;
    }
}
void dizi_olustur() {
    dizi.bas = NULL;
    dizi.son = NULL;
    dugum* ptr = new dugum;
    ptr = liste.bas;
    dizi_basaakle(ptr->veri);
    ptr = ptr->sonraki;
    while (ptr != liste.bas) {
        dizi_arayaekle(ptr->veri);
        ptr = ptr->sonraki;
    }
}
void dizi_listele() {
    dugum* ptr = new dugum;
    ptr = dizi.bas;
    while (ptr != dizi.son) {
        cout << ptr->veri << " ";
        ptr = ptr->sonraki;
    }
    cout << dizi.son->veri;
}
void alfabetik_say() {
    struct dugum* temp;
    int counter = 1;
    temp = dizi.bas;
    while (temp != NULL) {
        if (temp->sonraki == NULL) {
            cout << temp->veri << " -> " << counter << '\n';
            break;
        }
        else if (temp->veri == temp->sonraki->veri) {
            counter++;
            temp = temp->sonraki;
            continue;
        }
        else {
            cout << temp->veri << " -> " << counter << '\n';
            counter = 1;
            temp = temp->sonraki;
        }
    }
}
void tekil_say() {
    struct dugum* temp;
    int counter = 1;
    temp = dizi.bas;
    while (temp != NULL) {
        if (temp->sonraki == NULL) {
            break;
        }
        else if (temp->veri == temp->sonraki->veri) {
            temp = temp->sonraki;
            continue;
        }
        else {
            counter++;
            temp = temp->sonraki;
        }
    }
    cout << "\nMetindeki tekil kelime (farkli) sayisi: " << counter;
}
void son_guncelle() {
    struct dugum* ptr;
    ptr = liste.bas;
    do {
        liste.son = ptr;
        ptr = ptr->sonraki;
    } while (ptr != liste.bas);
}
void basa_ekle(string kelime) {
    dugum* gecici = new dugum;
    gecici->veri = kelime;
    if (liste.bas == NULL) {
        gecici->onceki = gecici;
        gecici->sonraki = gecici;
        liste.bas = gecici;
        liste.son = gecici;
    }
    else {
        gecici->onceki = liste.son;
        gecici->sonraki = liste.bas;
        liste.bas->onceki = gecici;
        liste.bas = gecici;
        liste.son->sonraki = liste.bas;
    }
}
void sona_ekle(string kelime) {
    dugum* gecici = new dugum;
    gecici->veri = kelime;
    if (liste.son == NULL) {
        gecici->onceki = gecici;
        gecici->sonraki = gecici;
        liste.bas = gecici;
        liste.son = gecici;
    }
    else {
        gecici->onceki = liste.son;
        gecici->sonraki = liste.bas;
        liste.son->sonraki = gecici;
        liste.son = gecici;
        liste.bas->onceki = liste.son;
    }
}
void bas_sil() {
    dugum* gecici = new dugum;
    gecici = liste.bas;
    liste.bas = liste.bas->sonraki;
    liste.son->sonraki = liste.bas;
    liste.bas->onceki = liste.son;
    //delete gecici;
    son_guncelle();
}
void son_sil() {
    dugum* gecici = new dugum;
    gecici = liste.son;
    liste.son = liste.son->onceki;
    liste.son->sonraki = liste.bas;
    liste.bas->onceki = liste.son;
    //delete gecici;
    son_guncelle();
}
void listele() {
    if (liste.bas == NULL)
        cout << "Kayit Yok!" << endl;
    else {
        dugum* ptr = new dugum;
        ptr = liste.bas;
        do {
            cout << ptr->veri << " ";
            ptr = ptr->sonraki;
        } while (ptr != liste.bas);
    }
}
void kelime_say() {
    int say = 0;
    struct dugum* bu;
    bu = liste.bas;
    do {
        say++;
        bu = bu->sonraki;
    } while (bu != liste.bas);
    cout << "\nMetindeki toplam kelime sayisi: " << say << endl;
}
void kelimelere_ayirma(string metin) {
    liste.bas = NULL;
    liste.son = NULL;
    int son = 0;
    string kelime;
    metin = metin + " ";
    for (int i = 0; i < metin.length(); i++) {
        if (metin[i] == ' ') {
            kelime = "";
            for (int j = son; j < i; j++) {
                kelime += metin[j];
            }
            son = i + 1;
            sona_ekle(kelime);
        }
    }
}
void kelime_arama(string kelime) {
    dugum* ptr = new dugum;
    int sayac = 0;
    ptr = liste.bas;
    cout << "Bulunan Konumlar :";
    do {
        sayac++;
        if (ptr->veri == kelime) {
            cout << " -" << sayac << "-";
        }
        ptr = ptr->sonraki;
    } while (ptr != liste.bas);
}
void kelime_degistir(string kelime, string aranan) {
    int sayac = 0;
    dugum* ptr = new dugum;
    ptr = liste.bas;
    do {
        if (aranan == ptr->veri) {
            ptr->veri = kelime;
        }
        ptr = ptr->sonraki;
    } while (ptr != liste.bas);
    cout << "\nMetinin Yeni Hali : ";
    listele();
}
void kelime_sil(string kelime) {
    dugum* ptr = new dugum;
    ptr = liste.bas;
    while (ptr != liste.son) {
        if (kelime == liste.bas->veri) {
            bas_sil();
        }
        else if (kelime == ptr->veri) {
            ptr->onceki->sonraki = ptr->sonraki;
            ptr->sonraki->onceki = ptr->onceki;
        }
        else if (kelime == liste.son->veri) {
            son_sil();
        }
        ptr = ptr->sonraki;
    }
    cout << "\nMetinin yeni hali : ";
    listele();
}
int main() {
    string metin, secim, strara, strsil, strdeg, straranan, choose;
    while (true) {
        cout << "\n1)Metin Girme \n";
        cout << "2)Kelime Sayma \n";
        cout << "3)Kelime Listeleme \n";
        cout << "4)Kelime Arama \n";
        cout << "5)Kelime Silme \n";
        cout << "6)Kelime Degistirme \n";
        cout << "7)Cikis \n";
        cout << "Islem : ";
        cin >> secim;
        if (secim == "1") {
            cout << "\nLutfen bir metin giriniz : ";
            cin.ignore();
            getline(cin, metin);
            auto start = std::chrono::high_resolution_clock::now();
            kelimelere_ayirma(metin);
            auto finish = std::chrono::high_resolution_clock::now();;
            cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
        }
        else if (secim == "2") {
            auto start = std::chrono::high_resolution_clock::now();
            dizi_olustur();
            linkedlist_olustur();
            kelime_say();
            tekil_say();
            auto finish = std::chrono::high_resolution_clock::now();;
            cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
        }
        else if (secim == "3") {
            auto start = std::chrono::high_resolution_clock::now();
            dizi_olustur();
            linkedlist_olustur();
            auto finish = std::chrono::high_resolution_clock::now();;
            cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
            while (true) {
                cout << "Alfabetik Siralama icin 8 " << endl;
                cout << "Adede Gore Siralama icin 9 " << endl;
                cout << "Cikis icin herhangi bir tusa basiniz " << endl;
                cout << "Secim : ";
                cin >> choose;
                cout << endl;
                if (choose == "8") {
                    auto start = std::chrono::high_resolution_clock::now();
                    alfabetik_say();
                    auto finish = std::chrono::high_resolution_clock::now();;
                    cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
                }
                else if (choose == "9") {
                    auto start = std::chrono::high_resolution_clock::now();
                    adetegore_say();
                    auto finish = std::chrono::high_resolution_clock::now();;
                    cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
                }
                else {
                    break;
                }
            }
        }
        else if (secim == "4") {
            cout << "\nAranacak Kelimeyi Giriniz : ";
            cin >> strara;
            auto start = std::chrono::high_resolution_clock::now();
            kelime_arama(strara);
            auto finish = std::chrono::high_resolution_clock::now();;
            cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
        }
        else if (secim == "5") {
            cout << "\nSilinecek Kelimeyi Giriniz : ";
            cin >> strsil;
            auto start = std::chrono::high_resolution_clock::now();
            kelime_sil(strsil);
            auto finish = std::chrono::high_resolution_clock::now();;
            cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
        }
        else if (secim == "6") {
            cout << "\nYeni Kelimeyi ve Degistirmek Istediginiz Kelimeyi Bosluk Birakarak Giriniz : ";
            cin >> strdeg >> straranan;
            auto start = std::chrono::high_resolution_clock::now();
            kelime_degistir(strdeg, straranan);
            auto finish = std::chrono::high_resolution_clock::now();;
            cout << endl << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
        }
        else if (secim == "7") {
            cout << "\nUygulamadan Cikis Yapiliyor\n";
            break;
        }
        else {
            cout << "\nHatali Secim Yaptiniz ";
            cout << "\nCikis icin 7 tusuna basiniz \n";
            continue;
        }
    }
}