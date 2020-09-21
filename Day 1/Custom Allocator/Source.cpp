#include <iostream>
#include <chrono>
using namespace std;

class Allocator
{
public:
    virtual void* allocate(size_t size) = 0;
    virtual void free(void* p) = 0;
};

struct b2StackEntry
{
    char* data;
    int size;
    bool usedMalloc;
};

class CustomAllocator : Allocator
{
public:
    virtual void* allocate(size_t size) override
    {
        b2StackEntry* entry = m_entries + count;
        entry->data = m_data + index;//(char*)malloc(size);
        entry->size = size;
        m_allocation += size;
        count++;
        return entry->data;
    }

    virtual void free(void* p) override
    {
        b2StackEntry* entry = m_entries + count - 1;
        index -= entry->size;
        m_allocation -= entry->size;;
        --count;
        p = nullptr;
    }
private:
    b2StackEntry m_entries[1000];
    char m_data[1000];
    int count = 0;
    int index = 0;
    int m_allocation = 0;
};

int main()
{
    int* x = nullptr;
    {
        
        //std::cout << sizeof(allocater);
        
        auto start = std::chrono::high_resolution_clock::now();
        CustomAllocator allocater;// = new CustomAllocator;
        for (int i = 0; i < 100000; i++)
        {
            x = (int*)allocater.allocate(sizeof(int));
            *x = 10;
            //delete x;
            allocater.free(x);
        }
       // delete allocater;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << elapsed.count() << std::endl;
    }

    //std::cout << *x;
std::cin.get();
}