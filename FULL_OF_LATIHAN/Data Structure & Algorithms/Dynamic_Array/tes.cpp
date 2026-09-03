#include <iostream>
#include <cctype> // Diperlukan untuk isalnum

int main() {
    char karakter1 = 'A';
    char karakter2 = '7';
    char karakter3 = '#';

    // Memeriksa karakter1
    if (isalnum(karakter1)) {
        std::cout << karakter1 << " adalah alfanumerik.\n";
    }

    // Memeriksa karakter2
    if (isalnum(karakter2)) {
        std::cout << karakter2 << " adalah alfanumerik.\n";
    }

    // Memeriksa karakter3
    if (!isalnum(karakter3)) {
        std::cout << karakter3 << " BUKAN alfanumerik.\n";
    }

    return 0;
}
