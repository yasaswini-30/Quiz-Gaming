#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    char options[4][50];
    char correct_option;
};

void displayQuestion(struct Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, q.options[i]);
    }
}

char getUserAnswer() {
    char answer;
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    return toupper(answer);
}

int checkAnswer(struct Question q, char userAnswer) {
    return (userAnswer == q.correct_option);
}

int main() {
    struct Question questions[4];

    // Question 1
    strcpy(questions[0].question, "What is the capital of Japan?");
    strcpy(questions[0].options[0], "Tokyo");
    strcpy(questions[0].options[1], "Seoul");
    strcpy(questions[0].options[2], "Beijing");
    strcpy(questions[0].options[3], "Bangkok");
    questions[0].correct_option = 'A';

    // Question 2
    strcpy(questions[1].question, "Which planet is known as the Red Planet?");
    strcpy(questions[1].options[0], "Mars");
    strcpy(questions[1].options[1], "Venus");
    strcpy(questions[1].options[2], "Jupiter");
    strcpy(questions[1].options[3], "Mercury");
    questions[1].correct_option = 'A';

    // Question 3
    strcpy(questions[2].question, "What is the largest mammal?");
    strcpy(questions[2].options[0], "Elephant");
    strcpy(questions[2].options[1], "Blue Whale");
    strcpy(questions[2].options[2], "Giraffe");
    strcpy(questions[2].options[3], "Hippopotamus");
    questions[2].correct_option = 'B';

    // Question 4
    strcpy(questions[3].question, "Which programming language is this quiz written in?");
    strcpy(questions[3].options[0], "Java");
    strcpy(questions[3].options[1], "C++");
    strcpy(questions[3].options[2], "Python");
    strcpy(questions[3].options[3], "C");
    questions[3].correct_option = 'D';

    // Display and check answers
    int score = 0;
    for (int i = 0; i < 4; i++) {
        displayQuestion(questions[i]);
        char userAnswer = getUserAnswer();
        if (checkAnswer(questions[i], userAnswer)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c\n", questions[i].correct_option);
        }
    }

    // Display final score
    printf("Your final score: %d out of 4\n", score);

    return 0;
}
