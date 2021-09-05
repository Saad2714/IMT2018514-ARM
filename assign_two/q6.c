#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct  MyQueue{
    int top, bottom;
    int  myArray[10];
    int size;
};

void add_to_queue(struct  MyQueue*, int num);
void remove_from_Queue(struct  MyQueue*);
void print(struct  MyQueue*);

int main(){
    printf("creating queue ... \n");

    struct  MyQueue* queue_1 =  (struct  MyQueue*)malloc(sizeof(struct  MyQueue));

    queue_1->size=10;
    printf("Size is %d \n", queue_1->size);

    queue_1->top=-1;
    printf("Top is %d \n", queue_1->top);
    
    queue_1->bottom = -1;
    printf("Bottom is %d \n", queue_1->bottom);

    for(int i=0;i<queue_1->size;i++){
        queue_1-> myArray[i]=0;
    }

    printf("\n");

        int n=0;
        int number = 0;

    for(int loop=0; loop<100;loop++){


        int x;
        printf("1 - Print Complete Circular_Queue   \n  ");
        printf("2 - Add to Circular_Queue   \n  ");
        printf("3 - Remove from Circular_Queue   \n  ");
        printf("4 - Exit the Circular_Queue program   \n  ");
        printf("\n");

        scanf("%d",&x);
        // printf("input number is %d ", n);

            if(x==1){
            print(queue_1);
                 }

            else if(x==2){
                    // int number;
                    printf("Enter  number:");
                    scanf("%d",& number);
                    add_to_queue(queue_1, number);
            }

            else if(x==3){
                   remove_from_Queue(queue_1);
                   printf("Successfully popped top number   \n  ");
            }

            else if(x==4){
            
                printf("Closing the program  \n  ");
                break;
            }
            else{
                printf("Please print 1, 2, 3 or 4... No other inputs!   \n  ");
                printf("\n");
            }
        

    }
    return 1;

}

// int peek() {
//    return intArray[front];
// }

// bool isEmpty() {
//    return itemCount == 0;
// }

// bool isFull() {
//    return itemCount == MAX;
// }

// int size() {
//    return itemCount;
// }  

// void insert(int num) {

//    if(!isFull()) {
	
//       if(rear == MAX-1) {
//          rear = -1;            
//       }       

//       intArray[++rear] = num;
//       itemCount++;
//    }
// }

// int removenum() {
//    int num = intArray[front++];
	
//    if(front == MAX) {
//       front = 0;
//    }
	
//    itemCount--;
//    return num;  
// }

void print(struct MyQueue* queue_1)
{
    printf("Inside Print function... \n");

    if(queue_1->top == -1){
        printf("Circular_Queue is completely empty, kindly push some numbers first \n ");
    printf("\n");
        
        return;
    }

    if(queue_1->top<=queue_1->bottom){
        for(int i=queue_1->top;i<=queue_1->bottom;i++)
        {
            printf(" %d  \n ",queue_1->myArray[i]);
        }
    printf("\n");

    }
    else if(queue_1->top > queue_1->bottom){
    printf("\n");

        for(int i = queue_1->top;i<queue_1->size;i++)
        {
            printf(" %d  \n ", queue_1->myArray[i]);
        }
    printf("\n");

        for(int i=0;i<=queue_1->bottom;i++)
        {
            printf(" %d  \n ", queue_1->myArray[i]);
        }

    printf("\n");

    }
}


void add_to_queue(struct MyQueue* queue_1, int num)
{
    printf("Inside add_to_queue function... \n");

    if((queue_1->top == 0 && queue_1->bottom == queue_1->size-1)){
        printf("Circular_Queue is completely full, kindly pop some numbers first \n ");
        return;
    }

    else if(queue_1->bottom == (queue_1->top-1)%(queue_1->size-1)){
        printf("Circular_Queue is completely full, kindly pop some numbers first \n ");
        return;
    }

    if(queue_1->top==-1 && queue_1->bottom==-1){
    printf("\n");
        
        queue_1->top = 0;
        queue_1->bottom = 0;
        queue_1->myArray[queue_1->bottom] = num;
        return;
    }

     if(queue_1->bottom == queue_1->size-1 && queue_1->top!=0){
    printf("\n");
        
        queue_1->bottom = 0;
        queue_1->myArray[queue_1->bottom]=num;
        return;
    }

    
    printf("\n");

    queue_1->bottom=queue_1->bottom+1;
    queue_1->myArray[queue_1->bottom] = num;

    

}

void remove_from_Queue(struct MyQueue* queue_1)
{
    printf("Inside remove_from_Queue function... \n");

    if(queue_1->top==-1){
    printf("\n");

        printf("Circular_Queue is completely empty, kindly push some numbers first \n ");
                return;

    }

    else if(queue_1->top!=-1){
    printf("\n");

    int element = queue_1->myArray[queue_1->top];

    if(queue_1->top == queue_1->bottom){
    printf("\n");

        queue_1->top = -1;
        queue_1->bottom = -1;
    }
    else if(queue_1->top==queue_1->size-1){
    printf("\n");

        queue_1->top = 0;
    }
    else{
    printf("\n");

        queue_1->top=queue_1->top + 1;
    }
    return;
    }
    

}

// int Queue::deQueue()
// {
//     if (front == -1)
//     {
//         printf("\nQueue is Empty");
//         return INT_MIN;
//     }
 
//     int num = arr[front];
//     arr[front] = -1;
//     if (front == rear)
//     {
//         front = -1;
//         rear = -1;
//     }
//     else if (front == size-1)
//         front = 0;
//     else
//         front++;
 
//     return num;
// }
 
// // Function displaying the elements
// // of Circular Queue
// void Queue::displayQueue()
// {
//     if (front == -1)
//     {
//         printf("\nQueue is Empty");
//         return;
//     }
//     printf("\nElements in Circular Queue are: ");
//     if (rear >= front)
//     {
//         for (int i = front; i <= rear; i++)
//             printf("%d ",arr[i]);
//     }
//     else
//     {
//         for (int i = front; i < size; i++)
//             printf("%d ", arr[i]);
 
//         for (int i = 0; i <= rear; i++)
//             printf("%d ", arr[i]);
//     }
// }


