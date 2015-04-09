   #include <stdio.h>
 
    void showbits(unsigned int x)
    {
        int i; 
        for(i=(sizeof(int)*8)-1; i>=0; i--)
            (x&(1<<i))?putchar('1'):putchar('0');
 
        printf("\n");
    }
 
    int main() 
    {
        int j = 1000, m, n;
        printf("The decimal %d is equal to binary - ", j);
        /* assume we have a function that prints a binary string when given 
           a decimal integer 
         */
        showbits(j);
 
        /* the loop for right shift operation */
        for ( m = 0; m <= 5; m++ ) {
            n = j >> m;
            printf("%d right shift %d gives %d in binary - ", j, m,n);
            showbits(n);
        }
        return 0;
    }