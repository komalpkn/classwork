#include <stdio.h>
#include <string.h>
//include stdlib to be able to use malloc
#include <stdlib.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
  char *reminders[MAX_REMIND]; //change how reminders is declared
  char day_str[3], msg_str[MSG_LEN+1];
  int day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      reminders[j] = reminders[j-1];//no longer need strcpy, can simply change pointers to point to other locations

    reminders[i] = malloc(strlen(day_str) + strlen(msg_str) + 1);//use dynamic memoroy allocation to allocate enough space for the new string

    if(reminders[i] == NULL){//check if the memory allocation was successful
        printf(" -- No space left, failed to allocate memory --\n");
        break;
    }

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  //free all dynamically allocated memory before ending the program
  //to avoid memory leaks
  for(int i = 0; i < num_remind; i++)
      free(reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}


