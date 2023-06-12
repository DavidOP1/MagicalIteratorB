#include <vector>
#include <map>
using namespace std;
namespace ariel{
    class MagicalContainer{
        public:
            MagicalContainer(){};
            MagicalContainer(MagicalContainer&){};
            class TopIterator{
                protected:
                    unsigned int  index=0;
                    vector <int*> & iter_arr ;
                    MagicalContainer & temp_container;
                public:
                    TopIterator(vector <int*>& arr, unsigned int index_up , MagicalContainer& cont) : iter_arr(arr) , index(index_up) , temp_container(cont){};
                    TopIterator(MagicalContainer& cont ,vector<int*>& container ) : temp_container(cont),
                    iter_arr(container){};
                    int& operator*();
                    bool operator==(const TopIterator& otherIter) const;
                    bool operator>(const TopIterator& otherIter) const;
                    bool operator<(const TopIterator& otherIter) const ;
                    bool operator!=(const TopIterator& otherIter) const ; 
                    void operator=(TopIterator& otherIter);

            };
            class AscendingIterator : public TopIterator{
              public:   
                AscendingIterator(vector <int*>& arr , unsigned int index , MagicalContainer& container):TopIterator(arr,index,container){}
                AscendingIterator(MagicalContainer& container) : TopIterator(container , container.elements){};
                AscendingIterator& operator++();
                AscendingIterator operator++(int);
                AscendingIterator begin();
                AscendingIterator end();

            };
            class PrimeIterator : public TopIterator{
             public:
                PrimeIterator(vector <int*>& arr , unsigned int index , MagicalContainer& container):TopIterator(arr,index,container){}
                PrimeIterator(MagicalContainer& container) : TopIterator(container , container.prime){};
                PrimeIterator& operator++();
                PrimeIterator operator++(int);
                PrimeIterator begin();
                PrimeIterator end();;
            
            };
            class SideCrossIterator : public TopIterator{
             public:
                SideCrossIterator(vector <int*>& arr , unsigned int index ,MagicalContainer& container):TopIterator(arr,index,container){};
                SideCrossIterator(MagicalContainer& container) : TopIterator(container, container.sideCross){};
                SideCrossIterator& operator++();
                SideCrossIterator operator++(int);
                SideCrossIterator begin();
                SideCrossIterator end();
            };
            int size(){return this->elements.size();};
            void removeElement(int);
            void sideCrossPattern(int* num);
            void addElement(int);
            int getPosition(int,vector<int*>);
            static bool compareVal(const int * , const int * b);
            static bool checkPrime(int) ;
            ~MagicalContainer(){
                //Only need to free SideCross , or any of the other vectors , since they all point
                //To the same addresses of new int()
                for (int* ptr : sideCross) {
                    delete ptr;
                }
                sideCross.clear();
            };
        private:
            vector<int*> elements ,arr , sideCross , prime;
    };
}
