#include "SussDilemma.h"

SussDilemma::SussDilemma(const std::string& name, double forgivenessProbability)
    : Actor(name), forgivenessProbability_(forgivenessProbability), gen_(rd_()), distrib_(0.0, 1.0) {}

void SussDilemma::face(Actor& opponent) {
    std::string move;
    const std::vector<std::string>& opponentMoves = opponent.getMoves();

    if (getMoves().empty()) {
        move = "cooperate"; // cooperate on the first move
    } else {
        if (!opponentMoves.empty()) {
            if (opponentMoves.back() == "defect") {
                if (opponentMoves.back() == "defect") {
                    move = "defect"; // Retaliate (like TFT)
                } else { // Opponent cooperated
                    // Explore with a small probability
                    if (distrib(gen) < explorationProbability) {
                        move = "defect"; // Explore by defecting
                    } else {
                        move = "cooperate"; // Otherwise, cooperate (like TFT)
                    }
                }
            } else {
                move = "cooperate"; // Cooperate if the opponent cooperated
            }
        } else {
            move = "cooperate"; // Should not happen after the first move, but be safe
        }
    }

    recordMove(move);
}

void sussDilemma::reset() {
    Actor::resetScore();
    moves_.clear();
}