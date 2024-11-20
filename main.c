#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ARRAY_LENGTH 30000

char ARRAY[ARRAY_LENGTH];	// Array to be initialized with 0
int ARRAY_POINTER = 0;	// the global array pointer
int NUM_BRACK = 0;	// bracket checking
int INS_PTR = 0;	// Instruction pointer

void evaluate_bf(char *expression, int brack_index)
{

   char current;

   while ((current = expression[INS_PTR]) != 0)
   {
      
      if (current == '>')
      {
         ARRAY_POINTER++;
         INS_PTR++;
      }
      else if (current == '<')
      {
         ARRAY_POINTER--;
         INS_PTR++;
      }
      else if (current == '+')
      {
         ARRAY[ARRAY_POINTER]++;
         INS_PTR++;
      }
      else if (current == '-')
      {
         ARRAY[ARRAY_POINTER]--;
         INS_PTR++;
      }
      else if (current == '.')
      {
         putchar(ARRAY[ARRAY_POINTER]);
         INS_PTR++;
      }
      else if (current == ',')
      {
         ARRAY[ARRAY_POINTER] = (char)getchar();
         INS_PTR++;
      }
      else if (current == '[')
      {
         NUM_BRACK++;
         INS_PTR++;
         evaluate_bf(expression, INS_PTR);
         
      }
      else if (current == ']')
      {
         if(ARRAY[ARRAY_POINTER]==0) {
            INS_PTR++;
            NUM_BRACK--;
            return;
         }
         INS_PTR=brack_index;         
      }

      continue;

      
   }
   if(NUM_BRACK!=0) {

      fprintf(stderr, "Not correct brackets");
      NUM_BRACK=0;
   }
}
int main(int argc, char const *argv[])
{
   for(int i=0;i<ARRAY_LENGTH;++i)
      ARRAY[i]=0;
   evaluate_bf("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.", 0);
   printf("\n");
   
   return 0;
}
