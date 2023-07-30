#include "Handler.h"
#include "../GameObj.h"
#include <vector>
#include <iterator>
#include <cstddef>

#ifndef GAME_OBJ_HANDLER_H
#define GAME_OBJ_HANDLER_H

class GameObjHandler : private Handler<GameObj, void> {
    public:
        GameObjHandler() {};
        ~GameObjHandler() {};

        void Initialize() override {};
        void Shutdown() override {};
        void Update(GameObj *obj) override {};

        void AddGameObj(GameObj *obj) {};
        void RemoveGameObj(GameObj *obj) {};

        template <class R>
        struct Iterator {
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = R*;
            using pointer = R*; 
            using reference = R&;

            Iterator(pointer ptr) : m_ptr(ptr) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() { return m_ptr; }

            Iterator& operator++() { m_ptr++; return *this; }  

            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }; 

            private:
                pointer m_ptr;  
        };

        Iterator<GameObj *> begin() { return Iterator<GameObj *>(&this->objs[0]); }
        Iterator<GameObj *> end() { return Iterator<GameObj *>(&this->objs[this->objs.size()]); }

    private:
        std::vector<GameObj*> objs;

};

#endif