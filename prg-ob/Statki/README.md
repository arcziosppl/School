# Gra w Statki

Gra w statki to klasyczna gra planszowa polegająca na rozmieszczaniu statków na planszy oraz próbie zatopienia statków przeciwnika, zgadując, na których polach znajdują się ich jednostki. W tej wersji gracz rywalizuje z komputerem.

## Zasady Gry

1. **Plansza**: Gra toczy się na planszy o wymiarach 10x10.
2. **Statki**: Każdy z graczy (gracz i komputer) rozmieszcza po 10 statków na swojej planszy.
3. **Rozgrywka**: Gracz i komputer na zmianę oddają strzały, próbując trafić statki przeciwnika. Plansza gracza pokazuje zarówno jego statki, jak i strzały komputera. Plansza komputera jest ukryta i pokazuje jedynie rezultaty strzałów gracza.
4. **Wygrana**: Wygrywa gracz, który pierwszy zatopi wszystkie statki przeciwnika.

## Struktura Plików

### Nagłówki:
- `Game/Board.h`: Definiuje klasę odpowiedzialną za planszę gry i operacje na niej.
- `Utils/Utils.h`: Zawiera funkcje pomocnicze, takie jak wyświetlanie ASCII-artu czy zapisywanie stanu gry.
- `Game/Player.h`: Definiuje klasę gracza odpowiedzialną za interakcję z użytkownikiem.
- `Game/PlayerPc.h`: Definiuje klasę komputera, który generuje losowe współrzędne do strzelania.

### Główne Funkcje:

1. **Board**:
   - `init()`: Inicjalizuje planszę.
   - `ShipsGenerate()`: Generuje losowe rozmieszczenie statków dla komputera.
   - `ShipsGeneratePlayerH()`: Pozwala graczowi na rozmieszczenie swoich statków.
   - `TakeTheShot(int[2])`: Rejestruje strzał gracza w podane współrzędne.
   - `TakeTheShotPc(int[2])`: Rejestruje strzał komputera w losowe współrzędne.
   - `GameWin()`: Sprawdza, czy któryś z graczy wygrał.

2. **Player**:
   - `GetCords()`: Pobiera współrzędne strzału od gracza.

3. **PlayerPc**:
   - `GenerateCordsToShoot()`: Generuje losowe współrzędne strzału dla komputera.

4. **Utils**:
   - `WelocmeAscii()`: Wyświetla powitanie w formie ASCII.
   - `SaveToTxt(char matrix[][], int size)`: Zapisuje aktualny stan planszy do pliku tekstowego.

## Przebieg Gry

1. Gra rozpoczyna się od inicjalizacji planszy i rozmieszczenia statków dla obu graczy.
2. Gracz oraz komputer na zmianę oddają strzały. Komputer generuje losowe współrzędne strzałów.
3. Po każdym strzale sprawdzany jest stan gry, by określić, czy któryś z graczy zatopił wszystkie statki przeciwnika.
4. Gra kończy się, gdy któryś z graczy wygra, a plansza jest zapisywana do pliku tekstowego.

## Kompilacja i Uruchomienie

Aby skompilować grę, należy użyć kompilatora obsługującego standard C++ (np. `g++`):

```bash
g++ -o statki main.cpp Board.cpp Player.cpp PlayerPc.cpp Utils.cpp
