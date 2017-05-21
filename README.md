# PSU_2016_42sh

A shell like TCSH with some cools colors 

### Prerequisites

What things you need to install the 42sh

```
Any terminal, GlibC and GCC
```

### Installing

There is a Makefile in the repository

```
make
```

### Functionality

```
• $PATH and environment
• errors and return value
• redirections (’<’, ’>’, ’<<’ and ’>>’)
• pipes (’|’)
• builtins: cd, echo, exit, setenv, unsetenv,
• separators: ’;’, ’&&’, ’||’
• history
• alias unalias
• inhibitors (’\’, '"', ''')
• globbings (’*’, ’?’, ’[’, ’]’)
• line edition (multiline, auto-completion dynamic)
• backticks (’‘’)
```

### Shortcuts

```
• Clear (ctrl + L)
• ls (alt + L)
• Cut the Line after the cursor (ctrl + K)
• ctrl + C handle as a "non signal" caracter
• Send EOF (ctrl + d)
```

## Authors

* **Nikola Tomic** - *Initial work with redirections, pipes, cd, execution and environnement* - [Pujomir](https://github.com/Pujomir)
* **Léandre Blanchard** - *Line editing, history, auto-completion dynamic and tools library* - [LeandreBL](https://github.com/LeandreBl)
* **Antoine Le Dû** - *Builtins echo and help for global parsing* -
* **Quentin Sonnefraud** -*Globbings, inihibitors, logical operator '&&' '||' and aliases* - [Vatoth](https://github.com/Vatoth)

Made with love at Epitech Paris in 2017
