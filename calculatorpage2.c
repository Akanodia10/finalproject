#include <stdio.h>
#include <math.h>

       
       float coshe();
       float sinhe();
       float tanhe();
       float loge();
       float log10e();
       float expe();

int fileoutput (float result);

int main()
{
  char op;
//  float num1, num2, result=0.0f;
    
  printf("WELCOME TO THE CALCULATOR\n");
  printf("Input * symbol for cosh\n");
  printf("Input / symbol for sinh\n");    
  printf("Input < symbol for tanh\n");
  printf("Input > symbol for log\n");
  printf("Input ? symbol for log10\n");
  printf("Input . symbol for exponential\n");


    scanf("%c", &op);

 float result;

    switch(op)
    {
        case '*': 
           result = coshe();
            break;
        case '/': 
           result =  sinhe();
            break;
        case '<':
           result = tanhe();
            break;
        case '>':
         result  =   loge();
            break;
        case '?':
       result =     log10e();
            break;
        case '.':
           result = expe();
            break;

    }

fileoutput(result);

}

float coshe()
{
    double x=0;
    double y= 0;
    printf("Enter the number you'd like to take cosh_value of in radians:\n");
    scanf("%lf", &x);
    y=cosh(x);
    printf("cosh(%lf)= %lf\n", x, y);
    return y;
}

float sinhe()
{
    double x=0;
    float y= 0;
    printf("Enter the number you'd like to take sinh_value of in radians:\n");
    scanf("%lf", &x);
    y=sinh(x);
    printf("sinh(%lf)= %lf\n", x, y);
    return y;
}

float tanhe()
{
    double x=0;
    float y= 0;
    printf("Enter the number you'd like to take tanh_value of in radians:\n");
    scanf("%lf", &x);
    y=tanh(x);
    printf("tanh(%lf)= %lf\n", x, y);
    return y;
}

float loge()
{
    double x=0;
    float y= 0;
    printf("Enter the number you'd like to take log_value of:\n");
    scanf("%lf", &x);
    y=log(x);
    printf("log(%lf)= %lf\n", x, y);
    return y;
} 

float log10e() 
{
    double x=0;
    float y= 0;
    printf("Enter the number you'd like to take log10_value of:\n");
    scanf("%lf", &x);
    y=log10(x);
    printf("log10(%lf)= %lf\n", x, y);
    return y;
} 

float expe()
{
    float x=0;
    float y= 0;
    float a= 0;
    printf("Enter the number you'd like to make the exponent base:\n");
    scanf("%f", &x);
    printf("Enter the number you'd like to make the exponent value:\n");
    scanf("%f", &a);
    y=pow(x, a);
    printf("%f^%f= %f\n", x, a, y);
    return y;
} 

int fileoutput(float result)
{
FILE* outFile;

outFile = fopen("testfile2.out", "w");
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

