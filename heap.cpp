#include <iostream>
#include <vector>

class Heap{
    private:
        std::vector<int> heap;
        void heapifyUp(int index)
        {
            // Parent of (i)th element = (i - 1) / 2
            // Left child of (i)th element = (2 * i) + 1
            // Right child of (i)th element = (2 * i) + 2
            while(index > 0)
            {
                int parent = (index - 1) / 2;
                if(this->heap[parent] < this->heap[index])
                {
                    std::swap(this->heap[index], this->heap[parent]);
                    index = parent;
                }
                else{
                    break;
                }
            }
        }

        void heapifyDown(int index)
        {
            while(index < this->heap.size())
            {
                int selected = index;
                int left = (2 * index) + 1;
                int right = (2 * index) + 2;
                if(left < this->heap.size() && this->heap[selected] < this->heap[left])
                {
                    selected = left;
                }
                if(right < this->heap.size() && this->heap[selected] < this->heap[right])
                {
                    selected = right;
                }
                if(selected == index)
                {
                    break;
                }
                std::swap(this->heap[index], this->heap[selected]);
                index = selected;
            }
        }
    public:
        Heap(int element)
        {
            this->heap.push_back(element);
        }
        Heap *insert(int data)
        {
            this->heap.push_back(data);
            this->heapifyUp(this->heap.size() - 1);
            return this;
        }
        int remove()
        {
            std::swap(this->heap[0], this->heap[this->heap.size()-1]);
            int element = this->heap[this->heap.size()-1];
            this->heap.pop_back();
            this->heapifyDown(0);
            return element;
        }
        Heap *print_heap()
        {
            for(int i=0;i< this->heap.size();i++)
            {
                std::cout << this->heap[i] << std::endl;   
            }
            return this;
        }
        int get_Max()
        {
            return this->heap[0];
        }

};

void heap_sort(std::vector<int> &arr)
{
     Heap h(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        h.insert(arr[i]);
    }
    for(int i=0;i<arr.size();i++)
    {
        arr[i] = h.remove();
    }
}

int main(void)
{
    std::vector<int> arr = {20, 10, 40, 50, 80, 5, 30};
    heap_sort(arr);
    for(int i=0;i<arr.size();i++)
    {
        std::cout << arr[i]<<std::endl;
    }
    // std::cout << "\n-----------------------------------------------------------\n\n";
    // h.print_heap()->remove();
    // std::cout << "\n-----------------------------------------------------------\n\n";
    // h.print_heap()->remove();
    // std::cout << "\n-----------------------------------------------------------\n\n";
    // h.print_heap()->remove();
}