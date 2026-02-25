#include <stdio.h>

int main() {

    int n, x, y;
    float div;

    scanf("%d", &n);

    for (int i = 0; i < n; i++ ){
        scanf("%d %d", &x, &y);

        if(y != 0){
            div = (float)x / y;
            printf("%.1f\n", div);

            // std::cout << std::fixed << std::setprecision(1) << div << std::endl;
        } else {
            printf("divisao impossivel\n");
        }
    }

    return 0;
}


