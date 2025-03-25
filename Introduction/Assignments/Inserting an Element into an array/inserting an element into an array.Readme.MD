Algorithm for Inserting an Element in a Circular Queue
• Check if the queue is full:
• If (rear + 1) % size == front, then the queue is full.
• Display an overflow message and exit.
• Check if the queue is empty:
• If front == -1, set front = 0 and rear = 0.
• Insert the element:
• Set rear = (rear + 1) % size and assign the new element to queue[rear].


C++ Code in the related file