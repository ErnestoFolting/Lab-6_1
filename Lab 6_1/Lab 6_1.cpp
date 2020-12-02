//25. Для заданого дійсного числа x, використовуючи розкладання
//функції Arctg(x) в ряд Тейлора обчислити із заданою точністю eps значення y.
#include <iostream>
using namespace std;

float arctg(float x, float eps);

int main()
{   
     float x, eps;
     cout << "Input x ( |x|<1 ) = "; cin >> x;
     cout << "eps = "; cin >> eps;
     if (fabs(x) < 1) {
         float y = arctg(x, eps);
         printf("%.8f", y);
     }
     else {
         cout << "You've input incorrect x";
     }
    

}
float arctg(float x, float eps) {
    float x1 = x;
    float x2 = (-1) * ((pow(x, 3)) / 3);
    float S = x + x2;
    int i = 3;
    while (fabs(x2 - x1) >= eps) {
        x1 = x2;
        x2 = ((-1) * x1 * pow(x, 2) * i) / (i + 2);
        i += 2;
        S += x2;
    }
    return S;
}

