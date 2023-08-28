//
// Created by Sneha Gurung on 12/15/22.
//

#include "DrawCard.h"

DrawCard::DrawCard() = default;

void DrawCard::runDrawCard() {
    sf::RenderWindow window({1000, 1000, 32}, "pokerCard Game!");
    window.setFramerateLimit(60);

    Card card(HEARTS, KING);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                window.close();
            }
        }

        window.clear(sf::Color(85, 125, 96));
        window.draw(card);
        window.display();
    }
}

sf::Texture Card::texture_card;
sf::Font Card::font_card;

Card::Card() : Card(HEARTS, ACE)
{
    initialize();
}

Card::Card(std::string suit, std::string rank)
{
    initialize();

}

Card::Card(suitEnums suit, rankEnum rank) : suits_card(suit), ranks_card(rank)
{
    initialize();
}

void Card::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(_background);
    window.draw(suit_card);
    window.draw(rank_card);
    window.draw(rank2_card);
}

std::string Card::rankToString()
{
    switch (ranks_card) {
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
        case NUM_RANKS: return "";
    }
}

std::string Card::suitToString()
{
    switch (suits_card) {
        case HEARTS: return "Image copy/heart.png";
        case DIAMONDS: return "Image copy/diamonds.png";
        case CLUBS: return "Image copy/club.png";
        case SPADES: return "Image copy/spades.png";
    }
}


void Card::initialize()
{
    setUpBackground();
    setUpRank();
    setUpSuit();
}

void Card::setUpBackground()
{
    _background.setSize({130, 200});
    _background.setPosition({450, 400});
}

void Card::setUpRank()
{
    if (!font_card.loadFromFile("Fonts/Sans-Bold copy.ttf"))
        exit(20);
    rank_card.setFont(font_card);
    rank_card.setString(rankToString());
    rank_card.setFillColor(sf::Color::Black);
    rank_card.setCharacterSize(30);
    rank2_card.setFont(font_card);
    rank2_card.setString(rankToString());
    rank2_card.setFillColor(sf::Color::Black);
    rank2_card.setCharacterSize(30);
    rank_card.setPosition({_background.getGlobalBounds().left, _background.getGlobalBounds().top});
    rank2_card.setPosition({_background.getGlobalBounds().left + _background.getGlobalBounds().width,
                            _background.getGlobalBounds().top + _background.getGlobalBounds().height});
    rank2_card.rotate(180);
}


void Card::setUpSuit()
{
    if (!texture_card.loadFromFile(suitToString()))
        exit(21);
    suit_card.setTexture(texture_card);
    if (suits_card == DIAMONDS)
        suit_card.setScale(0.2, 0.2);
    suit_card.setPosition({_background.getGlobalBounds().left + _background.getGlobalBounds().width / 4,
                           _background.getGlobalBounds().top + _background.getGlobalBounds().height/3});

}

void Card::setFillColor(const sf::Color &color) {
    setFillColor(color);
}

void Card::setSize(sf::Vector2f size) {
    setSize(size);
}

void Card::setSize(float width, float height) {
    setSize(width, height);
}

void Card::setPosition(sf::Vector2f position) {
    setPosition(position);
}

void Card::setPosition(float x, float y) {
    Transformable::setPosition(x, y);
}

