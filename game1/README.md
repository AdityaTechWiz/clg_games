# 🎨 Color Reflex Arena

A terminal-based reaction and reflex game written in **C**.

The player is given a randomly selected color and must enter the corresponding key as quickly as possible. After completing five rounds, the game generates a performance report showing the player's accuracy, response time, round-by-round results, and reflex tier.

---

## 🎮 Game Features

- 5 reaction-time rounds
- Randomly selected color challenges
- Four keyboard controls:
  - `R` → RED
  - `G` → GREEN
  - `B` → BLUE
  - `Y` → YELLOW
- Measures response time for each round
- Detects correct and incorrect responses
- Calculates overall accuracy
- Calculates average response time
- Displays a visual accuracy bar
- Provides a round-by-round performance report
- Assigns a reflex-performance tier
- Uses colored terminal output for a more interactive experience

---

## 🕹️ How to Play

1. Start the program.
2. Press **ENTER** to begin.
3. The game will display a color command.
4. Enter the corresponding key as quickly as possible.
5. Complete all **5 rounds**.
6. At the end, review your performance report.

### Controls

| Key | Color |
|-----|-------|
| `R` | 🔴 RED |
| `G` | 🟢 GREEN |
| `B` | 🔵 BLUE |
| `Y` | 🟡 YELLOW |

Both uppercase and lowercase letters are accepted.

---

## 📊 Scoring System

The game records whether the correct key was entered during each round.

The final report includes:

- **Score** — Number of correct responses out of 5
- **Accuracy Rate** — Percentage of correct responses
- **Average Speed** — Average response time across all 5 rounds
- **Round Performance** — Individual response time and result for every round

Example:

```text
Accuracy Rate: [################----] 4/5
Average Speed: 0.55 seconds
```

---

## 🏆 Reflex Tiers

The game assigns a performance tier based on the player's score and average response time.

| Condition | Reflex Tier |
|-----------|-------------|
| 5/5 and average time < 0.60 sec | GODLIKE REFLEXES |
| At least 4/5 and average time < 1.00 sec | SHARP SHOOTER |
| At least 3/5 | AVERAGE REFLEXES |
| Otherwise | SLEEPING TURTLE |

These tiers are intended for gameplay feedback and are not medical assessments.

---

## 💻 Compilation

### Using GCC

Open a terminal in the project directory and run:

```bash
gcc reaction_game.c -o reaction_game
```

### Run on Windows

```bash
reaction_game.exe
```

or:

```bash
.\reaction_game.exe
```

---

## 🧩 Technologies Used

- **C Programming**
- **GCC Compiler**
- Standard C libraries:
  - `stdio.h`
  - `stdlib.h`
  - `time.h`

---

## 📁 Files

```text
game1/
├── reaction_game.c
├── game1.mp4
└── README.md
```

### `reaction_game.c`

Contains the complete source code for the Color Reflex Arena.

### `game1.mp4`

Contains a gameplay demonstration of the program.

---

## 🔬 Project Purpose

Color Reflex Arena was developed as an educational interactive-gameplay prototype for exploring reaction and response performance.

The project demonstrates how simple interactive tasks can collect basic behavioral measurements such as response accuracy and reaction time.

> **Disclaimer:** This is an educational/research prototype and is **not a medical diagnostic tool**.

---

## 👨‍💻 Author

**Aditya Ghosh**
