#include "scoreManager.hpp"

ScoreManager::ScoreManager() : totalScore(0), highestScore(0), currentScore(0) {}

void ScoreManager::increaseScore(int points)
{
    currentScore += points;
    totalScore += points;

    if (currentScore > highestScore)
    {
        highestScore = currentScore;
    }
}

void ScoreManager::resetCurrentScore()
{
    currentScore = 0;
}

void ScoreManager::renderCurrentScore(SDL_Renderer* renderer, int x, int y)
{
    renderText(renderer, "Current Score: " + std::to_string(currentScore), x, y);
}

void ScoreManager::renderGameOverScores(SDL_Renderer* renderer, int x, int y)
{
    renderText(renderer, "Total Score: " + std::to_string(totalScore), x, y);
    renderText(renderer, "Highest Score: " + std::to_string(highestScore), x, y + 30);
}

void ScoreManager::renderText(SDL_Renderer* renderer, const std::string& text, int x, int y)
{
    // Implement your rendering logic for displaying text on the screen
    // This could involve creating an SDL_Surface, rendering it to a texture, and rendering the texture
    // Refer to SDL documentation for text rendering with SDL
    // Example: SDL_RenderCopy(renderer, texture, NULL, &destinationRect);
}
