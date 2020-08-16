#include<stdio.h>
struct complex
{
       int real;
       int img;
}n1,n2,n3;
struct complex addition(struct complex s1 , struct complex s2)
{
      struct complex s3;
      s3.real = s1.real + s2.real;
      s3.img = s1.img + s2.img;
      return s3;
}
struct complex subtraction(struct complex s1 , struct complex s2)
{
      struct complex s3;
      s3.real = s1.real - s2.real;
      s3.img = s1.img - s2.img;
      return s3;
}
struct complex multiplication(struct complex s1 , struct complex s2)
{
      struct complex s3;
      s3.real = (s1.real * s2.real) - (s1.img * s2.img);
      s3.img = (s1.real * s2.img) + (s2.real * s1.img);
      return s3;
}
int main()
{
     scanf("%d%d%d%d",&n1.real,&n1.img,&n2.real,&n2.img);
     n3 = addition(n1,n2);
     printf("addition of two numbers = %d + i%d\n",n3.real,n3.img);
     n3 = subtraction(n1,n2);
     printf("subtraction of two numbers = %d + i%d\n",n3.real,n3.img);
     n3 = multiplication(n1,n2);
     printf("multiplication of two numbers = %d + i%d\n",n3.real,n3.img);
     return 0;
}