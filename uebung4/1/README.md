# Übung 4.1

Welche Bedeutung hat das Schlüsselwort `static` in C/C++ bei Klassen und Funktionen? Erklären Sie anhand von Beispielen!

## Lösung

### Statische Klasse

Der `static`-Modifikator im Datei-Scope zeigt an, dass der Bezeichner der mit `static` ausgezeichnet wurde ausschließlich in der Datei in der er definiert wurde sichtbar ist. Diese Syntax is in für C++-Klassen nicht verfügbar (ausschließlich für Methoden und Variablen), jedoch kann ein ähnlicher Effekt durch Verwendung von anonymen Namespaces erreicht werden.

```cpp
namespace {
    class Foo {}
}
```

Eine andere Variante ist das sogenannte [Monostate Pattern](http://c2.com/cgi/wiki?MonostatePattern). In einer solchen Klasse besitzen alle Instanzen den selben Status. Dies ist mehr oder weniger equivalent zu einer statischen Klasse. Die Verwendung sieht aus wie folgt.

```cpp
/**
 * Monostate Class
 */
public class User {
    private:
        static int _userId;
    public:
        int getUserId() {
            return _userId;
        }
}

// Initializing the monostate value.
int User::_userId = 42;

// Using an instance of a monostatce class.
void Foo() {
    User user = new User();
    Assert.Equals(42, admin.getUserId()); // Will always be 42.
}
```

### Statische Funktion

Statische Methoden in einer Klasse sind im gleichen Ausführungsobjekt in allen Instanzen dieser Klasse gleich und auch verfügbar, wenn keine Instanz der Klasse existiert. Statische Methoden können in einer Klasse auf andere statische Mitglieder der Klasse zugreifen, jedoch nicht auf nicht-statische Mitglieder.

```cpp
class Q {
    public:
        static char *getFourKiloByte(void);
}

void f(Q &rQ, Q *pQ) {
    // Static call without instance.
    char *p1 = Q::getFourKiloByte();
    // Call via referenced object.
    char *p2 = rQ.getFourKiloByte();
    // Call via pointer on object.
    char *p3 = pQ->getFourKiloByte();
}
```

Ein anderes Beispiel, ausgeben der Anzahl an erzeugten Instanzen / Objekten einer Klasse.

```cpp
#include <iostream>

using namespace std;

class Animal {
    public:
        Animal() {
            ++instanceCount;
        }
        static int getInstanceCount() {
            return instanceCount;
        }
    private:
        static int instanceCount = 0;
}

int main() {
    cout << Animal::getInstanceCount() << endl;
    Animal t1;
    cout << Animal::getInstanceCount() << endl;
    Animal t2, t3;
    cout << Animal::getInstanceCount() << endl;
}
```

Die Ausgabe des obigen Beispielprogrammes wäre dann:

```
0
1
3
```
