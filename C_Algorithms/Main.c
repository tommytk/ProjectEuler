#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ComputeDivisors(int n) {
    double sq = sqrt(n);
    int intSqr = (int)sq;
    int count = intSqr == sq ? -1 : 0;
    //printf("Triangle for %d\n",n);
    for(long idx = 1; idx <= intSqr;idx++) {
        if(n % idx == 0) {
            count = count + 2;
            //printf("%d",idx);
        }
    }
    //printf("%d \n",n);
    return count;
}

void Problem12() {
    long triangle = 1;
    int divisors = 0;
    int targetDivisors = 500;
    int counter = 1;
    while(divisors < targetDivisors) {
        divisors = ComputeDivisors(triangle);
        //printf("%d \n", divisors);
        counter = counter + 1;
        triangle += counter;
        
    }
    printf("The number is: %d",triangle);
}

void Problem1() {
    int n = 1000;
    int sum;
    for(int idx = 1; idx<n;++idx) {
        int mod5 = idx%5;
        int mod3 = idx%3;
        //printf("%d %d %d\n",idx,mod5,mod3);
        if(mod3 == 0 || mod5 == 0) {
            sum += idx;
            //printf("idx:%d sum:%d \n",n,sum);
        }
    }
    printf("%d",sum);
}

void Problem2() {
    size_t maxVal = 4000000;
    size_t fib1 = 0;
    size_t fib2 = 1;
    size_t fibPremier = 0;
    size_t sumOfEvens = 0;
    while(fibPremier < maxVal) {
        
        
        printf("fib1 %d fib2 %d fibPrem %d\n",fib1,fib2,fibPremier);
        
        fibPremier = fib1 + fib2;
        if(fibPremier % 2 == 0) {
            sumOfEvens += fibPremier;
        }
        fib1 = fib2;
        fib2 = fibPremier;
        
    }
    printf("%d",sumOfEvens);
}

void Problem3_LargestPrimeFactor() {
    size_t n = 600851475143;
    int largetsPrimeFactor = 0;
    int tempPrime = 0;
    for(int idx = 1; idx < n; ++idx) {
        //if factor
        //printf("")
        size_t mod = n%idx;
        //printf("idx:%d mod:%d\n",idx,mod);
        if(mod == 0) {
            //printf("Factor found: %d \n",idx);
            //if prime
            int prime = 1;
            tempPrime = idx;
            for(int j =2; j<tempPrime; ++j) {
                //printf("j:%d tempPrime:%d\n",j,tempPrime);
                if((tempPrime % j) ==0) {
                    //printf("Not prime: %d\n",tempPrime);
                    prime = 0;
                    break;
                }
            }
            
            if(prime == 1) {
                printf("tempPrime: %d LargestPrime: %d \n",tempPrime,largetsPrimeFactor);
                if(largetsPrimeFactor < tempPrime) {
                    largetsPrimeFactor = tempPrime;
                    tempPrime = 0;
                    printf("LargestPrime: %d \n",largetsPrimeFactor);
                }
            }
        }
    }
    printf("Largest Prime is:%d",largetsPrimeFactor);
}
int FindNumOfDigits(int digits) {
    int count = 0;
    while(1) {
        //printf("Digits %d \n",digits);
        int digit = digits%10;
        digits /= 10;
        //printf("digit:%d digits: %d |",digit,digits);
        count++;
        if(digits <= 0) {
            break;
        }
    }
    return count;
}
void Prolem5() {
    FILE *fp;

    fp = fopen("C:\\Development\\C Programming\\C_Algorithms\\log.txt", "w+");
    

    int numOfDigits = 3;
    size_t product = 0;
    int num1 = 9999,num2=9999;
    //work out product of 999 * 999
    int count = 1;
    int floor = 9000;
    while(num1 >= 0 && num2 >= 0) {
        num1 = 9999;
        int match = 1;
        while (num1 > floor) {
            
            product = num1 * num2;
            /*
            if(product < 90000)
            {
                num1=0;
                num2=0;
                break;
            }
            */
            int count = FindNumOfDigits(product);
            size_t numToProcess = product;
            int* digitArray = malloc(count * sizeof(int));
            //Put digits into array
            fprintf(fp, "num1: %d num2:%d product: %d\n",num1,num2, product);
            printf("count: %d product: %d\n",count, product);
            for(int idx =0; idx < count; ++idx) {
                int digit = numToProcess%10;
                numToProcess /= 10;
                digitArray[idx] = digit;
                //printf("digit array[%d]: %d \n",idx,digitArray[idx]);
            }

            //compare digits forward and backward
            int match1,match2;
            int countFwd = 0; 
            int countBk = count-1;
            int found = 1;
            while(countFwd < count) {
                fprintf(fp,"itemFr[%d] itemBk[%d]\n",digitArray[countFwd],digitArray[countBk]);
                if(digitArray[countFwd] != digitArray[countBk]) {
                    found = 0;
                    break;
                }
                countFwd = countFwd +1;
                countBk = countBk -1;
            }
            if(found == 1) {
                num1=0;
                num2=0;
                break;
            }
            num1 = num1 - 1;
        }
        if(num2 <= floor) {
            floor /= 10;
        }
        num2 = num2 -1;
        
    }
    printf("Palindrome product is: %d made by %d  %d",product,num1,num2);
    fclose(fp);
}

void Problem6_SumOfSquares() {
    size_t sumOfSquares = 0;
    size_t squareOfTheSum = 0;
    size_t sumOfNumbers = 0;
    size_t difference = 0;  
    int n = 100;
    for(int idx = 1; idx <= n; ++idx) {
        sumOfSquares += idx * idx;
        printf("n: %d n2:%d \n",idx,sumOfSquares);
        sumOfNumbers += idx;
    }
    squareOfTheSum = sumOfNumbers * sumOfNumbers;
    difference = squareOfTheSum - sumOfSquares;
    printf("SumOfSquares %d\n SumOfNumbers %d\n SquareOfSum %d\n Difference %d\n",
    sumOfSquares, sumOfNumbers,squareOfTheSum, difference);
}

struct Node {
    struct Node *next;
    int val;
};

int CheckIfPrime(struct Node *node, size_t candidate) {
    int notAtTail = 1;
    int isPrime = 0;
    //starting off.
    printf("node location: %p",&node);
    printf("checking candidate %d",candidate);
    int checks = 1;
    struct Node **nodeCheck;
    nodeCheck = &node;
    while (notAtTail)
    {
        if (*nodeCheck)
        {
            printf("Check % d Node Value: %d\n", checks,(*nodeCheck)->val);
            int val = (*nodeCheck)->val;
            //Check if not prime
            if ((candidate % val) == 0)
            {
                break;
            }
            else
            {
                //check next value
                printf("address of node: %p\n",&(*nodeCheck));
                nodeCheck = &node->next;
                printf("address of node next: %p\n",&node->next);
                printf("address of node after next: %p\n",&(*nodeCheck));
            }
        }
        else
        {
            printf("At tail");
            isPrime = 1;
            notAtTail = 0;
            break;
        }
        checks = checks +1;
    }
    return isPrime;
}

int main() {
    
    //Create a linked list
    //Contains a tail and head plus a value.

    size_t numOfPrimes = 5;
    //size_t target = 10001;
    size_t target = 100;
    int primeFound = 0;
    int num = 3;
    struct Node *base = calloc(1,sizeof(struct Node));
    base->next == NULL;
    base->val = 2;
    struct Node *head;
    struct Node *tail;
    while (numOfPrimes <= target)
    {
        printf("Checking: %d\n",num);
        primeFound = CheckIfPrime(base,num);
        printf("PrimeFound: %d\n",primeFound);
        if(primeFound == 1) {
            //create new prime in nodes
            int val = base->next ? 1 : 0;
            printf("val %d",val);
            if(num == 3) {
                //first prime
                printf("Allocating the next node from base \n");
                base->next = calloc(1,sizeof(struct Node));
                printf("Allocated the memory");
                base->next->val = num;
                printf("num: %d ", base->next->val);
                tail = base->next;
            } else {
                tail->next = calloc(1,sizeof(struct Node));
                tail->val = num;
                printf("num: %d ",tail->val);
                tail = tail->next;
            }
            numOfPrimes = numOfPrimes + 1;
            
        }
        num = num +1;
        /* code */
    }
    
    return 0;
}


