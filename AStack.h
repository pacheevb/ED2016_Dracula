#ifndef STACK_H
#define STACK_H
#define defaultSize 2048
#include <stdexcept>

template <typename E>
class AStack{
    private:
        int maxSize;
        int top;
        E *ListArray; //puntero a arreglo

    public:
    AStack(int size = defaultSize){
        maxSize = size;
        top = 0;
        ListArray = new E[size];
    }

    ~AStack() {delete [] ListArray;}

    void clear(){top = 0;}

    void push(E pElement)throw(){
        if(top == maxSize){
        }
        ListArray[top++] = pElement;
    }

    E pop()throw(){
        if(top == 0){
        }
        return ListArray[--top]; //retorna top y despues lo decrementa
    }

    E topValue() throw(){
        if (top == 0){
        }
        return ListArray[top-1];
    }

    int length(){
        return top; //larog de pila
    }

};

#endif // STACK_H
