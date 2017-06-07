# The-Walk-of-Life

OpenGL 3D micro-game.

__Echipa__             __Grupa 252__

        * Micluța-Câmpeanu Marius 
        * Perescu Antonela-Mădălina
        * Merfu Andrei 
        
        


__Descriere, scopul jocului (dacă va fi gata)__

<p> Acțiunea se desfășoară într-o pădure de brazi, pe o pajiște din vârf de munte. Nae Cațavencu a ascuns în pădure sticle cu diferite băuturi care să îl tenteze pe Cetățeanul Turmentat
– "dă-i cu vin, dă-i cu bere, dă-i cu bere, dă-i cu vin", "Ce mai faceți, dom' Nae, nu mai mergem la o țuică? Hâc!" – astfel încât acesta să nu poată livra o scrisoare pierdută.

În dreapta sus există o bară care indică alcoolemia Cetățeanului Turmentat.

Dacă alcoolemia în sânge depășește un anumit prag, dom' Nae îl împinge, Cetățeanul Turmentat amețește, iar scrisoarea îi este sustrasă.<p>


__Desfășurare__

Jucătorul este așezat în apropierea casei. Se poate plimba prin pădure, poate colecționa diverse obiecte, poate privi cerul, poate sări, se poate învârti.


__Organizarea proiectului__

Codul este gândit într-o manieră Model-View (controller-ul a fost comasat fie în View, fie în main).

Pentru a facilita munca în echipă, fiecărui element din scenă i-a fost atribuit un fișier separat, iar în fișierul principal (main.cpp) se apelează o singură funcție care realizează desenarea.
Astfel, în schimbul unui timp de compilare mai mare, am obținut productivitate și calitate a codului.

Pentru a urmări și mai ușor ce se întâmplă, la începutul fișierului principal au fost declarate toate funcțiile, iar abia apoi au fost și definite. Din motive de performanță, toate texturile și
listele de display se încarcă/generează o singură dată, în funcția de inițializare.

Deoarece plimbarea prin scenă reprezintă o animație, se folosesc două buffere. Pentru reprezentarea corectă în perspectivă, a fost activat testul de adâncime și bufferul de adâncime. Am folosit transparența pentru a suprapune niște suprafețe Bézier.


<p>Pentru desenarea sticlelor există un vector de structuri care reține informații despre acestea (coordonatele și tipul). În funcție de tipul sticlei, aceasta va fi desenată cu un material diferit, iar alcoolemia personajului va crește diferit în funcție de lichidul din sticluță. În funcție de nivelul alcoolemiei, Cetățeanul Turmentat se va deplasa
mai greu și riscă să se lovească de gard. Acest lucru îl va împiedica să mai livreze scrisoarea. </p>

__Concepte geometrice__

* Personajul principal, personajul, solul, drumul și cerul sunt realizate din obiecte QUADS (de regulă dreptunghiuri) peste care s-au atașat texturi 2D (parțial).

* Pozițiile copacilor din pădure sunt stabilite prin generarea de coordonate random într-un anumit interval.

* Gardul este realizat din obiecte cuadrice pentru care s-a folosit iluminarea necesară pentru a obține efectul de materiale diferite.

* Sticlele sunt formate din doi cilindri și o sferă, cu aceleași mențiuni referitoare la proprietățile de material.

* Sticlele și gardul sunt desenate folosind liste de display.

* Casa este realizată din obiecte QUADS peste care s-au atașat texturi corespunzătoare (ziduri, ușă, ferestre, acoperiș, parchet).

* Cerul este realizat prin creearea unui cub departe de acțiunea jocului peste care a fost aplicată o textură.

* Apa care plutește în aer este formată din suprafețe Bézier suprapuse și semi-transparente. Pentru a determina coordonatele punctelor de control, am folosit site-ul https://geogebra.org.

* Prin apăsarea tastei 'f' se activează/dezactivează ceața.

* Pentru crearea fenomenelor meteorologice s-a folosit un cod existent; sursa o să apară la bibliografie. Se activează de pe tasta 'p'

* Pentru a activa efectul de balansare a Cetățeanului Turmentat, este necesară apăsarea tastei 'b'.

* Pentru creșterea alcoolemiei se poate utiliza tasta 'l' (încă nu este funcțională creșterea automată a alcoolemiei prin colecționarea sticlelor)

* Pentru evidențierea umbrelor, am încercat să proiectăm umbra casei pe sol (tasta o ), dar au apărut probleme referitoare la ordinea în care sunt desenate obiectele și umbrele pentru că interferează cu biblioteca SOIL; alte probleme posibile erau din cauză că existau mai multe surse de lumină. Am încercat și utilizarea unei alte biblioteci, dar lipsea documentația și era greu de adaptat.
 
 * Cetățeanul Turmentat nu poate intra în casă decât pe ușă: atât zidurile casei, cât și gardul reprezintă un obstacol pentru acesta și nu poate trece prin ele.


__Imagini:__

![start_point](http://i.imgur.com/Ti2zAt2.jpg)
![house_image](http://i.imgur.com/iU4IFMq.jpg)
![bezier_image](http://i.imgur.com/5JTiWTK.jpg)
![bottle_image](http://i.imgur.com/d7wlwTx.jpg)


__Bibliografie__

<p> Sursa fenomene meteorologice : 
              https://classes.soe.ucsc.edu/cmps161/Winter09/projects/mang/particles.cc </p>
<p> Suprafețe Bézier: https://www.geogebra.org/m/XktMDtsJ </p>
<p> Biblioteca pentru umbre menționată: ftp://ftp.sgi.com/sgi/opengl/contrib/mjk/tips/rts/index.html </p>
