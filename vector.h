
//============================================//
//           This is Vector Library           //
//           Create:shadowlink_0122           //
//                  2018/2/7                  //
//============================================//

#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>

namespace self{

  template < typename X >
  class vector{
  private:
    // protected:
    typedef struct LIST{
      X value;
      LIST *next;
    }LIST;

    LIST *vec;
  public:
    
    // Initialize Linear List
    vector(){
      vec->value = 0;
      vec->next = NULL;
    }

    // Addition to the List
    void push( X temp ){
      LIST *p;
      LIST *prev;
      p = ( LIST* )malloc( sizeof( LIST ) );
      p->value = temp;
      p->next = NULL;
      prev = vec;
      for( LIST *next = vec->next ; next != NULL ; next = next->next )prev = next;
      prev->next = p;
    }

    // Erase from the List
    void pop( X temp ){
      LIST *prev;
      prev = vec;
      for( LIST *p = vec->next ; p != NULL ; p = p->next ){
        if( p->value == temp ){
          if( p->next != NULL )prev->next = p->next;
          else prev->next = NULL;
          free( p );
          return;
        }
        prev = p;
      }
    }

    // Display Elements from the List
    void print(){
      if( vec->next == NULL )return;
      for( LIST *p = vec->next ; p != NULL ; p = p->next ){
        std::cout << p->value;
        if( p->next != NULL )std::cout << ",";
      }
      std::cout << std::endl;
    }

    // Release All Memory
    ~vector(){
      LIST *next;
      LIST *del;
      next = vec->next;
      while( next ){
        del = next;
        next = next->next;
        free( del );
      }
    }
  };

}

#endif //__VECTOR__