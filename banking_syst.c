#include <stdio.h>
#include <string.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int choice, sub_choice, pin, correct_pin = 0, new_pin, confirm_pin;
    int initial_deposit, account_number = 0, amount, agent_number;
    char name[50] = "";
    char username[20] = "";
    char login_username[20];
    float balance = 0.00;
    int running = 1, account_exists = 0;

    while (running == 1) {
        printf("\n\n====== BANKING SYSTEM ======\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("\nChoice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1: // Create Account
                printf("\n====== CREATE ACCOUNT ======\n");
                printf("Enter Full Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter Username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;

                printf("Enter Account Number: ");
                if (scanf("%d", &account_number) != 1) {
                    printf("Invalid account number.\n");
                    clearBuffer();
                    break;
                }

                printf("Enter Initial Deposit (Min Kshs. 100): ");
                if (scanf("%d", &initial_deposit) != 1 || initial_deposit < 100) {
                    printf("Account creation failed! Minimum initial deposit is Kshs. 100\n");
                    clearBuffer();
                    break;
                }

                printf("Set a 4-digit PIN: ");
                if (scanf("%d", &correct_pin) != 1) {
                    printf("Invalid PIN format.\n");
                    clearBuffer();
                    break;
                }
                clearBuffer();

                balance = (float)initial_deposit;
                account_exists = 1;

                printf("\n✅ Account created successfully!");
                printf("\nWelcome %s! Your Account Number is: %d\n", name, account_number);
                break;

            case 2: // Login
                if (!account_exists) {
                    printf("\n❌ No account found. Please create an account first.\n");
                    break;
                }

                printf("\n====== LOGIN ======\n");
                printf("Enter Username: ");
                fgets(login_username, sizeof(login_username), stdin);
                login_username[strcspn(login_username, "\n")] = 0;

                printf("Enter PIN: ");
                if (scanf("%d", &pin) != 1) {
                    printf("\nInvalid PIN format.\n");
                    clearBuffer();
                    break;
                }
                clearBuffer();

                // Validate both username and PIN
                if (strcmp(login_username, username) != 0 || pin != correct_pin) {
                    printf("\n❌ Invalid Username or PIN.\n");
                    break;
                }

                // Logged-in session loop
                int logged_in = 1;
                while (logged_in) {
                    printf("\n\n====== ACCOUNT MENU ======\n");
                    printf("Welcome, %s\n", name);
                    printf("1. Check Balance\n");
                    printf("2. Deposit\n");
                    printf("3. Withdraw\n");
                    printf("4. Change PIN\n");
                    printf("5. Logout\n");
                    printf("\nChoice: ");

                    if (scanf("%d", &sub_choice) != 1) {
                        printf("\nInvalid choice!\n");
                        clearBuffer();
                        continue;
                    }
                    clearBuffer();

                    switch (sub_choice) {
                        case 1: // Check Balance
                            printf("\nYour current balance is: Kshs. %.2f\n", balance);
                            break;

                        case 2: // Deposit
                            printf("\nEnter Deposit Amount: ");
                            if (scanf("%d", &amount) != 1 || amount <= 0) {
                                printf("Invalid deposit amount.\n");
                                clearBuffer();
                            } else {
                                clearBuffer();
                                balance += amount;
                                printf("✅ Deposit successful. New balance: Kshs. %.2f\n", balance);
                            }
                            break;

                        case 3: // Withdraw
                            printf("\nSelect Withdrawal Method:\n");
                            printf("1. Agent (Min 100, Max 20,000)\n");
                            printf("2. ATM (Min 200, Max 40,000)\n");
                            printf("Choose: ");

                            int withdraw_method;
                            if (scanf("%d", &withdraw_method) != 1) {
                                printf("Invalid choice.\n");
                                clearBuffer();
                                break;
                            }
                            clearBuffer();

                            if (withdraw_method == 1) { // Agent
                                printf("\nEnter Amount: ");
                                scanf("%d", &amount);
                                printf("Enter Agent Number: ");
                                scanf("%d", &agent_number);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                clearBuffer();

                                if (pin != correct_pin) {
                                    printf("\n❌ Incorrect PIN.");
                                } else if (amount < 100) {
                                    printf("\n❌ Minimum withdrawal is Kshs. 100.");
                                } else if (amount > 20000) {
                                    printf("\n❌ Maximum withdrawal is Kshs. 20,000.");
                                } else if ((float)amount > balance) {
                                    printf("\n❌ Insufficient Balance.");
                                } else {
                                    balance -= amount;
                                    printf("\n✅ Successful withdrawal of Kshs. %d from Agent %d.", amount, agent_number);
                                    printf("\nNew balance: Kshs. %.2f\n", balance);
                                }
                            } else if (withdraw_method == 2) { // ATM
                                printf("\nEnter Amount: ");
                                scanf("%d", &amount);
                                printf("Enter PIN: ");
                                scanf("%d", &pin);
                                clearBuffer();

                                if (pin != correct_pin) {
                                    printf("\n❌ Incorrect PIN.");
                                } else if (amount < 200) {
                                    printf("\n❌ Minimum withdrawal is Kshs. 200.");
                                } else if (amount > 40000) {
                                    printf("\n❌ Maximum withdrawal is Kshs. 40,000.");
                                } else if ((float)amount > balance) {
                                    printf("\n❌ Insufficient Balance.");
                                } else {
                                    balance -= amount;
                                    printf("\n✅ Successful ATM withdrawal of Kshs. %d.", amount);
                                    printf("\nNew balance: Kshs. %.2f\n", balance);
                                }
                            } else {
                                printf("\nInvalid option.\n");
                            }
                            break;

                        case 4: // Change PIN
                            printf("\nEnter Current PIN: ");
                            scanf("%d", &pin);
                            printf("Enter New PIN: ");
                            scanf("%d", &new_pin);
                            printf("Confirm New PIN: ");
                            scanf("%d", &confirm_pin);
                            clearBuffer();

                            if (pin != correct_pin) {
                                printf("\n❌ Incorrect Current PIN.");
                            } else if (new_pin != confirm_pin) {
                                printf("\n❌ New PINs do not match.");
                            } else {
                                correct_pin = new_pin;
                                printf("\n✅ PIN changed successfully!");
                            }
                            break;

                        case 5: // Logout
                            printf("\nLogged out successfully!\n");
                            logged_in = 0;
                            break;

                        default:
                            printf("\nInvalid choice!\n");
                    }
                }
                break;

            case 3: // Exit
                printf("\nThank you for using our Banking System!\n");
                running = 0;
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
