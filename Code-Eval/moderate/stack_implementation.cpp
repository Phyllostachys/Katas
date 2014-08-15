#include <cstdint>
#include <iostream>
#include <vector>
#include <fstream>

class Stack
{
public:
    void push(int val)
    {
        stack.push_back(val);
    }

    int pop()
    {
        if (stack.empty() == false) {
            int ret = stack[stack.size() - 1];
            stack.resize(stack.size() - 1);
            return ret;
        } else { return 0; }
    }

    int size()
    {
        return stack.size();
    }

    void clearStack()
    {
        stack.clear();
    }

    void toString()
    {
        for (int num : stack) {
            std::cout << num << " ";
        }
    }
private:
    std::vector<int> stack;
};

int main(int argc, char** argv)
{
    std::ifstream ifs(argv[1]);
    int num;
    Stack stack;

    while (ifs >> num) {
        stack.push(num);
        if (ifs.peek() == 0xD || ifs.peek() == 0xA) {
            //print out every other thing
            int startingSize = stack.size() / 2;
            for (int i = 0; i < startingSize; i++) {
                //std::cout << std::endl << "Current stack size: " << stack.size() << std::endl;
                std::cout << stack.pop() << " ";
                stack.pop();
            }

            if (stack.size() == 1) {
                std::cout << stack.pop() << " ";
            }

            // reset
            stack.clearStack();
            std::cout << std::endl;
        }
    }
    ifs.close();
    return 0;
}
