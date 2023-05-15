# eda
```c
//Calculate the runtime of a line of code
clock_t begin = clock();
//code you wanna measure
clock_t end = clock();
double t1 = (double)(end - begin) / CLOCKS_PER_SEC;
```

```c
//y é uma string (char*) e _atoi_ converte y em int.
int x = atoi(y);
```