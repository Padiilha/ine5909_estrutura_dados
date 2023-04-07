template<typename T>
class Stack{
    private:
        int top = -1, maxElements;
        T *array;
    
    public:
        // Default Constructor
        Stack(){}

        // Template Constructor
        Stack<T>(int maxEl){
            maxElements = maxEl;
            array = new T[maxEl];
        }

        // Destructor
        ~Stack(){
            delete[] array;
        }

        void push(int valor){
            if (!fullStack()){
                top++;
                array[top] = valor;
            } else {
                throw top;
            }
        }

        int pop(){
            if (!emptyStack()){
                int popVal = array[top];
                top--;
                return popVal;
            } else {
                throw top;
            }
        }

        bool emptyStack(){
            return (numElements() == 0);
        }

        bool fullStack(){
            return (numElements() == maxElements);
        }

        int numElements(){
            return top + 1;
        }

        int stackTop(){
            return array[top];
        }
};