#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

template<typename Object>
class ArrayList {
  private:
    void resize();

    bool emptyList();
    
  public:
    ArrayList<Object>(int size) {
      array* = new Object[size];
    }

    ~ArrayList() {
      delete array;
    }

    void insert(
      std::string nome,
      std::string curso,
      std::string semestre_ingresso,
      std::string cidade_origem
    );

    bool remove(int id);

    Object* access(int id);
};

#endif