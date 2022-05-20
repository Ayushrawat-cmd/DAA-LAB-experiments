# include<stdio.h>
 
void knapsack(int n, float weight[], float Cost[], float Max_capacity) {
   float x[20], Max_Cost = 0;
   int i, j, u;
   u = Max_capacity;
 
   for (i = 0; i < n; i++)
      x[i] = 0.0;
 
   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0; 
         Max_Cost = Max_Cost + Cost[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
      x[i] = u / weight[i];
 
   Max_Cost = Max_Cost + (x[i] * Cost[i]);
 
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nMaximum Cost is:- %f", Max_Cost);
 
}
 
int main() {
   float weight[20], Cost[20], Max_capacity;
   int num, i, j;
   float ratio[20], temp;
 
   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);
 
   printf("\nEnter the wts and Costs of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &Cost[i]);
   }
 
   printf("\nEnter the Max_capacity of knapsack:- ");
   scanf("%f", &Max_capacity);
 
   for (i = 0; i < num; i++) {
      ratio[i] = Cost[i] / weight[i];
   }
 
   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = Cost[j];
            Cost[j] = Cost[i];
            Cost[i] = temp;
         }
      }
   }
 
   knapsack(num, weight, Cost, Max_capacity);
   return 0;
}   