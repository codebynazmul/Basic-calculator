#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_HISTORY 100

// ===== HISTORY STORAGE =====
char history[MAX_HISTORY][100];
int historyCount = 0;

void addHistory(const char *entry) {
    if (historyCount < MAX_HISTORY) {
        strcpy(history[historyCount], entry);
        historyCount++;
    }
}

// ===== CROSS PLATFORM SLEEP =====
void delay(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

// ===== CLEAR SCREEN =====
void clearScreen() {
    fflush(stdout);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ===== ASCII SPLASH SCREEN =====
void showSplash() {
    clearScreen();
    const char *banner[] = {
        "_________        .__               .__          __                ",
        "\\_   ___ \\_____  |  |   ____  __ __|  | _____ _/  |_  ___________ ",
        "/    \\  \\/\\__  \\ |  | _/ ___\\|  |  \\  | \\__  \\\\   __\\/  _ \\_  __ \\",
        "\\     \\____/ __ \\|  |_\\  \\___|  |  /  |__/ __ \\|  | (  <_> )  | \\/",
        " \\______  (____  /____/\\___  >____/|____(____  /__|  \\____/|__|   ",
        "        \\/     \\/          \\/                \\/                   "
    };

    for (int i = 0; i < 6; i++) {
        printf("%s\n", banner[i]);
        delay(180);  // animation delay
    }

    printf("\n\nLoading Calculator...");
    delay(800);
}

// ===== FUNCTION DECLARATIONS =====
void basicCalculator();
void advancedCalculator();
long long factorial(int n);
void showHistory();

// ===== MAIN FUNCTION =====
int main() {
    int choice;

    showSplash(); // show ASCII animation first
    delay(600);

    do {
        clearScreen();
        printf("============================\n");
        printf("       SIMPLE CALCULATOR     \n");
        printf("============================\n");
        printf("1. Basic Operations (+, -, *, /)\n");
        printf("2. Advanced Operations (sqrt, power, factorial, sin, cos, tan)\n");
        printf("3. View History\n");
        printf("4. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
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
                showHistory();
                break;
            case 4:
                clearScreen();
                printf("\n====================================\n");
                printf("   Developed by: MD NAZMUL HASAN   \n");
                printf("====================================\n\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();

    } while (choice != 4);

    return 0;
}

// ===== SHOW HISTORY =====
void showHistory() {
    clearScreen();
    printf("========= HISTORY =========\n");

    if (historyCount == 0) {
        printf("No history available.\n");
        return;
    }

    for (int i = 0; i < historyCount; i++) {
        printf("%d. %s\n", i + 1, history[i]);
    }
    printf("===========================\n");
}

// ===== BASIC CALCULATOR =====
void basicCalculator() {
    float a, b, result;
    char op;

    clearScreen();
    printf("--- Basic Calculator ---\n");
    printf("Enter expression (a [+ - * /] b): ");

    if (scanf("%f %c %f", &a, &op, &b) != 3) {
        printf("Invalid input.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    char entry[100];

    switch (op) {
        case '+':
            result = a + b;
            printf("Result: %.2f\n", result);
            sprintf(entry, "%.2f + %.2f = %.2f", a, b, result);
            addHistory(entry);
            break;

        case '-':
            result = a - b;
            printf("Result: %.2f\n", result);
            sprintf(entry, "%.2f - %.2f = %.2f", a, b, result);
            addHistory(entry);
            break;

        case '*':
            result = a * b;
            printf("Result: %.2f\n", result);
            sprintf(entry, "%.2f * %.2f = %.2f", a, b, result);
            addHistory(entry);
            break;

        case '/':
            if (b == 0) {
                printf("Error! Division by zero.\n");
            } else {
                result = a / b;
                printf("Result: %.2f\n", result);
                sprintf(entry, "%.2f / %.2f = %.2f", a, b, result);
                addHistory(entry);
            }
            break;

        default:
            printf("Invalid operator!\n");
    }
}

// ===== ADVANCED CALCULATOR =====
void advancedCalculator() {
    int choice;
    double num, base, exp;
    int n;

    clearScreen();
    printf("--- Advanced Calculator ---\n");
    printf("1. Square Root\n");
    printf("2. Power\n");
    printf("3. Factorial\n");
    printf("4. Sine (sin)\n");
    printf("5. Cosine (cos)\n");
    printf("6. Tangent (tan)\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid input.\n");
        return;
    }

    char entry[100];

    switch (choice) {
        case 1:
            printf("Enter number: ");
            if (scanf("%lf", &num) != 1) { printf("Invalid input.\n"); return; }

            if (num < 0) {
                printf("Error! Negative number.\n");
            } else {
                double res = sqrt(num);
                printf("sqrt(%.2lf) = %.2lf\n", num, res);
                sprintf(entry, "sqrt(%.2lf) = %.2lf", num, res);
                addHistory(entry);
            }
            break;

        case 2:
            printf("Enter base: ");
            if (scanf("%lf", &base) != 1) { printf("Invalid input.\n"); return; }

            printf("Enter exponent: ");
            if (scanf("%lf", &exp) != 1) { printf("Invalid input.\n"); return; }

            double result;
            result = pow(base, exp);
            printf("Result: %.2lf\n", result);
            sprintf(entry, "%.2lf ^ %.2lf = %.2lf", base, exp, result);
            addHistory(entry);
            break;

        case 3:
            printf("Enter integer: ");
            if (scanf("%d", &n) != 1) { printf("Invalid input.\n"); return; }

            if (n < 0) {
                printf("Error! Negative factorial.\n");
            } else {
                long long fact = factorial(n);
                printf("%d! = %lld\n", n, fact);
                sprintf(entry, "%d! = %lld", n, fact);
                addHistory(entry);
            }
            break;

        case 4:
            printf("Enter angle (radians): ");
            if (scanf("%lf", &num) != 1) { printf("Invalid input.\n"); return; }

            printf("sin(%.2lf) = %.4lf\n", num, sin(num));
            sprintf(entry, "sin(%.2lf) = %.4lf", num, sin(num));
            addHistory(entry);
            break;

        case 5:
            printf("Enter angle (radians): ");
            if (scanf("%lf", &num) != 1) { printf("Invalid input.\n"); return; }

            printf("cos(%.2lf) = %.4lf\n", num, cos(num));
            sprintf(entry, "cos(%.2lf) = %.4lf", num, cos(num));
            addHistory(entry);
            break;

        case 6:
            printf("Enter angle (radians): ");
            if (scanf("%lf", &num) != 1) { printf("Invalid input.\n"); return; }

            printf("tan(%.2lf) = %.4lf\n", num, tan(num));
            sprintf(entry, "tan(%.2lf) = %.4lf", num, tan(num));
            addHistory(entry);
            break;

        default:
            printf("Invalid choice!\n");
    }
}

// ===== FACTORIAL =====
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
