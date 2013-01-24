# Übung 4.3

Implementieren Sie eine Template-Klasse __RingBuffer__ (auch _circular buffer_ genannt für beliebige Datentypen, Details siehe http://en.wikipedia.org/wiki/Circular_buffer).

* Überprüfen Sie Ihre Klasse mit sinnvollen _self-checking_ Tests. Überlegen und Implementieren Sie die Tests __bevor__ Sie die Klasse ausimplementieren!
* Das Verhalten bei Einfügen wenn der Buffer voll ist soll als Policy ausgeführt werden: entweder ignorieren, einen Fehler/Exception liefern, oder das älteste Element überschreiben.
* Das Verhalten bei Lesen wenn der Buffer leer ist soll als Policy ausgeführt werden: entweder einen Fehler/Exception liefern oder einen Default-Wert zurückliefern.

## Lösung

```shell
make test
```
