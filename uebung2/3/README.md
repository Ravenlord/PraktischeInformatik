# Übung 2.3

## Fragestellung

Wo wird Interprozesskommunikation praktisch eingesetzt? Und warum? Was sind die Vorteile? Am besten Sie beschreiben die Architektur eines Open-Source Projekt, dass Interprozesskommunikation verwendet...

## Antwort

* Interprozesskommunikation wird oft dazu verwendet, dass Software über ein Interface mit einer anderen Software kommunizieren kann. Praktische Beispiele umfassen Webserver & Datenbanken, oder Webserver & Programmiersprachen.
* Die Programme sind in sich geschlossen und bieten über die zuvor genannten Interfaces die Möglichkeit an, Eingaben zu verarbeiten. Das aufrufende Programm erhält dann über das Interface die Rückgaben.
* Vorteile:
    * Programme sind in sich geschlossen und spezifisch für eine Domäne, können jedoch durch die Interprozesskommunikation interagieren.
    * Standardisierte Interfaces (Implementierungsunabhängig)
    * Erweiterbarkeit
    * Verteilung / Clustering

### Open-Source Anwendungsbeispiel

Als Beispiel für Interprozesskommunikation haben wir Simple Common Gateway Interface (SimpleCGI, SCGI) gewählt. SCGI ist eine gemeinfreie Schnittstellenimplementierung worüber Applikationen mit einem HTTP-Server kommunizieren können. SCGI ist eine Weiterentwicklung von CGI und sehr ähnlich zu FastCGI. FastCGI ist komplex zu implementieren und deshalb wurde SCGI entwickelt. Es bietet weniger Möglichkeiten als FastCGI, jedoch wurde die Schnittstelle um Funktionalitäten erleichtert, die in der Regel nicht benötigt werden.

SCGI ist ein Prozess der am Computer läuft. Applikationen können eine Anfrage absetzen, diese muss einem vordefinierten Protokoll entsprechen, und erhalten von einer anderen SCGI-kompatiblen Applikation dann ihre Antwort (die Art der Antwort ist nicht spezifiziert).

SCGI verhält sich dabei wie ein Tunnel und es können immer nur zwei Applikationen direkt miteinander kommunizieren.