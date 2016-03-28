##Cruzarbits

Cruza bits según tabla.

####Ejemplo

```C
 0  1  2  3  4  5  6  7
 |   \ /  |  |  |  \ /
 |    X   |  |  |   X
 |   / \  |  |  |  / \
 0  1  2  3  4  5  6  7

int tabla[] = { 0, 2, 1, 3, 4, 5, 7, 6 }; //LSB first

```

```
**Bin**   0 1 0 1 0 0 1 1  -> cruzar ->   1 0 0 1 0 1 0 1 

**Hex**               0x53 -> cruzar ->   0x95  

**Dec**                83 --> cruzar ->   149  
```









