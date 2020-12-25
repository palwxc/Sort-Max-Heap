//Programmer: Phillip LaFrance	//Student ID: 12398940
//Intructor: Patrick Taylor		//Section: A		//Date: 04/11/2018
//File: MyHeap.h			    //Description: Defines functions for MyHeap class

#ifndef MYHEAP_H_INCLUDED
#define MYHEAP_H_INCLUDED

using std::cout;
using std::endl;

template <typename E>
class MyHeap
{
    private:
        E *Heap;          // Pointer to the heap array
        int maxsize;      // Maximum size of the heap
        int n;            // Number of elements now in the heap, cannot be used as index

        // Swap two elements in a generic array
        inline void swap(E& i, E& j){
            E temp = i;
            i = j;
            j = temp;
        }

        // Helper function to put element in its correct place
        void siftdown(int pos)
        {
            while(!isLeaf(pos)) // Stop if pos is a leaf
            {
                int greaterChild = leftchild(pos);
                int rc = rightchild(pos);

                if((rc < n) && (Heap[rc] > Heap[greaterChild]))
                    greaterChild = rc;            // Set to greater child's value

                if(Heap[pos] > Heap[greaterChild])
                    return; // Done

                std::swap(Heap[pos], Heap[greaterChild]);
                //swap(Heap, pos, greaterChild); // swaps indexed values, not indices

                pos = greaterChild;             // Move down (change index)
            }
        }

        //reserve
        void reserve()
        {
            /*
            E tmp[++maxsize];
            //Heap = source.Heap;
            for (int i=0; i<maxsize; i++)
                tmp[i]=Heap[i];
            delete[] Heap; //comment out to test leakage
            Heap = tmp;
            */
            E *tmp;
            tmp = new E[++maxsize];
            //tmp = Heap;
            for (int i=0; i<maxsize; i++)
                tmp[i]=Heap[i];
            delete[] Heap; //including makes push into middle not work
            /*
            cout << "\t";
            for (int i=0; i<maxsize; i++)
                cout << tmp[i] << " ";
            cout << endl;
            */
            Heap = tmp;
        }

        //shrink_to_fit
        //called if maxsize/4 > n
        void shrink_to_fit()
        {
            E *tmp;
            if(n>0)
            {
                tmp = new E[n]; //n*2??
                maxsize=n;
                for (int i=0; i<maxsize; i++)
                    tmp[i]=Heap[i];
            }
            else
            {
                tmp = new E[1]; //n*2??
                maxsize=1;
            }
            delete[] Heap;
            Heap = tmp;
        }

        bool isLeaf(int pos) const { return ((pos >= n/2) && (pos < n)); } // True if pos is a leaf

        // Indexing starting at 0
        int leftchild(int pos) const { return ((2 * pos) + 1); } // Return leftchild position

        int rightchild(int pos) const { return ((2 * pos) + 2); } // Return rightchild position

        int parent(int pos) const { return ((pos - 1) / 2); } // Return parent position

        // Heapify contents of Heap
        void buildHeap()
        {
            //for(int i = (n - 1) / 2; i >= 0; i--)
            for(int i = parent(n-1); i >= 0; i--)
                siftdown(i);
        }

        // Insert "it" into the heap
        void insert(const E &it)
        {
            if(n >= maxsize)
                reserve();

            Heap[n] = it;            // Start after end of heap
            int curr = n++;          // ask, what does post increment do?

            // Now sift up until curr's parent > curr
            while((curr != 0) && (Heap[curr] > Heap[parent(curr)]))
            {
                std::swap(Heap[curr], Heap[parent(curr)]);
                curr = parent(curr);
            }
        }

        // Remove first value
        E removefirst()
        {
            // Swap first with last value
            std::swap(Heap[0], Heap[--n]);

            if(n != 0)
                siftdown(0);  // Siftdown new root val

            if(maxsize/4 > n)
                shrink_to_fit();

            // Return "deleted" value (hack for temp storage after end of real data)
            return Heap[n];
        }
/*
        // Remove and return element at specified position (not really needed)
        E remove(int pos)
        {
            Assert((pos >= 0) && (pos < n), "Bad position");

            if(pos == (n - 1))
                n--; // Last element, no work to do
            else
            {
                std::swap(Heap[pos], Heap[--n]);
                //swap(Heap, pos, --n);          // Swap with last value

                while((pos != 0) && (Heap[pos] > Heap[parent(pos)]))
                {
                    std::swap(Heap[pos], Heap[parent(pos)]);
                    //swap(Heap, pos, parent(pos)); // Push up large key

                    pos = parent(pos);
                }

                if(n != 0)
                    siftdown(pos);     // Push down small key
            }
            return Heap[n];

        }
*/
    public:
        //Default Constructor
        MyHeap()
        {
            n = 0;
            maxsize = 0;
            Heap = new E[0];//?? delete[]
        }

        //Parameterized Constructor
        MyHeap(E h[], int num)
        {
            n = num;
            maxsize = num;
            Heap = new E[maxsize];
            Heap = h;
            buildHeap();
        }

        //Copy Constructor
        MyHeap(const MyHeap &source)//<E>??
        {
            n = source.n;
            maxsize = source.maxsize;
            Heap = new E[maxsize];
            //Heap = source.Heap;
            for (int i=0; i<n; i++)
                Heap[i]=source.Heap[i];
            buildHeap();
        }

        //Destructor
        ~MyHeap()
        {
            if(n!=0)
                delete[] Heap; //causing issues for fresh builds
            Heap = NULL;
        }

        //operator=
        MyHeap& operator=(const MyHeap &source)
        {
            delete[] Heap;
            n = source.n;
            maxsize = source.maxsize;
            Heap = new E[maxsize];
            Heap = source.Heap;
            buildHeap();
            return *this;
        }

        //top
        E top()
        {
            if(empty())
                return 0;
            return Heap[0];
        }
        //pop
        void pop()
        {
            if(empty())
                return;
            removefirst(); //also decrements n
        }

        //push
        void push(const E &it)
        {
            insert(it);
        }

        //empty
        bool empty()
        {
            if(n==0)
                return true;
            return false;
        }

        //size
        int size() const       // Return current heap size
        {
            return n;
        }
};


#endif // MYHEAP_H_INCLUDED
