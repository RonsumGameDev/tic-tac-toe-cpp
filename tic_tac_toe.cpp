#include <iostream>

void drawBoard(char[]);

void playerMove(char[], char);

void computerMove(char[], char);

bool checkWinner(char[], char, char);

bool tieCondition(char[]);

int main(){

    srand(time(0));

    char spaces[9];
    std::fill(spaces, spaces+9, ' ');

    char playerMarker = 'X';
    char computerMarker = 'O';

    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, playerMarker);
        drawBoard(spaces);

        if(checkWinner(spaces, playerMarker, computerMarker)){
            running = false;
            break;
        }

        if(tieCondition(spaces)){
            running = false;
            break;
        }

        computerMove(spaces, computerMarker);
        drawBoard(spaces);

        if(checkWinner(spaces, playerMarker, computerMarker)){
            running = false;
            break;
        }

        if(tieCondition(spaces)){
            running = false;
            break;
        }

    }

    return 0;
}

//The way this works is by drawing the lines and leaving 1 space for the input data, the initial data is " " so it looks empty.
void drawBoard(char spaces[]){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char spaces[], char playerMarker){

    int number;
    do{

        std::cout << "Enter a spot to place a marker (1-9) : ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = playerMarker;
            break;
        }

    }while(!number > 0 || !number < 8);

}

void computerMove(char spaces[], char computerMarker){
    int number;
    do{
        number = (rand() % 9);
    }while(spaces[number] != ' ');

    spaces[number] = computerMarker;
}

bool checkWinner(char spaces[], char playerMarker, char computerMarker){

    int winningConditions[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for(auto &w: winningConditions){
        if(((spaces[w[0]] == spaces[w[1]]) && (spaces[w[1]] == spaces[w[2]])) && spaces[w[0]] == playerMarker){
            std::cout << "You Win!" << '\n';
            return true;
        }

        if(((spaces[w[0]] == spaces[w[1]]) && (spaces[w[1]] == spaces[w[2]])) && spaces[w[0]] == computerMarker){
            std::cout << "Computer Wins!" << '\n';
            return true;
        }
    }

    return false;
}

bool tieCondition(char spaces[]){

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }

    std::cout << "It's a Tie!" << '\n';
    return true;
}