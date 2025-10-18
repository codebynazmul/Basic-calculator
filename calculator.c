#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
void clearScreen();
void basicCalculator();
void advancedCalculator();
long long factorial(int n);

int main() {
    int choice;

    do {
        clearScreen();
        printf("============================\n");
        printf("       SIMPLE CALCULATOR     \n");
        printf("============================\n");
        printf("1. Basic Operations (+, -, *, /)\n");
        printf("2. Advanced Operations (sqrt, power, factorial)\n");
        printf("3. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {} // flush
            choice = 0;
        }

        switch (choice) {
            case 1:
                basicCalculator();
                break;
            case 2:
                advancedCalculator();
                break;
            case 3:
                clearScreen();
                printf("\n====================================\n");
                printf("   Developed by: MD NAZMUL HASAN   \n");
                printf("====================================\n\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();

    } while (choice != 3);

    return 0;
}


void clearScreen() {
    fflush(stdout);
    int ret = 0;
#ifdef _WIN32
    ret = system("cls");
#else
    ret = system("clear");
#endif
    if (ret != 0) {
        for (int i = 0; i < 50; i++) {
            putchar('\n');
        }
        fflush(stdout);
    }
}


void basicCalculator() {
    float a, b, result;
    char op;

    clearScreen();
    printf("--- Basic Calculator ---\n");
    printf("Enter expression (a [+ - * /] b): ");
    if (scanf("%f %c %f", &a, &op, &b) != 3) {
        printf("Invalid input format.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    switch (op) {
        case '+':
            result = a + b;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = a - b;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = a * b;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (b == 0)
                printf("Error! Division by zero.\n");
            else {
                result = a / b;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid operator!\n");
    }
}


void advancedCalculator() {
    int choice;
    double num, base, exp;
    int n;

    clearScreen();
    printf("--- Advanced Calculator ---\n");
    printf("1. Square Root\n");
    printf("2. Power\n");
    printf("3. Factorial\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid input.\n");
        return;
    }

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            if (scanf("%lf", &num) != 1) { printf("Invalid input.\n"); return; }
            if (num < 0)
                printf("Error! Negative number.\n");
            else
                printf("Square root of %.2lf = %.2lf\n", num, sqrt(num));
            break;

        case 2:
            printf("Enter base: ");
            if (scanf("%lf", &base) != 1) { printf("Invalid input.\n"); return; }
            printf("Enter exponent: ");
            if (scanf("%lf", &exp) != 1) { printf("Invalid input.\n"); return; }
            printf("Result: %.2lf\n", pow(base, exp));
            break;

        case 3:
            printf("Enter an integer: ");
            if (scanf("%d", &n) != 1) { printf("Invalid input.\n"); return; }
            if (n < 0)
                printf("Error! Factorial of negative number doesn't exist.\n");
            else
                printf("Factorial of %d = %lld\n", n, factorial(n));
            break;

        default:
            printf("Invalid choice!\n");
    }
}


long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
