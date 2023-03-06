class queue{
    int* arr;
    int front;
    int rear ;
    public:
    queue(){
        arr = new int[n];
        front =-1;
        rear = -1;
    }
    void push(int x){
        if (rear == n-1)
        {
            cout<<"overflow"<<endl;
        }
        rear++;
        arr[rear] =x ;

        if (front==-1){
            front++;
        }   
        
    }
    void pop(){
        if (front ==-1 || front>rear)
        {
            cout<<"underflow"<<endl;
            return;
        }
        front++;
    }
    int peek(){

			if (front==-1||front>back){
				cout<<"queue is empty";
			}
			return arr[front];
		}
    bool empty (){
		if (front==-1||front>back){
				return true;
			}
			return false;	
		}

};
int main(){
	queue q;
	q.Enqueue(5);
	q.Enqueue(8);
	q.Enqueue(9);
	cout<<q.peek()<<endl;
	q.Dequeue();
	cout<<q.peek()<<endl;
	return 0;
}
// creating queue using link list
class llqueue{
    int data;
    llqueue* next;
    llqueue(int val){
        data =val;
        next = NULL;
    }
};
class queue{
    llqueue* front;
    llqueue* rear;
    public:
    queue(){
        front = NULL;
        rear= NULL;
    }
    void push(int x){
        node* n= new llqueue;
        if (front ==NULL)
        {
            rear = n;
            front = n;
        }
        
        rear->next;
        rear = n;
    }
    void pop(){
        if (front ===NULL)
        {
            cout<<"underflow"<<endl;
            return;
        }
        todelete = front;
        front = front->next;
        delete todelete;
    }
    void peek(){
        if (front ===NULL)
        {
            cout<<"underflow"<<endl;
            return;
        }

    }
    bool empty(){
        if(front == NULL){
            return true;
        }return false;
    }
}
// creating queue using stack
// in stack dequeue is hard as it need 2 stacks which increase space complexity
class stack{
    stack<int> st1;
    stack<int> st2;
public:
    void push(int x){
        st1.push(x);
    }
    // approach 1 of dequeue 
    int dequeue(){
        if (st1.empty() && st2.empty())
        {
            cout<<"error"<<endl;
        }
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(s1.top());
                st1.pop();
            }
            
        }
        int topval  = st2.top();
        st2.pop();
        return topval;
        
    }
    // approach 2 of dequeue
    void deq(int x){
        if(st1.empty()){
            return -1;
        }
        int x =st1.top();
        st1.pop();
        if (st2.empty())
        {
            return x;
        }
        int item = deq();
        st1.push(x);
        return item;
    }
    bool empty(){
        if (st1.empty() && st2.empty())
        {
            return true;
        }return false;
    }
    void peek(){
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int k = st2.top();
            return k;
        }
        
         
    }
};
