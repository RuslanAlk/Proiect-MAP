# Documentație Proiect sincretic: Problema celor 8 regine
Implementarea soluției pentru problema celor 8 regine în limbajul de programare C++

## Descriere
Proiectul rezolvă clasicul puzzle al reginelor pe o tablă de șah de dimensiune fixă (de obicei, 8x8). Scopul este de a plasa 8 regine pe tabla de șah astfel încât să nu existe două regine care să se atace reciproc, respectând regulile de mișcare ale reginei pe orizontală, verticală și diagonale.

## Funcții publice
- printChessboard(const vector<vector<int>>& chessboard): Afișează starea curentă a tabloului de șah.
- isSafe(const vector<vector<int>>& chessboard, int row, int col): Verifică dacă plasarea unei dame într-o poziție dată este în siguranță.
- placeQueens(vector<vector<int>>& chessboard, int row): Implementarea algoritmului de backtracking pentru găsirea soluțiilor.

## Funcția main()
- Inițializează un tablou de șah cu dimensiunea N x N și îl numește chessboard.
- Afișează un meniu cu două opțiuni:
1. Afișează toate soluțiile pentru problema N-Regine.
2. Ieșire din program.
- Folosește un bloc do-while pentru a menține programul în execuție până când utilizatorul alege să iasă.
- Folosește funcția placeQueens pentru a găsi și afișa soluțiile pentru problema N-Regine.

## Exemplu de utilizare:
Meniu:
1. Afiseaza toate solutiile
2. Iesire
Alegeti optiunea: 1
```plaintext
Aranjarea numarul 1/92
Q . . . . . . .  
. . . . Q . . .  
. . . . . . . Q  
. . . . . Q . .  
. . Q . . . . .  
. . . . . . Q .  
. Q . . . . . .  
. . . Q . . . .  

...

Aranjarea numarul 92/92
. . . . . . . Q  
. . . Q . . . .  
Q . . . . . . .  
. . Q . . . . .  
. . . . . Q . .  
. Q . . . . . .  
. . . . . . Q .  
. . . . Q . . .  
```
## Utilizarea programului cu Docker
### Construirea și rularea într-un container Docker
- Construim imaginea docker:
```docker -build -t ruslanal/regine .```
- Autentificarea in docker hub:
```docker login```
- Rularea in container Docker:
```docker run -it --rm ruslanal/regine```

#### Conținutul Dockerfile
```plaintext
FROM gcc:latest
WORKDIR /usr/src/myapp
COPY regine.cpp .
RUN gcc -o regine regine.cpp -lstdc++
CMD ["./regine"]
```

## Concluzie
Proiectul în C++ rezolvă eficient problema celor 8 regine, permițând utilizatorului să vizualizeze aranjamentele valide pe un tablou de șah N x N. Folosind backtracking, programul oferă un meniu simplu pentru interacțiune, evidențiind astfel versatilitatea și claritatea soluției propuse.

