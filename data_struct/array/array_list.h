

template <typename E> class MyArrayList {
private:
  E *data;

  int size;
  int cap;

  static const int INIT_CAP = 1;

public:
  MyArrayList() {
    this->data = new E[INIT_CAP];
    this->size = 0;
    this->cap = INIT_CAP;
  }

  MyArrayList(int initCapacity) {
    this->data = new E[initCapacity];
    this->size = 0;
    this->cap = initCapacity;
  }

  void addLast(E e) {
    if (size == cap) {
      // resize();
    }
    data[size] = e;
    size++;
  }

  void add(int index, E e) {
    (void)index;
    (void)e;
  }

  bool isElementIndex(int index) { return index >= 0 && index < size; }

  bool isPositionIndex(int index) { return index >= 0 && index <= size; }
};
