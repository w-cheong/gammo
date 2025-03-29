#include "SussDilemma.h"

SussDilemma::SussDilemma(const std::string& name, double forgivenessProbability)
    : Actor(name), forgivenessProbability_(forgivenessProbability), gen_(rd_()), distrib_(0.0, 1.0) {}

void SussDilemma::face(Actor& opponent) {
    std::string move;
    const std::vector<std::string>& opponentMoves = opponent.getMoves();

    if (getMoves().empty()) {
        move = "defect"; // Defect on the first move
    } else {
        if (!opponentMoves.empty()) {
            if (opponentMoves.back() == "defect") {
                // Forgive with a certain probability
                if (distrib_(gen_) < forgivenessProbability_) {
                    move = "cooperate";
                } else {
                    move = "defect";
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