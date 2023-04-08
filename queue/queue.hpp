template<typename T>
class Queue{
  private:
    int maxElements, first = 0, last = -1, size = 0;
    T *array;

  public:
    // Default Constructor
    Queue(){}

    // Template Constructor
    Queue<T>(int maxEl){
      maxElements = maxEl;
      array = new T[maxEl];
    }

    // Destructor
    ~Queue(){
      delete[] array;
    }

    void enqueue(int valor){
      if (!fullQueue()){
        last = (last + 1) % maxElements - 1;
        array[last] = valor;
        size++;
      } else {
        throw size;
      }
    }

    int dequeue(){
      if(!emptyQueue()){
        int dequeueVal = array[first];
        first = (first + 1) % maxElements;
        size--;
        return dequeueVal;
      } else {
        throw size;
      }
    }

    int queueFirst(){
      if(!emptyQueue()){
        return array[first];
      }
    }

    int queueLast(){
      if (!emptyQueue()){
        return array[last];
      }
    }

    bool emptyQueue(){
      return (size == 0);
    }

    bool fullQueue(){
      return (size == maxElements);
    }
};