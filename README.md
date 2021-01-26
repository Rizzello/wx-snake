# WX Snake

Correva l'anno 2008, frequentavo il primo anno di università e, durante un 
laboratorio di informatica (sostanzialmente nei ritagli di tempo fra una 
consegna e l'altra), decisi di sviluppare (per sfida) questa versione del 
celebre giochino.
Non è niente di speciale, ma per me ha un valore affettivo.

All'epoca ero uno sviluppatore ribelle, notare la totale assenza di commenti, i
fantasiosi nomi assegnati ai file e agli identificatori delle variabili; 
quest'ultimi rigorosamente in lingua italiana (cosa di cui non vado per nulla 
fiero, si intenda), pertanto proverò almeno ad illustrare, a grandi linee, come 
funzionano queste 4 linee di codice.

Innanzitutto, se non si fosse ancora capito dal nome, questo progetto è stato
sviluppato utilizzando il toolkit wxWigets 2.8, pertanto si presume che possa 
essere compilato senza alcun problema su windows, linux e mac... almeno per i 
primi due posso garantire che sia così. Per il terzo dovreste provare voi o, in 
alternativa, aspettare che io mi decida a comprare un MacBook e ad installarci
sopra il toolkit in questione (ma le probabilità che questo accada sono 
estremamente basse).

All'interno del codice si intravede un tentativo di disaccoppiare la logica di
presentazione (SnakeView) dalla "logica di business" (Snake), ho già 
detto che il progetto è stato sviluppato nei ritagli di tempo, vero!?

Il funzionamento dell'applicativo è molto semplice:
 - Troverete l'entry point del programma nel file main.cc, che si occupa di 
   istanziare il main frame (SnakeView).
 - SnakeView (che svolge le funzioni di vista e "controller"), istanzia Snake e
   si occupa di riceve l'input dell'utente e di generare il game loop (tramite 
   l'utilizzo di un wxTimer, perché nessuno vuole mandare in freeze il main
   thread). 
 - Snake contiene tutti i dati inerenti al serpente (coordinate, punteggio, 
   etc), si occupa (anche se non dovrebbe essere di sua pertinenza) di disegnare 
   l'interfaccia (ricevendo un device context, generato da SnakeView).
