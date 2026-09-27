# ⚡ Speed Tap Speedrun

A terminal-based keyboard agility and tapping-speed game written in **C**.

The player must alternate between the **Z** and **X** keys for 10 taps as quickly and accurately as possible. The game records the time between each tap and generates a final scorecard showing accuracy, total duration, tapping speed, and an agility tier.

---

## 🎮 Game Features

- 10-tap challenge
- Alternating `Z` and `X` targets
- Measures split time between taps
- Tracks accurate and missed taps
- Calculates:
  - Accuracy percentage
  - Total completion time
  - Tapping speed in taps/second
- Displays a round-by-round scorecard
- Visual accuracy progress bar
- Assigns an agility tier based on performance
- Colored terminal interface for a more interactive experience

---

## 🕹️ How to Play

1. Start the program.
2. Press **ENTER** to begin.
3. Follow the displayed key:
   - `Z`
   - `X`
   - `Z`
   - `X`
   - Continue alternating until 10 taps are completed.
4. Enter each key as quickly and accurately as possible.
5. Review your final scorecard.

### Controls

| Key | Action |
|-----|--------|
| `Z` | Press when the game requests Z |
| `X` | Press when the game requests X |

Both uppercase and lowercase letters are accepted.

---

## 📊 Performance Metrics

After the 10-tap challenge, the game reports:

### Accuracy

The percentage of correct taps out of 10.

```text
Accuracy: [████████████████----] 8/10
```

### Total Duration

The total time taken to complete all 10 taps.

### Tapping Speed

Calculated as:

```text
Tapping Speed = Total Taps / Total Duration
```

The result is displayed in **taps per second**.

### Split Time

Each tap has an individual split time showing the time between the previous tap and the current tap.

---

## 🏆 Agility Tiers

The game assigns a performance tier based on accuracy and tapping speed.

| Condition | Agility Tier |
|-----------|--------------|
| 10/10 and ≥ 4.0 taps/sec | ⚡ CYBORG DIGITS |
| At least 8/10 and ≥ 2.5 taps/sec | 🏆 RHYTHM MASTER |
| At least 6/10 | ⭐ CASUAL TAPPER |
| Otherwise | 💤 KEYBOARD STUMBLER |

These tiers are intended for gameplay feedback and are not medical assessments.

---

## 💻 Compilation

### Using GCC

Open a terminal in the project directory and run:

```bash
gcc reactiontimegame2.c -o reactiontimegame2
```

### Run on Windows

```bash
reactiontimegame2.exe
```

or:

```bash
.\reactiontimegame2.exe
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
game2/
├── reactiontimegame2.c
├── reactiontimegame2.exe
├── game2.mp4
└── README.md
```

### `reactiontimegame2.c`

Contains the complete source code for the Speed Tap Speedrun.

### `reactiontimegame2.exe`

Compiled Windows executable for running the game without recompiling the source.

### `game2.mp4`

Contains a gameplay demonstration of the program.

---

## 🔬 Project Purpose

Speed Tap Speedrun was developed as an educational interactive-gameplay prototype for exploring rapid alternating-key responses, accuracy, and motor-response performance.

The game demonstrates how simple interactive tasks can collect basic behavioral measurements such as response accuracy, split times, and tapping speed.

> **Disclaimer:** This is an educational/research prototype and is **not a medical diagnostic tool**.

---

## 👨‍💻 Author

**Aditya Ghosh**
