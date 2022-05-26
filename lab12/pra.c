#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PageFrame{
     int Id; /* Page ID */
     int ArrivalTime; /* Time that the page arrives */
     int LastRefTime; /* the Last time that the page was refered in the past */
     int Rbit; /* Referenced(R) bit */
     int Mbit; /* Modified(M) bit */
};
struct PageFrame page[100];
void first_in_first_out(){
  /* Your code for FIFO algorithm here */
  int pageSelect = 0;
  int compareTo = 0;
  	
  for (int y = 0; y < 101; y++)
      {
      if (page[y].ArrivalTime > compareTo){ //define last to arrive to compare against
      compareTo = page[y].ArrivalTime;
      } 
  }
  
  for (int i = 0; i < 101; i++) {
  if(page[i].ArrivalTime != 0){ //excludes pages that dont exist
  	if (page[i].ArrivalTime <= compareTo){  // reduces compareTo until the lowest arrivaltime is defined, aka first in.
		compareTo = page[i].ArrivalTime;
		pageSelect = page[i].Id;	
  	}
}
}
printf("Page selected: %d, Loaded at time %d, Last Refered at time %d, Rbit %d, Mbit %d.\n\n", page[pageSelect].Id, page[pageSelect].ArrivalTime, page[pageSelect].LastRefTime, page[pageSelect].Rbit, page[pageSelect].Mbit);

}


void least_recently_used(){
  /* Your code for LRU algorithm here */
  int pageSelect = 0;
  int compareTo = 0;
  	
  for (int y = 0; y < 101; y++)
      {
      if (page[y].LastRefTime > compareTo){ //define last to be referenced to compare against
      compareTo = page[y].LastRefTime;
      } 
  }
  
  for (int i = 0; i < 101; i++) {
  if(page[i].ArrivalTime != 0){ //excludes pages that dont exist
  	if (page[i].LastRefTime <= compareTo){  // reduces compareTo until the lowest reference time is defined, aka last referenced.
		compareTo = page[i].LastRefTime;
		pageSelect = page[i].Id;	
  	}
}
}
printf("Page selected: %d, Loaded at time %d, Last Refered at time %d, Rbit %d, Mbit %d.\n", page[pageSelect].Id, page[pageSelect].ArrivalTime, page[pageSelect].LastRefTime, page[pageSelect].Rbit, page[pageSelect].Mbit);

}
  


int main(){
   
     FILE *pFile= fopen("Testcase0.txt", "r");
     if (pFile == NULL) { 
        printf("Error! Could not open file\n"); 
        exit(-1);
    } 
    int i = 0;
    printf("Page\tArrival\tLastRef\tRbit\tMbit\n");
    while (fscanf(pFile, "%d%d%d%d%d", &page[i].Id, &page[i].ArrivalTime, &page[i].LastRefTime, &page[i].Rbit, &page[i].Mbit) != EOF){ 
        printf("%d\t%d\t%d\t%d\t%d\n", page[i].Id, page[i].ArrivalTime, page[i].LastRefTime, page[i].Rbit, page[i].Mbit);       
        i++;  
     }

    /* Run page replacement algorithms */
  printf("First-in-First-out...\n");
  first_in_first_out();

  printf("Least-Recently-Used...\n");
  least_recently_used();
  return 0;
}
