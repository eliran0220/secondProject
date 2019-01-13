#ifndef MYPRIORQUEUE_H
#define MYPRIORQUEUE_H

#include <queue>
#include <set>
#include "../searchPackage/State.h"
#include "MyUnorderedSet.h"


using namespace std;

/**
 * MyPriorityQueue class, creates a priority queue by the compare value
 * Can create min , max, and regular priority queue
 * @tparam T generic state
 * @tparam compare given compare value to determine the queue type
 */
template<class T, class compare>
class MyPriorQueue : public priority_queue<State<T> *, vector<State<T> *>, compare> {
    MyUnorderedSet<T> set;

public:
    /**
     * Function name: pushState
     * The function operation: given a state, pushes to the priorty queue
     * @param state a generic state
     */
    void pushState(State<T> *state) {
        this->push(state);
        this->set.insert(state);
    }

    /**
     * Function name: sizeQueue
     * The function operation: returns the size of the queue
     * @return int
     */
    int sizeQueue() {
        return (int) this->size();
    }

    /**
     * Function name: poll
     * The function operation: pops an element from the queue and removes it from the set
     * @return State<T>*
     */

    State<T> *poll() {
        if (this->sizeQueue() > 0) {
            State<T> *state = this->top();
            this->pop();
            this->set.remove(state);
            return state;
        }
        return nullptr;
    }

    /**
     * Function name: contains
     * The function operation: checks if the element exists in the set, if so, returns true
     * else returns false
     * @return bool
     * param state
     * @return
     */

    bool contains(State<T> *state) {
        if (this->set.contains(state)) {
            return true;
        }
        return false;
    }

    /**
     * Function name: eraseAndPush
     * The function operation: keeps popping elements untill the given element equals to the one
     * we popped. then we push all those elements back to the queue.
     * Used when a value was changed, so it's position in the priority queue might be changed.
     * @param state a given state
     */
    void eraseAndPush(State<T> *state) {
        vector<State<T> *> states;
        State<T> *temp;
        temp = this->poll();
        while (temp != nullptr) {
            states.push_back(temp);
            if (state->Equals(temp)) {
                break;
            }
            temp = this->poll();
        }
        for (int i = 0; i < (int) states.size(); ++i) {
            this->pushState(states[i]);
        }
    }

    MyUnorderedSet<T> getSetInQueue() {
        return this->set;
    }

};


#endif
