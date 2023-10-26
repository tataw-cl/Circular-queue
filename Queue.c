//Program for a priority queue where priority increases accoording to the decimal weight
#include<stdio.h>
#define MAX 5
int head=-1; //Where head is the position in which the last element was removed
int tail=0; //Where the tail is the position where the next element is to be added
int val=-1; //value for storage after dequeuing
int Array[MAX]; //initializaton of the array queue
int checker=0; //value to check if the array has gone cyclic so that we know how to print

//Creation of the function to check if it is empty
int IsEmpty(){
    if((head==-1 && tail==0)|| ((head+1)%MAX)==tail){
        //printf("The queue is empty\n");
        return 0;
    }
    else if ((head==MAX-1) && (tail<MAX))
    {
        head=head+1;
        head=head%MAX;//Or simply just set head to be zero...
        return 1; //return value of 1 is for negative
    }
    else{
        return 1;
    }
}

//Function to check if the array is full
int IsFull(){
    if((tail==MAX && head==-1)||(tail==(head+1))&& checker!=0){
   //    printf("The queue is full\n");
        return 0;
    }
    else if (tail==MAX && head!=-1)
    {
        
        tail=tail%MAX;
        checker=checker+1;
        
        return 1;
    }
    else{
        return 1;
    }

}

//Function to enqueue
void Enqueue(int x){
    if(IsFull()==1){
Array[tail]=x;
tail=tail+1;
    //printf("The value of IsFull is %d\n", IsFull());
   //  printf("Value of TAIL is %d\n", tail);
//printf("Value of HEAD is %d\n", head);

//printf("The %d element of the queue is %d\n",tail,Array[tail]);

    }
else{
    printf("The queue is full\n");
    return;
}

}
//Function to dequeue
int Dequeue(){
if(IsEmpty()==1){
   // printf("Value of IsEmpty is %d\n", IsEmpty());
    head=head+1;
    val=Array[head];
    return val;
}
else{
    printf("The queue is empty\n");
}

return -1;
}

//Peek function
int peek(){
    if(IsEmpty()!=0){
 val=Array[head];

    return val;
}
else{
    printf("The queue is empty\n");
}
return -1;
}

//Function to print the queue
void printQ(){
    printf("Queue members are as follows:\n");
    if (checker!=0)
    {
        for(int i=(head+1);i<MAX;i++){
        printf("%d and it's of index %d\n",Array[i], i);
    }
for(int i=0;i<tail;i++){
        printf("%d and it's of index %d\n", Array[i],i); 
          }
    printf("Position of head is %d\n",head);
     printf("Position of tail is %d\n",tail);
    }
    else{
     for(int i=(head+1);i<tail;i++){
        printf("%d and it's of index %d\n",Array[i], i);
        printf("Position of head is %d\n",head);
        printf("Position of tail is %d\n",tail);
    }
    
    }
    
/*    if(tail<MAX){
for(int i=0;i<=tail;i++){
        printf("%d\n", Array[i]); 
          }
    }*/
}


//main function
#include<stdio.h>
int main(){
    Enqueue(5);
  Enqueue(8);
      Enqueue(6);
       Dequeue();
       Enqueue(44);
        Dequeue();
        Dequeue();
        //  Dequeue();
         Enqueue(17);
         Enqueue(85);
         Enqueue(18);
         Enqueue(50);
         Enqueue(98);
         Enqueue(49);
        printQ();
       // printf("Position of head is %d\n",head);

   return 0;
}
