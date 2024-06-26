# SmartCalc v2.0

SmartCalc v2.0 is a comprehensive calculator program implemented in C++17, featuring a graphical user interface (GUI) built with the Qt library. This project was developed as part of a student assignment, adhering to strict specifications and best practices in software architecture.

## Features

- **Expression Calculation**: The program supports the evaluation of arbitrary bracketed arithmetic expressions in infix notation, including the use of both integers and real numbers.
![Calculator mode](misc/images/calc.png)
- **Arithmetic Operations**: Supports a wide range of arithmetic operators and mathematical functions, including addition, subtraction, multiplication, division, exponentiation, modulus, and various trigonometric and logarithmic functions. The accuracy of the fractional part to at least 13 decimal places. Users can input expressions of up to 255 characters in length.
- **Graph Plotting**: Users can plot graphs of functions specified by infix notation expressions with a variable 'x', with support for customizing the domain and codomain.
![Graph mode](misc/images/graph.png)
- **Credit Calculator**: Includes a special mode for calculating credit payments, providing details such as monthly payments, overpayment on credit, and total payment.
![Credit mode](misc/images/bank1.png)
- **Deposit Calculator**: Offers a deposit profitability calculator, allowing users to calculate accrued interest, tax amounts, and final deposit amounts based on various parameters.
![Deposit mode](misc/images/bank2.png)
- **Unit Testing**: Full coverage of expression calculation modules is ensured through unit tests using the GTest library.
- **MVC Architecture**: Implemented following the Model-View-Controller (MVC) pattern, ensuring separation of concerns and maintainability.

## Prerequisites

Before you can build and run SmartCalc v2.0, ensure that you have the following dependencies installed:

- **G++** 
- **Qt Libraries**: Qt5, Qt6, including the following components:
  - Widgets
  - PrintSupport
- **Make**
- **Cmake**
- **Additional Dependencies**: 
  - GTest: If you plan to run unit tests, you'll need the GTest library installed.

## Installation

```bash
git clone git@github.com:queeju/SmartCalc_CPP.git
cd SmartCalc_CPP
make
```
