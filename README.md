# Code Playground

A personal coding playground for learning and experimenting with multiple programming languages and frameworks.

## Project Structure

```text
code-playground/
├── c/                   # C/C++ exercises
│   ├── list.cpp         # Linked list
│   ├── arr_op.cpp       # Array operations
│   ├── key_detector.c   # Key detection
│   ├── manager.c        # Memory management
│   ├── max.cpp          # Maximum value
│   └── ...
├── cj/                  # CangJie language
│   └── src/main.cj      # Hello World
├── py/                  # Python scripts & projects
│   ├── pygame/          # Spaceship shooting game (Pygame)
│   ├── terminal_chat/   # TCP terminal chat (socket + threading)
│   ├── word.py          # Word processing
│   ├── 二分算法.py       # Binary search algorithm
│   └── ...
├── js/                  # JavaScript / HTML / CSS
│   └── text.html        # Navigation page
├── my_react_app/        # React 19 + TypeScript + Vite 6
├── my_react_app_js/     # React 19 + JavaScript + Vite 6
├── vue_besa/            # Vue.js getting started
├── perl/                # Perl scripts
├── sh/                  # Shell scripts
│   ├── monitor_system.sh
│   ├── subscription_converter.py
│   └── ...
└── lisp/                # Lisp exercises
```

## Tech Stack

| Language/Framework | Directory |
|---|---|
| C / C++ | `c/` |
| CangJie (仓颉) | `cj/` |
| Python | `py/` |
| JavaScript / HTML / CSS | `js/` |
| React + TypeScript | `my_react_app/` |
| React + JavaScript | `my_react_app_js/` |
| Vue.js | `vue_besa/` |
| Perl | `perl/` |
| Shell | `sh/` |
| Lisp | `lisp/` |

## Getting Started

### React Projects

```bash
cd my_react_app       # or my_react_app_js
npm install
npm run dev
```

### Python Projects

```bash
# Pygame spaceship game
cd py/pygame
python pygame_game.py

# Terminal chat
cd py/terminal_chat
python server.py    # run server first
python client.py    # then connect
```

### C / C++

```bash
cd c
g++ -o program file.cpp && ./program
```

## License

MIT — feel free to use, modify, and learn from this code.
