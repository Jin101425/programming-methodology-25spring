#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i=0; i<32; i++) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (int i=0; i<32; i++) {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
    size = 0;
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int len = string_length(src);
    
    for (int i = 0; i<len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size >= 32) {
        throw std::out_of_range("List is full");
    }    
    else {
        int index = 0;
        for (int i = 0; i<32; i++) {
            if (tasks[i] == nullptr) {
            index = i;
            break;
            }
        }
        int len = string_length(task);
        tasks[index] = new char[len + 1];
        string_copy(tasks[index], task);

        size ++;
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    delete[] tasks[index];
    for (int i = index; i < size - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }
    tasks[size - 1] = nullptr;
    size--;
    
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    static const char* readonly_tasks[32];
    for (int i = 0; i < 32; ++i) {
        readonly_tasks[i] = tasks[i];
    }

    return readonly_tasks;
}