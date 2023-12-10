#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <iostream>
#include <SDL.h>

class ScoreManager
{
private:
    int totalScore;
    int highestScore;
    int currentScore;

public:
    ScoreManager();

    void increaseScore(int points);

    void resetCurrentScore();

    void renderCurrentScore(SDL_Renderer* renderer, int x, int y);

    void renderGameOverScores(SDL_Renderer* renderer, int x, int y);

private:
    void renderText(SDL_Renderer* renderer, const std::string& text, int x, int y);
};

#endif // SCOREMANAGER_H
