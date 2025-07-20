#include <iostream>
#include <cmath>
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void print_welcome_banner() {
    cout << "\n**********************************************\n";
    cout << "*                                            *\n";
    cout << "*      WELCOME TO THE ADVANCED CALCULATOR    *\n";
    cout << "*                                            *\n";
    cout << "**********************************************\n\n";
}

unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void matrix_operations() {
    int choice;
    cout << "Choose matrix operation:\n";
    cout << "1. 2x2 Matrix Multiplication\n";
    cout << "2. 3x3 Matrix Multiplication\n";
    cout << "3. 2x2 Determinant\n";
    cout << "4. 3x3 Determinant\n";
    cout << "5. 3x3 Matrix Addition\n";
    cout << "6. 2x2 Matrix Addition\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        int a[2][2], b[2][2], product[2][2] = { {0,0},{0,0} };
        cout << "Enter elements of first 2x2 matrix:\n";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> a[i][j];

        cout << "Enter elements of second 2x2 matrix:\n";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> b[i][j];

        cout << "Matrix Multiplication:\n";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k)
                    product[i][j] += a[i][k] * b[k][j];
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 2) {
        int a[3][3], b[3][3], product[3][3] = { {0} };
        cout << "Enter elements of first 3x3 matrix:\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> a[i][j];

        cout << "Enter elements of second 3x3 matrix:\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> b[i][j];

        cout << "Matrix Multiplication:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k)
                    product[i][j] += a[i][k] * b[k][j];
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 3) {
        int m[2][2];
        cout << "Enter elements of 2x2 matrix:\n";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> m[i][j];

        int det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
        cout << "Determinant: " << det << endl;
    }
    else if (choice == 4) {
        int m[3][3];
        cout << "Enter elements of 3x3 matrix:\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> m[i][j];

        int det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
            - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
            + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
        cout << "Determinant: " << det << endl;
    }
    else if (choice == 5) {
        int a[3][3], b[3][3];
        cout << "Enter elements of first 3x3 matrix:\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> a[i][j];

        cout << "Enter elements of second 3x3 matrix:\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> b[i][j];

        cout << "Matrix Addition:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << a[i][j] + b[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (choice == 6) {
        int a[2][2], b[2][2];
        cout << "Enter elements of first 2x2 matrix:\n";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> a[i][j];

        cout << "Enter elements of second 2x2 matrix:\n";
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> b[i][j];

        cout << "Matrix Addition:\n";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cout << a[i][j] + b[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

void statistics_tools() {
    int n;
    cout << "How many numbers? ";
    cin >> n;
    vector<double> data(n);
    cout << "Enter numbers: ";
    for (int i = 0; i < n; ++i)
        cin >> data[i];

    double sum = 0;
    for (double x : data) sum += x;
    double mean = sum / n;
    sort(data.begin(), data.end());
    double median = (n % 2 == 0) ? (data[n / 2 - 1] + data[n / 2]) / 2 : data[n / 2];

    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Min: " << data.front() << ", Max: " << data.back() << endl;
}

void unit_converter() {
    string type;
    cout << "Enter conversion type (length, weight, temperature): ";
    cin >> type;

    if (type == "length") {
        double m;
        cout << "Enter meters: ";
        cin >> m;
        cout << m << " m = " << m * 100 << " cm = " << m * 39.3701 << " in" << endl;
    }
    else if (type == "weight") {
        double kg;
        cout << "Enter kilograms: ";
        cin >> kg;
        cout << kg << " kg = " << kg * 1000 << " g = " << kg * 2.20462 << " lbs" << endl;
    }
    else if (type == "temperature") {
        double c;
        cout << "Enter Celsius: ";
        cin >> c;
        cout << c << " C = " << (c * 9 / 5 + 32) << " F = " << (c + 273.15) << " K" << endl;
    }
    else {
        cout << "Invalid type." << endl;
    }
}
int main() {
    srand(time(0));
    double num1, num2, result;
    int choice;
    string op;

    print_welcome_banner();
    cout << "  ******************************************" << endl;
    cout << "  *        SELECT A CALCULATOR MODE        *" << endl;
    cout << "  ******************************************" << endl;

    cout << "\n           --- Basic Operations ---\n";
    cout << "[1] Basic Arithmetic (+, -, *, /)\n";
    cout << "[2] Trigonometric Functions (sin, cos, tan, cot, arcsin, arccos, arctan, arccot)\n";
    cout << "[3] Log/Exponential (log10, ln, sqrt, pow, exp)\n";

    cout << "\n           --- Math Utilities ---\n";
    cout << "[4] Modulus / Absolute / Factorial\n";
    cout << "[5] Number System Conversion (dec2bin, bin2dec, dec2hex, hex2dec)\n";
    cout << "[6] Mid-Level Math Tools (gcd, lcm, isprime, randint, deg2rad, rad2deg)\n";
    cout << "[7] Advanced Complex Number Tools(complex_add, complex_mul, norm, conj\n";

    cout << "\n           --- Matrix and Data Tools ---\n";
    cout << "[8] Matrix Operations\n";
    cout << "[9] Statistics Tools (mean, median, min, max)\n";
    cout << "[10] Unit Converter (length, weight, temp)\n";

    cout << "\nYour choice: ";

    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        if (op == "+") result = num1 + num2;
        else if (op == "-") result = num1 - num2;
        else if (op == "*") result = num1 * num2;
        else if (op == "/") {
            if (num2 == 0) {
                cout << "Division by zero is not allowed!" << endl;
                return 0;
            }
            result = num1 / num2;
        }
        else {
            cout << "Invalid operator!" << endl;
            return 0;
        }
        break;

    case 2:
        cout << "Enter operator (sin, cos, tan, cot, arcsin, arccos, arctan, arccot): ";
        cin >> op;
        cout << "Enter the number: ";
        cin >> num1;

        if (op == "sin")
            result = sin(num1 * M_PI / 180);
        else if (op == "cos")
            result = cos(num1 * M_PI / 180);
        else if (op == "tan")
            result = tan(num1 * M_PI / 180);
        else if (op == "cot")
            result = 1.0 / tan(num1 * M_PI / 180);
        else if (op == "arcsin") {
            if (num1 < -1 || num1 > 1) {
                cout << "Invalid input (arcsin requires -1 <= x <= 1)!" << endl;
                return 0;
            }
            result = asin(num1) * 180 / M_PI;
        }
        else if (op == "arccos") {
            if (num1 < -1 || num1 > 1) {
                cout << "Invalid input (arccos requires -1 <= x <= 1)!" << endl;
                return 0;
            }
            result = acos(num1) * 180 / M_PI;
        }
        else if (op == "arctan")
            result = atan(num1) * 180 / M_PI;
        else if (op == "arccot")
            result = atan(1.0 / num1) * 180 / M_PI;
        else {
            cout << "Unknown trigonometric operator!" << endl;
            return 0;
        }
        break;

    case 3:
        cout << "Enter operator (log10, ln, sqrt, pow, exp): ";
        cin >> op;

        if (op == "log10") {
            cout << "Enter number: ";
            cin >> num1;
            result = log10(num1);
        }
        else if (op == "ln") {
            cout << "Enter number: ";
            cin >> num1;
            result = log(num1);
        }
        else if (op == "sqrt") {
            cout << "Enter number: ";
            cin >> num1;
            result = sqrt(num1);
        }
        else if (op == "exp") {
            cout << "Enter number: ";
            cin >> num1;
            result = exp(num1);
        }
        else if (op == "pow") {
            cout << "Enter base: ";
            cin >> num1;
            cout << "Enter exponent: ";
            cin >> num2;
            result = pow(num1, num2);
        }
        else {
            cout << "Invalid operator!" << endl;
            return 0;
        }
        break;

    case 4:
        cout << "Enter operator (mod, abs, fact): ";
        cin >> op;

        if (op == "mod") {
            int a, b;
            cout << "Enter number 1: ";
            cin >> a;
            cout << "Enter number 2: ";
            cin >> b;
            if (b == 0) {
                cout << "Division by zero is not allowed!" << endl;
                return 0;
            }
            result = a % b;
        }
        else if (op == "abs") {
            cout << "Enter number: ";
            cin >> num1;
            result = fabs(num1);
        }
        else if (op == "fact") {
            int n;
            cout << "Enter number (non-negative integer): ";
            cin >> n;
            result = factorial(n);
        }
        else {
            cout << "Invalid operator!" << endl;
            return 0;
        }
        break;

    case 5:
        cout << "Enter conversion type (dec2bin, bin2dec, dec2hex, hex2dec): ";
        cin >> op;

        if (op == "dec2bin") {
            int n;
            cout << "Enter decimal number: ";
            cin >> n;
            string binary = bitset<32>(n).to_string();
            binary.erase(0, binary.find_first_not_of('0'));
            if (binary == "") binary = "0";
            cout << "Binary: " << binary << endl;
            return 0;
        }
        else if (op == "bin2dec") {
            string bin;
            cout << "Enter binary number: ";
            cin >> bin;
            int dec = stoi(bin, nullptr, 2);
            cout << "Decimal: " << dec << endl;
            return 0;
        }
        else if (op == "dec2hex") {
            int n;
            cout << "Enter decimal number: ";
            cin >> n;
            cout << "Hexadecimal: " << hex << n << endl;
            return 0;
        }
        else if (op == "hex2dec") {
            string hexStr;
            cout << "Enter hexadecimal number: ";
            cin >> hexStr;
            int dec = stoi(hexStr, nullptr, 16);
            cout << "Decimal: " << dec << endl;
            return 0;
        }
        else {
            cout << "Invalid conversion type!" << endl;
            return 0;
        }
        break;

    case 6:
        cout << "Enter operator (gcd, lcm, isprime, randint, deg2rad, rad2deg): ";
        cin >> op;

        if (op == "gcd") {
            int a, b;
            cout << "Enter first number: "; cin >> a;
            cout << "Enter second number: "; cin >> b;
            cout << "GCD: " << gcd(a, b) << endl;
        }
        else if (op == "lcm") {
            int a, b;
            cout << "Enter first number: "; cin >> a;
            cout << "Enter second number: "; cin >> b;
            cout << "LCM: " << lcm(a, b) << endl;
        }
        else if (op == "isprime") {
            int n;
            cout << "Enter number: "; cin >> n;
            cout << (isPrime(n) ? "Prime" : "Not Prime") << endl;
        }
        else if (op == "randint") {
            int min, max;
            cout << "Enter min: "; cin >> min;
            cout << "Enter max: "; cin >> max;
            cout << "Random number: " << (rand() % (max - min + 1) + min) << endl;
        }
        else if (op == "deg2rad") {
            double deg;
            cout << "Enter degrees: "; cin >> deg;
            cout << "Radians: " << deg * M_PI / 180 << endl;
        }
        else if (op == "rad2deg") {
            double rad;
            cout << "Enter radians: "; cin >> rad;
            cout << "Degrees: " << rad * 180 / M_PI << endl;
        }
        else {
            cout << "Invalid mid-level math operator!" << endl;
        }
        break;
    case 7:
        cout << "Enter operator (complex_add, complex_mul, norm, conj): ";
        cin >> op;

        if (op == "complex_add" || op == "complex_mul") {
            double r1, i1, r2, i2;
            cout << "Enter real part of first number: "; cin >> r1;
            cout << "Enter imaginary part of first number: "; cin >> i1;
            cout << "Enter real part of second number: "; cin >> r2;
            cout << "Enter imaginary part of second number: "; cin >> i2;

            complex<double> c1(r1, i1), c2(r2, i2);
            complex<double> cresult = (op == "complex_add") ? c1 + c2 : c1 * c2;
            cout << "Result: " << cresult << endl;
        }
        else if (op == "norm") {
            double r, i;
            cout << "Enter real part: "; cin >> r;
            cout << "Enter imaginary part: "; cin >> i;
            complex<double> c(r, i);
            cout << "Norm: " << norm(c) << endl;
        }
        else if (op == "conj") {
            double r, i;
            cout << "Enter real part: "; cin >> r;
            cout << "Enter imaginary part: "; cin >> i;
            complex<double> c(r, i);
            cout << "Conjugate: " << conj(c) << endl;
        }
        else {
            cout << "Invalid advanced math operator!" << endl;
        }
        break;
    case 8:
        matrix_operations();
        break;
    case 9:
        statistics_tools();
        break;
    case 10:
        unit_converter();
        break;

        default:
        cout << "Invalid category selection!" << endl;
        return 0;
    }

    if (choice >= 1 && choice <= 4)
        cout << "Result: " << result << endl;

    return 0;
}