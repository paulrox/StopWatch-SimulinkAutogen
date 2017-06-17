# STM32F4 Stopwatch (Simulink FSM)

Stopwatch application for the STM32F4-Discovery board under Erika OS (Real-Time Operating System). The stopwatch core functionalities have been described using a Simulink Stateflow diagram. The FSM behavior has been tested directly in MATLAB using a GUI. The application has been displayed on the touchpad extension for the Discovery board and the FSM source code have been automatically generated using the MATLAB Embedded Coder.

## Getting Started

In order to compile the application, you need:

* [Erika Enterprise](http://erika.tuxfamily.org/drupal/download.html) - OS used on top of the STM32F4-Discovery board.

I suggest to download the IDE version and simply import this project in the IDE and compile it from there.

The obtained `.elf` file can be used to flash the board.

## Running the application

The FSM behavior can be tested directly in MATLAB by running the `SwatchModel.slx` Simulink model inside the `Model/` directory.

The real application will automatically start after flashing the binary obtained at the previous step.

## Author

* **Paolo Sassi** - [paulrox](https://github.com/paulrox)
