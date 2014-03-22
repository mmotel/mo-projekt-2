# Metody obliczeniowe - projek 2

## Treść zadania (II.12):

Dla równania `f(x) = 0` , gdzie `f(x) = 2x-6-lnx`, wczytać liczby rzeczywiste `a`,`b` takie, by `0 < a < b` oraz `f(a) * f(b) < 0`. Następnie dopóki Użytkownikowi się nie znudzi, wczytywać wartość `0 < E < 1` i metodą połowienia na `[ a, b ]` przybliżyć z dokładnością `E` rozwiązanie tego równania. Rozwiązanie to przybliżyć również metodą siecznych z `x_0 = a`, `x_1 = b`, przy czym `x_k` będzie dobrym przybliżeniem, gdy `| x_n-x_n-1 | < E`. Porównać ilość kroków wykonanych metodą połowienia i metodą siecznych.

## Metoda połowienia (bisekcji)

Jeśli funkcja spełnia następujące założenia można zastosować metodę połowienia:

1. Funkcja jest ciągła w przedziale domkniętym `[ a, b ]`,
2. Funkcja przyjmuje różne znaki na końcach przedziału: `f(a) * (b) < 0`.


#### Przebieg algorytmu:

1. Sprawdzić czy pierwiastkiem jest punkt `c = (a + b) / 2`  , czyli czy `f(c) = 0`.
2. Jeżeli tak jest, algorytm kończy, a punkt `c` jest miejscem zerowym. W przeciwnym razie `c` dzieli przedział `[ a, b ]` na dwa mniejsze przedziały `[ a, c ]` i `[ c, b ]`.
3. Wybierany jest ten przedział, dla którego spełnione jest drugie założenie, to znaczy albo `f(c) * f(a) < 0` albo `f(c) * f(b) < 0` . Cały proces powtarzany jest dla wybranego przedziału.
 

## Metoda siecznych
Metodę siecznych dla funkcji `f(x)` mającej pierwiastek w przedziale `< a, b >` można zapisać następującym wzorem rekurencyjnym:

![metoda siecznych - wzor rekurencyjny](http://oi58.tinypic.com/9u3g9x.jpg)

Obliczamy kolejne wartości `x_n+1` do momentu, w którym `f(x_n+1) = 0` lub `| x_n - x_n-1 | <= E`.
