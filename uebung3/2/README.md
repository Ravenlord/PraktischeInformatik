# Übung 3.2

Lesen Sie _Writing a C library_ (URL: http://davidz25.blogspot.com/2011/07/writing-c-library-intro-conclusion-and.html). Was halten Sie davon? Präsentieren Sie 5 wichtige, lehrreiche Hinweise. Ist der Artikel für die eigene Arbeit relevant? Welche Punkte sind ihnen unklar?

## Lösung

* _Was halten Sie davon?_ Sehr kompetent verfasst. Der Autor hat sehr viel Ahnung auf diesem Gebiet, jedoch ist er sehr technisch orientiert und setzt viel Wissen bereits voraus.
* _Präsentieren Sie 5 wichtige, lehrreiche Hinweise._
    1. __Wiederverwenden bestehender Libraries__: Es gibt bereits für sehr viele Anwendungsgebiete Libraries, die ihre Aufgabe perfekt erfüllen. Diese sind bereits getestet und performant, weshalb abzuraten ist, die Funktionalität selbst umzusetzen. Außerdem sparen diese Libraries Zeit und Mühen.
    2. __Dokumentation__: Klare API-Doku, Speicherverwaltung + Paramtermanagement, Threadfähigkeit + Anleitung wie diese genutzt werden kann, Interne Nutzung von Threads
	3. __Asychronous I/O__: Alle Operationen, die viel Zeit in Anspruch nehmen, sollten asynchron durchgeführt werden können (Worker-Thread). Diese können dann auch leicht abgebrochen werden und führen durch ihre Asynchronität zu einer besseren Usability.
    4. __Naming conventions__: Da C keine Namespaces zur Verfügung stellt, sollten bei der Entwicklung der Funktionen und Konstanten konsistente Prefixes verwendet werden, die klar angeben zu welcher Library diese gehören.
    5. __Error Handling__: Jeglicher Input über die public API sollte validiert werden, Gültige/ungültige Parameter Ranges sollten dokumentiert werden, Policies für die Behandlung von Programmer / Run-time errors
* _Ist der Artikel für die eigene Arbeit relevant?_: Nicht wirklich, da wir uns darauf spezialisieren, Websites zu entwickeln. Auf diesem Gebiet kommt man nicht mit C oder anderen Low-Level-Sprachen in Berührung.
* _Welche Punkte sind ihnen unklar?_
    * Threading in C
	* Main Loop integration
	* C
	