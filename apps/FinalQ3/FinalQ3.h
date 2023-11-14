//https://www.scaler.com/topics/quadratic-probing/
//used this for help

template <class RecordType>
class Table 
{
public:
    static const std::size_t CAPACITY = 811;
    Table();
    void insert(const ReacordType& entry) 
    {
        bool alreadPresent;
        std::size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);
        if (!alreadyPresent) 
        {
            assert(size() < CAPACITY);
            index = hash(entry.key);
            std::size_t count = 0;
            while (!isVacant(index)) 
                quadProbe(index, ++count);
            
            ++used;
        }
        data[index] = entry;
    }
    void remove(int key) 
    {
        bool found;
        std::size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }
    bool isPresent(int key) const
    {
        bool found;
        std::size_t index;
        findIndex(key, found, index);
        return found;
    }
    void find(int key, bool& found, RecordType& result) const
    {
        std::size_t index;
        findIndex(key, found, index);

        if (found)
            result = data[index];
        
    }
    std::size_t size() const { return used; }
private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    std::size_t used;
    std::size_t hash(int key) const
    {
        return key % CAPACITY;
    }
    std::size_t nextIndex(std::size_t index) const
    {
        return (index + count * count) % CAPACITY;
    }
    void findIndex(int key, bool& found, std::size_t& index) const 
    {
        std::size_t count = 0;
        index = hash(key);
        while ((count < CAPACITY) && (!never_used(index)) && (data[index].key != key)) 
        {
            ++count;
            quadProbe(index, count);
        }
        found = (data[index].key == key);
    }
    bool neverUsed(std::size_t index) const { return (index == NEVERUSED); }
    bool isVacant(std::size_t index) const { return (index == PREVIOUSLYUSED); }
    void quadProbe(std::size_t& index, std::size_t count) const
    {
        index = (index + count * count) % CAPACITY;
    }
};

template <class RecordType>
Table<RecordType>::Table() : used(0) 
{
    for (std::size_t i = 0; i < CAPACITY; ++i)
    {
        data[i].key = NEVERUSED;
    }
}



