
#ifndef SUSSDILEMMA_H
#define SUSSDILEMMA_H

#include "Actor.h"
#include <string> //added string
#include <vector> //added vector
#include <random>

class SussDilemma : public Actor {
public:
    SussDilemma(const std::string& name, double forgivenessProbability = 0.05); //changed forgivenessProbability to 0.05
    void face(Actor& opponent) override;
    void reset() override;

private:
    double forgivenessProbability_;
    std::random_device rd_;
    std::mt19937 gen_;
    std::uniform_real_distribution<> distrib_;
};

#endif // SUSSDILEMMA_H





void SussDilemma::reset() {
    Actor::resetScore();
    moves_.clear();
}