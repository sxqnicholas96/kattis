#include <bits/stdc++.h>
 
int main(void){
     int numRooms, numBooked,i,j,bookedRooms[100];
 
     scanf("%d %d", &numRooms, &numBooked);

     for(i=0;i<numBooked;i++){
         scanf("%d", &bookedRooms[i]);
         
     }
 
     if(numBooked == numRooms){
         printf("too late\n");
         
     }
     else if(numBooked){
         for(i=1;i<=numRooms;i++){
             for(j=0;j<numBooked;j++){
                 if(bookedRooms[j] == i){
                     break;
                 }
                 if(j == numBooked -1){
                     printf("%d\n", i);
                     return 0;
                     
                 }
              }
             
         }
         
     }
     else{
         printf("1\n");
     }
      return 0;
}
