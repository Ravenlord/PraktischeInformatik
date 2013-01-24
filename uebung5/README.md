# Übung 5

Implementieren Sie einen Cache-Simulator. Dieser soll mit `valgrind lackey` erzeugte Speicher-Traces verarbeiten können. Das Format der Traces ist in `lackey.txt` definiert, ein Trace-Beispiel ist in `trace-ls.txt`.

* Der Simulator soll _direct-mapped_, _fully-associative_ und _set-associative_ Caches unterstützen.
* Der Cache soll eine konfigurierbare Größe, _associativity_ und _cache line size_ habe.
* Überlegen Sie sich eine sinnvolle Strategie zum Ersetzen von cache lines.
* Instruktionen (`I`) und Datenzugriffe (`L`, `S`, `M`) sollen von getrennten Caches behandelt werden.
* Ermitteln Sie die _hit rate_ und _miss rate_ für folgende Konfiguration:
    * instruction cache: Größe 4096 Bytes, cache line 32 Bytes, direct-mapped.
    * data cache: Größe 256 Kilobytes, cache line size 32 Bytes, 4-fach assoziativ.
* Ermitteln Sie für obige Konfiguration wie viele cache lines belegt werden.

__Hinweis:__ Speicherzugriffe können sich über mehr als eine cache line erstrecken.

## Lösung

```cpp
make test
```
