# Timer

A simple **console-based stopwatch & countdown timer** written in C. This project demonstrates how to build a small C application using CMake, and how to generate both a native Linux executable (`timer`) and a Windows-style executable (`timer.exe`) along with a helper shell script (`run_timer.sh`)


## 🎯 Features

- **Stopwatch** 
  - Start/stop by pressing Enter 
  - Displays elapsed time in seconds with two-decimal precision 

- **Countdown Timer** 
  - Enter a number of seconds (integer) 
  - Shows remaining time in `MM:SS` format, updated every second 
  - Alerts “Time’s up!” with a bell character (`\a`) when finished 
  
  
## 🔧 Prerequisites

Before you begin, ensure that you have the following installed on your system:

- **C compiler** (e.g. `gcc` or `clang`) 
- **CMake** (version 3.10 or newer) 
- **Ninja** (or any other CMake generator, though Ninja is assumed below) 


## 🚀 Getting Started

Depending on what OS you are running, **Clone or download** this repository to your local machine:

   **If you use Linux**
     
     1. git clone https://github.com/Zzorro-Kid/Timer.git
     2. Go to Downloads
     3. Go to Timer 
     4. Run: `run_timer.sh`
     
   **If you use Windows**
   
     1. Download project archive 
     2. Go to Downloads  
     3. Unzip Timer archive to a folder or location convenient for you
     4. Go to Timer  
     5. Run: `timer.exe`
