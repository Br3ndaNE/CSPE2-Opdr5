## Projectinformatie
**Projectnaam:** Tic Tac Toe  
**Gemaakt door:** Brendan Endenburg

**Type project:** Consoleversie en UI-versie

## Beschrijving
Dit project is een implementatie van het spel Tic Tac Toe (Noughts and Crosses). In dit project heb ik het twee versies gemaakt van het spel Tic Tac Toe gemaakt. Een grafische interface versie & command line versie. De console versie is onafhankelijk van de externe bibliotheek SFML, die wel word gebruikt bij de grafische interface versie. 


## Bouw en Uitvoering

### Consoleversie

Om de console versie te bouwen wil je deze commandos in de commandline achter elkaar invoeren.

1.  bmptk-make clean
2.  bmptk-make -f Makefile.text
3.  bmptk-make run

Het eerste commando maakt het project schoon (haald alle files weg die zijn gebruikt bij het compileren). Vervolgens run je de makefile.text. Dit zorgt ervoor dat alle files worden gemaakt. Als laatst run je de files die zijn gemaakt.

Hoe het spel werk:

    0   1   2 X
0   .   .   .
1   .   .   .
2   .   .   .
Y

Hierboven is het boord weergegeven en de structuur van de posities. U moet cordinaten doorgeven. Om te beginnen met X cordinaat en vervolgens een Y cordinaat. Als het niet de eerste zet is, word er gevraagd voor een nieuwe zet plaatsen of u de vorige move wilt terugnemen (Undo). Als u dat wilt druk "1". Anders druk "0".

Voorbeeld van een zet:
X: 1
Y: 1

    0   1   2 X
0   .   .   .
1   .   x   .
2   .   .   .
Y

### UI-versie

Om de Grafische-Interface versie van het project te bouwen en uit te voeren, gebruik je het volgende commando:

1.  bmptk-make clean
2.  bmptk-make -f Makefile
3.  bmptk-make run

De UI-versie van het spel wordt geladen, waarbij u op de vakjes kan kliken om uw zet te zetten. Als u een zet wilt terugnemen druk dan de 'u' knop in.