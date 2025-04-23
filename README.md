# minishell

Minishell is a simple shell implementation that replicates basic functionalities of a Unix shell. This project was developed as part of a team effort, where my main
contributions were focused on implementing built-in commands, signal handling, and environment variable expansion (including handling $? for exit status).
---

### Features
- Command execution with arguments
- Built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.
- Environment variable handling
- Redirections: input `<`, output `>`, append `>>`, heredoc `<<`
- Pipes `|`
- Signal handling: ctrl-C, ctrl-D and ctrl-\
- Error handling

---

### Usage
1. Clone the repository
```bash
    ǵit clone https://github.com/AnastasiyaKuzmenko/42-minishell
`````


2. Build the project
```bash
    cd minishell
    make
`````


4. Run
```bash
    ./minishell
`````


6. You can try builtin commands but also other standard commands will work, for example, built-in echo and standard command ls
```
    echo "hello world"
    ls
`````
