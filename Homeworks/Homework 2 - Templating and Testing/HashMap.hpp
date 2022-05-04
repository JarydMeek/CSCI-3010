#ifndef _HASHMAP_H_
#define _HASHMAP_H_


template <typename T>
class HashMap {
    public:
        //Initialize the map with a list of elements. You will also fix the size of your hash table(map) through the constructor.
        HashMap(std::vector<T> vals, int size);
        HashMap();

        //This function should return the bucket in which the element should be inserted.
        int hashKey(T val);

        //Insert an element at the appropriate position in the Map.
        void insertElement(T val);

        //Returns if the element is found in the Binary Search Tree
        bool search(const T val);

        //Delete the element from the Tree
        void deleteElement(const T val);

        //Overload Print
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const HashMap<U> &l);


    private:
        int arrSize_;
        std::vector<T> *data_;
};


#endif

/*
  Function: Constructor when passed vals + size
  Input: Values to add to hashmap, size of hashmap
  Returns: none
*/
template <typename T>
    HashMap<T>::HashMap(std::vector<T> vals, int size) {
        data_ = new std::vector<T>[size];
        arrSize_ = size;
        for (T curr : vals) {
            insertElement(curr);
        }
    }


/*
  Function: default constructor
  Input: none
  Returns: none
*/
template <typename T>
    HashMap<T>::HashMap() {
        data_ = new std::vector<T>[100];
        arrSize_ = 100;
    }

/*
  Function: Generates the hash key for a given value
  Input: a value to generate a hashkey for.
  Returns: the generated hash key
*/
template <typename T>
    int HashMap<T>::hashKey(T val) {
        std::hash<T> hasher;
        int hashed = (int)hasher(val);
        return abs(hashed % arrSize_);
    }

/*
  Function: insert the given value into the hashmap
  Input: value to insert into the table
  Returns: none
*/
template <typename T>
    void HashMap<T>::insertElement(T val) {
        data_[hashKey(val)].push_back(val);
    }

/*
  Function: search for the given data_ in the hashmap
  Input: value to search for
  Returns: true if value could be found, false if item could not
*/
template <typename T>
    bool HashMap<T>::search(T val) {
        for (T curr : data_[hashKey(val)]) {
            if (curr == val) {
                return true;
            }
        }
        return false;
    }

/*
  Function: delete the given element from the hashmap
  Input: value to delete from the hashmap
  Returns: none
*/
template <typename T>
    void HashMap<T>::deleteElement (T val) {
        for (int x = 0; x < data_[hashKey(val)].size(); x++) {
            if (data_[hashKey(val)][x] == val) {
                data_[hashKey(val)].erase(data_[hashKey(val)].begin()+x);
                return;
            }
        }
    }
    

/*
  Function: overloaded << operator to allow printing of hashmap
*/
template <typename U>
    std::ostream& operator<<(std::ostream& os, const HashMap<U> &l) {
        os << "{";
        std::string output = "";
        for (int x = 0; x < l.arrSize_; x++) {
            for (U currVal : l.data_[x]) {
                output += std::to_string(currVal) + ",";
            }
        }
        output.pop_back();
        os << output << "}";
        return os;
    }