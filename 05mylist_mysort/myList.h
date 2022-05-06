


namespace MyList {
    template <typename T>
    struct Node {
        T value;
        std::unique_ptr<MyList::Node> next;
    };


    template <class T>
    class MyList {
        private:
            struct Node<T> * _head;
            int _size;


        public:

            MyList() {
                _size = 0;
                _head = NULL;
            }

            int size() {return _size;}

            void push_front(T const &);
            T pop_front();
            T front() const;

    };

        template <class T>
        void MyList<T>::push_front (T const& elem) {
            struct Node<T> new_node = {elem, NULL};
            if(_head == NULL) {
                _head = &new_node;
            }
            else {
                struct Node<T> * prev_head = &_head;
                _head = &new_node;
                _head->next = prev_head;
            }
        }

        template <class T>
        T MyList<T>::pop_front () {

        }

        template <class T>
        T MyList<T>::front ()  const{

        }


}