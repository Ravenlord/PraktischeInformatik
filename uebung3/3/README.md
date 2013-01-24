# Übung 3.3

Lesen Sie das _libabc README_ (URL: http://0pointer.de/blog/projects/libabc.html). Was halten Sie davon? Prasentieren Sie 5 wichtige, lehrreiche Hinweise. Ist der Artikel fur die eigene Arbeit relevant? Welche Punkte sind ihnen unklar?

## Lösung

_Was halten Sie davon?_
Sehr gut verfasste Liste mit Tips für Entwickler in einfacher Sprache und daher sehr verständlich.

_Präsentieren Sie 5 wichtige, lehrreiche Hinweise._  
    1. __De-facto name standards__: Immer an die Gewachsenen Standard-Namensschemen von Funktionen halten. Z.B. _new(), _free(), _ref() und _unref(). Diese machen die API-Aufrufe verständlicher und einheitlich.  
    2. __Callbacks in der API vermeiden__: Da für Language bindings und Entwickler-Komfort Iterators von großer Wichtigkeit sind, sollten Callbacks vermieden werden.  
    3. __Abbrüche vermeiden__: Libraries müssen sicher in kritischen Prozessen verwendet werden können, die sich von Fehlern erholen können. exit(), abort(), assert() brechen die Ausführung ab, weshalb error codes verwendet werden sollten.  
    4. __Rückgabewerte__: Funktionen sollten int-Werte oder negative error codes zurückliefern, da NULL nicht aussagekräftig ist. Kernel-artige error codes sind weithin bekannt und können durch Einbinden von <errno.h> verwendet werden.  
    5. __Mehrfacheinbindung von Headern__: Diese muss verhindert werden, da es sonst zu Fehlern und aufgeblähtem Code kommt. #ifndef, #define und #endif sind in header files Pflicht.  

_Ist der Artikel für die eigene Arbeit relevant?_  
Nein, da wir als Webentwickler nicht mit C in Berührung kommen. Wenn einmal die Lust aufkommt, am Linux Kernel mitzuarbeiten, wäre er schon sehr relevant.

_Welche Punkte sind ihnen unklar?_
* Initializers richtig verwenden
* autotools
* TLS
* Symbols
* extern
