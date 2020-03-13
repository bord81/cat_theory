#include <string>

std::string function_1(int n) {
    std::string result;
    switch (n) {
        case 0:
            result = "q";
            break;
        case 1:
            result = "w";
            break;
        case 2:
            result = "e";
            break;
        case 3:
            result = "r";
            break;
        case 4:
            result = "t";
            break;
        case 5:
            result = "y";
            break;
        default:
            result = "Z";
    }
    return result;
}

double function_2(std::string s) {
    return s == "Z" ? 1.0 : 0;
}