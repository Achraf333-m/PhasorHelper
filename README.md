# AC Phasor Helper

**AC Phasor Helper** is a starter project; a CLI-based tool designed for electrical engineering students. It allows manipulation and conversion of complex numbers in **polar** and **rectangular** form — ideal for solving AC circuit problems involving phasors.

This project was inspired by an assignment from my *Programming Methodology* class, where I used operator overloading to handle complex number operations. I’ve since expanded it into a more practical and scalable tool for AC analysis.

---

## Features

- Convert between **polar** and **rectangular** forms
- Generate **sinusoidal expressions** from phasor forms, using frequency
- Perform **addition, multiplication, and division** of complex numbers (rectangular/polar form)
- Apply **Ohm’s Law** using complex impedance and phasors
- Solve **2×2 systems** using **Cramer’s Rule**

---

## How to Use

### Option 1: Run Executable (Windows)

Download the `.exe` file and run it from your terminal or double-click in your file explorer.

### Option 2: Build from Source

```bash
git clone https://github.com/Achraf333-m/PhasorHelper.git
cd PhasorHelper
g++ -o PhasorHelper AlternateCurrentHelper.cpp
./PhasorHelper
```
*make sure your IDE compiles all the .cpp files -> "*.cpp"*