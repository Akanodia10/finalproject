#include <stdio.h>
#include <math.h>

float add();
float subtract();
float multiply();
float divide();
float sine();
float cosine();
float tangent();

int fileoutput (float result);

int main()
{
    char op;
   //    float num1, num2, result=0.0f;

    printf("WELCOME TO THE CALCULATOR\n");
    printf("Input + symbol for addition\n");
    printf("Input - symbol for subtraction\n");
    printf("Input * symbol for multiplication\n");
    printf("Input / symbol for division\n");
    printf("Input < symbol for sin\n");
    printf("Input > symbol for cos\n");
    printf("Input ? symbol for tan\n");

    scanf("%c", &op);
    
    float result;

    switch(op)
    {
        case '+': 
           result = add();
            break;

        case '-': 
            result = subtract();
            break;

        case '*': 
            result = multiply();
            break;

        case '/': 
            result = divide();
            break;

        case '<':
            result = sine();
            break;

        case '>':
            result = cosine();
            break;

        case '?':
            result = tangent();
            break;

    }
   fileoutput(result); 

}

float add()
{
    float a, b, c =0;
    printf("Enter the first number you'd like to add:\n");
    scanf("%f", &a);
    printf("Enter the second number you'd like to add:\n");
    scanf("%f", &b);
    c=a+b;
    printf("%f + %f= %f\n", a, b, c);
    return c;
}
float subtract()
{
    float a, b, c =0;
    printf("Enter the first number you'd like to subtract from:\n");
    scanf("%f", &a);
    printf("Enter the second number you'd like to subtract:\n");
    scanf("%f", &b);
    c=a-b;
    printf("%f + %f= %f\n", a, b, c);
    return c;
}
float multiply()
{
    float a, b, c =0;
    printf("Enter the first number you'd like to multiply:\n");
    scanf("%f", &a);
    printf("Enter the second number you'd like to multiply:\n");
    scanf("%f", &b);
    c=a*b;
    printf("%f + %f= %f\n", a, b, c);
    return c;
}
float divide()
{
    float a, b, c =0;
    printf("Enter the dividend:\n");
    scanf("%f", &a);
    printf("Enter the divisor:\n");
    scanf("%f", &b);
    c=a/b;
    printf("%f + %f= %f\n", a, b, c);
    return c;
}
float sine()
{
    float x=0;
    float y= 0;
    printf("Enter the number you'd like to take sin() of in radians:\n");
    scanf("%f", &x);
    y=sin(x);
    printf("sin(%f)= %f\n", x, y);
    return y;
}
float cosine()
{
    float x=0;
    float y= 0;
    printf("Enter the number you'd like to take cos() of in radians:\n");
    scanf("%f", &x);
    y=cos(x);
    printf("cos(%lf)= %lf\n", x, y);
    return y;
}
float tangent()
{
    float x=0;
    float y= 0;
    printf("Enter the number you'd like to take tan() of in radians:\n");
    scanf("%f", &x);
    y=tan(x);
    printf("tan(%lf)= %lf\n", x, y);
    return y;
}


int fileoutput(float result)
{
FILE* outFile;

outFile = fopen("testfile.out", "w");
  if (outFile == NULL) {
    printf("error - failed to open file for writing\n");
    return 1;
  }
  {
    fprintf(outFile, "\n\n Resulting Value:\n\n\n");
    fprintf(outFile, "ANSWER: %f\n", result );
    
    
    fprintf(outFile, "\nGood work!\n\n");
	  fprintf(outFile, "Good Job!\n");

    }
    
    
    fclose(outFile);
}
