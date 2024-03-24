# PO-PWr-TEL-HW2
Zadanie domowe nr 2, kliker

Program typu Kliker

Zasady działania programu:
1. Naciśnij klawisz "b", aby zebrać punkt.
2. Po uzyskaniu 5 punktów, gracz awansuje na kolejny poziom.
3. Aby wyjść z gry, naciśnij klawisz "e".

## Funkcje
### GameModel
- `addPoint()`: Dodaje 1 punkt do aktualnej liczby punktów.
- `getPoints() const`: Zwraca aktualną liczbę punktów.
- `NextLevel() const`: Zwraca true, jeśli gracz uzyskał odpowiednią liczbę punktów, aby przejść na kolejny poziom. (czyli gdy reszta z dzielenia liczby uzyskanych punktów przez 5 jest równa 0)

### GameView
- `printStartHeader()`: Wyświetla nagłówek powitalny gry.
- `printData(int points, int level)`: Wyświetla aktualną liczbę punktów oraz poziom gracza.
- `getUserInput()`: Pobiera wejście od użytkownika.

### GameController
- `launch()`: Rozpoczyna główną pętlę gry, obsługując wejście użytkownika i aktualizując stan gry.

Utworzona została również funkcja konwertująca liczby arabskie na rzymskie. 
W każdym z warunków, idąc od liczb maksymalnie największych w zapisie rzymskim, dodaje do zapisu "Level: XXX" odpowiednie liczby rzymskie, a od liczby aktualnych punktów odejmuje odpowiednią liczbe. 
