# my_radar

## Introduction

`my_radar` is a personal project that simulates air traffic control using a 2D visualization panel. This project, part of my Epitech curriculum, helps enhance my understanding of graphical programming, simulation systems, and C programming.

## Features

- Simulates aircrafts flying between points and control towers managing airspace.
- Displays aircrafts and control towers on a 1920x1080 pixel window.
- Handles aircraft collisions and control tower areas.
- User interactions for toggling hitboxes and sprites visibility.

## Installation

Follow these steps to set up `my_radar`:

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/jeremyarmijo/My_radar.git
    ```

2. **Navigate to the Project Directory:**

    ```bash
    cd my_radar
    ```

3. **Compile the Project:**

    ```bash
    make
    ```

## Usage

Run the `my_radar` command from the terminal with a script file as an argument:

```bash
./my_radar <path_to_script>
```

### Example

1. **Running a Simulation:**

    ```bash
    ./my_radar example.txt
    ```

    Example content of `example.txt`:

    ```
    #A pos_x pos_y final_pos_x final_pos_y speed delay_before_aircraft_takes_off
    A 815 321 1484 166 5 0
    A 1589 836 811 936 2 0
    A 202 894 103 34 3 0
    #T pos_x pos_y final_pos_x final_pos_y radius_of_tower_control
    T 93 47 19
    T 49 56 25
    ```