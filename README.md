# comp-recursive-decent-parsing

Simple [Recursive-Decent Parsing](https://en.wikipedia.org/wiki/Recursive_descent_parser) Implementation for Evaluating Expressions in C


## Grammer

```
E  -> T E`
E` -> ε
E1 -> + T E`
T  -> F T`
T` -> ε
T` -> * F T`
F  -> ( E )
F  -> num
```


## Get Started

```shell
$ git clone https://github.com/taehwanno/comp-recursive-decent-parsing
$ cd comp-recursive-decent-parsing
$ gcc main.c
$ ./a.out
```

## Execution Results

```shell
./a.out
1 + 2
3
```

```
./a.out
2 + 3 * (4+2)
20
```


## License

MIT © [Taehwan Noh](https://github.com/taehwanno)
