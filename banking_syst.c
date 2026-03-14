#include <stdio.h>
#include <string.h>

int main() {
    int choice, sub_choice, pin, correct_pin, new_pin, initial_deposit, account_number, amount, agent_number;
    char name[50];
    char username[20];
    float balance = 0.00;
    int running = 1, account_exists = 0;

    while(running == 1) {
        printf("\n\n======BANKING SYSTEM======\n");
        printf("\n1. Create Account");
        printf("\n2. Login");
        printf("\n3. Exit");

        printf("\n\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n\n======CREATE ACCOUNT======\n");
                printf("\nEnter Your name: ");
                scanf("%s", name);
                printf("\nEnter Username: ");
                scanf("%s", username);
                printf("\nEnter a valid Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Initial Deposit: ");  
                scanf("%d", &initial_deposit);
                printf("Set a 4-digit PIN: ");
                scanf("%d", &correct_pin);

                if(initial_deposit < 100) {
                    printf("Minimum initial deposit is Kshs. 100\n");
                } else {
                    printf("Account created successfully!\n");
                    printf("\nYour PIN is: %d", correct_pin);
                }
                account_exists = 1;
                balance = initial_deposit;
                break;

            case 2: // Login
                if(!account_exists) {
                    printf("\nNo account found. Please create an account first.\n");
                    break;
                }
                
                // Ask for login credentials ONCE
                printf("\n\n======LOGIN======\n");
                printf("Enter Username: ");
                scanf("%s", username);
                printf("Enter PIN: ");
                scanf("%d", &pin);
                
                if(pin != correct_pin) {
                    printf("\n❌ Incorrect PIN.\n");
                    break;
                }
                
                // Successful login - show account menu
                int logged_in = 1;
                while(logged_in) {
                    printf("\n\n======ACCOUNT MENU======\n");
                    printf("Welcome %s\n", name);
                    printf("1. Check Balance\n");
                    printf("2. Deposit\n");
                    printf("3. Withdraw\n");
                    printf("4. Change PIN\n");
                    printf("5. Logout\n");
                    printf("\nChoice: ");
                    scanf("%d", &sub_choice);

                    switch(sub_choice) {
                        case 1: 
                            printf("\nYour Balance is: Kshs. %.2f\n", balance);
                            break;
                            
                        case 2:
                            printf("\nEnter Deposit Amount: ");
                            scanf("%d", &amount);
                            if (amount <= 0) {
                                printf("Invalid deposit amount.\n");
                            } else {
                                balance += amount;
                                printf("Deposit successful. New balance is Kshs. %.2f\n", balance);
                            }
                            break;
                            
                        case 3:
                            printf("\nWithdrawal:");
                            printf("\n1. Agent");
                            printf("\n2. ATM");
                            printf("\nChoose: ");
                            scanf("%d", &sub_choice);

                            switch(sub_choice) {
                                case 1:
                                    printf("\nEnter Amount: ");
                                    scanf("%d", &amount);
                                    printf("Enter Agent Number: ");
                                    scanf("%d", &agent_number);
                                    printf("Enter PIN: ");
                                    scanf("%d", &pin);
                                    
                                    if (pin != correct_pin) {
                                        printf("\nIncorrect PIN.");
                                    } else if (amount < 100) {
                                        printf("\nMinimum is Kshs. 100.");
                                    } else if (amount > 20000) {
                                        printf("\nMaximum is Kshs. 20,000.");
                                    } else if (amount > balance) {
                                        printf("\nInsufficient Balance.");
                                    } else {
                                        balance -= amount;
                                        printf("\nSuccessful withdrawal of Kshs. %.2f from Agent %d. New balance is Kshs. %.2f\n", 
                                               amount, agent_number, balance);
                                    }  
                                    break;
                                    
                                case 2:
                                    printf("\nEnter Amount: ");
                                    scanf("%d", &amount);
                                    printf("Enter PIN: ");
                                    scanf("%d", &pin);
                                    
                                    if (pin != correct_pin) {
                                        printf("\nIncorrect PIN.");
                                    } else if (amount < 200) {
                                        printf("\nMinimum is Kshs. 200.");
                                    } else if (amount > 40000) {
                                        printf("\nMaximum is Kshs. 40,000.");
                                    } else if (amount > balance) {
                                        printf("\nInsufficient Balance.");
                                    } else {
                                        balance -= amount;
                                        printf("\nSuccessful withdrawal of Kshs. %.2f from ATM. New balance is Kshs. %.2f\n", 
                                               amount, balance);
                                    }  
                                    break;
                            }
                            break;
                            
                        case 4:
                            printf("\nEnter Current PIN: ");
                            scanf("%d", &pin);
                            printf("\nEnter New PIN: ");
                            scanf("%d", &correct_pin);
                            printf("\nConfirm New PIN: ");
                            scanf("%d", &new_pin);
                            
                            if (pin != correct_pin) {
                                printf("\nIncorrect Current PIN.");
                            } else if (correct_pin != new_pin) {
                                printf("\nNew PINs do not match.");
                            } else {
                                printf("\nPIN changed successfully!");
                                correct_pin = new_pin;
                            }
                            break;
                            
                        case 5:
                            printf("\nLogged out successfully!\n");
                            logged_in = 0;
                            break;
                            
                        default:
                            printf("\nInvalid choice!\n");
                    }
                }
                break;
                
            case 3:
                printf("\nThank you for using our Banking System!\n");
                running = 0;
                break;
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}