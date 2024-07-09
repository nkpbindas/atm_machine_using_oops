# ATM Machine System

This project is a simple ATM Machine System implemented in C++. It allows users to log in, check their balance, deposit funds, and withdraw funds. Account information is stored in a text file.

## Features

- *Login*: Users can log in using their account number and PIN.
- *Check Balance*: Users can view their current balance.
- *Deposit*: Users can deposit funds into their account.
- *Withdraw*: Users can withdraw funds from their account.

## Files

- main.cpp: Contains the main function and the implementation of the BankAccount class and other functions.
- file.txt: A text file where account information (account number, PIN, balance) is stored.

## Usage

1. *Compile the code*: Use a C++ compiler to compile the main.cpp file.

    sh
    g++ main.cpp -o atm_machine
    

2. *Run the program*:

    sh
    ./atm_machine
    

3. *Interact with the program*: Follow the on-screen instructions to log in and perform transactions.

## Sample Account File (file.txt)

The file.txt file should contain account information in the following format:

accountNumber1 pin1 balance1
accountNumber2 pin2 balance2

For example:

123456 1234 1000.50
987654 5678 200.00
