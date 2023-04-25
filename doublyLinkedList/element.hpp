class Element {
  private:
    int key;
    Element* prev;
    Element* next;

  public:
    Element(int k, Element* p, Element* n) {
      key = k;
      prev = p;
      next = n;
    }

    Element(int k) {
      key = k;
      prev = nullptr;
      next = nullptr;
    }

    int getKey() {
      return key;
    }

    void setPrevious(Element* p) {
      prev = p;
    }

    Element* getPrevious() {
      return prev;
    }

    void setNext(Element* n) {
      next = n;
    }

    Element* getNext() {
      return next;
    }
};
