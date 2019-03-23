/******************************************************/
/***************Ayrik Matematik Odev 3*****************/
/***************Muhammed Galib Uludag******************/
/**********************161002017***********************/
/******************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Obj //objeyi struct olarak olusturdum
{
    int price, weight;
    string sira;
};

Obj *best; //olasilik sayisi uzunlugunda en iyileri saklayacak dinamik dizi
int FonkMax(Obj best[], int *bag); //max fiyati bulan fonk
void knapsack (int n);
void all_sets (int n, int k, int a[], Obj nesne[], int mak, int *bag); //butun olasiliklari bulan fonk

void all_sets (int n, int k, int a[], Obj nesne[], int mak, int *bag)
{
    ostringstream str1;
    int i, sumweight = 0, sumprice = 0;

    if (k == n)
    {
        for (i = 0; i < n; i++) //burada en iyiyi bulurken her durumda cantaya alinan nesneleri de gosteriyor
        {
            if(a[i]==0)
                cout<<"   ";
            if (a[i]==1)
            {
                sumweight = sumweight + nesne[i].weight;
                sumprice = sumprice + nesne[i].price;
                cout<<"N"<<i+1<<" ";
                if (sumweight <= mak)
                {
                    best[i].price=sumprice;
                    best[i].weight=sumweight;
                    str1<<"N"<<i+1<<" ";
                    best[i].sira=str1.str();

                }
            }
        }
        cout<<"\tToplam Agirlik : "<<sumweight<<" kg";
        cout<<"\tToplam Fiyat: "<<sumprice<<" TL \tDurum: ";

        if (sumweight <= mak)
        {
            cout<<" sigiyor\n";
            *bag += 1;

        }
        else
        {
            cout<<" sigmiyor\n";
            *bag += 1;
        }
    }
    else
    {
        all_sets(n,k+1,a,nesne,mak,bag);
        a[k] = 1; //nesnenin cantaya alinma durumu
        all_sets(n,k+1,a,nesne,mak,bag);
        a[k] = 0; //nesnenin cantaya alinmama durumu
    }
}

void knapsack ( int n )
{
    int i,a[n],w[n],mak, bag=0;
    Obj nesne[n];

    for (i = 0; i < n; i++)
    {
        a[i] = 0;
        cout<<i+1<<". Nesnenin Agirligi (1-10 kg):\t";
        cin>>nesne[i].weight;
        cout<<i+1<<". Nesnenin Degeri (20-80 TL):\t";
        cin>>nesne[i].price;
        cout<<endl;

    }
    cout<<"Cantanin max kapasitesini giriniz : ";
    cin>>mak;
    cout<<endl;
    all_sets(n,0,a,nesne,mak,&bag);
    cout<<endl<<mak<<" kg canta ve "<<n<<" nesne icin toplam "<<bag<<" olasilik bulundu."<<endl;
    FonkMax(best, &bag);

}

int FonkMax(Obj best[], int *bag)
{
    Obj mak=best[0];
    for(int i=1; i<*bag; i++)
    {
        if(best[i].price>mak.price)
            mak=best[i];
    }
    cout<<endl<<"En Iyi Secenek: "<<mak.sira<<" \tToplam Agirlik : "<<mak.weight<<" kg"<<", "<<"\tToplam Fiyat: "<<mak.price<<" TL"<<endl;
}

int main()
{
    int n, pow=1;
    cout<<"Knapsack problemi\n";
    cout<<"Toplam nesne sayisini giriniz : ";
    cin>>n;
    for(int i=0;i<n;i++){
        pow*=n;
    }
    best=new Obj[pow];
    cout<<endl;
    knapsack(n);
    system("pause");
    return 0;
}




