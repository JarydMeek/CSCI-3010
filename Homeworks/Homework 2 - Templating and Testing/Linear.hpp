#ifndef _LINEAR_H_
#define _LINEAR_H_

#include<vector>


template <typename T>
class Linear {
    public:
        Linear(){}

        void insertElement(T val);

        T getElementAtIndex(const int index);

        bool search(const T val);

        void deleteElement(const T val);

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Linear<U> &l);


    private:
        std::vector<T> storage_;
};


#endif


/*
  Function: insert given value to the vector
  Input: value to add to the array
  Returns: none
*/
template <typename T>
    void Linear<T>::insertElement(T val) {
        storage_.push_back(val);
    }

/*
  Function: getter for element at index
  Input: index to get value of
  Returns: value at given index
*/
template <typename T>
    T Linear<T>::getElementAtIndex(const int index) {
        return storage_[index];
    }

/*
  Function: searches vector for given value
  Input: value to search for.
  Returns: true if element found in vector, false if not.
*/
template <typename T>
    bool Linear<T>::search(const T val) {
        for (T curr : storage_ ) {
            if (curr == val) {
                return true;
            }
        }
        return false;
    }

/*
  Function: delete the given element from array
  Input: value to delete from vector
  Returns: none
*/
template <typename T>
    void Linear<T>::deleteElement(const T val) {
        for (int x = 0; x < storage_.size(); x++) {
            if (storage_[x] == val) {
                storage_.erase(storage_.begin()+x);
            }
        }
    }


/*
  Function: overload << for printing vector
*/
template <typename U>
    std::ostream& operator<<(std::ostream& os, const Linear<U> &l) {
        os << "{";
        for (int x = 0; x < l.storage_.size(); x++) {
            if (x < l.storage_.size()-1){
                os << l.storage_[x] << ", ";
            } else {
                os << l.storage_[x];
            }
        }
        os << "}";
        return os;
    }
