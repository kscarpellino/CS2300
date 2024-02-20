//
// Created by Julia Booth-Howe on 2/17/24.
//
#include "Quiz.h"
#include <ctime>
#include <iostream>
using namespace std;

/** TODO: test each function in Quiz.h and Question. h **/

bool test_Quiz();
bool test_Question();

int main(){
    srand(time(NULL));
    if (test_Quiz()){
        cout << "Passed all Quiz test cases" << endl;
    }
    if (test_Question()){
        cout << "Passed all Question test cases" << endl;
    }
    return 0;
}

bool test_Quiz(){
    bool passed = true;
    Quiz qz;
    /**
     * TODO: Test case for read quiz from file
     * TODO: Test case for takeQuiz
     */
     //constructor test case
     if ((qz.getTitle()!= "")||(qz.getTotalPointsCorrect()!=0||(qz.getTotalPointsPossible()!=0))){
         passed = false;
         cout << "FAILED default constructor test case" << endl;
     }
     /* Test case for readQuizFromFile */
        // I HAVE NO CLUE

    /* Test case for setTitle */
    qz.setTitle("Quiz");
    if (qz.getTitle()!="Quiz") {
        passed = false;
        cout << "FAILED setTitle test case" << endl;
    }

     /* Test case for addQuestion*/
     Question correct_question;
     Question result;
     correct_question.setPrompt("Is water wet?");
     correct_question.setPoints(1);
     correct_question.addAnswer({"Yes"}, false);
     correct_question.addAnswer({"No"}, true);
     qz.addQuestion(correct_question);
     if (qz.getQuestionsSize() != 1){
         passed = false;
         cout << "Failed addQuestion test case" << endl;
     }

     /* getQuestion from int test case */
     qz.getQuestion(0) = result;
    if(!(result == correct_question)){
        passed = false;
        cout << "Failed getQuestion(int) test case" << endl;
    }

    /*getQuestion from string test case*/
    qz.getQuestion("Is water wet?") = result;
    if(!(result == correct_question)){
        passed = false;
        cout << "Failed getQuestion(string) test case" << endl;
    }
    /* removeQuestion from int index test case*/
    qz.removeQuestion(0);
    if (qz.getQuestionsSize()!= 0){
        passed = false;
        cout << "Failed removeQuestion(int) test case" << endl;
    }

    /*removeQuestion from string test case */
    correct_question.setPrompt("Is water wet?");
    correct_question.setPoints(1);
    correct_question.addAnswer({"Yes"}, false);
    correct_question.addAnswer({"No"}, true);
    qz.addQuestion(correct_question);

    qz.removeQuestion("Is water wet?");
    if (qz.getQuestionsSize()!=0){
        passed = false;
        cout <<  "Failed removeQuestion(string) test case" << endl;
    }


    return passed;




}

bool test_Question(){
    bool passed = true;
    Question qt;
    /** TODO: Test case for constructor
     * TODO: Test case for getPrompt()
     * TODO: Test case for getPoints()
     * TODO: Test case for getNumAnswers()
     * TODO: Test case for setPrompt(string prompt)
     * TODO: Test case for setPoints(int points)
     * TODO: Test case for addAnswer(answer a)
     * TODO: Test case for addAnswer(string text, bool correct)
     * TODO: Test case for removeAnswer(int index)
     * TODO: Test case for removeAnswer(string s)
     * TODO: Test case for void clearAnswers()
     * TODO: Test case for bool isCorrect(int index)
     * TODO: Test case for bool isCorrect(string text)
     * not sure if i need a test case for
     * friend ostream& operator << (ostream& outs, const Question& q)
     */
     return passed;
};

