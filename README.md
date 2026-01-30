# ZH.U.SH. — ZHushi Unix SHell

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
 
Just another shell recreactional programming project honestly.

<img width="950" height="774" alt="Screenshot 2026-01-30 at 13 34 58" src="https://github.com/user-attachments/assets/9fba7eb0-615c-4fec-b838-190a0100c142" />

# Steps to run on your machine

1. Clone this repository

```
 git clone https://github.com/gentzhushi/zhush-shell
```

2. Build the project

```
 cd zhush_shell && make
```

3. Run it

```
 ./zhush
```

# Features

- Tokenization
- Builtin Functions
  - cd
  - echo
  - exit
  - pwd
  - source
- Fork / Execution of external programs

# Project Structure
```
 .
 ├── LICENSE
 ├── Makefile
 ├── README.md
 ├── builtin.c  ── Definition of Builtin Functions
 ├── util.c     ── Definition of utilities (system call wrappers, shell functionality)
 ├── zhush.c    ── Main REPL
 └── zhush.h    ── Declarations
```

# How it works
Read ➡ Tokenize ➡ Attempt Builtin ➡ Fork/Exec ➡ Loop

# Roadmap

- Implementation of the remaining builtins
- Improve Tokenization
- Pipes ("|") and Redirection (">"/">>")
