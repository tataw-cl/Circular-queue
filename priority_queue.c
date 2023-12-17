#include <stdio.h>

#define max 100
int head = -1;
int tail = -1;

struct PQitem {
    int val;
    int priority;
};

typedef struct PQitem pqitem;

pqitem Priorityqueue[max];


void enqueue(int val, int priority) {
    if (tail == max-1) {
        printf("Queue is full.\n");
        return;
    }

    if (head==-1 &&tail == -1) {
        head= 0;
        tail=0;
        Priorityqueue[tail].val = val;
        Priorityqueue[tail].priority = priority;
    } else {
        int i;
        for (i =tail; i >= head; i--) {
            if (priority > Priorityqueue[i].priority) {
                Priorityqueue[i + 1] = Priorityqueue[i];
            } else {
                break;
            }
        }
        Priorityqueue[i + 1].val = val;
        Priorityqueue[i + 1].priority = priority;
        tail++;
    }
}

pqitem dequeue() {
    pqitem element = { -1, -1 };
    if (head == -1 || head > tail) {
        printf(" Queue is empty.\n");
        return element;
    }

    element = Priorityqueue[head];
    head++;

    if (head > tail) {
        head = tail = -1;
    }

    return element;
}

int main() {
    enqueue(10, 1);
    enqueue(20, 2);
    enqueue(30, 3);
    enqueue(40, 2);
    enqueue(50, 1);

    printf("%d ", dequeue().val);
    printf("%d ", dequeue().val);
    printf("%d ", dequeue().val);
    printf("%d ", dequeue().val);
    printf("%d ", dequeue().val);

    return 0;
}