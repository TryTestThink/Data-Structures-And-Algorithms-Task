#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *nextPtr;
};

struct node *text1e = NULL;
struct node *text2e = NULL;
struct node *record = NULL;



void insert(int data) {

   struct node *llist = (struct node*) malloc(sizeof(struct node));
   struct node *currentPtr;

   llist->data = data;
   llist->nextPtr = NULL;

if(1)
{
	if(text1e == NULL) {
         text1e = llist;
         return;
      }
      else {
         currentPtr = text1e;

         while(currentPtr->nextPtr != NULL)
         currentPtr = currentPtr->nextPtr;

         currentPtr->nextPtr = llist; 
      }
      
  }
  else{
  		if(text2e == NULL) {
         text2e = llist;
         return;
      }
    	currentPtr = text2e;

         while(currentPtr->nextPtr != NULL)
         currentPtr = currentPtr->nextPtr;

         currentPtr->nextPtr = llist;
  }
      
 }
 void insert1(int data) {

   struct node *llist = (struct node*) malloc(sizeof(struct node));
   struct node *currentPtr;

   llist->data = data;
   llist->nextPtr = NULL;


	if(text2e == NULL) {
         text2e = llist;
         return;
      }
      else {
         currentPtr = text2e;

         while(currentPtr->nextPtr != NULL)
         currentPtr = currentPtr->nextPtr;

          currentPtr->nextPtr = llist; 

   }
      
 }


void join() {
   struct node *llist;

   record = text1e;
   llist = record;
    
   while(llist->nextPtr!= NULL) {
      llist = llist->nextPtr;
   }

   llist->nextPtr = text2e;
 
}
 
void sort()
{
        struct node *currentPtr = record;  
        struct node *newPtr = NULL;
        int temp;  
          
            while(currentPtr != NULL) {  
                 newPtr = currentPtr->nextPtr;  
                while(newPtr != NULL) {  
                     if(currentPtr->data > newPtr->data) {  
                     
                        temp = currentPtr->data;  
                        currentPtr->data = newPtr->data;  
                        newPtr->data = temp;  
                    }  
                    newPtr = newPtr->nextPtr;  
                }  
                currentPtr = currentPtr->nextPtr;  
            }      

}
	
void printList(struct node *head) {
	
   struct node *value = head;

   while(value != NULL) {        
      printf(" %d,",value->data);
      value = value->nextPtr;
   
   }
 
   printf(" \n");
   
   
}

void main() {
	int n,i,j,k,number,number1;
	
	int random,text1Elements,text2Elements;
 
    srand(time(NULL));
	
	FILE *text1File;
	text1File = fopen("text1.txt","w");

	number = rand()%10+1;

	number1 = rand()%10+1;
    
	for (i=0; i<number; i++) {
		
	    random = rand()%200+1;
        fprintf(text1File,"%d ",random);
        
        FILE *readtext1File;
    	readtext1File = fopen("text1.txt","r");
 
    	fscanf(readtext1File,"%d ",&random); 

    }
    fclose(text1File);

  	FILE *file1;
    file1=fopen("text1.txt","r");
 
    for(k=0; k<number; k++){
    	
    	fscanf (file1, " %d", &text1Elements);
        insert(text1Elements);
    	
	}
    
    FILE *text2File;
	text2File = fopen("text2.txt","w");
	
	number1 = rand()%10+1;

	for (j=0; j<number1; j++) {
		
		random = rand()%200+1;
        fprintf(text2File,"%d ",random);
        
        FILE *readtext2File;
    	readtext2File = fopen("text2.txt","r");
    	fscanf(readtext2File,"%d ",&random);

	}
	fclose(text2File);

  	FILE *file2;
    file2 = fopen("text2.txt","r");
  
    for(k=0; k<number1; k++){
	
    	fscanf(file2, " %d", &text2Elements);
    	insert1(text2Elements);

	}
	
   printf(" Unsorted linked list 1:");
   printList(text1e);
   
   printf(" Unsorted linked list2:");
   printList(text2e);
   
   join();
   
   printf(" Combined linked list:");
   printList(record);
   
   printf(" Sorted linked list:");
   sort();
   printList(record);


}
