//
// Created by Sneha Gurung on 12/15/22.
//

#ifndef PORTFOLIO_POKERGAME_H
#define PORTFOLIO_POKERGAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include "suitEnums.h"
#include "rankEnums.h"

enum Scores {
    ROYAL_FLUSH = 0, STRAIGHT_FLUSH = 1, FOUR_OF_A_KIND = 2, FULL_HOUSE = 3, FLUSH = 4, STRAIGHT = 5,
    THREE_OF_A_KIND = 6, TWO_PAIR = 7, ONE_PAIR = 8, HIGH_CARD = 9, SIZE_SCORES
};

class PokerGame {
public:
    PokerGame();
    void runPokerGame();
};



class PokerScore {
private:
    std::vector<Scores> scores;

public:
//    int temp[SIZE_SCORES] = {0};
    PokerScore();
    std::string getPokerScore();
    int size() const;
    void operator += (const Scores& score);
    friend bool operator ==(const PokerScore& p, Scores score);
    Scores& operator[](unsigned int index);
    void addScore(Scores score);
    Scores getScoreAt(int index) const;
    static float numChances[10];
};


class pokerCard {
private:
    suitEnums suit;
    rankEnum value;

public:
    pokerCard();
    pokerCard(suitEnums suit, rankEnum value);
    pokerCard(const pokerCard& other);

    friend std::ostream& operator <<(std::ostream& outs, const pokerCard& card);

    std::string suitToString() const;
    std::string rankToString() const;

    void setSuit(suitEnums newSuit);
    void setRank(rankEnum newValue);
    suitEnums getSuit() const;
    rankEnum getRank() const;

    int getRankInt() const;
};

class CardHand
{
private:
    std::vector<pokerCard> player_hand;
public:
    float m_xPos;
    float m_yPos;

public:
    CardHand();
    CardHand(float, const float);

    void add_card(const pokerCard& card);

    friend std::ostream& operator <<(std::ostream& outs, const CardHand& hand);
    friend bool operator <(const pokerCard& a, const pokerCard& b);
    pokerCard getCardAt(int index) const;

    int getSize() const;
    int getCardValueAt(int index);
    void sortRank();
};


class CardHandScorer {
public:
    CardHandScorer();

    static PokerScore scorePokerHand(CardHand& hand);
    static bool isRoyalFlush(CardHand& hand);
    static bool isStraightFlush(CardHand& hand);
    static bool isFourOfAKind(CardHand& hand);
    static bool isFullHouse(CardHand& hand);
    static bool isFlush(CardHand& hand);
    static bool isStraight(CardHand& hand);
    static bool isThreeOfAKind(CardHand& hand);
    static bool isTwoPair(CardHand& hand);
    static bool isOnePair(CardHand& hand);
    static bool isHighCard(CardHand& hand);
    static PokerScore hold;
};


class Deck
{
private:
    int cardIndex;
    const static int DECK_SIZE = 52;
    pokerCard deck[DECK_SIZE];

public:
    Deck();
    bool empty();
    void shuffle();
    pokerCard dealCard();
    pokerCard getCardAt(int index);
    void printDeck();
//    friend std::ostream& operator <<(std::ostream& outs, const Deck& deck);
};

class SFML_hand : public sf::Drawable
{
private:
    CardHand hand;
    sf::Vector2f position;

public:
    SFML_hand();
    SFML_hand(CardHand hand_1);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setPosition(sf::Vector2f pos);
};


class PokerRankings {
private:
    std::vector<CardHand> allHands = {};
    std::vector<SFML_hand> drawableHands = {};
    int startXpos = 500;
    int startYpos = 50;
    int startXpos2 = 1200.f;
    int startYpos2 = 50;
    const static int rowIncrementAmount = 250;

public:
    PokerRankings();
    void outputHand(sf::RenderWindow& window);
};

class drawCard : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape background;
    sf::Text rank;
    sf::Text rank2;
    sf::Sprite suit;
    static sf::Texture texture;
    static sf::Font font;
    sf::Text RoyalFlush, StraightFlush, FourOfAKind, FullHouse, Flush,
            Straight, ThreeOfAKind, TwoPair, Pair, HighCard;
    /* textures for SUITS */
    static sf::Texture Hearts;
    static sf::Texture Spades;
    static sf::Texture Diamonds;
    static sf::Texture Clubs;
    suitEnums _suit;
    rankEnum _rank;
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void setUpProbability();
    void setUpBackground();
    void setUpRank();
    void setUpSuit();
    void positionSuit();
    void positionRank();

    void setText();

public:
    drawCard();
    drawCard(std::string suit, std::string rank);
    drawCard(suitEnums suit, rankEnum rank);
    PokerScore scoreObj;
    sf::FloatRect bounds();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
};







#endif //PORTFOLIO_POKERGAME_H
