template<typename T>
class Element {
  private:
    int key;
    T* prev, next;

  public:
    Element() {}

    Element<T>(int k, T &p, T &n) {
      key = k;
      prev = &p
      next = &n;
    }

    ~Element() {
      delete[];
    }

    int getKey() {
      return key;
    }

    void setPrevious(T &p) {
      prev = &p;
    }

    T getPrevious() {
      return *prev;
    }

    void setNext(T &n) {
      next = &n;
    }

    T getNext() {
      return *next;
    }
};
