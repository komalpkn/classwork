#include <stdio.h>
#include <stdlib.h>

int main(void){
  int month, day, year;
  char *day_, *monthName;
 

  printf("Enter date (mm/dd/yy): ");
  scanf("%d/%d/%d", &month, &day, &year); 
  
  year = (20*100) + year;

  switch(day){
    case 01: day_ = "1st"; break;
    case 21: day_ = "21st"; break;
    case 31: day_ = "31st"; break;
    
    case 2: day_ = "2nd"; break;
    case 22: day_ = "22nd"; break;

    /*default: day_ = ; break;*/
  }
  
  switch(month){
    case 1: monthName = "January"; break; 
    case 2: monthName = "February"; break; 
    case 3: monthName = "March"; break;   
    case 4: monthName = "April"; break; 
    case 5: monthName = "May"; break; 
    case 6: monthName = "June"; break; 
    case 7: monthName = "July"; break; 
    case 8: monthName = "August"; break; 
    case 9: monthName = "September"; break; 
    case 10: monthName = "October"; break; 
    case 11: monthName = "November"; break; 
    case 12: monthName = "December"; break; 
  }

  printf("Dated this %s day of %s, %d.\n", day_, monthName, year);
  return 0;
}
