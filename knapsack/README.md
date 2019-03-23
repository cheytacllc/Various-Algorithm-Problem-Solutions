# 0 1 Knapsack Problem – Dynamic Programming Solutions
This is a C++ Program that Solves 0 1 Knapsack Problem using Dynamic Programming technique.

## Problem Description
Given weights and values of n items, put these items in a knapsack of capacity M to get the maximum total value in the knapsack.

Note that, you can select items, the sum of whose weight is less than or equal to the capacity of knapsack, W.

## Problem Solution
The problem is to find a subset of items such that –

the sum of weight of all the items in the subset should be less than or equal to knapsack capacity
out of all subsets that satisfy criteria 1 above, the desired subset is the one in which the sum values of its items is maximum.
consider this example-
n=3
w[]=3 2 1
v[]=5 3 4

M=5

Create a matrix of order (n+1)*(M+1), ie. knapsack[n+1][M+1] 
knapsack[i][j]=maximum attainable value of items in the knapsack with i available items and capacity of knapsack being j.

Initialize –
knapsack[0][j]=0 for 0<=j<=M 
knapsack[i][0]=0 for 0<=i<=n 
Now, start filling the matrix row wise, following the given recursive formula –

knapsack[i][j]=	knapsack[i-1][j] , if w[i]>j
max{knapsack[i-1][j], v[i]+knapsack[i-1][j-w[i]] } , if w[i]<=j
The time complexity of this solution is O(n*M).

## Expected Input and Output

>```
>Knapsack problemi
>Toplam nesne sayisini giriniz : 3
>
>1. Nesnenin Agirligi (1-10 kg): 10
>1. Nesnenin Degeri (20-80 TL):  68
>
>2. Nesnenin Agirligi (1-10 kg): 5
>2. Nesnenin Degeri (20-80 TL):  76
>
>3. Nesnenin Agirligi (1-10 kg): 9
>3. Nesnenin Degeri (20-80 TL):  38
>
>Cantanin max kapasitesini giriniz : 15
>
>                Toplam Agirlik : 0 kg   Toplam Fiyat: 0 TL      Durum:  sigiyor
>      N3        Toplam Agirlik : 9 kg   Toplam Fiyat: 38 TL     Durum:  sigiyor
>   N2           Toplam Agirlik : 5 kg   Toplam Fiyat: 76 TL     Durum:  sigiyor
>   N2 N3        Toplam Agirlik : 14 kg  Toplam Fiyat: 114 TL    Durum:  sigiyor
>N1              Toplam Agirlik : 10 kg  Toplam Fiyat: 68 TL     Durum:  sigiyor
>N1    N3        Toplam Agirlik : 19 kg  Toplam Fiyat: 106 TL    Durum:  sigmiyor
>N1 N2           Toplam Agirlik : 15 kg  Toplam Fiyat: 144 TL    Durum:  sigiyor
>N1 N2 N3        Toplam Agirlik : 24 kg  Toplam Fiyat: 182 TL    Durum:  sigmiyor
>
>15 kg canta ve 3 nesne icin toplam 8 olasilik bulundu.
>
>En Iyi Secenek: N1 N2   Toplam Agirlik : 15 kg,         Toplam Fiyat: 144 TL
>```
## Explain the Code
This solution uses recursion for solve knapsack problem. As you see the input and output example this code shows every probabilities and every results then it finds best possible solution.

### void all_sets (int n, int k, int a[], Obj nesne[], int mak, int *bag);
This function takes
- int n: this is number of objects
- int k: index of objects structure
- int a[]: this array stores the object taken in the bag (1) or not (0)
- Obj nesne[]: this is objects type of Obj struct
- int mak: max capacity of bag
- int *bag: max number of objects fit in the bag
arguments.

First this function controls if the object in the bag or not. If object in the bag going in the loop then calculate the total weight and total price.
If total weight is smaller or equal the max weight print the objects weight price and status. If not also print the same things but status is different.
Every probability that objects fits in the bag stored in the Obj *best structure.

### void knapsack (int n)
This function takes n number of object's weight and price values from user input. And takes bag's max capacity value from input. Then calls all_sets (int n, int k, int a[], Obj nesne[], int mak, int *bag) function.

### int FonkMax(Obj best[], int *bag)
This function shows best value and its objects in the bag.
