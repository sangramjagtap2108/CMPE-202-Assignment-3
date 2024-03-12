#include "GameChoice.h"

std::string GameChoice::choiceToString(Choice c) {
    switch (c) {
    case ROCK: return "Rock";
    case PAPER: return "Paper";
    case SCISSORS: return "Scissors";
    default: return "Unknown";
    }
}

Choice GameChoice::charToChoice(char c) {
    switch (c) {
    case 'R': return ROCK;
    case 'P': return PAPER;
    case 'S': return SCISSORS;
    default: return ROCK; 
    }
}

Choice GameChoice::winningChoiceAgainst(Choice c) {
    switch (c) {
    case ROCK: return PAPER;
    case PAPER: return SCISSORS;
    case SCISSORS: return ROCK;
    default: return ROCK; 
    }
}
