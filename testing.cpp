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
     * TODO: Test case for takeQuiz
     */
     //constructor test case
     if ((qz.getTitle()!= "")||(qz.getTotalPointsCorrect()!=0||(qz.getTotalPointsPossible()!=0))){
         passed = false;
         cout << "FAILED default constructor test case" << endl;
     }
     /* Test case for readQuizFromFile */
     qz.readQuizFromFile("OurQuiz.txt");
     int num_questions = qz.getQuestionsSize();
     string title = qz.getTitle();
     Question q;
     q.setPrompt("How many children are born in the world every single day?");
     q.setPoints(3);
     auto question = qz.getQuestion(0);
     if (num_questions != 5 || title != "Welcome to Our Random but Vitally Important Quiz" || !(question == q)){
         passed = false;
         cout << "FAILED readQuizFromFile test case" << endl;
     }


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

    /* test case for takeQuiz() */

    return passed;

}

bool test_Question(){
    bool passed = true;

    /* constructor test case */
    Question q;
    if (q.getPrompt() != "" or q.getPoints()!=0){
        passed = false;
        cout << "Failed question constructor test case" << endl;
    }

    /* getPrompt() test case */
    if (q.getPrompt()!= ""){
        passed = false;
        cout << "Failed getPrompt test case" << endl;
    }

    /* getPoints() test case */
    if (q.getPoints()!= 0){
        passed = false;
        cout << "Failed getPoints test case" << endl;
    }

    /* getNumAnswers test case */
    q.addAnswer("Yes", 0);
    if (q.getNumAnswers()!=1){
        passed = false;
        cout << "Failed getNumAnswers test case" << endl;
    }

    /* Test case for setPrompt (string prompt) */
    q.setPrompt("Is water wet?");
    if (q.getPrompt()!= "Is water wet?"){
        passed = false;
        cout << "Failed setPrompt test case" << endl;
    }

    /* Test case for setPoints */
    q.setPoints(4);
    if(q.getPoints()!=4){
        passed = false;
        cout << "Failed setPoints test case" << endl;
    }

    /* Test case for add answer with answer input */
    answer a;
    a.text = "Yes";
    a.correct = false;
    q.addAnswer(a);

    if (q.getNumAnswers() !=1){
        passed = false;
        cout << "Failed addAnswer test case with answer parameter" << endl;
    }

    /* Test case for add answer with string and bool input */
    q.addAnswer("No", true);
    if (q.getNumAnswers()!=2){
        passed = false;
        cout << "Failed addAnswer test case with string and bool parameters" << endl;
    }

    /*Test case for removeAnswer given integer index */
    q.removeAnswer(0);
    if (q.getNumAnswers()!=1){
        passed = false;
        cout << "Failed removeAnswer test case with integer index" << endl;
    }

    /* Test case for removeAnswer given string */
    q.removeAnswer("No");
    if (q.getNumAnswers() != 0){
        passed = false;
        cout << "Failed removeAnswer test case with string input" << endl;
    }

    /*Test case for clearAnswers */
    q.addAnswer(a);
    q.addAnswer("No", true);
    q.clearAnswers();
    if (q.getNumAnswers()!=0){
        passed = false;
        cout << "Failed clearAnswers test case" << endl;
    }

    /* Test case for is correct with int input */
    q.addAnswer(a);
    q.addAnswer("No", true);
    if (q.isCorrect(0)){
        passed = false;
        cout << "Failed isCorrect with int input test case" << endl;
    }

    /* Test case for isCorrect with string input */
    if (q.isCorrect("Yes")){
        passed = false;
        cout << "Failed isCorrect with string input test case" << endl;
    }

     return passed;
};

