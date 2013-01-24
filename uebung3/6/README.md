# Übung 3.6

Berechnen Sie unter Annahme von 64-bit Adressen die folgenden Werte für einen 8-fach assoziativen 256 KB grossen Cache mit 64 Bytes cache lines:
* Anzahl der Bits für offset, index und tag bits
* Anzahl der sets im Caches
* Anzahl der cache lines im Caches

## Lösung

```
|-------------------------------------------------|---------|------|
|                      49bit                      |   9bit  | 6bit |
|-------------------------------------------------|---------|------|
                        tag                           index   offset

256 KB / 64 B = 4096 cache lines

4096 / 8 (assoc) = 512 = 2^9 index


Aussehen:
                           8-fach assoziativ -->
  0 |------|------|---     |------------|------------|---
    | set0 | set1 |        |    set0    |    set1    |   
    |------|------|---     |------------|------------|---
    | set0 | set1 |        |    set0    |    set1    |   
    |------|------|---     |------------|------------|---
    |      |      |        |            |            |   


    |      |      |        |            |            |   
    |------|------|---     |------------|------------|---
    | set0 | set1 |        |    set0    |    set1    |   
511 |------|------|---     |------------|------------|---
      18bit   18bit            64Bytes      64Bytes
```
