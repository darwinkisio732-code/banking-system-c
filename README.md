Here is the copy-and-paste ready README.md for your Banking System program:

Markdown
# Simple Banking System

A lightweight, interactive command-line banking application written in C. It supports account creation, authentication, deposits, withdrawals via Agent or ATM, PIN changes, and real-time balance tracking.

## Features

- **Account Registration:** Create an account with user details, account number, set a 4-digit PIN, and set an initial deposit (Min: Kshs. 100).
- **Secure Authentication:** Validates both registered username and PIN before unlocking account access.
- **Deposit Funds:** Add money to your balance dynamically.
- **Flexible Withdrawals:**
  - **Agent:** Min Kshs. 100 / Max Kshs. 20,000 (Requires Agent Number & PIN confirmation)
  - **ATM:** Min Kshs. 200 / Max Kshs. 40,000 (Requires PIN confirmation)
- **PIN Management:** Safely update your account PIN with current PIN verification and confirmation matching.
- **Buffer Safety:** Employs robust input buffer handling (`clearBuffer()` and `fgets`) to prevent menu-skipping bugs and terminal crashes.

## How to Compile & Run

### Prerequisites
- GCC Compiler (or any standard C compiler)

### Commands

1. **Compile the program:**
   ```bash
   gcc banking_system.c -o banking_system
Run the program:

Bash
./banking_system
Menu Options
Plaintext
====== BANKING SYSTEM ======
1. Create Account
2. Login
3. Exit
Account Options (Post-Login)
Plaintext
====== ACCOUNT MENU ======
1. Check Balance
2. Deposit
3. Withdraw
4. Change PIN
5. Logout
Example Run
Plaintext
====== BANKING SYSTEM ======
1. Create Account
2. Login
3. Exit

Choice: 1

====== CREATE ACCOUNT ======
Enter Full Name: Darwin Kisio
Enter Username: darwin
Enter Account Number: 100234
Enter Initial Deposit (Min Kshs. 100): 500
Set a 4-digit PIN: 1234

✅ Account created successfully!
Welcome Darwin Kisio! Your Account Number is: 100234
Requirements
Standard C library (stdio.h, string.h)

Windows / Linux / macOS terminal environment
