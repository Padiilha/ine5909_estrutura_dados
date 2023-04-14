template<typename T>
class Element{
  private:
    int value;
    T *next;

  public:
    Element(){}

    Element<T>(int v, T &n){
      value = v;
      next = &n;
    }

    ~Element(){
      delete[];
    }
};