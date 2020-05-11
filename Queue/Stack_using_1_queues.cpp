void QueueStack :: push(int x)
{
        // Your Code
        int count=q1.size();
        q1.push(x);
        while(count--){
            q1.push(q1.front());
            q1.pop();
        }
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code 
        if(q1.empty())return -1;
        int x=q1.front();
        q1.pop();
        return x;
}
