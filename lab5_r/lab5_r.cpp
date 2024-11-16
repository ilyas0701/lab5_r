#include <fstream>
#include <iostream>

double calculateYPositiveX(double x, double n)
{
    double y = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (i != 0) {
            y += (x / i);
        }
    }

    return y;
}

double calculateYNegativeX(double x, double n)
{
    double y = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            y += (x - i + j);
        }
    }

    return y;
}


void checkValidInput()
{
    if (std::cin.fail()) {
        throw std::runtime_error("Invalid input expected a number.");
    }
}

void checkValidN(double n)
{
    if (n <= 3) {
        throw std::runtime_error("N must be >= 3");
    }
}


int main() {
    double a, b, h, n;

    std::ofstream file("result.txt");

    try
    {
        std::cout << "Enter a number:" << '\n';
        std::cin >> a;
        checkValidInput();

        std::cout << "Enter b number:" << '\n';
        std::cin >> b;
        checkValidInput();

        std::cout << "Enter h number:" << '\n';
        std::cin >> h;
        checkValidInput();

        std::cout << "Enter n number:" << '\n';
        std::cin >> n;
        checkValidInput();
        checkValidN(n);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception " << e.what() << std::endl;
        return -1;
    }


    double x = a;

    while (x <= b) {
        if (x < 0) {
            file << "x = " << x << ' ' << "y = " << calculateYNegativeX(x, n) << '\n'; // Write to the file in the specified format 
        }
        else {
            file << "x = " << x << ' ' << "y = " << calculateYPositiveX(x, n) << '\n'; //  // Write to the file in the specified format
        }

        x += h;
    }

    file.close();

    return 0;
}
