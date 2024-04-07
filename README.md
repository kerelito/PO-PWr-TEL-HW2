# PO-PWr-TEL-HW2
Zadanie domowe nr 3, kliker

Program typu Kliker

Zasady działania programu:
1. Naciśnij klawisz "b", aby zebrać punkt.
2. Po uzyskaniu 5 punktów, gracz awansuje na kolejny poziom.
3. Aby wyjść z gry, naciśnij klawisz "e".
4. Aby zapisać stan gry, naciśnij klawisz "s".
5. Aby wczytać zapisany stan gry, naciśnij klawisz "l".

## Funkcje
### GameModel
- `addPoint()`: Dodaje 1 punkt do aktualnej liczby punktów.
- `setPoints(int newPoints)`: Ustawia liczbę punktów na nową wartość.
- `getPoints() const`: Zwraca aktualną liczbę punktów.
- `setLevel(int newLevel)`: Ustawia poziom na nową wartość.
- `getLevel() const`: Zwraca aktualny poziom gracza.
- `nextLevel() const`: Zwraca true, jeśli gracz uzyskał odpowiednią liczbę punktów, aby przejść na kolejny poziom. (czyli gdy reszta z dzielenia liczby uzyskanych punktów przez 5 jest równa 0)

### GameView
- `printStartHeader()`: Wyświetla nagłówek powitalny gry.
- `printData(int points, int level)`: Wyświetla aktualną liczbę punktów oraz poziom gracza.
- `getUserInput()`: Pobiera wejście od użytkownika.

### GameController
- `launch()`: Rozpoczyna główną pętlę gry, obsługując wejście użytkownika i aktualizując stan gry.
- `saveGame(const string& filename, int points, int level)`: Zapisuje stan gry (ilość punktów i poziom) do pliku o podanej nazwie.
- `loadGame(const string& filename, GameModel& model)`: Wczytuje stan gry (ilość punktów i poziom) z pliku o podanej nazwie i przywraca go do modelu gry.

### Konwersja liczb arabskich na rzymskie
- Funkcja `romanNumeral(int num)`: Konwertuje liczbę całkowitą na zapis rzymski.
