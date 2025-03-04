#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <cctype>
#include <atomic>
#include <iomanip>

using namespace std;
float percentage;
int courseCodeEnter;
int num_of_students = 0;
int num_of_teachers = 5;
int index_teacher;
int time_view = 1;
string stuORteach;
bool timerRunning = true;
int timePerQuestion;
int counterAnswers;
bool z = true;
int remainingMin, remainingSec;
string studentName, studentPassword;
struct teacher
{
    string username_teacher;
    string password_teacher;
    int coursecode_teacher;
} teachers[100];
struct Subject_display
{
    string question;
    string options[5];
    char correctAnswer;
} SP_testbank[22], businesscCommunication_testbank[22], english_testbank[22], german_testbank[22], ethics_testbank[22];
struct Question
{
    string question;
    string options[4];
    char correctAnswer;
};
struct Exam
{
    Question ques[100];
    int num_of_questions = 3;
};
struct Subject
{

    int courseCode;
    Exam exams;
} entering, subject[5];
struct student
{
    float studentGrade;
    string student_id;
    string username_student;
    string password_student;
    int list_of_subject[5] = { -1, -1, -1, -1, -1 };
} students[100];

void display_grades();
void Main_Screen();
void Register();
void Log_in();
void valid(string maxvalid, string& input);
void student();
void choose_subject();
void exam(int coursecode, int num_of_questions);
void change_answers(char change_answer[], int num_of_questions);
void submit_exam(int index_of_subject, char answer_array[]);

void displayQuestions(Subject entering, vector<pair<string, char>>& questions_correct_answer, vector<string>& answers, int number_of_question)
{
    //
    SP_testbank[1].question = "What is C++?";
    SP_testbank[1].options[1] = "C++ is an object oriented programming language.";
    SP_testbank[1].options[2] = "C++ is a procedural programming language.";
    SP_testbank[1].options[3] = "C++ supports both procedural and object oriented programming language.";
    SP_testbank[1].options[4] = "C++ is a functional programming.";
    SP_testbank[1].correctAnswer = 'C';
    //

    SP_testbank[2].question = "Which of the following is a correct identifier in C++?";
    SP_testbank[2].options[1] = "VAR_1234";
    SP_testbank[2].options[2] = "$var_name";
    SP_testbank[2].options[3] = "7VARNAME";
    SP_testbank[2].options[4] = "7var_name";
    SP_testbank[2].correctAnswer = 'A';
    //
    SP_testbank[3].question = "Which of the following approach is used by C++?";
    SP_testbank[3].options[1] = "Left - right";
    SP_testbank[3].options[2] = "Right-left";
    SP_testbank[3].options[3] = "Bottom-up";
    SP_testbank[3].options[4] = "Top-down";
    SP_testbank[3].correctAnswer = 'C';
    //
    SP_testbank[4].question = "Which of the following type is provided by C++ but not C?";
    SP_testbank[4].options[1] = "double";
    SP_testbank[4].options[2] = "float";
    SP_testbank[4].options[3] = "int";
    SP_testbank[4].options[4] = "bool";
    SP_testbank[4].correctAnswer = 'D';
    //
    SP_testbank[5].question = "Which of the following correctly declares an array in C++?";
    SP_testbank[5].options[1] = "array{10};";
    SP_testbank[5].options[2] = "array array[10];";
    SP_testbank[5].options[3] = "int array;";
    SP_testbank[5].options[4] = "int array[10];";
    SP_testbank[5].correctAnswer = 'D';
    //
    SP_testbank[6].question = "Which is more effective while calling the C++ functions?";
    SP_testbank[6].options[1] = "call by reference";
    SP_testbank[6].options[2] = " call by object ";
    SP_testbank[6].options[3] = "call by pointer ";
    SP_testbank[6].options[4] = "call by value ";
    SP_testbank[6].correctAnswer = 'A';
    //
    SP_testbank[7].question = "Which of the following symbol is used to declare the preprocessor directives in C++?";
    SP_testbank[7].options[1] = " $ ";
    SP_testbank[7].options[2] = " ^ ";
    SP_testbank[7].options[3] = " # ";
    SP_testbank[7].options[4] = " * ";
    SP_testbank[7].correctAnswer = 'C';
    //
    SP_testbank[8].question = "Which of the following is used to terminate the function declaration in C++?";
    SP_testbank[8].options[1] = " ; ";
    SP_testbank[8].options[2] = " ] ";
    SP_testbank[8].options[3] = " ) ";
    SP_testbank[8].options[4] = " : ";
    SP_testbank[8].correctAnswer = 'A';
    //
    SP_testbank[9].question = "Which of the following is the correct syntax to add the header file in the C++ program?";
    SP_testbank[9].options[1] = " #include<userdefined> ";
    SP_testbank[9].options[2] = "#include (userdefined.h)";
    SP_testbank[9].options[3] = "<include> <userdefined.h>";
    SP_testbank[9].options[4] = " Both 1 and 2";
    SP_testbank[9].correctAnswer = 'A';
    //
    SP_testbank[10].question = "Which of the following is the correct syntax to read the single character to console in the C++ language? ";
    SP_testbank[10].options[1] = " Read ch() ";
    SP_testbank[10].options[2] = "Getline vh() ";
    SP_testbank[10].options[3] = "get(ch)  ";
    SP_testbank[10].options[4] = "Scanf(ch) ";
    SP_testbank[10].correctAnswer = 'C';
    /////////////////////////////////////////////////////////////////
    businesscCommunication_testbank[1].question = " Communication is a __.";
    businesscCommunication_testbank[1].options[1] = "one way process.";
    businesscCommunication_testbank[1].options[2] = "two way process. ";
    businesscCommunication_testbank[1].options[3] = "three way process. ";
    businesscCommunication_testbank[1].options[4] = " four way process. ";
    businesscCommunication_testbank[1].correctAnswer = 'B';
    //
    businesscCommunication_testbank[2].question = "Communication saves time in __.";
    businesscCommunication_testbank[2].options[1] = "internal communication. ";
    businesscCommunication_testbank[2].options[2] = " interview. ";
    businesscCommunication_testbank[2].options[3] = " oral communication. ";
    businesscCommunication_testbank[2].options[4] = "  schedule. ";
    businesscCommunication_testbank[2].correctAnswer = 'D';
    //
    businesscCommunication_testbank[3].question = "A group discussion of a real life situation with in a training environment is __.";
    businesscCommunication_testbank[3].options[1] = "discussion. ";
    businesscCommunication_testbank[3].options[2] = "listening. ";
    businesscCommunication_testbank[3].options[3] = "  case study method. ";
    businesscCommunication_testbank[3].options[4] = "all of the above. ";
    businesscCommunication_testbank[3].correctAnswer = 'A';
    //
    businesscCommunication_testbank[4].question = "Communication is the __ of business.";
    businesscCommunication_testbank[4].options[1] = "life blood. ";
    businesscCommunication_testbank[4].options[2] = "Backbone.  ";
    businesscCommunication_testbank[4].options[3] = "nervous system. ";
    businesscCommunication_testbank[4].options[4] = "both(1)& (2). ";
    businesscCommunication_testbank[4].correctAnswer = 'B';
    //
    businesscCommunication_testbank[5].question = "The communication cycle, the process of re translation of signals into ideas is called  __.";
    businesscCommunication_testbank[5].options[1] = "encoding ";
    businesscCommunication_testbank[5].options[2] = "decoding ";
    businesscCommunication_testbank[5].options[3] = "response ";
    businesscCommunication_testbank[5].options[4] = "feedback ";
    businesscCommunication_testbank[5].correctAnswer = 'B';
    //
    businesscCommunication_testbank[6].question = "The downward communication flow from __.";
    businesscCommunication_testbank[6].options[1] = " a subordinate to a superior. ";
    businesscCommunication_testbank[6].options[2] = " a subordinate to a subordinate. ";
    businesscCommunication_testbank[6].options[3] = "a superior to a superior. ";
    businesscCommunication_testbank[6].options[4] = "a superior to a subordinate.  ";
    businesscCommunication_testbank[6].correctAnswer = 'D';
    //
    businesscCommunication_testbank[7].question = "Face - to - face communication is a __.";
    businesscCommunication_testbank[7].options[1] = "visual communication. ";
    businesscCommunication_testbank[7].options[2] = "direct conversation. ";
    businesscCommunication_testbank[7].options[3] = "oral communication. ";
    businesscCommunication_testbank[7].options[4] = " written. ";
    businesscCommunication_testbank[7].correctAnswer = 'B';
    //
    businesscCommunication_testbank[8].question = "__ is the process of exchanging messages between a seller and a customer. ";
    businesscCommunication_testbank[8].options[1] = "Organisational communication. ";
    businesscCommunication_testbank[8].options[2] = "Business Communication. ";
    businesscCommunication_testbank[8].options[3] = "Managerial communication. ";
    businesscCommunication_testbank[8].options[4] = "Professional communication. ";
    businesscCommunication_testbank[8].correctAnswer = 'B';
    //
    businesscCommunication_testbank[9].question = "__ is talking to oneself in one's own mind such as soliloquies, asides in dramatic work etc. ";
    businesscCommunication_testbank[9].options[1] = "Dialogue. ";
    businesscCommunication_testbank[9].options[2] = "Interpersonal communication. ";
    businesscCommunication_testbank[9].options[3] = "Intrapersonal communication. ";
    businesscCommunication_testbank[9].options[4] = "Unilateral communication.  ";
    businesscCommunication_testbank[9].correctAnswer = 'C';
    //
    businesscCommunication_testbank[10].question = "Communication between HR manager and salesman is an example of __. ";
    businesscCommunication_testbank[10].options[1] = "Horizontal communication. ";
    businesscCommunication_testbank[10].options[2] = "Lateral communication. ";
    businesscCommunication_testbank[10].options[3] = "Diagonal communication. ";
    businesscCommunication_testbank[10].options[4] = "Vertical communication. ";
    businesscCommunication_testbank[10].correctAnswer = 'C';
    //
    /////////////////////////////////////////////////////////////////
    english_testbank[1].question = " Identify the adverb in the following sentence: 'She sings beautifully.'";
    english_testbank[1].options[1] = "She ";
    english_testbank[1].options[2] = "sings ";
    english_testbank[1].options[3] = "beautifully ";
    english_testbank[1].options[4] = "sings beautifully ";
    english_testbank[1].correctAnswer = 'C';
    //
    english_testbank[2].question = "Choose the correct form of the verb to complete the sentence: 'She _ her keys yesterday.'";
    english_testbank[2].options[1] = "lose ";
    english_testbank[2].options[2] = "loses ";
    english_testbank[2].options[3] = "loosed ";
    english_testbank[2].options[4] = "lost ";
    english_testbank[2].correctAnswer = 'D';
    //
    english_testbank[3].question = "Choose the correct form of the comparative adjective to complete the sentence: 'This book is _ than that one.'";
    english_testbank[3].options[1] = "more interesting ";
    english_testbank[3].options[2] = "interestinger ";
    english_testbank[3].options[3] = "interestinger than ";
    english_testbank[3].options[4] = "interestingest";
    english_testbank[3].correctAnswer = 'A';
    //
    english_testbank[4].question = " Identify the preposition in the following sentence: 'The cat jumped over the fence.'";
    english_testbank[4].options[1] = "cat ";
    english_testbank[4].options[2] = "jumped ";
    english_testbank[4].options[3] = "over ";
    english_testbank[4].options[4] = "fence ";
    english_testbank[4].correctAnswer = 'C';
    //
    english_testbank[5].question = "Identify the subject in the following sentence: 'The cat chased the mouse.'";
    english_testbank[5].options[1] = "cat ";
    english_testbank[5].options[2] = "chased ";
    english_testbank[5].options[3] = "mouse ";
    english_testbank[5].options[4] = "the ";
    english_testbank[5].correctAnswer = 'A';
    //
    english_testbank[6].question = "Choose the correct form of the verb to complete the sentence: 'I _ to the store yesterday.' ";
    english_testbank[6].options[1] = "go ";
    english_testbank[6].options[2] = "goes ";
    english_testbank[6].options[3] = "went ";
    english_testbank[6].options[4] = "going ";
    english_testbank[6].correctAnswer = 'C';
    //
    english_testbank[7].question = "What type of pronoun is used in the sentence: 'He gave her the book.'";
    english_testbank[7].options[1] = "personal pronoun. ";
    english_testbank[7].options[2] = "demonstrative pronoun. ";
    english_testbank[7].options[3] = "possessive pronoun. ";
    english_testbank[7].options[4] = "indefinite pronoun. ";
    english_testbank[7].correctAnswer = 'A';
    //
    english_testbank[8].question = "Choose the correct form of the adjective to complete the sentence: 'She is the _ girl in the class.'";
    english_testbank[8].options[1] = "tall ";
    english_testbank[8].options[2] = "taller ";
    english_testbank[8].options[3] = "tallest ";
    english_testbank[8].options[4] = "talliest ";
    english_testbank[8].correctAnswer = 'C';
    //
    english_testbank[9].question = " Choose the correct form of the verb to complete the sentence: 'They _ been waiting for hours.'";
    english_testbank[9].options[1] = "has ";
    english_testbank[9].options[2] = "have ";
    english_testbank[9].options[3] = "had ";
    english_testbank[9].options[4] = "has been ";
    english_testbank[9].correctAnswer = 'B';
    //
    english_testbank[10].question = " Identify the conjunction in the following sentence: 'I wanted to go to the party, but I had too much homework.'";
    english_testbank[10].options[1] = "wanted ";
    english_testbank[10].options[2] = "to ";
    english_testbank[10].options[3] = "but ";
    english_testbank[10].options[4] = "had ";
    english_testbank[10].correctAnswer = 'C';
    //
    /////////////////////////////////////////////////////////////////
    german_testbank[1].question = "Welcher Artikel geh rt zu dem Wort 'Schule' ? ";
    german_testbank[1].options[1] = "der ";
    german_testbank[1].options[2] = "das ";
    german_testbank[1].options[3] = "die ";
    german_testbank[1].options[4] = "dem ";
    german_testbank[1].correctAnswer = 'C';
    //
    german_testbank[2].question = " Was ist das Verb in diesem Satz? 'Der Hund bellt laut.'";
    german_testbank[2].options[1] = "Der ";
    german_testbank[2].options[2] = "bellt ";
    german_testbank[2].options[3] = "laut ";
    german_testbank[2].options[4] = "Hund ";
    german_testbank[2].correctAnswer = 'B';
    //
    german_testbank[3].question = "Welches Pronomen passt am besten? '__ trinkt gerne Tee.'";
    german_testbank[3].options[1] = "Er ";
    german_testbank[3].options[2] = "Ich ";
    german_testbank[3].options[3] = "Ihr ";
    german_testbank[3].options[4] = "Wir ";
    german_testbank[3].correctAnswer = 'A';
    //
    german_testbank[4].question = "Welcher Satz ist korrekt?";
    german_testbank[4].options[1] = " Wir ist m de. ";
    german_testbank[4].options[2] = "Du spielen Fu ball. ";
    german_testbank[4].options[3] = " Ich esse eine Pizza. ";
    german_testbank[4].options[4] = "Sie fahren Auto. ";
    german_testbank[4].correctAnswer = 'C';
    //
    german_testbank[5].question = " Welches Wort ist ein Verb?";
    german_testbank[5].options[1] = "Blau ";
    german_testbank[5].options[2] = "Laufen ";
    german_testbank[5].options[3] = "Tisch ";
    german_testbank[5].options[4] = "Auto ";
    german_testbank[5].correctAnswer = 'B';
    //
    german_testbank[6].question = "Was ist das Verb in diesem Satz?";
    german_testbank[6].options[1] = "das ";
    german_testbank[6].options[2] = "ist ";
    german_testbank[6].options[3] = "das Verb ";
    german_testbank[6].options[4] = "in ";
    german_testbank[6].correctAnswer = 'B';
    //
    german_testbank[7].question = "Welches Pronomen passt am besten? '__ bin ein Student.' ";
    german_testbank[7].options[1] = "Ich ";
    german_testbank[7].options[2] = "Du ";
    german_testbank[7].options[3] = "Wir ";
    german_testbank[7].options[4] = "Ihr ";
    german_testbank[7].correctAnswer = 'A';
    //
    german_testbank[8].question = "Was ist das Pluralform von 'Stuhl' ?";
    german_testbank[8].options[1] = "Stuhlen ";
    german_testbank[8].options[2] = "Stuhls ";
    german_testbank[8].options[3] = "St hle ";
    german_testbank[8].options[4] = "Stuhles ";
    german_testbank[8].correctAnswer = 'C';
    //
    german_testbank[9].question = " Welche Pr position passt am besten? 'Das Buch liegt __ Tisch.'";
    german_testbank[9].options[1] = "auf ";
    german_testbank[9].options[2] = "hinter ";
    german_testbank[9].options[3] = "neben ";
    german_testbank[9].options[4] = "in ";
    german_testbank[9].correctAnswer = 'A';
    //
    german_testbank[10].question = "Welches Wort ist ein Nomen?";
    german_testbank[10].options[1] = "Sch n ";
    german_testbank[10].options[2] = "Gehen ";
    german_testbank[10].options[3] = "Auto ";
    german_testbank[10].options[4] = "Schnell ";
    german_testbank[10].correctAnswer = 'C';
    //

    /////////////////////////////////////////////////////////////////
    ethics_testbank[1].question = "What is considered a conflict of interest in a business setting?";
    ethics_testbank[1].options[1] = "Advocating for personal gain over company interests.";
    ethics_testbank[1].options[2] = " Prioritizing customer needs over company policies.";
    ethics_testbank[1].options[3] = " Accepting gifts from clients to build rapport.";
    ethics_testbank[1].options[4] = " Collaborating with competitors to improve industry standards.";
    ethics_testbank[1].correctAnswer = 'A';
    //
    ethics_testbank[2].question = "What should be the primary consideration when making business decisions?";
    ethics_testbank[2].options[1] = "Maximizing profits at all costs. ";
    ethics_testbank[2].options[2] = "Balancing the needs of stakeholders. ";
    ethics_testbank[2].options[3] = "Prioritizing personal interests. ";
    ethics_testbank[2].options[4] = "Following industry trends blindly. ";
    ethics_testbank[2].correctAnswer = 'B';
    //
    ethics_testbank[3].question = "Under what circumstances is it acceptable to engage in deceptive marketing practices?";
    ethics_testbank[3].options[1] = "To gain a competitive advantage over rivals. ";
    ethics_testbank[3].options[2] = "To increase customer satisfaction. ";
    ethics_testbank[3].options[3] = "To manipulate consumer perceptions for short-term gain. ";
    ethics_testbank[3].options[4] = " To promote transparency and honesty. ";
    ethics_testbank[3].correctAnswer = 'D';
    //
    ethics_testbank[4].question = "What is the importance of fair competition in business?";
    ethics_testbank[4].options[1] = "To eliminate competitors through aggressive tactics. ";
    ethics_testbank[4].options[2] = "To maintain a monopoly in the market. ";
    ethics_testbank[4].options[3] = "To foster innovation and improve product quality. ";
    ethics_testbank[4].options[4] = " To manipulate prices for personal profit. ";
    ethics_testbank[4].correctAnswer = 'C';
    //
    ethics_testbank[5].question = " What is the role of transparency in business ethics?";
    ethics_testbank[5].options[1] = "To conceal information from stakeholders. ";
    ethics_testbank[5].options[2] = "To promote honesty and openness in business practices. ";
    ethics_testbank[5].options[3] = "To manipulate market perceptions for personal gain. ";
    ethics_testbank[5].options[4] = "To limit communication with employees. ";
    ethics_testbank[5].correctAnswer = 'B';
    //
    ethics_testbank[6].question = "What is the responsibility of businesses towards human rights?";
    ethics_testbank[6].options[1] = "To exploit labor for cheap production costs. ";
    ethics_testbank[6].options[2] = "To ensure fair labor practices and respect human dignity. ";
    ethics_testbank[6].options[3] = "To ignore labor rights in pursuit of profit. ";
    ethics_testbank[6].options[4] = "To discriminate based on race, gender, or religion. ";
    ethics_testbank[6].correctAnswer = 'B';
    //
    ethics_testbank[7].question = "What is the significance of diversity and inclusion in the workplace?";
    ethics_testbank[7].options[1] = "It fosters a homogeneous work environment. ";
    ethics_testbank[7].options[2] = "It limits creativity and innovation. ";
    ethics_testbank[7].options[3] = "It promotes a culture of respect and acceptance. ";
    ethics_testbank[7].options[4] = " It encourages discrimination and bias. ";
    ethics_testbank[7].correctAnswer = 'C';
    //
    ethics_testbank[8].question = " What is the purpose of a code of conduct in a business organization?";
    ethics_testbank[8].options[1] = "To limit employee freedom and creativity. ";
    ethics_testbank[8].options[2] = "To establish guidelines for ethical behavior. ";
    ethics_testbank[8].options[3] = "To encourage competition among colleagues. ";
    ethics_testbank[8].options[4] = " To promote a culture of secrecy and confidentiality. ";
    ethics_testbank[8].correctAnswer = 'B';
    //
    ethics_testbank[9].question = "How should employees handle situations where they witness unethical behavior within the company?";
    ethics_testbank[9].options[1] = "By confronting the individual directly and publicly. ";
    ethics_testbank[9].options[2] = "By ignoring the behavior to avoid conflict. ";
    ethics_testbank[9].options[3] = "By reporting the behavior through appropriate channels. ";
    ethics_testbank[9].options[4] = "By joining in to avoid being seen as an outsider. ";
    ethics_testbank[9].correctAnswer = 'C';
    //
    ethics_testbank[10].question = "What issibility of businesses towards environmental sustainability?";
    ethics_testbank[10].options[1] = "To prioritize profit over ecological concerns. ";
    ethics_testbank[10].options[2] = "To minimize environmental impact and promote sustainability. ";
    ethics_testbank[10].options[3] = "To ignore environmental regulations for financial gain. ";
    ethics_testbank[10].options[4] = "To delegate environmental responsibility to government agencies. ";
    ethics_testbank[10].correctAnswer = 'B';
    int chosenQuestion;
    //  int questionAnswer;
    string isNextQuestion;
    int currentQuestionIndex = 1;
    int questionsCounter = 0;

    cout << "                   ------------------------------------------------------------------------------                          " << endl;
    switch (teachers[index_teacher].coursecode_teacher)
    {
    case 1907:
        cout << "\033[1;36mChoose from these questions:\033[0m" << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << i << ".";
            cout << SP_testbank[i].question << endl;
        }
        cout << "        " << endl;
        while (currentQuestionIndex == 1 || isNextQuestion == "Yes" || isNextQuestion == "yes" || isNextQuestion == "y" || isNextQuestion == "Y")
        {
            cout << "Enter the number of question that you want to display (1->10): ";
            questionsCounter++;
            currentQuestionIndex++;
            while (!(cin >> chosenQuestion) || chosenQuestion < 1 || chosenQuestion > 10)
            {
                cout << "\033[1;31m Invalid!! , Please enter a number between 1 and 10.\033[0m" << endl;
                cin.clear();
                cin.ignore(123, '\n');
                isNextQuestion = "Yes";
            }
            questions_correct_answer.push_back({ SP_testbank[chosenQuestion].question, SP_testbank[chosenQuestion].correctAnswer }); // 0 based
            for (int i = 1; i <= 4; i++)
            {
                answers.push_back(SP_testbank[chosenQuestion].options[i]); // 0 based
            }
            if (number_of_question <= questionsCounter)
                break;
            while (true)
            {
                cout << "Do you want to choose another question? (Yes/No): ";
                cin >> isNextQuestion;
                if (isNextQuestion[0] == 'Y' || isNextQuestion[0] == 'y' || isNextQuestion == "Yes" || isNextQuestion == "yes" ||
                    isNextQuestion[0] == 'n' || isNextQuestion[0] == 'N' || isNextQuestion == "No" || isNextQuestion == "no") break;
                else
                {
                    cout << "\033[1;31m Inavlid !!, please try agian\n \033[0m";
                    continue;
                }
            }
        }
        cout << "          --------------------------------------------------------------------------------------           " << endl;

        break;
    case 1911:
        cout << "\033[1;36mChoose from these questions:\033[0m" << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << i << ".";
            cout << businesscCommunication_testbank[i].question << endl;
        }
        cout << "        " << endl;
        while (currentQuestionIndex == 1 || isNextQuestion == "Yes" || isNextQuestion == "yes" || isNextQuestion == "y" || isNextQuestion == "Y")
        {

            cout << "Enter the number of question that you want to display (1->10): ";
            questionsCounter++; // to change from answers of ques(n) to ques(n+1)
            currentQuestionIndex++;
            while (!(cin >> chosenQuestion) || chosenQuestion < 1 || chosenQuestion > 10)
            {
                cout << "\033[1;31m Invalid!! , Please enter a number between 1 and 10.\033[0m" << endl;
                cin.clear();
                cin.ignore(123, '\n');
                isNextQuestion = "Yes";

            }
            questions_correct_answer.push_back({ businesscCommunication_testbank[chosenQuestion].question, businesscCommunication_testbank[chosenQuestion].correctAnswer }); // 0 based
            for (int i = 1; i <= 4; i++)
            {
                answers.push_back(businesscCommunication_testbank[chosenQuestion].options[i]); // 0 based
            }
            if (number_of_question <= questionsCounter)
                break; // - 1 because it have initial val = 1

            while (true)
            {
                cout << "Do you want to choose another question? (Yes/No): ";
                cin >> isNextQuestion;
                if (isNextQuestion[0] == 'Y' || isNextQuestion[0] == 'y' || isNextQuestion == "Yes" || isNextQuestion == "yes" ||
                    isNextQuestion[0] == 'n' || isNextQuestion[0] == 'N' || isNextQuestion == "No" || isNextQuestion == "no") break;
                else
                {
                    cout << "\033[1;31m Inavlid !!, please try agian\n \033[0m";
                    continue;
                }
            }


        }
        cout << "          --------------------------------------------------------------------------------------           " << endl;

        break;
    case 1902:
        cout << "\033[1;36mChoose from these questions:\033[0m" << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << i << ".";
            cout << english_testbank[i].question << endl;
        }
        cout << "        " << endl;
        while (currentQuestionIndex == 1 || isNextQuestion == "Yes" || isNextQuestion == "yes" || isNextQuestion == "y" || isNextQuestion == "Y")
        {
            cout << "Enter the number of question that you want to display (1->10): ";
            questionsCounter++; // to change from answers of ques(n) to ques(n+1)
            currentQuestionIndex++;
            while (!(cin >> chosenQuestion) || chosenQuestion < 1 || chosenQuestion > 10)
            {
                cout << "\033[1;31m Invalid!! , Please enter a number between 1 and 10.\033[0m" << endl;
                cin.clear();
                cin.ignore(123, '\n');
                isNextQuestion = "Yes";
            }
            questions_correct_answer.push_back({ english_testbank[chosenQuestion].question, english_testbank[chosenQuestion].correctAnswer }); // 0 baseed
            for (int i = 1; i <= 4; i++)
            {
                answers.push_back(english_testbank[chosenQuestion].options[i]); // 0 based
            }
            if (number_of_question <= questionsCounter)
                break;

            while (true)
            {
                cout << "Do you want to choose another question? (Yes/No): ";
                cin >> isNextQuestion;
                if (isNextQuestion[0] == 'Y' || isNextQuestion[0] == 'y' || isNextQuestion == "Yes" || isNextQuestion == "yes" ||
                    isNextQuestion[0] == 'n' || isNextQuestion[0] == 'N' || isNextQuestion == "No" || isNextQuestion == "no") break;
                else
                {
                    cout << "\033[1;31m Inavlid !!, please try agian\n \033[0m";
                    continue;
                }
            }


        }
        cout << "          --------------------------------------------------------------------------------------           " << endl;

        break;
    case 1955:
        cout << "\033[1;36mChoose from these questions:\033[0m" << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << i << ".";
            cout << german_testbank[i].question << endl;
        }
        cout << "        " << endl;
        while (currentQuestionIndex == 1 || isNextQuestion == "Yes" || isNextQuestion == "yes" || isNextQuestion == "y" || isNextQuestion == "Y")
        {
            cout << "Enter the number of question that you want to display (1->10): ";
            questionsCounter++; // to change from answers of ques(n) to ques(n+1)
            currentQuestionIndex++;
            while (!(cin >> chosenQuestion) || chosenQuestion < 1 || chosenQuestion > 10)
            {
                cout << "\033[1;31m Invalid!! , Please enter a number between 1 and 10.\033[0m" << endl;
                cin.clear();
                cin.ignore(123, '\n');
                isNextQuestion = "Yes";
            }
            questions_correct_answer.push_back({ german_testbank[chosenQuestion].question, german_testbank[chosenQuestion].correctAnswer }); // 0 baseed
            for (int i = 1; i <= 4; i++)
            {
                answers.push_back(german_testbank[chosenQuestion].options[i]); // 0 based
            }
            if (number_of_question <= questionsCounter)
                break;

            while (true)
            {
                cout << "Do you want to choose another question? (Yes/No): ";
                cin >> isNextQuestion;
                if (isNextQuestion[0] == 'Y' || isNextQuestion[0] == 'y' || isNextQuestion == "Yes" || isNextQuestion == "yes" ||
                    isNextQuestion[0] == 'n' || isNextQuestion[0] == 'N' || isNextQuestion == "No" || isNextQuestion == "no") break;
                else
                {
                    cout << "\033[1;31m Inavlid !!, please try agian\n \033[0m";
                    continue;
                }
            }

        }
        cout << "          --------------------------------------------------------------------------------------           " << endl;

        break;
    case 1914:
        cout << "\033[1;36mChoose from these questions:\033[0m" << endl;
        for (int i = 1; i <= 10; i++)
        {
            cout << i << ".";
            cout << ethics_testbank[i].question << endl;
        }
        cout << "        " << endl;
        while (currentQuestionIndex == 1 || isNextQuestion == "Yes" || isNextQuestion == "yes" || isNextQuestion == "y" || isNextQuestion == "Y")
        {

            cout << "Enter the number of question that you want to display (1->10): ";
            questionsCounter++; // to change from answers of ques(n) to ques(n+1)
            currentQuestionIndex++;
            while (!(cin >> chosenQuestion) || chosenQuestion < 1 || chosenQuestion > 10)
            {
                cout << "\033[1;31m Invalid!! , Please enter a number between 1 and 10.\033[0m" << endl;
                cin.clear();
                cin.ignore(123, '\n');
                isNextQuestion = "Yes";
            }
            questions_correct_answer.push_back({ ethics_testbank[chosenQuestion].question, ethics_testbank[chosenQuestion].correctAnswer }); // 0 baseed
            for (int i = 1; i <= 4; i++)
            {
                answers.push_back(ethics_testbank[chosenQuestion].options[i]); // 0 based
            }
            if (number_of_question <= questionsCounter)
                break;

            while (true)
            {
                cout << "Do you want to choose another question? (Yes/No): ";
                cin >> isNextQuestion;
                if (isNextQuestion[0] == 'Y' || isNextQuestion[0] == 'y' || isNextQuestion == "Yes" || isNextQuestion == "yes" ||
                    isNextQuestion[0] == 'n' || isNextQuestion[0] == 'N' || isNextQuestion == "No" || isNextQuestion == "no") break;
                else
                {
                    cout << "\033[1;31m Inavlid !!, please try agian\n \033[0m";
                    continue;
                }
            }

        }
        cout << "          --------------------------------------------------------------------------------------           " << endl;

        break;
    default:
        cout << "\033[1;31m Number is not found , Please try again. \033[0m" << endl;
    }
}
void view_exam(vector<pair<string, char>>& questions_correct_answer, vector<string>& answers)
{
    for (int i = 0; i < questions_correct_answer.size(); i++)
    {
        cout << endl;
        cout << i + 1 << "- " << questions_correct_answer[i].first << endl
            << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << char(j + 65) << "- " << answers[j + (i * 4)] << endl;
        }
        cout << "\033[1;32m The correct answer is number : \033[0m" << questions_correct_answer[i].second << endl;
    }
    cout << endl;
}
void add_question(vector<pair<string, char>>& questions_correct_answer, vector<string>& answers)
{
    string question, choices;
    string char_of_correct_answer;
    cout << "\033[1;36m Please enter the question that you want to add: \033[0m" << endl;
    cin.ignore();
    getline(cin, question);
    questions_correct_answer.push_back({ question, 0 });
    cout << "\033[1;36m Please enter 4 choices: \033[0m\n"
        << endl;
    for (char i = 'A'; i <= 'D'; i++)
    {
        cout << "\033[1;36m Enter choice \033[0m" << i << " : ";
        cin.ignore();
        getline(cin, choices);
        answers.push_back(choices);
    }
    while (true)
    {
        cout << "\033[1;36m Please enter the letter of correct choice : \033[0m";
        cin >> char_of_correct_answer;
        if (char_of_correct_answer[0] == 'a' || char_of_correct_answer[0] == 'b' || char_of_correct_answer[0] == 'c' || char_of_correct_answer[0] == 'd')
        {
            char_of_correct_answer[0] -= 32;
        }
        if (char_of_correct_answer[0] == 'A' || char_of_correct_answer[0] == 'B' || char_of_correct_answer[0] == 'C' || char_of_correct_answer[0] == 'D')
        {
            break;
        }
        else
        {
            cout << "\033[1;36m Please make sure that your answer is A,B,C or D\n \033[0m";
            continue;
        }
    }
    questions_correct_answer[questions_correct_answer.size() - 1].second = char_of_correct_answer[0];
}
void delete_question(vector<pair<string, char>>& questions_correct_answer, vector<string>& answers, int remove)
{
    int choice;
    while (remove--)
    {
        view_exam(questions_correct_answer, answers);
        cout << "\033[1;36m Choose only one question:\n \033[0m";
        while (!(cin >> choice) || choice > questions_correct_answer.size() || choice < 1)
        {
            cout << "\033[1;31m Invalid question!! (enter a number within the specified range), please try agian\n \033[0m";
            cin.clear();
            cin.ignore(123, '\n');
        }
        questions_correct_answer.erase(questions_correct_answer.begin() + choice - 1);
        for (int i = 0; i < 4; i++)
        {
            int start = (choice - 1) * 4;           // 1 2 3 4      if we erase 3 ==>  1 2 4      4 will be shift
            answers.erase(answers.begin() + start); // (3 - 1) * 4 = 8     8 + 1 = 9   9 the first choice in quest 3
        }
    }
}
void create_exam(vector<pair<string, char>>& questions_correct_answer, vector<string>& answers, int& time)
{
    int number_of_question;
    cout << "\033[1;36m How many questions do you want to appear on your exam ? \033[0m" << endl;
    while (!(cin >> number_of_question) || number_of_question < 1 || number_of_question > 100)
    {
        cout << "\033[1;31m Invalid!!, Please try again with range between (1 - 100)\n \033[0m";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cout << "\033[1;36m What is the time of the exam (in minutes) ? \033[0m" << endl;
    while (!(cin >> time) || time < 1 || time > 1000)
    {
        cout << "\033[1;31m Invalid!!, Please try again\n \033[0m";
        cin.clear();
        cin.ignore(123, '\n');
    }
    time_view = time;

    while (true)
    {
        string choice;
        cout //<< "Choose one number : " << endl
            << endl
            << "\033[1;30m Press 1 to enter a question. \033[0m" << endl
            << "\033[1;30m Press 2 to choose from test bank. \033[0m" << endl;
        cin >> choice;
        if (choice == "1")
        {
            add_question(questions_correct_answer, answers);
            //number_of_question--;
        }
        else if (choice == "2")
        { // 5
            displayQuestions(entering, questions_correct_answer, answers, number_of_question - questions_correct_answer.size());
            // number_of_question -= questions_correct_answer.size() - 1;    // - * - = +         // when you add quest from 5 you choosed then you can add 4 from test
        }
        else
        {
            cout << "\033[1;31m Invalid!! , Please try again\n \033[0m";
            continue;
        }
        if (number_of_question == questions_correct_answer.size())
        {
            break;
        }
    }
}
void edit(vector<pair<string, char>>& questions_correct_answer, vector<string>& answers, int& time)
{
    while (true)
    {
        string accept;
        int the_number_of_question_add;
        string choice;
        cout << endl
            << "\033[1;30m Press 1 to change the time of the exam.\n \033[0m"
            << "\033[1;30m Press 2 to change question with another one.\n \033[0m"
            << "\033[1;30m Press 3 to add a new questions.\n \033[0m"
            << "\033[1;30m Press 4 to remove questions.\n \033[0m"
            << "\033[1;30m Press 5 to change answer of a question.\n \033[0m"
            << "\033[1;30m Press 6 to view the exam.\n \033[0m"
            << "\033[1;30m Press 7 to save the exam.\n \033[0m";

        cin >> choice;
        if (choice == "1")
        {
            cout << "\033[1;36m Enter the new time:\n \033[0m";
            while (!(cin >> time) || time < 1 || time > 1000)
            {
                cout << "\033[1;31m Invalid!!, Please try again\n \033[0m";
                cin.clear();
                cin.ignore(123, '\n');
            }
        }
        else if (choice == "2")
        {
            while (true)
            {
                view_exam(questions_correct_answer, answers);
                int choice;
                cout << "\033[1;34m Choose the question that you want to change:\n \033[0m";
                while (!(cin >> choice) || choice < 1 || choice > questions_correct_answer.size())
                {
                    cout << "\033[1;31m Invalid!!, please try again\n \033[0m";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                questions_correct_answer.erase(questions_correct_answer.begin() + choice - 1);
                for (int i = 0; i < 4; i++)
                {
                    int start = (choice - 1) * 4;           // 1 2 3 4      if we erase 3 ==>  1 2 4      4 will be shift
                    answers.erase(answers.begin() + start); // (3 - 1) * 4 = 8     8 + 1 = 9   9 the first choice in quest 3
                }
                string choice_of_way;
                cout << endl
                    << "\033[1;30m Press 1 to enter question. \033[0m" << endl
                    << "\033[1;30m Press 2 to choose from test bank. \033[0m" << endl;
                cin >> choice_of_way;
                if (choice_of_way == "1")
                {
                    add_question(questions_correct_answer, answers);
                }
                else if (choice_of_way == "2")
                {
                    displayQuestions(entering, questions_correct_answer, answers, 1);
                }
                else
                {
                    cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
                    continue;
                }
                break;
            }
        }
        else if (choice == "3")
        {
            int old_size = questions_correct_answer.size();
            cout << "\033[1;34m Enter number of questions that you want to add: \033[0m";
            while (!(cin >> the_number_of_question_add) || the_number_of_question_add <= 0)
            {
                if (the_number_of_question_add + old_size > 100)
                {
                    cout << "\033[1;31m You can't add more than one hundred questions\n \033[0m";
                }
                cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
                cin.clear();
                cin.ignore(123, '\n');
            }
            while (true)
            {
                string choice;
                cout << endl
                    << "\033[1;30m Press 1 to enter question. \033[0m" << endl
                    << "\033[1;30m Press 2 to choose from test bank. \033[0m" << endl;
                cin >> choice;
                if (choice == "1")
                {
                    add_question(questions_correct_answer, answers);
                }
                else if (choice == "2")
                {
                    displayQuestions(entering, questions_correct_answer, answers, the_number_of_question_add);
                    // the_new_num_of_question -= questions_correct_answer.size() - 1;    // - * - = +       
                }
                else
                {
                    cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
                    continue;
                }
                if (the_number_of_question_add + old_size == questions_correct_answer.size())
                {
                    break;
                }
            }

        }
        else if (choice == "4")
        {
            int num_of_quest_will_be_del;
            cout << "\033[1;34m Please enter number of the questions that you want to delete:\n \033[0m";
            while (!(cin >> num_of_quest_will_be_del) || num_of_quest_will_be_del <= 0 || num_of_quest_will_be_del > questions_correct_answer.size())
            {
                cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
                cin.clear();
                cin.ignore(123, '\n');
            }
            delete_question(questions_correct_answer, answers, num_of_quest_will_be_del);
        }
        else if (choice == "5")
        {
            int question, number_of_answers_change;
            view_exam(questions_correct_answer, answers);
            cout << "\033[1;34m \nEnter the number of the question that you want to change their answers:\n \033[0m";
            while (!(cin >> question) || question > questions_correct_answer.size() || question < 1)
            {
                cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
                cin.clear();
                cin.ignore(123, '\n');
            }
            cout << "\033[1;34m Enter number of answers that you want to change (1 - 4):\n \033[0m";
            while (!(cin >> number_of_answers_change) || number_of_answers_change > 4 || number_of_answers_change < 1)
            {
                cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
                cin.clear();
                cin.ignore(123, '\n');
            }
            while (number_of_answers_change--)
            {
                string new_answer;
                cout << "\033[1;34m Enter the letter of choice:\n \033[0m";
                string choice;
                cin >> choice;
                if (choice == "A" || choice == "a" || choice == "B" || choice == "b" || choice == "C" || choice == "c" || choice == "D" || choice == "d")
                {
                    if (choice == "a" || choice == "b" || choice == "c" || choice == "d") choice[0] -= 32;
                    if (choice[0] == questions_correct_answer[question - 1].second) // 0 based
                    {
                        cout << "\033[1;35m Make sure, that is the correct answer!\n \033[0m";
                    }
                    cout << "\033[1;34m Enter the new answer:\n \033[0m";
                    cin.ignore();
                    getline(cin, new_answer);
                    choice[0] -= 'A';
                    answers[(question - 1) * 4 + int(choice[0])] = new_answer;
                }
                else
                {
                    cout << "\033[1;35m Your letter should be A,B,C or D\n \033[0m";
                    number_of_answers_change++;
                    continue;
                }
            }
        }
        else if (choice == "6")
        {
            view_exam(questions_correct_answer, answers);
        }
        else if (choice == "7")
        {
            cout << "\033[1;35m You will submit the exam , Do you want to continue ? (y/n) \033[0m";
            cin >> accept;
            if (accept == "Y" || accept == "y")
            {
                if (questions_correct_answer.size() == 0)
                {
                    cout << "\033[1;31m You can't save empty exam please add questions\n \033[0m";
                    continue;
                }
                break;
            }
            else if (accept == "N" || accept == "n")
            {
                continue;
            }
            else
            {
                cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
                continue;
            }
        }
        else
        {
            cout << "\033[1;31m Invalid!! ,Please try again.\n \033[0m";
            continue;
        }
    }
}
void ShowStudentGrades()
{
    bool studentEntered = false;
    cout << "\033[1;33m Username \033[0m" << "\t\t" << "\033[1;33m Percentage \033[0m" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (!students[i].username_student.empty())
        {
            studentEntered = true;
            cout << students[i].username_student << "\t\t\t" << students[i].studentGrade << "%" << endl;
        }
    }

    if (!studentEntered)
    {
        cout << "\033[1;31m Their isn't any student entered yet. \033[0m" << endl;
    }
}
void teacher()
{
    vector<pair<string, char>> questions_correct_answer; // char
    vector<string> answers;
    string option; // choice
    int time;
    while (true)
    {
        cout << endl
            << "Press 1 to create a new exam." << endl
            << "Press 2 to edit a previous exam." << endl
            << "Press 3 to show student's grades. " << endl
            << "Press 4 to submit the exam." << endl;

        cin >> option;
        cin.ignore();
        valid("4", option);
        if (option == "1")
        {
            if (questions_correct_answer.size() > 0)
            {
                cout << "\033[1;31m  Please, sumbit the exam first\n \033[0m" << endl;
                continue;
            }
            else
            {
                create_exam(questions_correct_answer, answers, time);
            }
        }
        else if (option == "2")
        {

            if (questions_correct_answer.size() > 0)
                edit(questions_correct_answer, answers, time);
            else
                cout << "\033[1;31m  There is no exams to edit.\n \033[0m" << endl;
        }
        else if (option == "3")
            ShowStudentGrades();
        else if (option == "4")
        {
            if (questions_correct_answer.size() == 0)
            {
                cout << "\033[1;31m There is no exam to submit.\n \033[0m";
                continue;
            }
            string accept;
            cout << " You can't edit on the exam after that , Do you want to continue ?(y/n) ";
            cin >> accept;

            if (accept == "Y" || accept == "y")
            {
                cout << "\033[1;32m Your exam has been submitted successfully < 3 \033[0m" << endl;
                if (index_teacher == 0)
                {
                    int counter_current = 0;
                    for (int i = 0; i < questions_correct_answer.size(); i++)
                    {
                        subject[0].exams.ques[i].question = questions_correct_answer[i].first;
                        subject[0].exams.ques[i].correctAnswer = questions_correct_answer[i].second;
                        for (int j = counter_current; j < counter_current + 4; j++)
                        {
                            subject[0].exams.ques[i].options[j % 4] = answers[j];
                        }
                        counter_current += 4;
                    }
                    subject[0].exams.num_of_questions = questions_correct_answer.size();
                }
                else if (index_teacher == 1)
                {
                    int counter_current = 0;
                    for (int i = 0; i < questions_correct_answer.size(); i++)
                    {
                        subject[1].exams.ques[i].question = questions_correct_answer[i].first;
                        subject[1].exams.ques[i].correctAnswer = questions_correct_answer[i].second;
                        for (int j = counter_current; j < counter_current + 4; j++)
                        {
                            subject[1].exams.ques[i].options[j % 4] = answers[j];
                        }
                        counter_current += 4;
                    }
                    subject[1].exams.num_of_questions = questions_correct_answer.size();
                }
                else if (index_teacher == 2)
                {
                    int counter_current = 0;
                    for (int i = 0; i < questions_correct_answer.size(); i++)
                    {
                        subject[2].exams.ques[i].question = questions_correct_answer[i].first;
                        subject[2].exams.ques[i].correctAnswer = questions_correct_answer[i].second;
                        for (int j = counter_current; j < counter_current + 4; j++)
                        {
                            subject[2].exams.ques[i].options[j % 4] = answers[j];
                        }
                        counter_current += 4;
                    }
                    subject[2].exams.num_of_questions = questions_correct_answer.size();
                }
                else if (index_teacher == 3)
                {
                    int counter_current = 0;
                    for (int i = 0; i < questions_correct_answer.size(); i++)
                    {
                        subject[3].exams.ques[i].question = questions_correct_answer[i].first;
                        subject[3].exams.ques[i].correctAnswer = questions_correct_answer[i].second;
                        for (int j = counter_current; j < counter_current + 4; j++)
                        {
                            subject[3].exams.ques[i].options[j % 4] = answers[j];
                        }
                        counter_current += 4;
                    }
                    subject[3].exams.num_of_questions = questions_correct_answer.size();
                }
                else if (index_teacher == 4)
                {
                    int counter_current = 0;
                    for (int i = 0; i < questions_correct_answer.size(); i++)
                    {
                        subject[4].exams.ques[i].question = questions_correct_answer[i].first;
                        subject[4].exams.ques[i].correctAnswer = questions_correct_answer[i].second;
                        for (int j = counter_current; j < counter_current + 4; j++)
                        {
                            subject[4].exams.ques[i].options[j % 4] = answers[j];
                        }
                        counter_current += 4;
                    }
                    subject[4].exams.num_of_questions = questions_correct_answer.size();
                }
                Main_Screen();
                break;
            }
            else if (accept == "n" || accept == "N")
            {
                continue;
            }
            else
            {
                cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
                continue;
            }
        }
    }
}


void displayTimer(int minutes, int seconds)
{

    cout << "\r" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << flush;
}
void countdown(int minutes) {
    int totalSeconds = minutes * 60;
    for (int i = totalSeconds; i >= 0; --i)
    {
        if (z == false)
        {
            i = 0;
            z = true;
            counterAnswers = 0;
            break;
        }
        remainingMin = i / 60;
        remainingSec = i % 60;
        displayTimer(remainingMin, remainingSec);
        this_thread::sleep_for(chrono::seconds(1));
        if (remainingMin == 0 && remainingSec == 0)
        {
            timerRunning = false;

        }

    }
}


int main() {



    subject[0].exams.ques[0].question = "Which of the following is a correct identifier in C++?"; ;
    subject[0].exams.ques[0].correctAnswer = 'A';
    subject[0].exams.ques[0].options[0] = "VAR_1234";
    subject[0].exams.ques[0].options[1] = "$var_name";
    subject[0].exams.ques[0].options[2] = "7VARNAME";
    subject[0].exams.ques[0].options[3] = "7var_name";


    //

    subject[0].exams.ques[1].question = "Which of the following symbol is used to declare the preprocessor directives in C++?";
    subject[0].exams.ques[1].correctAnswer = 'C';
    subject[0].exams.ques[1].options[0] = " $ ";
    subject[0].exams.ques[1].options[1] = " ^ ";
    subject[0].exams.ques[1].options[2] = " # ";
    subject[0].exams.ques[1].options[3] = " * ";

    //
    subject[0].exams.ques[2].question = "Which of the following approach is used by C++?";
    subject[0].exams.ques[2].correctAnswer = 'C';
    subject[0].exams.ques[2].options[0] = "Left - right";
    subject[0].exams.ques[2].options[1] = "Right-left";
    subject[0].exams.ques[2].options[2] = "Bottom-up";
    subject[0].exams.ques[2].options[3] = "Top-down";

    // /////////////////////////////////////////
    subject[1].exams.ques[0].question = " Communication is a __.";
    subject[1].exams.ques[0].correctAnswer = 'B';
    subject[1].exams.ques[0].options[0] = "one way process.";
    subject[1].exams.ques[0].options[1] = "two way process. ";
    subject[1].exams.ques[0].options[2] = "three way process. ";
    subject[1].exams.ques[0].options[3] = " four way process. ";
    //
    subject[1].exams.ques[1].question = "Communication is the __ of business.";
    subject[1].exams.ques[1].correctAnswer = 'B';
    subject[1].exams.ques[1].options[0] = "life blood. ";
    subject[1].exams.ques[1].options[1] = "Backbone.  ";
    subject[1].exams.ques[1].options[2] = "nervous system. ";
    subject[1].exams.ques[1].options[3] = "both(1)& (2). ";
    //
    subject[1].exams.ques[2].question = "Face - to - face communication is a __.";
    subject[1].exams.ques[2].correctAnswer = 'B';
    subject[1].exams.ques[2].options[0] = "visual communication. ";
    subject[1].exams.ques[2].options[1] = "direct conversation. ";
    subject[1].exams.ques[2].options[2] = "oral communication. ";
    subject[1].exams.ques[2].options[3] = " written. ";
    //////////////////////////////////////////////////////////


    subject[2].exams.ques[0].question = "Identify the subject in the following sentence: 'The cat chased the mouse.'";
    subject[2].exams.ques[0].correctAnswer = 'A';
    subject[2].exams.ques[0].options[0] = "cat ";
    subject[2].exams.ques[0].options[1] = "chased ";
    subject[2].exams.ques[0].options[2] = "mouse ";
    subject[2].exams.ques[0].options[3] = "the ";

    //
    subject[2].exams.ques[1].question = "What type of pronoun is used in the sentence: 'He gave her the book.'";
    subject[2].exams.ques[1].correctAnswer = 'A';
    subject[2].exams.ques[1].options[0] = "personal pronoun. ";
    subject[2].exams.ques[1].options[1] = "demonstrative pronoun. ";
    subject[2].exams.ques[1].options[2] = "possessive pronoun. ";
    subject[2].exams.ques[1].options[3] = "indefinite pronoun. ";
    //
    subject[2].exams.ques[2].question = " Identify the adverb in the following sentence: 'She sings beautifully.'";
    subject[2].exams.ques[2].correctAnswer = 'C';
    subject[2].exams.ques[2].options[0] = "She ";
    subject[2].exams.ques[2].options[1] = "sings ";
    subject[2].exams.ques[2].options[2] = "beautifully ";
    subject[2].exams.ques[2].options[3] = "sings beautifully ";
    ///////////////////////////////////////////////////////////////////////////////////////

    subject[3].exams.ques[0].question = "Welcher Artikel geh rt zu dem Wort 'Schule' ? ";
    subject[3].exams.ques[0].correctAnswer = 'C';
    subject[3].exams.ques[0].options[0] = "der ";
    subject[3].exams.ques[0].options[1] = "das ";
    subject[3].exams.ques[0].options[2] = "die ";
    subject[3].exams.ques[0].options[3] = "dem ";
    //
    subject[3].exams.ques[1].question = " Was ist das Verb in diesem Satz? 'Der Hund bellt laut.'";
    subject[3].exams.ques[1].correctAnswer = 'B';
    subject[3].exams.ques[1].options[0] = "der ";
    subject[3].exams.ques[1].options[1] = "bellt";
    subject[3].exams.ques[1].options[2] = "laut ";
    subject[3].exams.ques[1].options[3] = "hund";
    //
    subject[3].exams.ques[2].question = "Welcher Satz ist korrekt?";
    subject[3].exams.ques[2].correctAnswer = 'C';
    subject[3].exams.ques[2].options[0] = " Wir ist m de. ";
    subject[3].exams.ques[2].options[1] = "Du spielen Fu ball. ";
    subject[3].exams.ques[2].options[2] = " Ich esse eine Pizza. ";
    subject[3].exams.ques[2].options[3] = "Sie fahren Auto. ";
    /////////////////////////////////////////////////////////////////////////////////////// 
    subject[4].exams.ques[0].question = " What is the role of transparency in business ethics?";
    subject[4].exams.ques[0].correctAnswer = 'B';
    subject[4].exams.ques[0].options[0] = "To conceal information from stakeholders. ";
    subject[4].exams.ques[0].options[1] = "To promote honesty and openness in business practices. ";
    subject[4].exams.ques[0].options[2] = "To manipulate market perceptions for personal gain. ";
    subject[4].exams.ques[0].options[3] = "To limit communication with employees. ";
    //
    subject[4].exams.ques[1].question = "What is the responsibility of businesses towards human rights?";
    subject[4].exams.ques[1].correctAnswer = 'B';
    subject[4].exams.ques[1].options[0] = "To exploit labor for cheap production costs. ";
    subject[4].exams.ques[1].options[1] = "To ensure fair labor practices and respect human dignity. ";
    subject[4].exams.ques[1].options[2] = "To ignore labor rights in pursuit of profit. ";
    subject[4].exams.ques[1].options[3] = "To discriminate based on race, gender, or religion. ";
    //
    subject[4].exams.ques[2].question = "What is considered a conflict of interest in a business setting?";
    subject[4].exams.ques[2].correctAnswer = 'A';
    subject[4].exams.ques[2].options[0] = "Advocating for personal gain over company interests.";
    subject[4].exams.ques[2].options[1] = " Prioritizing customer needs over company policies.";
    subject[4].exams.ques[2].options[2] = " Accepting gifts from clients to build rapport.";
    subject[4].exams.ques[2].options[3] = " Collaborating with competitors to improve industry standards.";


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    teachers[0].coursecode_teacher = 1907;
    teachers[0].username_teacher = "Mohamed Hassan";
    teachers[0].password_teacher = "mohamed1907";

    teachers[1].coursecode_teacher = 1911;
    teachers[1].username_teacher = "Hossam Mansour";
    teachers[1].password_teacher = "hossam1911";

    teachers[2].coursecode_teacher = 1902;
    teachers[2].username_teacher = "Amir Mamdouh";
    teachers[2].password_teacher = "amir1902";

    teachers[3].coursecode_teacher = 1955;
    teachers[3].username_teacher = "Asmaa Fathy";
    teachers[3].password_teacher = "asmaa1955";

    teachers[4].coursecode_teacher = 1914;
    teachers[4].username_teacher = "Marim Alaa";
    teachers[4].password_teacher = "marim1914";

    subject[0].courseCode = 1907;
    subject[1].courseCode = 1911;
    subject[2].courseCode = 1902;
    subject[3].courseCode = 1955;
    subject[4].courseCode = 1914;
    // exam(0, 5);
    Main_Screen();
    return 0;
}


void Main_Screen()
{
    string log_in;
    cout << "\033[1;30m Press 1 to enter as a Teacher. \033[0m" << endl
        << "\033[1;30m Press 2 to enter as a Student. \033[0m" << endl;
    //  cout << "Press 1 if you are a teacher otherwise Press 2" << endl;
    cin >> stuORteach;
    cin.ignore();
    valid("2", stuORteach);
    if (stuORteach == "1")
    {
        //cout << endl;
       // cout << "\t\t\t_Welcome to the place where you impose your authority. Enjoy imposing your character to build an impressive generation_\t\t\t";
        //cout << "                                       ___________________________________________________________________" << endl;
        cout << endl
            << "\033[1;30m Press 1 for Log in. \033[0m" << endl
            << "\033[1;30m Press 2 for Register. \033[0m" << endl
            << "\033[1;30m Press 3 to return to Main Screen. \033[0m" << endl;

        cin >> log_in;
        cin.ignore();
        valid("3", log_in);
        if (log_in == "1")
        {
            cout << endl;
            cout << "\033[1;36m \t\t\t_Welcome to the place where you impose your authority. Enjoy imposing your character to build an impressive generation_\t\t\t \033[0m";
            cout << " \033[1;30m                                   ___________________________________________________________________\033[0m" << endl;

            Log_in();
        }
        else if (log_in == "2")
        {
            cout << "\033[1;36m \t\t\t_Welcome to the place where you impose your authority. Enjoy imposing your character to build an impressive generation_\t\t\t \033[0m";
            cout << "\033[1;30m                                   ___________________________________________________________________\033[0m" << endl;
            Register();
        }
        else if (log_in == "3")
        {
            Main_Screen();
        }
    }
    else if (stuORteach == "2")
    {
        // cout << endl;
         //cout << "\t     _Embark on a journey of knowledge exploration! Welcome to our online exam portal, where every click unlocks the door to your future success_\t\t";
        // cout << "                                      ___________________________________________________________________________________" << endl;
        cout << endl
            << "\033[1;30m Press 1 for Log in. \033[0m" << endl
            << "\033[1;30m Press 2 for Register. \033[0m" << endl
            << "\033[1;30m Press 3 to return to Main Screen. \033[0m" << endl;
        cin >> log_in;
        cin.ignore();
        valid("3", log_in);
        if (log_in == "1")
        {
            Log_in();
        }
        else if (log_in == "2")
        {
            cout << endl;
            cout << "\033[1;36m \t     _Embark on a journey of knowledge exploration! Welcome to our online exam portal, where every click unlocks the door to your future success_\t\t \033[0m";
            cout << "\033[1;30m \t                   ___________________________________________________________________________________\033[0m" << endl;

            Register();
        }
        else if (log_in == "3")
        {
            Main_Screen();
        }
    }
}
void Register()
{
    string username, password;
    cout << "Enter your username:" << endl;
    getline(cin, username);
    cout << "Enter your password:" << endl;
    getline(cin, password);
    bool Teacher, Student;
    do
    {
        Teacher = true;
        Student = true;
        for (int i = 0; i < num_of_teachers; i++)
        {
            if (username == teachers[i].username_teacher)
            {
                cout << "\033[1;31m This username is already existed , Enter another username: \033[0m" << endl;
                Teacher = false;
                getline(cin, username);
            }
        }
        for (int i = 0; i < num_of_students; i++)
        {
            if (username == students[i].username_student)
            {
                cout << "\033[1;31m This username is already existed , Enter another username: \033[0m" << endl;
                Student = false;
                getline(cin, username);
            }
        }
        if (username.size() <= 2 && Teacher && Student)
        {
            cout << "\033[1;31m Username is too short , Your username must contain at least 3 letters or numbers. \033[0m" << endl;
            cout << "Enter another Username:" << endl;
            getline(cin, username);
        }
    } while (Teacher == false || Student == false || username.size() <= 2);
    do
    {
        Teacher = true;
        Student = true;
        for (int i = 0; i < num_of_teachers; i++)
        {
            if (password == teachers[i].password_teacher)
            {
                cout << "\033[1;31m This password is already existed , Enter another password: \033[0m" << endl;
                Teacher = false;
                getline(cin, password);
            }
        }
        for (int i = 0; i < num_of_students; i++)
        {
            if (password == students[i].password_student)
            {
                cout << "\033[1;31m This password is already existed , Enter another password: \033[0m" << endl;
                Student = false;
                getline(cin, password);
            }
        }
        if (password.size() < 5 && Teacher && Student)
        {
            cout << "\033[1;31m Password is too short , Your Password must contain at least 5 letters or numbers.  \033[0m" << endl;
            cout << "Enter another Password:" << endl;
            getline(cin, password);
        }
        else if (password == username && Teacher && Student)
        {
            cout << "\033[1;31m Password is similar to Username, Please change the Password . \033[0m" << endl;
            getline(cin, password);
        }
    } while (Teacher == false || Student == false || password.size() < 5 || password == username);
    if (stuORteach == "2")
    {
        num_of_students++;
        students[num_of_students - 1].student_id = "2024170" + to_string(num_of_students);
        students[num_of_students - 1].username_student = username;
        students[num_of_students - 1].password_student = password;
    }
    else if (stuORteach == "1")
    {
        int coursecode;
        cout << "\033[1;34m Enter the coursecode of your subject: \033[0m" << endl;
        cout << "\033[1;30m 1907 for Structure Programming(SP). \033[0m" << endl;
        cout << "\033[1;30m 1911 for Business Communication. \033[0m " << endl;
        cout << "\033[1;30m 1902 for English.  \033[0m" << endl;
        cout << "\033[1;30m 1955 for German. \033[0m" << endl;
        cout << "\033[1;30m 1914 for Ethics. \033[0m" << endl;
        while (!(cin >> coursecode))
        {
            cout << "\033[1;31m Invalid!!, Please try again. \033[0m" << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }
        while (coursecode != 1907 && coursecode != 1911 && coursecode != 1902 && coursecode != 1955 && coursecode != 1914)
        {
            cout << "\033[1;31m This coursecode doesn't exist , Please Enter again. \033[0m" << endl;
            while (!(cin >> coursecode))
            {
                cout << "\033[1;31m Invalid!!, Please try again. \033[0m" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }
        }
        num_of_teachers++;
        teachers[num_of_teachers - 1].username_teacher = username;
        teachers[num_of_teachers - 1].password_teacher = password;
        teachers[num_of_teachers - 1].coursecode_teacher = coursecode;
    }
    cout << "\033[1;32m Registration Successful <3 \033[0m" << endl;
    Main_Screen();
}
void Log_in()
{
    string username, password, not_exist;
    bool exist_student = false, exist_teacher = false;
    cout << "Enter your username : " << endl;
    getline(cin, username);
    cout << "Enter your password : " << endl;
    getline(cin, password);
    if (stuORteach == "2")
    {
        for (int i = 0; i < num_of_students; i++)
        {
            if (username == students[i].username_student && password == students[i].password_student)
            {
                studentName = username;
                studentPassword = password;
                exist_student = true;
                student();
                break;
            }
        }
        if (!exist_student)
        {
            cout << endl
                << "\033[1;31m Not exist!! \033[0m" << endl
                << "\033[1;30m Press 1 for Register  \033[0m" << endl
                << "\033[1;30m Press 2 to enter again  \033[0m" << endl
                << "\033[1;30m Press 3 to return to Main Screen  \033[0m" << endl;
            cin >> not_exist;
            cin.ignore();
            valid("3", not_exist);
            if (not_exist == "1")
                Register();
            else if (not_exist == "2")
                Log_in();
            else if (not_exist == "3")
                Main_Screen();
        }
    }
    else if (stuORteach == "1")
    {
        for (int i = 0; i < num_of_teachers; i++)
        {
            if (username == teachers[i].username_teacher && password == teachers[i].password_teacher)
            {
                if (teachers[i].coursecode_teacher == 1907)
                {
                    index_teacher = 0;
                }
                else if (teachers[i].coursecode_teacher == 1911)
                {
                    index_teacher = 1;
                }
                else if (teachers[i].coursecode_teacher == 1902)
                {
                    index_teacher = 2;
                }
                else if (teachers[i].coursecode_teacher == 1955)
                {
                    index_teacher = 3;
                }
                else if (teachers[i].coursecode_teacher == 1914)
                {
                    index_teacher = 4;
                }
                exist_teacher = true;
                teacher();
                break;
            }
        }
        if (!exist_teacher)
        {
            cout << endl
                << "\033[1;31m Not exist!! \033[0m" << endl
                << "\033[1;30m Press 1 to enter again.  \033[0m" << endl
                << "\033[1;30m Press 2 to return to Main Screen. \033[0m" << endl;
            cin >> not_exist;
            cin.ignore();
            valid("2", not_exist);
            if (not_exist == "1")
                Log_in();
            else if (not_exist == "2")
                Main_Screen();
        }
    }
}
void valid(string maxvalid, string& input)
{
    if (maxvalid == "1")
    {
        while (input != "1")
        {
            cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
            getline(cin, input);
        }
    }
    else if (maxvalid == "2")
    {
        while (input != "1" && input != "2")
        {
            cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
            getline(cin, input);
        }
    }
    else if (maxvalid == "3")
    {
        while (input != "1" && input != "2" && input != "3")
        {
            cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
            getline(cin, input);
        }
    }
    else if (maxvalid == "4")
    {
        while (input != "1" && input != "2" && input != "3" && input != "4")
        {
            cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
            getline(cin, input);
        }
    }
    else if (maxvalid == "5")
    {
        while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5")
        {
            cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
            getline(cin, input);
        }
    }
    else if (maxvalid == "6")
    {
        while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6")
        {
            cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
            getline(cin, input);
        }
    }
}
void student()
{

    string choose_student;
    cout << endl
        << "\033[1;30m Press 1 to return to Main Screen. \033[0m" << endl
        << "\033[1;30m Press 2 to choose an exam. \033[0m" << endl
        << "\033[1;30m Press 3 to show your profile. \033[0m" << endl
        << "\033[1;30m Press 4 to show your grades. \033[0m" << endl;
    cin >> choose_student;
    cin.ignore();
    valid("4", choose_student);
    if (choose_student == "1")
        Main_Screen();
    else if (choose_student == "2")
        choose_subject();
    else if (choose_student == "3")
    {


        string last_screen;
        for (int i = 0; i < num_of_students; i++)
        {
            if (studentName == students[i].username_student && studentPassword == students[i].password_student)
            {
                cout << "\033[1;36m ID : \033[0m" << students[i].student_id << endl;
                cout << "\033[1;36m Username : \033[0m" << students[i].username_student << endl
                    << endl;
            }
        }

        cout << endl
            << "\033[1;30m Press 1 to return to student screen \033[0m" << endl
            << "\033[1;30m Press 2 to return to Main Screen \033[0m" << endl;
        cin >> last_screen;

        cin.ignore();
        valid("2", last_screen);
        if (last_screen == "1")
            student();
        else if (last_screen == "2")
            Main_Screen();
    }
    else if (choose_student == "4")
        display_grades();
}
void choose_subject()
{
    int choosen_coursecode;
    cout << "\033[1;34m Enter the course code for the subject you want : \033[0m" << endl;
    cout << "\033[1;30m 1907 for Structure Programming(SP). \033[0m" << endl;
    cout << "\033[1;30m 1911 for Business Communication. \033[0m " << endl;
    cout << "\033[1;30m 1902 for English. \033[0m " << endl;
    cout << "\033[1;30m 1955 for German. \033[0m" << endl;
    cout << "\033[1;30m 1914 for Ethics. \033[0m" << endl;
    while (!(cin >> choosen_coursecode))
    {
        cout << "\033[1;31m Invalid!! , Please try again. \033[0m" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    while (choosen_coursecode != 1907 && choosen_coursecode != 1911 && choosen_coursecode != 1902 && choosen_coursecode != 1955 && choosen_coursecode != 1914)
    {
        cout << "\033[1;31m This coursecode doesn't exist , Please Enter again. \033[0m" << endl;
        while (!(cin >> choosen_coursecode))
        {
            cout << "\033[1;31m Invalid!! , Please try again. \033[0m" << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (choosen_coursecode == subject[i].courseCode)
            exam(i, subject[i].exams.num_of_questions);
    }
}
void exam(int index_of_subject, int num_of_questions)
{
    string submit;
    string ready;
    cout << endl;
    cout << "\033[1;35m time : \033[0m" << time_view << "\033[1;35m minutes \033[0m" << endl;
    cout << "\033[1;35m Number of questions : \033[0m" << num_of_questions << endl;
    cout << "\033[1;35m Are you ready to begin the exam (y/n)? \033[0m";
    cin >> ready;
    cin.ignore();
    while (ready != "n" && ready != "N" && ready != "y" && ready != "Y")
    {
        cout << "\033[1;31m Invalid!! , Please try again. \033[0m" << endl;
        cin >> ready;
        cin.ignore();
    }
    cout << endl;

    if (ready == "y" || ready == "Y")
    {
        thread t(countdown, time_view);
        string answer;

        char answer_array[100];
        while (true)
        {
            if (timerRunning == false)
                break;
            for (int i = 0; i < num_of_questions; i++)
            {
                char choose = 'A';
                cout << i + 1 << ") " << subject[index_of_subject].exams.ques[i].question << endl;

                for (int j = 0; j < 4; j++)
                {
                    cout << choose << ") " << subject[index_of_subject].exams.ques[i].options[j] << endl;
                    choose++;
                }
                cout << endl

                    << "\033[1;35m Answer : \033[0m";
                if (timerRunning == false)
                    break;
                cin >> answer;
                counterAnswers++;
                cin.ignore();
                while (answer.size() > 1 || answer[0] != 'a' && answer[0] != 'A' && answer[0] != 'b' && answer[0] != 'B' && answer[0] != 'c' && answer[0] != 'C' && answer[0] != 'd' && answer[0] != 'D')
                {
                    cout << "\033[1;31m Invalid!! , Please try again. \033[0m" << endl;
                    cout << "\033[1;35m Answer : \033[0m";
                    cin >> answer;
                    cin.ignore();
                }
                answer_array[i] = answer[0];
                if (answer_array[i] == 'a')
                    answer_array[i] = 'A';
                else if (answer_array[i] == 'b')
                    answer_array[i] = 'B';
                else if (answer_array[i] == 'c')
                    answer_array[i] = 'C';
                else if (answer_array[i] == 'd')
                    answer_array[i] = 'D';

                cout << endl;

            }
            if (num_of_questions == counterAnswers)
            {

                do
                {

                    cout << endl
                        << "\033[1;30m Press 1 to submit the exam. \033[0m" << endl
                        << "\033[1;30m Press 2 to change your answer(s). \033[0m" << endl;
                    cin >> submit;
                    cin.ignore();
                    valid("2", submit);

                    if (submit == "1")
                    {
                        //remainingMin = 0;
                        //remainingSec = 0;

                        z = false;
                        submit_exam(index_of_subject, answer_array);
                    }
                    else if (submit == "2")
                        change_answers(answer_array, num_of_questions);
                } while (submit == "2");
                break;
            }
        }
        //string submit;
        if (timerRunning == false)
        {
            submit_exam(index_of_subject, answer_array);

        }
        else if (ready == "n" || ready == "N")
            student();
        t.join();
    }

}

void change_answers(char change_answer[], int num_of_questions)
{
    string check, new_answer;
    int change_question;
    do
    {
        cout << "Do you want to change any answer ? (y/n)" << endl;
        cin >> check;
        cin.ignore();
        while (check.size() > 1 || check[0] != 'n' && check[0] != 'N' && check[0] != 'y' && check[0] != 'Y')
        {
            cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
            cin >> check;
            cin.ignore();
        }
        if (check == "y" || check == "Y")
        {
            cout << "Enter the number of question that you want to change : ";
            cout << endl;
            if (timerRunning == false)
                break;
            while (!(cin >> change_question))
            {
                cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }
            while (change_question > num_of_questions || change_question <= 0)
            {
                cout << "\033[1;31m This number doesn't exist in the range of the questions, Please try again. \033[0m" << endl;
                while (!(cin >> change_question))
                {
                    cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
                    cin.clear();
                    cin.ignore(123, '\n');
                }
            }
            cout << "Enter the new answer : ";
            if (timerRunning == false)
                break;
            cin >> new_answer;
            cin.ignore();
            while (new_answer.size() > 1 || new_answer[0] != 'a' && new_answer[0] != 'A' && new_answer[0] != 'b' && new_answer[0] != 'B' && new_answer[0] != 'c' && new_answer[0] != 'C' && new_answer[0] != 'd' && new_answer[0] != 'D')
            {
                cout << "\033[1;31m Invalid!! ,please Enter again. \033[0m" << endl;
                cout << "Enter the new answer : ";
                cin >> new_answer;
                cin.ignore();
            }
            cout << endl;
            for (int i = 0; i < num_of_questions; i++)
            {
                if (i + 1 == change_question)
                {
                    if (new_answer[0] == 'a')
                        new_answer[0] = 'A';
                    else if (new_answer[i] == 'b')
                        new_answer[0] = 'B';
                    else if (new_answer[i] == 'c')
                        new_answer[0] = 'C';
                    else if (new_answer[i] == 'd')
                        new_answer[0] = 'D';
                    if (change_answer[i] == new_answer[0])
                        cout << "\033[1;31m Note: This answer like another answer before!! \033[0m" << endl;
                    change_answer[i] = new_answer[0];
                }
            }
        }

    } while (check == "y" || check == "Y");
}
void submit_exam(int index_of_subject, char answer_array[])
{
    cout << endl;
    cout << "\033[1;32m the Exam has been submitted. \033[0m" << endl;
    string view;
    cout << endl
        << "\033[1;30m Press 1 to view exam results. \033[0m" << endl
        << "\033[1;30m Press 2 to return to student screen. \033[0m" << endl;
    cin >> view;
    cout << endl;
    cin.ignore();
    valid("2", view);
    if (view == "1")
    {
        int correctCounter = 0;

        for (int i = 0; i < subject[index_of_subject].exams.num_of_questions; i++)
        {
            if (subject[index_of_subject].exams.ques[i].correctAnswer == answer_array[i])
                correctCounter++;

        }

        if (subject[index_of_subject].exams.ques[counterAnswers - 1].correctAnswer == answer_array[counterAnswers - 1] && timerRunning == false)
            correctCounter--;

        percentage = (correctCounter * 100) / subject[index_of_subject].exams.num_of_questions;
        cout << "\033[1;34m Your Grade is : \033[0m" << correctCounter * 10 << "\033[1;34m / \033[0m" << subject[index_of_subject].exams.num_of_questions * 10 << endl;
        cout << "\033[1;34m The precentage : \033[0m" << percentage << "\033[1;34m % \033[0m" << endl;

        for (int i = 0; i < num_of_students; i++)
        {
            if (studentName == students[i].username_student && studentPassword == students[i].password_student)
            {
                students[i].list_of_subject[index_of_subject] = correctCounter * 10;
                students[i].studentGrade = percentage;
            }
        }
        if (percentage >= 50)
        {
            cout << "\033[1;32m Student's status: Passed. \033[0m" << endl;
            cout << endl
                << "\033[1;32m Congratulations! Your hard work and dedication have paid off <3 \033[0m" << endl;
        }
        else
        {
            cout << "\033[1;31m Student's status: Failed \033[0m" << endl;
            cout << endl
                << "\033[1;31m You don't have to be great to start , but you have to start to be great <3 \033[0m" << endl;
        }
        cout << endl;
        string return_student;
        cout << "\033[1;30m Press 1 to return to student screen. \033[0m" << endl;
        cin >> return_student;
        cin.ignore();
        valid("1", return_student);
        if (return_student == "1")
            student();
    }
    else if (view == "2")
    {
        student();
    }
}
void display_grades()
{
    cout << "\033[1;34m SP     \033[0m"
        << "\033[1;34m Business   \033[0m"
        << "\033[1;34m English   \033[0m"
        << "\033[1;34m German   \033[0m"
        << "\033[1;34m Ethics   \033[0m" << endl;
    for (int i = 0; i < num_of_students; i++)
    {
        if (studentName == students[i].username_student && studentPassword == students[i].password_student)
        {

            for (int j = 0; j < 5; j++)
            {

                if (students[i].list_of_subject[j] >= 0 && students[i].list_of_subject[j] <= 100)
                {
                    cout << " " << students[i].list_of_subject[j] << "       ";
                }
                else
                {
                    cout << "\033[1;34m    -     \033[0m";
                }
            }
        }
    }

    cout << endl;
    string return_student;
    cout << "\033[1;30m Press 1 to return to student screen. \033[0m" << endl;
    cin >> return_student;
    cin.ignore();
    valid("1", return_student);
    if (return_student == "1")
        student();
}