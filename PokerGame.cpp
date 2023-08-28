//
// Created by Sneha Gurung on 12/15/22.
//

#include "PokerGame.h"

PokerGame::PokerGame() = default;

void PokerGame::runPokerGame() {
    srand(time(0));
    Deck deck;
    PokerScore a;
    for(int i = 0; i < 1000; i++)
    {
        deck.shuffle();
        CardHand ch;
        for (int j = 0; j < 5; j++)
        {
            ch.add_card(deck.dealCard());
        }
        a = CardHandScorer::scorePokerHand(ch);
    }
    std::cout << a.getPokerScore() << std::endl;

    sf::RenderWindow window({2300, 1300, 32}, "Poker Analysis");
    window.setFramerateLimit(60);

    PokerRankings b;
    b.outputHand(window);
}

/* CONSTRUCTORS */

pokerCard::pokerCard() : pokerCard(HEARTS, TEN) { }

pokerCard::pokerCard(const pokerCard& other) : pokerCard(other.suit, other.value) { }

pokerCard::pokerCard(suitEnums suit, rankEnum value) : value(value), suit(suit) { }

std::ostream& operator <<(std::ostream& outs, const pokerCard& card)
{
    outs << card.getRank() << " of " << card.getSuit() << std::endl;
    return outs;
}

/* CONVERSION FUNCTIONS - String */

std::string pokerCard::rankToString() const {
    switch (value) {
        case ACE: return "Ace";
        case KING: return "King";
        case QUEEN: return "Queen";
        case JACK: return "Jack";
        case TEN: return "Ten";
        case NINE: return "Nine";
        case EIGHT: return "Eight";
        case SEVEN: return "Seven";
        case SIX: return "Six";
        case FIVE: return "Five";
        case FOUR: return "Four";
        case THREE: return "Three";
        case TWO: return "Two";
        default: return "Error";
    }
}

std::string pokerCard::suitToString() const{
    switch (suit) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
    }
}

/* CONVERSION FUNCTION - Int */

int pokerCard::getRankInt() const {
    switch (value) {
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN: return 10;
        case JACK: return 11;
        case QUEEN: return 12;
        case KING: return 13;
        case ACE: return 14;
        default: return -1;
    }
}

/* GETTER FUNCTIONS */

suitEnums pokerCard::getSuit() const {
    return suit;
}

rankEnum pokerCard::getRank() const {
    return value;
}

/* SETTER FUNCTIONS */

void pokerCard::setSuit(suitEnums newSuit) {
    this->suit = newSuit;
}

void pokerCard::setRank(rankEnum newValue) {
    this->value = newValue;
}

CardHand::CardHand(): CardHand(0, 0) { }

CardHand::CardHand(float xPos, const float yPos)
        : m_xPos(xPos), m_yPos(yPos)
{
}

void CardHand::add_card(const pokerCard& card) {
    player_hand.push_back(card);
}

std::ostream& operator <<(std::ostream& outs, const CardHand& hand) {
    for (int i = 0; i < hand.getSize(); i++) {
        outs << hand.player_hand[i] << std::endl;
    }
    return outs;
}

pokerCard CardHand::getCardAt(int index) const {
    return player_hand.at(index);
}

int CardHand::getSize() const {
    return player_hand.size();
}

int CardHand::getCardValueAt(int index) {
    return player_hand[index].getRank();
}

bool operator<(const pokerCard& a, const pokerCard& b) {
    return a.getRankInt() < b.getRankInt();
}

void CardHand::sortRank() {
    std::sort(player_hand.begin(), player_hand.end());
}


PokerScore CardHandScorer::hold;

CardHandScorer::CardHandScorer() { }

PokerScore CardHandScorer::scorePokerHand(CardHand& hand) {
    hand.sortRank();
    isRoyalFlush(hand);
    isStraightFlush(hand);
    isFourOfAKind(hand);
    isFullHouse(hand);
    isFlush(hand);
    isStraight(hand);
    isThreeOfAKind(hand);
    isTwoPair(hand);
    isOnePair(hand);
    isHighCard(hand);
    return hold;
}

bool CardHandScorer::isRoyalFlush(CardHand &hand) {
    bool stands = true;
    for (int i = 0; i < hand.getSize(); i++) {
        if (hand.getCardAt(0).getSuit() != hand.getCardAt(i).getSuit())
            stands = false;
    }

    if (hand.getCardAt(0).suitToString() == "TEN"
        && hand.getCardAt(1).suitToString() == "JACK"
        && hand.getCardAt(2).suitToString() == "QUEEN"
        && hand.getCardAt(3).suitToString() == "KING"
        && hand.getCardAt(4).suitToString() == "ACE"
        && stands)
        hold.addScore(Scores::ROYAL_FLUSH);

    return stands;
}

bool CardHandScorer::isStraightFlush(CardHand &hand) {
    bool stands = true;
    for (int i = 0; i < hand.getSize(); i++) {
        if (hand.getCardAt(0).getSuit() != hand.getCardAt(i).getSuit())
            return false;
    }

    hand.sortRank();
    for (int i = 0; i < hand.getSize()-1; i++) {
        if (hand.getCardValueAt(i+1) - hand.getCardValueAt(i) != 1)
            return false;
    }
    hold.addScore(Scores::STRAIGHT_FLUSH);
    return stands;
}

bool CardHandScorer::isFourOfAKind(CardHand& hand) {
    bool stands = false;
    int count[13] = {0};
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)] ++;
    }
    for (int j = 0; j < 13; j++) {
        if (count[j] >= 4)
        {
            hold.addScore(Scores::FOUR_OF_A_KIND);
            stands = true;
            break;
        }
    }
    return stands;
}

bool CardHandScorer::isFullHouse(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    int three = 0;
    int pair = 0;
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)]++;
    }

    for (int i = 0; i < rankEnum::NUM_RANKS; i++) {
        if (count[i] == 2)
            pair += 1;
        if (count[i] == 3)
            three += 1;
        if (three > 0 && pair > 0){
            hold.addScore(Scores::FULL_HOUSE);
            break;
        }
    }

    return stands;
}

bool CardHandScorer::isFlush(CardHand &hand) {
    bool stands = true;
    for (int i = 0; i < hand.getSize(); i++) {
        if (hand.getCardAt(0).getSuit() != hand.getCardAt(i).getSuit()) {
            stands = false;
            break;
        }
    }
    if (stands)
        hold.addScore(Scores::FLUSH);

    return stands;
}

bool CardHandScorer::isStraight(CardHand &hand) {
    bool stands = true;
    hand.sortRank();
    for (int i = 0; i < hand.getSize()-1; i++) {
        if (hand.getCardValueAt(i+1) - hand.getCardValueAt(i) != 1)
            return stands;
    }
    hold.addScore(Scores::STRAIGHT);
    return stands;
}

bool CardHandScorer::isThreeOfAKind(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)] ++;
    }
    for (int i = 0; i < rankEnum::NUM_RANKS; i++) {
        if (count[i] >= 3)
        {
            hold.addScore(Scores::THREE_OF_A_KIND);
            break;
        }
    }

    return stands;
}

bool CardHandScorer::isTwoPair(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    int pairs = 0;
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)]++;
    }

    for(int i = 0; i < rankEnum::NUM_RANKS; i++) {
        if(count[i] >= 2) {
            pairs++;
            if(pairs >= 2) {
                hold.addScore(Scores::TWO_PAIR);
                break;
            }
        }
    }
    return stands;
}

bool CardHandScorer::isOnePair(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    //int count[rankEnum::NUM_RANKS] = {0};
    for (int i = 0; i < hand.getSize(); i++)
    {
        count[hand.getCardValueAt(i)]++;
    }
    for(int i = 0; i < rankEnum::NUM_RANKS; i++)
    {
        if(count[i] >= 2)
        {
            hold.addScore(Scores::ONE_PAIR);
            break;
        }
    }
    return stands;
}

bool CardHandScorer::isHighCard(CardHand &hand) {
    hold.addScore(Scores::HIGH_CARD);
    return true;
}

Deck::Deck() : cardIndex(0)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[cardIndex] = pokerCard(static_cast<suitEnums>(i), static_cast<rankEnum>(j));
            cardIndex++;
        }
    }
    cardIndex = 0;
}

bool Deck::empty() {
    if (cardIndex > DECK_SIZE)
        return true;
    return false;
}

void Deck::shuffle() {
    cardIndex = 0;
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % 52;
        pokerCard swap = deck[i];
        deck[i] = deck[r];
        deck[r] = swap;
    }
}

pokerCard Deck::dealCard() {
    if (!empty()) {
        pokerCard card = deck[cardIndex];
        cardIndex++;
        return card;
    }
    pokerCard card;
    return card;
}

pokerCard Deck::getCardAt(int index) {
    return deck[index];
}

void Deck::printDeck()
{
    for (int i = 0; i < 52; i++) {
        std::cout << i+1 << ": " << getCardAt(i);
    }
}

#include <vector>

SFML_hand::SFML_hand() {

}

SFML_hand::SFML_hand(CardHand hand_1) : hand(hand_1)
{
    setPosition({hand_1.m_xPos, hand_1.m_yPos});
}

void SFML_hand::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    std::vector<drawCard> cards;
    for(int i = 0; i < hand.getSize(); i++)
    {
        cards.emplace_back(hand.getCardAt(i).getSuit(), hand.getCardAt(i).getRank());
    }
    int num = 110; // :)
    for(int i = 0; i < cards.size(); i++)
    {
        cards[i].setPosition(position.x + (num * i), position.y);
        window.draw(cards[i]);
    }
}

void SFML_hand::setPosition(sf::Vector2f pos) {
    this->position = pos;
}


void PokerRankings::outputHand(sf::RenderWindow& window) {

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({HEARTS, ACE});
        ch.add_card({HEARTS, KING});
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({HEARTS, JACK});
        ch.add_card({HEARTS, TEN});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({CLUBS, TEN});
        ch.add_card({CLUBS, NINE});
        ch.add_card({CLUBS, EIGHT});
        ch.add_card({CLUBS, SEVEN});
        ch.add_card({CLUBS, SIX});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({SPADES, QUEEN});
        ch.add_card({DIAMONDS, QUEEN});
        ch.add_card({CLUBS, QUEEN});
        ch.add_card({HEARTS, KING});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({SPADES, QUEEN});
        ch.add_card({DIAMONDS, QUEEN});
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({CLUBS, FIVE});
        ch.add_card({HEARTS, FIVE});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({CLUBS, KING});
        ch.add_card({CLUBS, NINE});
        ch.add_card({CLUBS, SEVEN});
        ch.add_card({CLUBS, FIVE});
        ch.add_card({CLUBS, TWO});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({DIAMONDS, TEN});
        ch.add_card({SPADES, NINE});
        ch.add_card({HEARTS, EIGHT});
        ch.add_card({CLUBS, SEVEN});
        ch.add_card({DIAMONDS, SIX});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({DIAMONDS, FIVE});
        ch.add_card({SPADES, NINE});
        ch.add_card({HEARTS, FIVE});
        ch.add_card({CLUBS, FIVE});
        ch.add_card({DIAMONDS, SIX});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({DIAMONDS, ACE});
        ch.add_card({SPADES, ACE});
        ch.add_card({HEARTS, TEN});
        ch.add_card({CLUBS, TEN});
        ch.add_card({SPADES, SIX});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({CLUBS, TWO});
        ch.add_card({DIAMONDS, JACK});
        ch.add_card({SPADES, ACE});
        ch.add_card({HEARTS, ACE});
        ch.add_card({SPADES, SEVEN});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({SPADES, JACK});
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({CLUBS, KING});
        ch.add_card({HEARTS, FIVE});
        ch.add_card({DIAMONDS, TWO});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    for (int i = 0; i < allHands.size(); ++i) {
        drawableHands.emplace_back(allHands[i]);
    }

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                window.close();
            }
        }

        window.clear(sf::Color(85, 125, 96));
        for (int i = 0; i < drawableHands.size(); i++)
        {
            window.draw(drawableHands[i]);
        }
        window.display();
    }
}

PokerRankings::PokerRankings() = default;



sf::Texture drawCard::texture;
sf::Font drawCard::font;
sf::Texture drawCard::Hearts;
sf::Texture drawCard::Spades;
sf::Texture drawCard::Diamonds;
sf::Texture drawCard::Clubs;

drawCard::drawCard() : drawCard(HEARTS, ACE)
{
    initialize();
}

drawCard::drawCard(suitEnums suit, rankEnum rank) : _suit(suit), _rank(rank)
{
    initialize();
}

void drawCard::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background), window.draw(suit), window.draw(rank), window.draw(rank2);
    window.draw(RoyalFlush), window.draw(StraightFlush), window.draw(FourOfAKind);
    window.draw(FullHouse), window.draw(FullHouse), window.draw(Flush);
    window.draw(Straight), window.draw(ThreeOfAKind), window.draw(TwoPair);
    window.draw(Pair), window.draw(HighCard);
}

std::string drawCard::rankToString()
{
    switch (_rank) {
        case ACE: return "A";
        case KING: return "K";
        case QUEEN: return "Q";
        case JACK: return "J";
        case TEN: return "10";
        case NINE: return "9";
        case EIGHT: return "8";
        case SEVEN: return "7";
        case SIX: return "6";
        case FIVE: return "5";
        case FOUR: return "4";
        case THREE: return "3";
        case TWO: return "2";
        default: return "Error";
    }
}

std::string drawCard::suitToString()
{
    switch (_suit) {
        case HEARTS: return "Image copy/heart.png";
        case DIAMONDS: return "Image copy/diamonds.png";
        case CLUBS: return "Image copy/club.png";
        case SPADES: return "Image copy/spades.png";
        default: return "Error";
    }
}

void drawCard::initialize()
{
    setText();
    setUpBackground();
    setUpRank();
    setUpSuit();
}

void drawCard::setUpBackground()
{
    background.setSize({100, 150});
    background.setPosition({150, 200});
}

void drawCard::setUpRank()
{
    if (!font.loadFromFile("Fonts/Sans-Bold copy.ttf"))
        exit(20);
    rank.setFont(font);
    rank.setString(rankToString());
    rank.setFillColor(sf::Color::Black);
    rank.setCharacterSize(30);
    rank2.setFont(font);
    rank2.setString(rankToString());
    rank2.setFillColor(sf::Color::Black);
    rank2.setCharacterSize(30);
    positionRank();
    rank2.rotate(180);
}

void drawCard::positionSuit() {
    suit.setPosition({bounds().left + bounds().width/4,bounds().top + bounds().height/3});
}

void drawCard::positionRank() {
    rank.setPosition({bounds().left, bounds().top});
    rank2.setPosition({bounds().left + bounds().width,bounds().top + bounds().height});
}

void drawCard::setUpSuit()
{
    if (!texture.loadFromFile(suitToString()))
        exit(21);

    if (_suit == SPADES) {
        Spades.loadFromFile(suitToString());
        suit.setTexture(Spades);
        suit.setScale({0.7, 0.7});
        positionSuit();
    }

    if (_suit == DIAMONDS) {
        Diamonds.loadFromFile(suitToString());
        rank.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);
        suit.setTexture(Diamonds);
        suit.setScale(0.14, 0.14);
        positionSuit();
    }

    if (_suit == HEARTS) {
        Hearts.loadFromFile(suitToString());
        rank.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);
        suit.setTexture(Hearts);
        suit.setScale({0.7, 0.7});
        positionSuit();
    }

    if (_suit == CLUBS) {
        Clubs.loadFromFile(suitToString());
        suit.setTexture(Clubs);
        suit.setScale({0.7, 0.7});
        positionSuit();
    }
}

void drawCard::setFillColor(const sf::Color &color) {
    setFillColor(color);
}

void drawCard::setSize(sf::Vector2f size) {
    setSize(size);
}

void drawCard::setSize(float width, float height) {
    setSize(width, height);
}

void drawCard::setPosition(float x, float y) {
    setPosition({x, y});
}

void drawCard::setPosition(sf::Vector2f position) {
    background.setPosition(position);
    positionSuit();
    positionRank();
}

sf::FloatRect drawCard::bounds() {
    return background.getGlobalBounds();
}

void drawCard::setText() {
    if (!font.loadFromFile("Fonts/Sans-Bold copy.ttf"))
        exit(20);

    /* Left side Column */
    RoyalFlush.setPosition({50, 50});
    RoyalFlush.setFont(font);
    RoyalFlush.setString("Royal Flush\nProbability: " + std::to_string(scoreObj.numChances[0]) + "%");
    RoyalFlush.setFillColor(sf::Color(250, 132, 226));
    RoyalFlush.setCharacterSize(35);

    StraightFlush.setPosition({50, 300});
    StraightFlush.setFont(font);
    StraightFlush.setString("Straight Flush\nProbability: " + std::to_string(scoreObj.numChances[1]) + "%");
    StraightFlush.setFillColor(sf::Color(250, 132, 226));
    StraightFlush.setCharacterSize(35);

    FourOfAKind.setPosition({50, 550});
    FourOfAKind.setFont(font);
    FourOfAKind.setString("Four of a kind\nProbability: " + std::to_string(scoreObj.numChances[2]) + "%");
    FourOfAKind.setFillColor(sf::Color(250, 132, 226));
    FourOfAKind.setCharacterSize(35);

    FullHouse.setPosition({50, 800});
    FullHouse.setFont(font);
    FullHouse.setString("Full House\nProbability: " + std::to_string(scoreObj.numChances[3]) + "%");
    FullHouse.setFillColor(sf::Color(250, 132, 226));
    FullHouse.setCharacterSize(35);

    Flush.setPosition({50, 1050});
    Flush.setFont(font);
    Flush.setString("Flush\nProbability: " + std::to_string(scoreObj.numChances[4]) + "%");
    Flush.setFillColor(sf::Color(250, 132, 226));
    Flush.setCharacterSize(35);

    /* Right side Column */
    Straight.setPosition({1800, 50});
    Straight.setFont(font);
    Straight.setString("Straight\nProbability: " + std::to_string(scoreObj.numChances[5]) + "%");
    Straight.setFillColor(sf::Color(250, 132, 226));
    Straight.setCharacterSize(35);

    ThreeOfAKind.setPosition({1800, 300});
    ThreeOfAKind.setFont(font);
    ThreeOfAKind.setString("Three of a Kind\nProbability: " + std::to_string(scoreObj.numChances[6]) + "%");
    ThreeOfAKind.setFillColor(sf::Color(250, 132, 226));
    ThreeOfAKind.setCharacterSize(35);

    TwoPair.setPosition({1800, 550});
    TwoPair.setFont(font);
    TwoPair.setString("Two Pair\nProbability: " + std::to_string(scoreObj.numChances[7]) + "%");
    TwoPair.setFillColor(sf::Color(250, 132, 226));
    TwoPair.setCharacterSize(35);

    Pair.setPosition({1800, 800});
    Pair.setFont(font);
    Pair.setString("Pair\nProbability: " + std::to_string(scoreObj.numChances[8]) + "%");
    Pair.setFillColor(sf::Color(250, 132, 226));
    Pair.setCharacterSize(35);

    HighCard.setPosition({1800, 1050});
    HighCard.setFont(font);
    HighCard.setString("High pokerCard\nProbability: " + std::to_string(scoreObj.numChances[9]) + "%");
    HighCard.setFillColor(sf::Color(250, 132, 226));
    HighCard.setCharacterSize(35);
}





float PokerScore::numChances[10] = {0};

PokerScore::PokerScore() = default;

void PokerScore::operator+=(const Scores &score) {
    this->addScore(score);
}

Scores& PokerScore::operator[](unsigned int index) {
    return scores[index];
}

void PokerScore::addScore(Scores score) {
    scores.push_back(score);
}

bool operator ==(const PokerScore& p, Scores score) {
    for (int i = 0; i < p.size(); i++) {
        if (p.getScoreAt(i) == score)
            return true;
    }
    return false;
}

int PokerScore::size() const {
    return scores.size();
}

Scores PokerScore::getScoreAt(int index) const {
    return scores[index];
}

std::string PokerScore::getPokerScore() {
    int temp[SIZE_SCORES] = {0};
    for (auto & score : scores) {
        switch (score) {
            case ROYAL_FLUSH:
                temp[ROYAL_FLUSH] += 1;
                break;
            case STRAIGHT_FLUSH:
                temp[STRAIGHT_FLUSH] += 1;
                break;
            case FOUR_OF_A_KIND:
                temp[FOUR_OF_A_KIND] += 1;
                break;
            case FULL_HOUSE:
                temp[FULL_HOUSE] += 1;
                break;
            case FLUSH:
                temp[FLUSH] += 1;
                break;
            case STRAIGHT:
                temp[STRAIGHT] += 1;
                break;
            case THREE_OF_A_KIND:
                temp[THREE_OF_A_KIND] += 1;
                break;
            case TWO_PAIR:
                temp[TWO_PAIR] += 1;
                break;
            case ONE_PAIR:
                temp[ONE_PAIR] += 1;
                break;
            case HIGH_CARD:
                temp[HIGH_CARD] += 1;
                break;
            default:
                break;
        }
    }

//    int num = 1000;

    std::string arr[] = {"ROYAL_FLUSH", "STRAIGHT_FLUSH", "FOUR_OF_A_KIND", "FULL_HOUSE", "FLUSH",
                         "STRAIGHT","THREE_OF_A_KIND", "TWO_PAIR", "ONE_PAIR", "HIGH_CARD"};

    for (int i = 0; i < SIZE_SCORES; i++){
        numChances[i] = (((float) temp[i] / (float) temp[9]) * 100);
//        std::cout << arr[i] << ": " << temp[i] << std::endl;
    }

    return "";
}





