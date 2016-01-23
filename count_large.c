#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int check_permissons( char * array1, char*  array2){
  int i;
  if(array1[0] == 'd'){
    return 0;
  }
  // printf("file %s\n", array1);
  //printf("required %s\n", array2); 
  for (i =1; i < 9; i++){
    if (array2[i] != '-') {
     if(array1[i+1] != array2[i]){
	  return 0; 
          	 }
      }
      }
  return 1;
}

int check_size(int size_required, int size){
  if (size_required < size){
    return 1; } 
  return 0; 
}  

int main (int argc, char *argv[]){

   char c[30];
   int total;
   int size;
   if (argc == 1){
     //   int  size = atoi(argv[1]);
     scanf("%s %d",c, &total); 
     printf(" You didn't specify the required size \n");
     return 0; 
   }

   if (argc ==2){
     size = atoi(argv[1]);         
     scanf("%s %d",c, &total);
     //printf(" Required size is  %d \n", size);
        
     char str1[40],  str2[35], str3[35], str4[30], str5[15], str6[20], str7[25], str8[35];
     int fsize;
     int filecount = 0; 
     while(scanf("%s %s %s %s %d %s %s %s %s", str1, str2, str3, str4, &fsize, str5, str6, str7, str8) >0 ){
         if (check_size(size, fsize)==1 && str1[0] != 'd') {
	 filecount++;
	 // printf("%s ", str1);
	 //printf(" File size %d \n " , fsize);
       }
     }  
     printf("%d \n", filecount); 
    return 0;}
 
   if (argc ==3){
     size = atoi(argv[1]);
     scanf("%s %d",c, &total);
     //printf(" Required size is  %d \n", size);
     char str1[40],  str2[35], str3[35], str4[30], str5[15], str6[20], str7[25], str8[35];
     int fsize;
     int filecount = 0;
     while(scanf("%s %s %s %s %d %s %s %s %s", str1, str2, str3, str4, &fsize, str5, str6, str7, str8) >0 ){
       if (check_size(size, fsize)==1 && str1[0] != 'd' && check_permissons(str1, argv[2]) == 1) {
         filecount++;
	 //  printf("%s ", str1);
         //printf(" File size %d \n " , fsize);
       }
     }
     printf("%d \n", filecount);
     return 0;
   }
   return 1;   
}


