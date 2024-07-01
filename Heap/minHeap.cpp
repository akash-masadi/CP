#include <bits/stdc++.h>
using namespace std;

template <typename T> 
class PriorityQueue {
private:
    std::vector<T> pq;

    void swap(T* a, T* b) {
        T t = *a;
        *a = *b;
        *b = t;
    }

public:
	bool isEmpty()
	{
		return pq.size()==0;
	}
    int size() {
        return pq.size();
    }

    T poll() {
        T x = *pq.begin();
        *pq.begin()=*(pq.end()-1);
        pq.pop_back();
        heapify();
        copy(pq.begin(), pq.end(), std::ostream_iterator<int>(std::cout, " "));
        cout<<'\n';
        return x;
    }

void heapify() {
	int current=0;
    int size = pq.size();
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    while (left < size) 
    {
        int largest = current;
        if (left < size && pq[left] < pq[largest]) {
            largest = left;
        }
        if (right < size && pq[right] < pq[largest]) {
            largest = right;
        }
        if (largest != current) {
            swap(&pq[current], &pq[largest]);
            current = largest;
            left = 2 * current + 1; 
            right = 2 * current + 2;
        } 
		else 
		{
            break;
        }
    }
}


    T peek() {
        return *pq.begin();
    }

    void insert(T data) {
        pq.push_back(data);
        int current = pq.size() - 1;
        int parent;
        while (current > 0) {
            parent = (current - 1) / 2;
            if (pq[parent] > pq[current]) {
                swap(&pq[parent], &pq[current]);
            }
            current = parent;
        }
        copy(pq.begin(), pq.end(), std::ostream_iterator<int>(std::cout, " "));
        cout<<'\n';
    }

    void print()
    {	
    	typename std::vector<T>:: iterator itr;
    	for(itr=pq.begin();itr!=pq.end();itr++)
    	{
    		std::cout<<*itr<<" ";
		}
		std :: cout<<std::endl;
	}
};

int main() {
    PriorityQueue<int> PQ;
    for (int i = 10; i > 0; i--) {
        PQ.insert(i);
    }
    std::cout << PQ.size() << std::endl;
    PQ.print();
    while(!PQ.isEmpty())
    {
    	std::cout<<PQ.poll()<<" ";
//    	PQ.print();
	}
    return 0;
}

