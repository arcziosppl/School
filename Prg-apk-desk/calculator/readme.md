# Aplikacja Kalkulator w C#

Ten projekt to prosta aplikacja kalkulatora napisana w Windows Forms, która wykonuje podstawowe operacje arytmetyczne, takie jak dodawanie, odejmowanie, mnożenie i dzielenie.

## Funkcjonalności

1. **Podstawowe operacje arytmetyczne**:
   - Dodawanie (`+`)
   - Odejmowanie (`-`)
   - Mnożenie (`*`)
   - Dzielenie (`/`)

2. **Wprowadzanie liczb**:
   - Obsługa liczb `0-9` za pomocą przycisków.

3. **Obsługa liczb dziesiętnych**:
   - Wprowadzanie liczb dziesiętnych za pomocą przycisku `.`.

4. **Funkcja czyszczenia**:
   - Resetowanie wprowadzonych danych i operacji za pomocą przycisku `C`.

5. **Obsługa błędów**:
   - Wyświetlanie komunikatu przy próbie dzielenia przez zero.

---

## Opis kodu

### **Główne komponenty**
1. **Pole tekstowe** (`textBox1`):
   - Służy do wyświetlania wprowadzanych danych i wyników.

2. **Przyciski**:
   - Przyciski do wprowadzania liczb: `n0` do `n9`
   - Przycisk dziesiętny: `ndot`
   - Przyciski operacji: `bad` (Dodawanie), `bsub` (Odejmowanie), `bmul` (Mnożenie), `bdiv` (Dzielenie)
   - Przycisk równości: `nequal`
   - Przycisk czyszczenia: `bc`

---

### **Kluczowe zmienne**
- `double FirstNumber`: Przechowuje pierwszą liczbę w operacji.
- `string Operation`: Przechowuje wybraną operację arytmetyczną (`+`, `-`, `*`, `/`).

---

### **Obsługa zdarzeń**
#### Przyciski numeryczne (np. `n1_Click`, `n2_Click`, itp.)
- Dodają odpowiednią cyfrę do pola tekstowego `textBox1`, chyba że początkowa wartość to `0`.

#### Przyciski operacji (`bad_Click`, `bsub_Click`, itp.)
- Przechowują bieżącą liczbę w zmiennej `FirstNumber` i ustawiają wybraną operację (`Operation`).
- Resetują pole tekstowe `textBox1` do wartości `0` dla kolejnego wprowadzania.

#### Przycisk równości (`nequal_Click`)
- Wykonuje obliczenie na podstawie wybranej operacji i wyświetla wynik w polu `textBox1`.

#### Przycisk czyszczenia (`bc_Click`)
- Resetuje kalkulator, ustawiając `textBox1` na `0`.

#### Przycisk dziesiętny (`ndot_Click`)
- Dodaje kropkę dziesiętną do wprowadzanego tekstu.

---

### **Obsługa błędów**
- Dzielenie przez zero jest obsługiwane za pomocą komunikatu: `"Cannot divide by zero"`.

---

## Przykład użycia

1. **Dodawanie**:
   - Naciśnij `1`, `+`, `2`, `=` → Wyświetli `3`.

2. **Odejmowanie**:
   - Naciśnij `5`, `-`, `3`, `=` → Wyświetli `2`.

3. **Dzielenie**:
   - Naciśnij `8`, `/`, `0`, `=` → Wyświetli `"Cannot divide by zero"`.

4. **Czyszczenie**:
   - Naciśnij `C`, aby zresetować kalkulator.

---

## Możliwe ulepszenia
1. Obsługa wprowadzania za pomocą klawiatury.
2. Ulepszony interfejs graficzny (UI/UX) z nowoczesnym wyglądem.
3. Implementacja funkcji pamięci (`M+`, `M-`, `MR`).
4. Dodanie wsparcia dla zaawansowanych operacji (np. pierwiastkowanie, potęgowanie).

---

## Jak uruchomić
1. Otwórz projekt w Visual Studio.
2. Zbuduj i uruchom aplikację.
3. Używaj przycisków w formularzu do wykonywania obliczeń.

