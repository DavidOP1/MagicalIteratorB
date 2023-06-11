#include"./MagicalContainer.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
namespace ariel{
    /////////////////////////////////CONTAINER FUNCTIONS////////////////////////////////////////
    int MagicalContainer::getPosition(int num , vector <int> elems){
        unsigned int start = 0 ,end = elems.size();
        while(start < end){
            unsigned int mid = start + (end - start)/2;

            if(elems[mid] == num){
                return int(mid);
            }else if(elems[mid] < num){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return int(start);
    }

    void MagicalContainer::addElement(int num){
        int position = this->getPosition(num , this->elements);
        this->elements.insert(this->elements.begin()+position , num);
        //add element to prime vector only
        this->sideCrossPattern(num);
        if(this->checkPrime(num)){
            position = this->getPosition(num , this->prime);
            this->prime.insert(this->prime.begin()+position , num);
        }

        for(int i : this->prime){
            cout << i << endl;
        }
        }

     void MagicalContainer::sideCrossPattern(int num){
            sideCross.push_back(num);
            sort(sideCross.begin(), sideCross.end());

            vector<int> temp;
            vector<int>::size_type left = 0;
            vector<int>::size_type right = sideCross.size() - 1;

            while (left < right) {
                temp.push_back(sideCross[left++]);
                temp.push_back(sideCross[right--]);
            }

            if (left == right) {
                temp.push_back(sideCross[left]);
            }

            sideCross = temp;
        }


     bool MagicalContainer::checkPrime(int num){
         bool prime = true;
         if( num ==0 || num == 1) return false;
         for(int i=2; i<=(num/2) ; i++){
             if(num%i==0) prime = false;
         }

         return prime;
    }
;
    void MagicalContainer::removeElement(int num){
            int index=0;
            bool exist = false;
            for(int i : this->elements){            
            if(i==num) { exist = true ; break;}
            index++;
        }
        if(exist) this->elements.erase(this->elements.begin()+index);
        else throw runtime_error("element doesnt exist");
    }


    //////////////////////////////////////OPERATOR OVERLOADING///////////////////////
    bool  MagicalContainer::TopIterator::operator<(const TopIterator& other) const{
        //cout << "blyat: " << this->index << "asd : "<<other.index << endl;
        return (this->index<other.index);
    }
    bool  MagicalContainer::TopIterator::operator>(const TopIterator& other) const{
        //cout << "blyat: " << this->index << "asd : "<<other.index << endl;
        return (this->index>other.index);
    }
    bool  MagicalContainer::TopIterator::operator!=(const TopIterator& other) const{
        //cout << "blyat: " << this->index << "asd : "<<other.index << endl;
        return !(this->index==other.index);
    }
    bool MagicalContainer::TopIterator::operator==(const TopIterator& other) const{
        return (this->index==other.index);
    }
    int& MagicalContainer::TopIterator::operator*() {
        return this->iter_arr[this->index];
    }
    void MagicalContainer::TopIterator::operator=(TopIterator& otherIter){
        if(&this->temp_container!=&otherIter.temp_container){
            throw runtime_error("different containers");
        };
    }
    //////////////////////////////////////////ASCENDING ITERATOR//////////////////////////////////
    // Iterator prefix increment operator
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
    unsigned int index_temp = index;
    index_temp++;
    if(index_temp>this->iter_arr.size()){
        throw runtime_error("cant increase");
    }
    ++index;
    return *this;
    }

    // Iterator postfix increment operator
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int) {
    PrimeIterator temp = *this;
    ++index;
    return temp;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        return PrimeIterator(this->iter_arr , this->index, this->temp_container);
    }
    
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        return PrimeIterator(this->iter_arr , this->iter_arr.size() , this->temp_container);
    }

    ////////////////////////////////////PRIME ITERATOR//////////////////////////////////////

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
    unsigned int index_temp = index;
    index_temp++;
    if(index_temp>this->iter_arr.size()){
        throw runtime_error("cant increase");
    }
    ++index;
    return *this;
    }

    // Iterator postfix increment operator
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) {
    AscendingIterator temp = *this;
    ++index;
    return temp;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        return AscendingIterator(this->iter_arr , this->index , this->temp_container);
    }
    
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        return AscendingIterator(this->iter_arr , this->iter_arr.size() , this->temp_container);
    }


    ////////////////////////////////////SIDE CROSS ITERATOR///////////////////////////////////////////
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
    unsigned int index_temp = index;
    index_temp++;
    if(index_temp>this->iter_arr.size()){
        throw runtime_error("cant increase");
    }
    ++index;
    return *this;
    }

    // Iterator postfix increment operator
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) {
    SideCrossIterator temp = *this;
    ++index;
    return temp;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        return SideCrossIterator(this->iter_arr , this->index , this->temp_container);
    }
    
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        return SideCrossIterator(this->iter_arr , this->iter_arr.size() , this->temp_container);
    }

}