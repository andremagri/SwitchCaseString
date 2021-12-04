#pragma warning(disable : 4307) // disable warning for "integral constant overflow", during hash generation. It is not a problem for this hash algorithm

#include <iostream>
#include <string>

constexpr uint64_t FNV_offset_basis = 14695981039346656037U;
constexpr uint64_t FNV_prime = 1099511628211U;

uint64_t constexpr mix(char byte, uint64_t hash)
{
    return (hash == 0 ? FNV_offset_basis ^ byte : (hash * FNV_prime) ^ byte);
}

uint64_t constexpr hash(const char * m)
{
    return (*m) ? mix(*m, hash(m + 1)) : 0;
}


int main()
{
    std::cout << "Switch Case using string!\n\n";

    std::cout << "Enter a name: ";

    std::string value;
    std::cin >> value;

    std::string favoriteColor;
    
    switch (hash(value.c_str( )))  // This hash is calculated at run time
    {
        case hash("Mary"):  // This hash is calculated at compilation time
            favoriteColor = "Blue";
            break;
        case hash("John"):
            favoriteColor = "Yellow";
            break;
        case hash("Lisa"):
            favoriteColor = "Green";
            break;
        case hash("David"):
            favoriteColor = "Red";
            break;
            
        default:
            favoriteColor = "unknown";
    }

    std::cout << value << "'s favorite color is " << favoriteColor << std::endl;

}
