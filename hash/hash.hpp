template<typename T>
class Hash {
  private:
    int hashing(int key) {
      return key % size;
    }
  public:

    Hash() {}

    Hash<T>(int size) {
      array = new T[size];
    }

    ~Hash() {
      delete[array];
    }

    void insertElement(int key) {
      arrayPosition = hashing(key);
      if (*array[arrayPosition] == NULL) {
        array[arrayPosition] = new LinkedList<T>();
      }
      array[arrayPosition].insertElement(key);
    }

    Element searchElement(int key) {
      arrayPosition = hasing(key);
      if (*array[arrayPosition] != NULL) {
        return array[arrayPosition].searchElement(key);
      } else {
        return NULL
      }
    }

    void deleteElement(int key) {
      arrayPosition = hashing(key);
      if (*array[arrayPosition] != NULL) {
        throw ... // the required Element to delete do not exist
      } else {
        array[arrayPosition].deleteElement(key);
      }
    }
};
