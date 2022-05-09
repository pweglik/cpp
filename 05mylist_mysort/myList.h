#include <iosfwd>
#include <memory>

template <typename T> class MyList ;

template<typename U>
std::ostream& operator<<(std::ostream& os, const MyList<U>& my_list);


template <typename T>
class MyList {
    public:
        struct Node {
            T value;
            std::unique_ptr<MyList::Node> next = nullptr;

            Node(T value, std::unique_ptr<MyList::Node> next) {
                this->value = value;
                this->next = std::move(next);
            }
        };
        //fields
        std::unique_ptr<MyList::Node> head = nullptr;
        int _size;
    
        //cosntructors and operators
        explicit MyList();
        MyList(const MyList&) = delete;
        MyList& operator=(const MyList&) = delete;
        ~MyList() = default;

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const MyList<U>& my_list);

        //methods
        int size() const {return _size;};
        void push_front(T const &);
        T pop_front();
        T front() const;
        void remove(T);

        struct Iterator
        {
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::input_iterator_tag;

            friend class LinkedList;
            // constructor that takes in a pointer from the linked list
            Iterator() : current_node(nullptr){};
            Iterator(const std::unique_ptr<MyList::Node>& node) : current_node(node.get()){};

            // incrementing means going through the list
            Iterator &operator++()
            {
                if (current_node != nullptr)
                {
                    previous_node = current_node;
                    current_node = current_node->next.get();
                }
                return *this;
            };

            // post fixing is bad in general but it has it's usages
            Iterator operator++(int)
            {
                Iterator tempIter = *this; // we make a copy of the iterator
                ++*this;                   // we increment
                return tempIter;           // we return the copy before increment
            };

            // we need to be able to compare nodes
            bool operator!=(const Iterator &other) const
            {
                return this->current_node != other.current_node;
            };

            // return the data from the node (dereference operator)
            T operator*() const
            {
                return this->current_node->value;
            };

            private:
                const Node *previous_node = nullptr;
                const Node *current_node = nullptr;
        };
        // returning a const pointer to the front
        MyList::Iterator begin() const
        {
            return Iterator(this->head);
        };

        // returning a const pointer to the back - the back is always null because it marks the end of the list
        MyList::Iterator end() const
        {
            return Iterator(nullptr);
        };

        // returning a const pointer to the front
        MyList::Iterator begin()
        {
            return Iterator(this->head);
        };

        // returning a const pointer to the back - the back is always null because it marks the end of the list
        MyList::Iterator end()
        {
            return Iterator(nullptr);
        };
        
};

template <typename T>
MyList<T>::MyList() {
    _size = 0;
    head = nullptr;
}

template <typename T>
void MyList<T>::push_front (T const& elem) {
    if(head == nullptr) {
        head =  std::make_unique<MyList::Node>(elem, nullptr);
    }
    else {
        std::unique_ptr<MyList::Node> new_node =  std::make_unique<MyList::Node>(elem, nullptr);
        new_node->next = std::move(head);
        head = std::move(new_node);
    }
    _size++;
}

template <typename T>
T MyList<T>::pop_front () {
    if(_size == 0) {
        throw std::out_of_range("Cannot pop from empty list!");
    }
    T value = head->value;
    head = std::move(head->next);
    
    _size--;
    return value;
}

template <typename T>
T MyList<T>::front () const{
    return head->value;
}

template <typename T>
void MyList<T>::remove (T elem){
    Node * cur_node = head.get();
    Node * prev_node = NULL;

    while(cur_node != NULL) {
        if(cur_node->value == elem) {
            if(prev_node == NULL) { //  we want to delete first element
                head = std::move(cur_node->next);
                cur_node = head.get();
                _size--;
            }
            else
            {
                if(cur_node->next == nullptr) { // if last element
                    prev_node->next = nullptr;
                    _size--;
                    break;
                }
                
                prev_node->next = std::move(cur_node->next);
                cur_node = prev_node->next.get();
                _size--;
                continue;
                
            }  
        }
        prev_node = cur_node;
        cur_node = cur_node->next.get();
        
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyList<T>& my_list) {
    typename MyList<T>::Node * cur_node = my_list.head.get();

    while(cur_node != NULL) {
        os << cur_node->value << " ";
        cur_node = cur_node->next.get();
    }
    return os;
}

