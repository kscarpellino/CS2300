#include "Quiz.h"
#include <iostream>
using namespace std;

int main() {
    Quiz q;
    q.takeQuiz("OurQuiz.txt", cout, cin);
    return 0;
}
