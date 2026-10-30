//Η εργασία μου για τον goldbach
//tests if the number given is prime
//this function returns 0 if the number given is prime and 1 if its not
#include <stdio.h>
#include <stdlib.h>
int is_prime(long long x){
    int count = 0;
    for(int i = 1;i <= x; i++){
        if (x % i == 0){
            ++count;
        }
    }
    if (count == 2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    long long number;
    do{
        printf("Give me a number: ");
        if (scanf("%lld", &number) == EOF){
            printf("\nEOF detected, exiting\n");
            exit(0);
        }else if (!(number >= 0 && number <= 1000000000)){
            printf("Number should be in the range [0, 10000000000]\n");
            exit(1);
        }else if (number >= 0 && number <= 1000000000){
            char test;
            printf("Choose how to test %lld - ('p' for prime, 'g' for goldbach): ", number);
        
            if (scanf(" %c", &test) == EOF) {
                printf("\nEOF detected, exiting\n");
                exit(0);
            }else if (test != 'g' && test != 'p') {
                printf("Invalid choice: expected 'p' or 'g'\n");
                exit(1);
            }else if (test == 'p') {
                if (is_prime(number)) {
                    printf("%lld is prime\n", number);
                } else {
                    printf("%lld is not prime\n", number);
                }
            }else{
                if (number%2 ==1 || number<= 2){
                    printf("Goldbach's conjecture is applicable only to even numbers greater than 2!");
                }else {
                    int flag = 0;
                    long long A = 3;
                    long long B;
                    do
                    {
                        B = number - A;
                        if (is_prime(B) == 1 && is_prime(A) == 1){
                        flag = 1;
                        }else {
                            while (is_prime(A) == 0){
                            A = A + 2;
                            }
                        }
                    } while (flag == 0);
                
                    if (A > B){
                        A = A + B;
                        B = A;
                        A = A - B;
                    }
                    printf("%lld = %lld + %lld \n", number, A, B);
                }
            }        
        }else {
        printf("Invalid input: expected an integer");
        exit(1);
        }
    } while (1);
    return 0;
}

