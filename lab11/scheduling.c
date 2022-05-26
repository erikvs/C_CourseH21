#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process
{
  /* Values initialized for each process */
  int id;
  int arrivaltime; /* Time process arrives and wishes to start */
  int runtime;     /* Time process requires to complete job */

  /* Values algorithm may use to track processes */
  int starttime;
  int endtime;
};
struct process proc[100];
void first_come_first_served()
{
  /* Your code for FCFS algorithm here */

  int starttime = 0;
  int endtime = 0;
  for (int i = 0; i < 101; i++)
  {
    if (proc[i].runtime != 0)
    { //excludes any iteration of the struct outside of where we have data.
      starttime = endtime;

      if (proc[i].arrivaltime == 0)
      { //first process arriving defines initial endtime
        endtime = starttime + proc[i].runtime;
      }

      if (proc[i].arrivaltime >= endtime)
      { //(processor idles) update starttime to be proc[i].arrivaltime
        starttime = proc[i].arrivaltime;
      }

      endtime = starttime + proc[i].runtime;
      printf("Process %d started at time %d and finished at time %d\n", proc[i].id, starttime, endtime);
    }
  }
}

void shortest_job_first()
{
  /* Your code for SJF algorithm here */
  int endtime = proc[0].arrivaltime;
  int starttime;
  int lowestRunTime = proc[0].runtime;
  int nextToRun = proc[0].id;
  int runableProc[100];

  for (int z = 0; z < 101; z++)
  {
    runableProc[z] = 102;
  }

  for (int x = 0; x < 101; x++)
  {

    int arrayCheck = 0;

    if (proc[x].runtime != 0)
    { //excludes any iteration of the struct outside of where we have data.

      for (int i = 0; i < 101; i++)
      { //checks what is runnable and what is not for a given iteration
        if (proc[i].runtime != 0)
        { //excludes any iteration of the struct outside of where we have data.
          if (proc[i].arrivaltime <= endtime)
          { //what procs are available
            if (!(proc[i].endtime > 0))
            { // disregards procs that have run

              runableProc[i] = proc[i].id; //adds current proc to temp array
            }
          }
          else
          {
            runableProc[i] = 102; //assign index as 102 so we can check for it later
          }
        }
      }

      for (int y = 0; y < 101; y++)
      {
        if (runableProc[y] != 102)
        {
          arrayCheck = 1;
        }
      }

      for (int j = 0; j < 101; j++)
      { //which process to run next
        if (proc[j].runtime != 0)
        { //excludes any iteration of the struct outside of where we have data.

          if (runableProc[j] != 102)
          { //checking to see what processes can be chosen from

            if (proc[j].runtime < lowestRunTime)
            {
              lowestRunTime = proc[j].runtime;
              nextToRun = proc[j].id;
            }
            else
            {
              if (proc[j].arrivaltime == proc[nextToRun - 1].arrivaltime)
              {
                if (proc[j].runtime < proc[nextToRun - 1].runtime)
                {
                  lowestRunTime = proc[j].runtime;
                  nextToRun = proc[j].id;
                }
              }
            }
          }
        }
      }
      if (arrayCheck == 0)
      {
        lowestRunTime = proc[x].runtime;
        nextToRun = proc[x].id;
        endtime = proc[x].arrivaltime;
      }

      runableProc[nextToRun - 1] = 102;

      starttime = endtime;
      endtime = endtime + lowestRunTime;
      lowestRunTime = endtime;
      proc[nextToRun - 1].endtime = endtime;
      printf("Process %d started at time %d and finished at time %d\n", nextToRun, starttime, endtime);
    }
  }
}

int main()
{

  FILE *pFile = fopen("Testcase.txt", "r");
  if (pFile == NULL)
  {
    printf("Error! Could not open file\n");
    exit(-1);
  }
  int i = 0;
  printf("Process\tarrival\truntime\n");
  while (fscanf(pFile, "%d%d%d", &proc[i].id, &proc[i].arrivaltime, &proc[i].runtime) != EOF)
  {
    printf("%d\t%d\t%d\n", proc[i].id, proc[i].arrivaltime, proc[i].runtime);
    i++;
  }

  /* Run scheduling algorithms */
  printf("First come first served...\n");
  first_come_first_served();

  printf("Shortest job first...\n");
  shortest_job_first();
  return 0;
}
