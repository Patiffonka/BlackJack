/*
 * BlacJack
 *
 * Kulisov Sergey
 *
 * QT Creator v.4.11.0
 *
 */

#include <iostream>
#include <vector>
#define UP true
#define DOWN false

using namespace std;

class Card {
public:
    enum cardRank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN=10, JACK=10, QUEEN=10, KING=10 };
    enum cardSuit {HEART, DIAMOND, CLUB, SPADE};
    Card (cardRank r, cardSuit s, bool f) : rank(r), suit (s), faceup(f) {}
    void Flip() {
        faceup = !faceup;
    }
    int GetValue() const {
        return static_cast<int>(rank);
    }
    cardRank getRank(){return rank;}
private:
    cardRank rank;
    cardSuit suit;
    bool faceup;
};

class Hand {
private:
    vector<Card*> hand;
public:
    void add(Card* c) {hand.push_back(c);}
    void clear(){
        for (unsigned int i = 0; i < hand.size(); ++i) delete hand[i];
        hand.clear();
        }
    unsigned int size() const {return hand.size();}
    int getValue() const{
        int sum=0;
        for (unsigned int i = 0; i < hand.size(); ++i){
            if (hand.at(i)->getRank() == Card::ACE && ((sum+11)<21)) sum+=11;
            else sum+=static_cast<int>(hand.at(i)->GetValue());
        }
        return sum;
    }
    void print() {
        for (int i = 0; i < hand.size(); ++i)
             cout << hand.at(i)->getRank() << endl;
        cout << "sum: " << getValue() << endl;
    }
};

int main()
{
    Hand *hand = new Hand;
    Card *ACECLUB = new Card(Card::ACE, Card::CLUB, DOWN);
    Card *TWODIAMOND = new Card(Card::TWO, Card::DIAMOND, DOWN);
    Card *JACKSPADE = new Card(Card::JACK, Card::SPADE, DOWN);
    hand->add(ACECLUB);
    hand->add(TWODIAMOND);
    hand->add(JACKSPADE);
    hand->print();
}
