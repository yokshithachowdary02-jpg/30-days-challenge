#include <stdio.h>
#include <math.h>

void showMenu() {
    printf("\n=== Menu Options ===\n");
    printf("1. Solve a linear equation (ax + b = 0)\n");
    printf("2. Calculate factorial (n!)\n");
    printf("3. Solve a quadratic equation (ax^2 + bx + c = 0)\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Linear Equation: ax + b = 0
                double a, b;

                printf("\nEnter coefficients for ax + b = 0:\n");
                printf("Enter a: ");
                scanf("%lf", &a);
                printf("Enter b: ");
                scanf("%lf", &b);

                if (a == 0) {
                    if (b == 0) {
                        printf("Infinitely many solutions.\n");
                    } else {
                        printf("No solution.\n");
                    }
                } else {
                    double x = -b / a;
                    printf("Solution: x = %.4f\n", x);
                }
                break;
            }

            case 2: {
                // Factorial: n! (0 to 12 only)
                int n;

                printf("\nEnter an integer (0 to 12): ");
                scanf("%d", &n);

                if (n < 0 || n > 12) {
                    printf("Error: Input must be between 0 and 12 only.\n");
                } else {
                    long long factorial = 1;

                    for (int i = 1; i <= n; i++) {
                        factorial *= i;
                    }

                    printf("%d! = %lld\n", n, factorial);
                }
                break;
            }

            case 3: {
                // Quadratic Equation: ax^2 + bx + c = 0
                double a, b, c;

                printf("\nEnter coefficients for ax^2 + bx + c = 0:\n");
                printf("Enter a: ");
                scanf("%lf", &a);
                printf("Enter b: ");
                scanf("%lf", &b);
                printf("Enter c: ");
                scanf("%lf", &c);

                if (a == 0) {
                    printf("Invalid quadratic equation (a cannot be 0).\n");
                } else {
                    double discriminant = (b * b) - (4 * a * c);

                    if (discriminant > 0) {
                        double root1 = (-b + sqrt(discriminant)) / (2 * a);
                        double root2 = (-b - sqrt(discriminant)) / (2 * a);

                        printf("Type of roots: Two distinct real roots.\n");
                        printf("Root 1 = %.4f\n", root1);
                        printf("Root 2 = %.4f\n", root2);
                    } else if (discriminant == 0) {
                        double root = -b / (2 * a);

                        printf("Type of roots: Two equal real roots.\n");
                        printf("Root = %.4f\n", root);
                    } else {
                        printf("Type of roots: Complex roots (No real roots exist).\n");
                    }
                }
                break;
            }

            case 4:
                printf("\nThank you for using the program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option from 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}
