# Übung 2.1

Lesen Sie (die angegebenen Teile von) _[What Every Programmer Should Know About Memory](http://www.akkadia.org/drepper/cpumemory.pdf)_ und beantworten Sie die Fragen. Der Text ist sehr technisch, nicht verzweifeln.

## Übung 2.1a

Lesen Sie Kapitel 2, 2.1, 2.2.4 und 2.2.5. Erklären sie die Abkürzungen SMP und NUMA.

__Antwort__

* In __symmetric multi-processing__ (__SMP__) Systemen arbeiten die Caches der CPUs nicht unabhängig voneinander. All CPUs sehen jederzeit den selben Speicherinhalt. Die Erhaltung dieser konsistenten Ansicht des Speichers wird „cache coherency” (Speicherkohärenz) genannt. Ohne SMP könnte ein Prozessor nicht ohne weiteres auf den Speicher eines anderen Prozessors zugreifen. Prozessoren können erkennen was andere Prozessoren im Speicher bearbeiten, somit kann ein Prozess den Cache-Inhalt eines anderen Prozessors auch invalidieren. Der Autor führt die Technik noch weiter im Detail aus.
* __Non-uniform memory architecture__ (__NUMA__), in der einfachsten Form besitzt ein Prozessor lokalen Speicher auf den effizienter zugegriffen werden kann, als auf den Speicher anderer Prozessoren. Diese Technologie lässt sich am besten anhand eines Bildes erklären (siehe unten). Wie im Bild zu sehen ist, müsste CPU1 um auf das RAM2 zuzugreifen, über CPU2 fahren. Das bedeutet, dass sich die Zugriffszeit, verglichen mit einem Zugriff auf das eigene RAM, erhöhen würde. Die Speicherzugriffszeiten in einem solchen Verbund hängen daher davon ab, ob sich eine Speicheradresse im lokalen oder im fremden Speicher befindet.

![NUMA-Architektur](https://raw.github.com/Fleshgrinder/Praktische_Informatik/master/uebung2/1/numa-architektur.png)

## Übung 2.1b

Lesen Sie Kapitel 3, 3.1, 3.2. Was ist die von Neumann Architektur? Was kostet ein Zugriff auf ein Register bzw. auf den Hauptspeicher? Was versteht man unter _eviction_?

__Antwort__

* Der Autor beschreibt die von-Neumann-Architektur nicht näher (der Weblink in der PDF verweist auf Wikipedia). Intel verwendet bereits seit 1993 andere Architekturen. 
    * von-Neumann-Aufbau:
        * Steuerwerk
        * Rechenwerk
        * Speicher
        * E/A-Einheiten
    * von-Neumann-Eigenschaften:
        * Struktur ist unabhängig vom Problem 
        * Speicherzellen gleicher Größe, fortlaufend nummeriert 
        * Daten und Programme im selben Speicher 
        * Programme sind eine Folge von Befehlen und werden hintereinander ausgeführt 
        * Befehlsabfolge durch Sprungbefehle änderbar 
        * Binärcodeverarbeitung
* Der Autor gibt folgende Kosten für einen Intel Pentium M an (Speicher Verhältnis Zyklen): Register <= 1, L1d ~3, L2 ~14, Hauptspeicher ~240
* Unter _eviction_ versteht man den Vorgang, wenn Daten von einem Cache in den nächsten gepushed werden (z. B. von L1 zu L2, dann zu L3, dann ins RAM).

## Übung 2.1c

Lesen Sie Kapitel 4, 4.1, 4.2. Wofür braucht man virtuellen Speicher? Warum wird mehrstufige _address translation_ verwendet?

__Antwort__

* Virtueller Speicher (VM) ist ein Subsystem des Prozessors der virtuelle Speicheradressräume für jeden Prozess verteilt. Das führt dazu, dass jeder Prozess glaubt alleine auf dem System ausgeführt zu werden. Der Autor geht nicht weiter auf virtuelle Speicher ein: „The list of advantages of virtual memory are described in detail elsewhere so they will not be repeated here.”
* Multiple Stufen für die Seitentabellen zu verwenden, ermöglicht es die Seitentabellen für viele Prozesse im Speicher zu halten ohne die Performance zu stark zu beeinträchtigen.

## Übung 2.1d

Lesen Sie Kapitel 6.2, 6.2.1 (bis Seite 51) und probieren Sie den angegeben Code zur Matrix-Multiplikation aus. Messen Sie mit `gettimeofday()` und vergleichen Sie das Ergebnis mit dem Artikel. Was versteht man unter _locality_, Was versteht man unter _alignment_?

__Antwort__

```c
$ make test
./mm
Original: 12519830 ms
Transposed: 2890913 ms
Sub-Matrix: 867917 ms
Vectorized: 1211789 ms
Transposed needs 23.09% of time of Original.
Sub-Matrix needs 6.93% of time of Original.
Vectorized needs 9.68% of time of Original.
```

* Bei uns dauert die Vectorized-Version länger als die Sub-Matrix-Version. Diesen hohen Grad an Optimierung konnten wir nur durch Verwendung des `-O3`-Flags erreichen.
* _Locality_ bedeutet, dass zu einem bestimmten Zeitabstand nur auf einen kleinen Speicherbereich zugegriffen wird. Deshalb lassen sich die Daten besser cachen.
* _Alignment_ bezieht sich darauf, wie Datenstrukturen im Speicher abgelegt werden. Ist die Adresse eines Datenelements kein vielfaches von 2 (oder nicht 1) dann sind die Daten nicht ausgerichtet. Ein Zugriff dauert dann 20 bis 30% länger als der Zugriff auf korrekt ausgerichtete Daten.