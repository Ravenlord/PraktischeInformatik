# �bung 2.3

## Fragestellung

Wo wird Interprozesskommunikation praktisch eingesetzt? Und warum? Was sind die Vorteile? Am besten Sie beschreiben die Architektur eines Open-Source Projekt, dass Interprozesskommunikation verwendet...

## Antwort

* Interprozesskommunikation wird oft dazu verwendet, dass Software �ber ein Interface mit einer anderen Software kommunizieren kann. Praktische Beispiele umfassen Webserver & Datenbanken, oder Webserver & Programmiersprachen.
* Die Programme sind in sich geschlossen und bieten �ber die zuvor genannten Interfaces die M�glichkeit an, Eingaben zu verarbeiten. Das aufrufende Programm erh�lt dann �ber das Interface die R�ckgaben.
* Vorteile:
    * Programme sind in sich geschlossen und spezifisch f�r eine Dom�ne, k�nnen jedoch durch die Interprozesskommunikation interagieren.
    * Standardisierte Interfaces (Implementierungsunabh�ngig)
    * Erweiterbarkeit
    * Verteilung / Clustering

### Open-Source Anwendungsbeispiel

Als Beispiel f�r Interprozesskommunikation haben wir Simple Common Gateway Interface (SimpleCGI, SCGI) gew�hlt. SCGI ist eine gemeinfreie Schnittstellenimplementierung wor�ber Applikationen mit einem HTTP-Server kommunizieren k�nnen. SCGI ist eine Weiterentwicklung von CGI und sehr �hnlich zu FastCGI. FastCGI ist komplex zu implementieren und deshalb wurde SCGI entwickelt. Es bietet weniger M�glichkeiten als FastCGI, jedoch wurde die Schnittstelle um Funktionalit�ten erleichtert, die in der Regel nicht ben�tigt werden.

SCGI ist ein Prozess der am Computer l�uft. Applikationen k�nnen eine Anfrage absetzen, diese muss einem vordefinierten Protokoll entsprechen, und erhalten von einer anderen SCGI-kompatiblen Applikation dann ihre Antwort (die Art der Antwort ist nicht spezifiziert).

SCGI verh�lt sich dabei wie ein Tunnel und es k�nnen immer nur zwei Applikationen direkt miteinander kommunizieren.