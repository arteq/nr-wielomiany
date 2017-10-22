# nr-wielomiany
Program oblicza wielomian interpolacyjny Lagrange'a na podstawie znanych danych.

Funkcja, którą interpolujemy to funkcja wykładnicza:
f(x)= exp(x).

## Opis zmiennych
double punkt;
Punkt (x) dla którego będziemy szukali rozwiazania

double *dat_x, *dat_y;
Wskaźniki do tablic zawierających wczytane dane. Tablice są następnie generowane dynamicznie w zależności od ilości danych jakie są do przeczytania.

int ile;
Zmienna trzyma liczbę punktów danych jakie znajdują się w pliku.

char nazwa[80];
Nazwa pliku z którego będziemy czytać.

## Kolejność operacji
1. Na początku pytamy użytkownika o nazwę pliku z danymi, który trzeba wczytać. Plik powinien zawierać dwie kolumny liczb (x,y) rozdzielone jakimś białym znakiem. 
2. Plik jest czytany w celu ustalenia ile danych zawiera. 
3. Wiedząc ile mamy par liczb tworzymy dynamicznie tablice na te dane o stosownym rozmiarze...,
4. ...a następnie ponownie odczytujemy plik tym razem zapisując wczytane dane do tablic.
5. Dalej pytamy użytkownika o punkt, w którym program ma policzyć wartość wielomianu.
6. Obliczona wartość jest wyświetlana na ekranie...,
7. błąd jest obliczany jako różnica wartości zwróconej przez funkcję interpolującą oraz wartości obliczonej normalnie jako exp(punkt). 
8. Na koniec zwalniana jest pamięć zadeklarowana na tablice.

Główna funkcja licząca wielomian jest zadeklarowana następująco:
	
double interpolacja (double x, int st, double *tab_x, double *tab_f);

x to punkt w którym liczymy wartość wielomianu, st to stopień wielomianu (równy 6), *tab_x, *tab_y to wskaźniki do tablic z danymi. Funkcja zwraca wartość rzeczywistą typu double. Funkcja zasadniczo składa się z dwóch pętli: w wewnętrznej mamy mnożenie, w zewnętrznej dodawanie. Po wykonaniu w całości najbardziej zewnętrznej pętli (sumowania) wartość tej sumy jest zwracana przez funkcję.
