# The-Walk-of-Life
OpenGL 3D micro-game.

__Scopul jocului (dacă va fi gata)__

Cetățeanul Turmentat trebuie să ducă o scrisoare pierdută la destinatar. El trebuie să fie precaut, deoarece dom' Nae Cațavencu încearcă să-l ademenească – "dă-i cu vin, dă-i cu bere, dă-i cu bere, dă-i cu vin" – și să-i sustragă scrisoarea atunci când respectabilul cetățean nu este atent.


__Desfășurare__

Jucătorul este așezat în apropierea casei. Se poate plimba prin pădure, poate colecționa diverse obiecte, poate privi cerul, poate sări, se poate învârti.


__Organizarea proiectului__

Codul este gândit într-o manieră Model-View (controller-ul a fost comasat fie în View, fie în main).

Pentru a facilita munca în echipă, fiecărui element din scenă i-a fost atribuit un fișier separat, iar în fișierul principal (main.cpp) se apelează o singură funcție care realizează desenarea. Astfel, în schimbul unui timp de compilare mai mare, am obținut productivitate și calitate a codului.

Pentru a urmări și mai ușor ce se întâmplă, la începutul fișierului principal au fost declarate toate funcțiile, iar abia apoi au fost și definite. Din motive de performanță, toate texturile și listele de display se încarcă/generează o singură dată, în funcția de inițializare.

Deoarece plimbarea prin scenă reprezintă o animație, se folosesc două buffere. Pentru reprezentarea corectă în perspectivă, a fost activat testul de adâncime și bufferul de adâncime. TODO legat de GLUT_RGBA, am folosit transparența pentru...


__Concepte geometrice__

Casa, parchetul, personajul, solul, drumul și cerul sunt formate din dreptunghiuri, pentru a putea pune texturi 2D pe acestea.

Gardul și copacii sunt desenați din cilindri și conuri și folosesc iluminarea pentru a obține efectul de materiale diferite.

Sticlele sunt formate din doi cilindri și o sferă, cu aceleași mențiuni referitoare la proprietățile de material.

Sticlele și gardul sunt obiecte cuadrice și sunt desenate folosind liste de display.

Apa care plutește în aer este formată din suprafețe Bézier suprapuse și semi-transparente.

Prin apăsarea tastei 'f' se activează/dezactivează ceața.
