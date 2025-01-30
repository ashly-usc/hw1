#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  // put at the front
  if(head_ == nullptr){
    head_ = new Item();
    tail_ = head_;
    tail_->first = 0;
    tail_->last = 0;
  }
  else if(tail_->last == ARRSIZE){
    Item* newitem = new Item();
    newitem->prev = tail_;
    tail_->next = newitem;
    tail_ = newitem;
    tail_->first = 0;
    tail_->last = 0;
  }
  tail_->val[tail_->last] = val;
  tail_->last = tail_->last + 1;
  size_ = size_ + 1;
}

void ULListStr::pop_back()
{
  // if no nodes
  if(head_ == nullptr){

  }
  // if last != 0, only val will be removed and variables updated
  else if(tail_->last - tail_->first > 1){
    // tail_->val[tail_->last] = nullptr;
    tail_->last = tail_->last - 1;
    size_ = size_ - 1;
  }
  // if last = 0, tail_ node will be deleted
  else if(tail_->last - tail_->first == 1){
    Item* deleteitem = tail_;
    tail_ = tail_->prev;
    if(size_ == 1){
      head_ = nullptr;
      tail_ = nullptr;
    }
    delete deleteitem;
    size_ = size_ - 1;
  }

}

void ULListStr::push_front(const std::string& val)
{
  // put at the end 
  // if no items
  if(head_ == nullptr){
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
    
  }
  // if new item needs to be added bc first = 0
  if(head_->first == 0){
    Item* newitem = new Item();
    newitem->next = head_;
    head_->prev = newitem;
    head_ = newitem;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }
  head_->first = head_->first - 1;
  head_->val[head_->first] = val;
  size_ = size_ + 1;
}

void ULListStr::pop_front()
{
  if(head_ == nullptr){

  }
  // if only one val in first item, delete first item and change head
  else if(head_->last - head_->first == 1){
    Item* deleteitem = head_;
    head_ = head_->next;
    delete deleteitem;
    size_ = size_ - 1;
  }
  // if multiple val in first item, only val will be removed and variables updated
  else if(head_->last - head_->first > 1){
    head_->first++;
    size_ = size_ - 1;
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{

  if((head_ == nullptr) || (loc >= size_)){
    return nullptr;
  }

  // loc is index
  int temploc = loc;
  int itemsize = 0;
  Item* curr = head_;
  while(curr != nullptr){
    itemsize = curr->last - curr->first;
    if(temploc + 1 <= itemsize){ // found the right item
      // return &(curr->val[curr->first]);
      return &(curr->val[temploc + curr->first]);
    }
    else{
      temploc = temploc - itemsize;
      curr = curr->next;
    }
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
