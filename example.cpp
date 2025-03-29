#include "../include/<your_dot_h_file>.h"

<ActorName>::<ActorName>(const std::string& name) : Actor(name) {}

void <ActorName>::face(Actor& opponent) {
    std::string move;

    
    const std::vector<std::string>&    opponentMoves = opponent.getMoves();
    // Check if opponent has made any moves
    if (!opponentMoves.empty()) {
        // Use opponents last move
        move = opponentMoves.back();
    } else {
        // Default/first move action
        move = "cooperate" or "defect;
    }

    recordMove(move);
}